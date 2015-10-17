/**
 * Created by andreas.pinto on 31.05.15.
 */

Drupal.behaviors.map = {
  attach: function (context, settings) {
    var map = getMap();
    // @todo fetch cluster layer dynamically
    console.log(map, 'm');
    if(map.layers['openlayers_examples_layer_cluster_cities_pdm'] != undefined) {
      map.layers['openlayers_examples_layer_cluster_cities_pdm'].setStyle(addIconStyle);
    }
    if(map.layers['geofield_field_formatter_layer'] != undefined) {
      //map.layers['geofield_field_formatter_layer'].setStyle(addIconStyle);
    }
  }
};

/**
 * fetch GeoJSON data from feed set in map
 * @categories term ids '1+2+3' or '1,2,3' are attached to request url
 */
var fetchData = function (categories) {
  var map = getMap();
  var locationsFeedName = findGeoJSONFeedInSources(map.sources);
  var locationsFeed = map.sources[locationsFeedName];
  var locationsFeedUrl = Drupal.settings.pathPrefix + 'locations-feed';

  if (categories != undefined) {
    locationsFeedUrl += '/' + categories;
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

jQuery(function () {
  /**
   * create filter tree with data from ajax call
   */
  if (jQuery('#filter').length) {
    jQuery('#filter').fancytree({
      source: {
        url: Drupal.settings.pathPrefix + 'map/map-filter',
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
      select: function (event, data) {
        // A node was selected: fetchData (and redraw map)
        var node = data.node;
        // select node on activation
        var selectedNodes = data.tree.getSelectedNodes();
        var selectedKeys = [];
        selectedNodes.forEach(function (element1, element2, set) {
          selectedKeys.push(element1.key)
        });
        fetchData(selectedKeys.join('+'));
        //
        if (node.selected === false && node.isActive() === true) {
          node.setActive(false);
          // console.log(node, 'de-select node');
        }
        if (node.selected === true) {
          console.log(node, 'select node');
        }
      }

    });
  }
});

// helper function to fetch the map from dom tree via its id
var getMap = function() {
  var mapId = jQuery('.openlayers-map').attr('id');
  var map = Drupal.openlayers.instances[mapId];
  return map;
}

var findGeoJSONFeedInSources = function(sources) {
  for(var element in sources) {
    if(sources[element] instanceof ol.source.GeoJSON) {
      return element;
    }
  }
};

var addIconStyle = function(feature, resolution) {
  // return for empty features
  if (feature === undefined) return;
  var iconStyle = {};
  feature = feature.get('features');
  // different iconStyles for single and clustered features
  if (feature.length == 1) {
    iconStyle = singleFeatureStyle(feature[0]);
  } else {
    iconStyle = clusterStyle(feature);
  }
  // console.log(resolution, 'r');
  return [iconStyle];
};

// small help function which returns the style for clustered features
var clusterStyle = function (feature) {
  var size = feature.length;
  return new ol.style.Style({
    image: new ol.style.Circle({
      radius: size * 6.2,
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
  var icon_image_name = feature.get('parent_machine_name') || feature.get('machine_name') || 'default-marker';
  // default iconStyle
  return new ol.style.Style({
    image: new ol.style.Icon( ({
      anchor: [0.5, 0.5],
      anchorXUnits: 'fraction',
      anchorYUnits: 'pixels',
      opacity: 1,
      scale: 0.14,
      src: Drupal.settings.themePath + '/images/source/' + icon_image_name +'-icon.png'
    }))
  });
};
