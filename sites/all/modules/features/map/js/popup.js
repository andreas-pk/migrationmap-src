Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.component.internal.popup',
  init: function (data) {
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
    closer.onclick = function () {
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

    map.on('click', function (evt) {
      var feature = map.forEachFeatureAtPixel(evt.pixel, function (feature, layer) {
        if (goog.isDef(data.opt.layers[layer.mn])) {
          return feature;
        }
      });
      if (feature === undefined) return;
      content.innerHTML = '';
      // set position at marker (feature) point
      overlay.setPosition(feature.getGeometry().getCoordinates());
      // get features from structure
      feature = feature.get('features');
      // put different html for single and clustered features
      if (feature.length == 1) {
        feature = feature[0];
        content.innerHTML = getInnerHtml(feature, true);
      } else {
        // handle cluster popup
        feature.forEach(function (element, index, array) {
          var first = (index == 0) || false;
          content.innerHTML += getInnerHtml(element, first);
        });
        content.innerHTML = '<div class="cluster-popup-wrapper multiple"><a class="sliderNav prev"></a>' + content.innerHTML + '<a class="sliderNav next"></av></div>';
      }
      container.style.display = 'block';
      initializePopupSlider();
    });

    function getInnerHtml(feature, first) {
      var name = feature.get('name') || '';
      var description = feature.get('description') || '';
      var category = feature.get('field_location_category') || '';
      var logo = feature.get('field_location_logo') || '';
      var link = feature.get('view_node') || '';
      var is_visible = 'hidden';
      if (first) {
        is_visible = 'visible';
      }
      var innerHtml = '<div class="cluster-slide-wrapper ' + is_visible +'">';
      innerHtml +=  '<div class="ol-popup-logo">' + logo + '</div>';
      innerHtml +=  '<div class="ol-popup-category">' + category + '</div>';
      innerHtml +=  '<div class="ol-popup-name">' + name + '</div>';
      innerHtml +=  '<div class="ol-popup-description">' + description + '</div>';
      innerHtml +=  '<div class="ol-popup-link">' + link + '</div>';
      innerHtml +=  '</div>';
      return innerHtml;
    }
  }
});

/**
 * Adds slider functionality to cluster popups via event listener
 */
var initializePopupSlider = function() {
  jQuery('.cluster-popup-wrapper .sliderNav').on('click', function (event) {
    event.preventDefault();
    direction = (jQuery(this).hasClass('next')) ? 'next' : 'prev';
    var slides = jQuery(this).parent().children('.cluster-slide-wrapper');

    cycle(slides, 'div.cluster-slide-wrapper', 'visible', direction);
  });
};

/**
 * Helper function to slide depending on the direction
 * @param slides Array
 * @param sliderSelector selector to find slides in dom
 * @param visibilitySelector String the class name which visible elements have
 * @param direction String 'prev' or 'next'
 */
var cycle = function (slides, sliderSelector, visibilitySelector, direction) {
  currentSlide = slides.filter('.' + visibilitySelector).first().removeClass(visibilitySelector).hide();

  switch (direction) {
    case 'next':
      if (currentSlide.next(sliderSelector).length == 1) {
        nextSlide = currentSlide.next(sliderSelector);
      } else {
        nextSlide = slides.first();
      }
      break;

    case 'prev':
      if (currentSlide.prev(sliderSelector).length == 1) {
        nextSlide = currentSlide.prev(sliderSelector);
      } else {
        nextSlide = slides.last();
      }
      break;
    default :
  }

  nextSlide.addClass(visibilitySelector).show();
};