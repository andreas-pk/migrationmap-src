<?php
/**
 * @file
 * map.default_openlayers_maps.inc
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function map_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_views_locations_pdm_page';
  $ol_map->name = 'Map_views_locations_pdm_page';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.map.internal.OLMap';
  $ol_map->options = array(
    'provideBlock' => 1,
    'provideBlockLayerSwitcher' => 1,
    'contextualLinks' => 1,
    'provideIframe' => 0,
    'width' => 'auto',
    'height' => '600px',
    'view' => array(
      'center' => array(
        'lat' => '13.082251967684',
        'lon' => '52.40028441093099',
      ),
      'rotation' => '0',
      'zoom' => '12',
      'minZoom' => '10',
      'maxZoom' => '0',
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_layer_openstreetmap_reduced',
      1 => 'openlayers_examples_layer_cluster_cities_pdm',
    ),
    'sources' => array(
      0 => 'views_geojson_locations_feed_1',
      1 => 'openlayers_examples_source_cluster_pdm',
      2 => 'openlayers_source_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
    ),
    'components' => array(
      0 => 'locations_geojson_popup',
    ),
  );
  $export['map_views_locations_pdm_page'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'map_views_map_location_page_1';
  $ol_map->name = 'Views Map: map_location:page_1';
  $ol_map->description = 'Map from <a href="/admin/structure/views/view/map_location/edit/page_1">this</a> views map';
  $ol_map->factory_service = 'openlayers.map.internal.Views';
  $ol_map->options = array(
    'views_display' => 'map_location:page_1',
    'view' => array(
      'center' => array(
        'lat' => '13.058607886444',
        'lon' => '52.40028441093099',
      ),
      'rotation' => '0',
      'zoom' => '12',
      'minZoom' => '10',
      'maxZoom' => '',
    ),
    'sources' => array(
      0 => 'openlayers_source_mapquest_osm',
      1 => 'source_views_locations_openlayers_1',
    ),
    'layers' => array(
      0 => 'map_view_openlayers_data_layer',
      1 => 'openlayers_layer_openstreetmap_reduced',
    ),
    'width' => 'auto',
    'height' => '600px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'renderer' => 'canvas',
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragzoom',
    ),
  );
  $export['map_views_map_location_page_1'] = $ol_map;

  return $export;
}
