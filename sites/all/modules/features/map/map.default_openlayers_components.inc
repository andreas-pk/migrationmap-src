<?php
/**
 * @file
 * map.default_openlayers_components.inc
 */

/**
 * Implements hook_default_openlayers_components().
 */
function map_default_openlayers_components() {
  $export = array();

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'locations_geojson_popup';
  $ol_component->name = 'Locations GeoJSON popup';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.component.internal.Popup';
  $ol_component->options = array(
    'layers' => array(
      'openlayers_examples_layer_cluster_cities_pdm' => 'openlayers_examples_layer_cluster_cities_pdm',
    ),
    'positioning' => 'bottom-center',
    'source' => 'views_geojson_locations_feed_1',
    'zoom' => '10',
    'enableAnimations' => 0,
    'animations' => array(
      'pan' => '500',
      'zoom' => '500',
    ),
  );
  $export['locations_geojson_popup'] = $ol_component;

  return $export;
}
