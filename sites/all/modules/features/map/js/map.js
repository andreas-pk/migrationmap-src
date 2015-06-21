/**
 * Created by andreas.pinto on 31.05.15.
 */

/**
 * fetch GeoJSON data from feed set in map
 * @categories term ids '1+2+3' or '1,2,3' are attached to request url
 */
var fetchData = function (categories) {
  var mapId = jQuery('.openlayers-map').attr('id');
  var map = Drupal.openlayers.instances[mapId];
  var locationsFeedName = findGeoJSONFeedInSources(map.sources);
  var locationsFeed = map.sources[locationsFeedName];
  var locationsFeedUrl = '/locations-feed';
  if (categories != undefined) {
    locationsFeedUrl += '/' + categories;
  }
  jQuery.ajax(locationsFeedUrl,
    {
      dataType: 'json',
      success: function (data, textStatus, jqXHR) {
        locationsFeed.clear(); //remove existing features
        var features = locationsFeed.readFeatures(data);
        console.log(features, 'f');
        addIconStyle(features);
        locationsFeed.addFeatures(addIconStyle(features));
      },
      error: function (jqXHR, textStatus, errorThrown) {
      }
    });
};

jQuery(function () {
  /**
   * create filter tree with data from ajax call
   */
  jQuery("#filter").fancytree({
    source: {
      url: "map/map-filter",
      cache: false
    },
    activeVisible: true,
    checkbox: true,
    selectMode: 3,
    generateIds: true,
    idPrefix: 'filter-',
    icons: true,
    activate: function(event, data) {
    },
    deactivate: function(event, data) {
    },
    select: function(event, data) {
      // A node was selected: fetchData (and redraw map)
      var node = data.node;
      // select node on activation
      var selectedNodes = data.tree.getSelectedNodes();
      var selectedKeys = [];
      selectedNodes.forEach( function(element1, element2, set) {
        selectedKeys.push(element1.key)
      });
      fetchData(selectedKeys.join('+'));
      //
      if(node.selected === false && node.isActive() === true) {
        node.setActive(false);
        console.log(node, 'de-select node');
      }
      if(node.selected === true) {
        console.log(node, 'select node');
      }
    }

  });
    });

var findGeoJSONFeedInSources = function(sources) {
  for(var element in sources) {
    if(sources[element] instanceof ol.source.GeoJSON) {
      return element;
    }
  }
}

var addIconStyle = function(features) {

  var iconStyle = new ol.style.Style({
    image: new ol.style.Icon( ({
      anchor: [0.5, 46],
      anchorXUnits: 'fraction',
      anchorYUnits: 'pixels',
      opacity: 0.75,
      src: 'data/icon.png'
    }))
  });

  features.forEach( function(feature, index, array) {
    features[index].setStyle(iconStyle);
  });
  return features;
}