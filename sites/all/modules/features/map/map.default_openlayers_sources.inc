<?php
/**
 * @file
 * map.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function map_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_cluster_pdm';
  $ol_source->name = 'Cluster Potsdam';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Cluster';
  $ol_source->options = array(
    'source' => 'views_geojson_locations_feed_1',
    'distance' => '50',
  );
  $export['openlayers_examples_source_cluster_pdm'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_map_views_map_location_page_1';
  $ol_source->name = 'Views Map: map_location:page_1';
  $ol_source->description = 'Source for <a href="/en/admin/structure/views/view/map_location/edit/page_1">this</a> views map';
  $ol_source->factory_service = 'openlayers.source.internal.Vector';
  $ol_source->options = array();
  $export['source_map_views_map_location_page_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_views_locations_openlayers_1';
  $ol_source->name = 'Views Source: locations openlayers data overlay source';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Vector';
  $ol_source->options = array(
    'url' => 'http://mp.local/locations-feed',
    'source' => 'source_views_locations_openlayers_1',
    'distance' => '50',
  );
  $export['source_views_locations_openlayers_1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'source_views_map_location_openlayers_1';
  $ol_source->name = 'Views Source: map_location_openlayers_1';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.source.internal.Vector';
  $ol_source->options = array(
    'url' => 'http://mp.local/en/locations',
  );
  $export['source_views_map_location_openlayers_1'] = $ol_source;

  return $export;
}
