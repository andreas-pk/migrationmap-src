<?php
/**
 * @file
 * map.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function map_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'layer_map_views_map_location_page_1';
  $ol_layer->name = 'Views Map:map_location:page_1';
  $ol_layer->description = 'Layer for <a href="/en/admin/structure/views/view/map_location/edit/page_1">this</a> views map';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'source_map_views_map_location_page_1',
  );
  $export['layer_map_views_map_location_page_1'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'locations_geojson_feed_layer';
  $ol_layer->name = 'Locations GeoJSON feed layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_locations_feed_1',
    'visible' => 1,
    'style' => 'openlayers_examples_style_blue_marker',
  );
  $export['locations_geojson_feed_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'map_view_openlayers_data_layer';
  $ol_layer->name = 'Map view openlayers data layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'source_views_locations_openlayers_1',
    'visible' => 1,
    'style' => 'openlayers_style_default',
  );
  $export['map_view_openlayers_data_layer'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_cluster_cities_pdm';
  $ol_layer->name = 'Layer cluster Potsdam';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_cluster_pdm',
    'visible' => 1,
    'style' => 'locations_pdm_style',
  );
  $export['openlayers_examples_layer_cluster_cities_pdm'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_layer_openstreetmap_reduced';
  $ol_layer->name = 'OpenStreetMap reduced';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_source_mapquest_osm',
    'visible' => 1,
  );
  $export['openlayers_layer_openstreetmap_reduced'] = $ol_layer;

  return $export;
}
