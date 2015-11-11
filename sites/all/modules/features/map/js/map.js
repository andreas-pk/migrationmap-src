/**
 * Created by andreas.pinto on 31.05.15.
 */

Drupal.behaviors.map = {
  attach: function (context, settings) {
    var map = getMap();
    // @todo fetch cluster layer dynamically
    if(map.layers['openlayers_examples_layer_cluster_cities_pdm'] != undefined) {
      map.layers['openlayers_examples_layer_cluster_cities_pdm'].setStyle(addIconStyle);
    }
    if(map.layers['geofield_field_formatter_layer'] != undefined) {
      map.layers['geofield_field_formatter_layer'].setStyle(addIconStyle);
    }
    if(jQuery('#search').length) {
      jQuery('#search').autocomplete({
        source: [],
        minLength: 3,
        search: function(event, ui){fetchData(event.type, getSearchText())}
      });
    }
  }
};

/**
 * fetch GeoJSON data from feed set in map
 * @categories term ids '1+2+3' or '1,2,3' are attached to request url
 */
var fetchData = function (event, data) {
  categories = undefined;
  searchText = undefined;
  var locationsFeed = getLocationsFeed();
  //var locationsFeedUrl = '?q=' + Drupal.settings.pathPrefix + 'locations-feed';
  var locationsFeedUrl = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'locations-feed';
  if (event == 'fancytreeselect') {
    categories = data;
    searchText = getSearchText();
  }
  if (event == 'autocompletesearch') {
    searchText = data;
    categories = getTreeSelectedNodes();
  }
  if (categories != undefined) {
    locationsFeedUrl += '/' + categories;
  }
  if (searchText != undefined) {
    locationsFeedUrl += '?combine=' + searchText;
  }
  jQuery.ajax(locationsFeedUrl,
    {
      dataType: 'json',
      success: function (data, textStatus, jqXHR) {
        locationsFeed.clear(); //remove existing features
        var features = locationsFeed.readFeatures(data);
        locationsFeed.addFeatures(features);
      },
      error: function (jqXHR, textStatus, errorThrown) {
      }
    });
};

/*
 * Help function to get selected keys from tree filter
 * and merged into string i.e. '1+2+3'
 */
function getTreeSelectedNodes(tree) {
  if (tree == undefined) {
    tree = jQuery("#filter").fancytree("getTree");
  }
  // select node on activation
  var selectedNodes = tree.getSelectedNodes();
  var selectedKeys = [];
  selectedNodes.forEach(function (element1, element2, set) {
    selectedKeys.push(element1.key)
  });
  selectedKeys = selectedKeys.join('+');
  return selectedKeys;
}

/*
 *Help functin to get search text from input field
 */
function getSearchText() {
  return jQuery('#search').val();
}

jQuery(function () {

  replaceJSONSourcePath(getLocationsFeed());

  /**
   * create filter tree with data from ajax call
   */
  if (jQuery('#filter').length) {
    jQuery('#filter').fancytree({
      source: {
        url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'map/map-filter',
        cache: false
      },
      activeVisible: true,
      checkbox: true,
      selectMode: 3,
      generateIds: true,
      idPrefix: 'filter-',
      icons: true,
      activate: function (event, data) {
      },
      deactivate: function (event, data) {
      },
      create: function (event, data) {
      },
      select: function (event, data) {
        // A node was selected: fetchData (and redraw map)
        fetchData(event.type, getTreeSelectedNodes(data.tree));
        if (data.node.selected === false && data.node.isActive() === true) {
          data.node.setActive(false);
        }
        if (data.node.selected === true) {
        }
      }

    });
  }
});

// helper function to fetch the map from dom tree via its id
var getMap = function() {
  var mapId = jQuery('.openlayers-map').attr('id');
  return Drupal.openlayers.getMapById(mapId);
}

// helper function to get (only first) json src from map sources
var findGeoJSONFeedInSources = function(sources) {
  for(var element in sources) {
    if(sources[element] instanceof ol.source.GeoJSON) {
      return element;
    }
  }
};

var replaceJSONSourcePath = function(feedSource) {
  //console.log('feed', feedSource);
  fetchData('initialisation');
};

// helper function to get locations feed (from map)
var getLocationsFeed = function () {
  var map = getMap();
  var locationsFeedName = findGeoJSONFeedInSources(map.sources);
  var locationsFeed = map.sources[locationsFeedName];
  return locationsFeed;
};

/**
 * Helper function to return feature style depending on a single feature or a cluster.
 * @param feature
 * @param resolution
 * @returns {*[]}
 */
var addIconStyle = function(feature, resolution) {
  // return for empty features
  if (feature === undefined) return;
  var iconStyle = {};
  var featureContent = feature.get('features');
  // try to fetch geometry from feature
  if (featureContent === undefined) {
    featureContent = feature.get('geometry');
  }
  // different iconStyles for single and clustered features
  if (featureContent instanceof ol.geom.Point) {
    return [singleFeatureStyle(featureContent)];
  }
  if (featureContent.length == 1) {
    return [singleFeatureStyle(featureContent[0])];
  } else {
    return [clusterStyle(featureContent)];
  }
};

// small help function which returns the style for clustered features
var clusterStyle = function (feature) {
  var size = feature.length;
  return new ol.style.Style({
    image: new ol.style.Circle({
      radius: Math.max(12, (12 + 0.35*size)),
      stroke: new ol.style.Stroke({
        color: '#fff'
      }),
      fill: new ol.style.Fill({
        color: '#3399CC'
      })
    }),
    text: new ol.style.Text({
      text: size.toString(),
      fill: new ol.style.Fill({
        color: '#fff'
      })
    })
  })
};

// small help function which returns icon style for a single feature
// depending on its category
var singleFeatureStyle = function (feature) {
  // get category
  if (feature instanceof ol.geom.Point) {
    var icon_image_name = 'default-marker';
  } else {
    var icon_image_name = feature.get('parent_machine_name') || feature.get('machine_name') || 'default-marker';
  }
  // default iconStyle
  return new ol.style.Style({
    image: new ol.style.Icon( ({
      //anchor: [1, 0.1],
      //anchorXUnits: 'fraction',
      //anchorYUnits: 'pixels',
      opacity: 1,
      scale: 0.14,
      src: Drupal.settings.themePath + '/images/source/' + icon_image_name +'-icon.png'
    }))
  });
};
