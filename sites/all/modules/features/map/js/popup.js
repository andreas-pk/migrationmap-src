Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.component.internal.popup',
  init: function(data) {
    var map = data.map;

    var container = jQuery('<div/>', {
      id: 'popup',
      'class': 'ol-popup'
    }).appendTo('body');
    var content = jQuery('<div/>', {
      id: 'popup-content'
    }).appendTo('#popup');
    var closer = jQuery('<a/>', {
      href: '#',
      id: 'popup-closer',
      'class': 'ol-popup-closer'
    }).appendTo('#popup');

    var container = document.getElementById('popup');
    var content = document.getElementById('popup-content');
    var closer = document.getElementById('popup-closer');

    /**
     * Add a click handler to hide the popup.
     * @return {boolean} Don't follow the href.
     */
    closer.onclick = function() {
      container.style.display = 'none';
      closer.blur();
      return false;
    };

    /**
     * Create an overlay to anchor the popup to the map.
     */

    var overlay = new ol.Overlay({
      element: container,
      positioning: data.opt.positioning
    });

    map.addOverlay(overlay);

    map.on('click', function(evt) {
      var feature = map.forEachFeatureAtPixel(evt.pixel, function(feature, layer) {
        if (goog.isDef(data.opt.layers[layer.mn])) {
          return feature;
        }
      });
      if(feature === undefined) return;
      // set position at marker (feature) point
      overlay.setPosition(feature.getGeometry().getCoordinates());
      // get features from structure
      feature = feature.get('features');
      // put different html for single and clustered features
      if(feature.length == 1) {
        feature = feature[0];
        content.innerHTML = getInnerHtml(feature);
      } else {
        content.innerHTML = '';
        feature.forEach( function(element, index, array) {
          content.innerHTML += getInnerHtml(element);
        });
      }
      container.style.display = 'block';
    });

    function getInnerHtml(feature) {
      var name = feature.get('name') || '';
      var description = feature.get('description') || '';
      return '<div class="ol-popup-name">' + name + '</div><div class="ol-popup-description">' + description + '</div>';
    }
  }
});
