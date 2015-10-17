<?php
/**
 * @file
 * map.default_openlayers_styles.inc
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function map_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'locations_pdm_style';
  $ol_style->name = 'locations_pdm_style';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.style.internal.OLStyle';
  $ol_style->options = array(
    'javascript' => '  console.log(data, \'data\');
  var style = new ol.style.Style({
    image: new ol.style.Icon( ({
      anchor: [0.5, 46],
      anchorXUnits: \'fraction\',
      anchorYUnits: \'pixels\',
      opacity: 0.75,
      src: \'sites/all/themes/mp/images/source/loading.gif\'
    }))
  });',
  );
  $export['locations_pdm_style'] = $ol_style;

  return $export;
}
