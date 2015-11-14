<?php
/**
 * @file
 * permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeownership_link_text';
  $strongarm->value = 'Claim';
  $export['nodeownership_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeownership_node_types';
  $strongarm->value = array(
    'location' => 'location',
    'article' => 0,
    'page' => 0,
  );
  $export['nodeownership_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeownership_pending_text';
  $strongarm->value = 'Claim Pending';
  $export['nodeownership_pending_text'] = $strongarm;

  return $export;
}
