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
  $strongarm->name = 'mollom_audio_captcha_enabled';
  $strongarm->value = 1;
  $export['mollom_audio_captcha_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_connection_timeout';
  $strongarm->value = '3';
  $export['mollom_connection_timeout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_fai_dialog';
  $strongarm->value = 'mollom';
  $export['mollom_fai_dialog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_fai_entity_types';
  $strongarm->value = array(
    'node' => 0,
  );
  $export['mollom_fai_entity_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_fallback';
  $strongarm->value = '1';
  $export['mollom_fallback'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_fba_enabled';
  $strongarm->value = 1;
  $export['mollom_fba_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_languages_expected';
  $strongarm->value = array(
    0 => 'ar',
    1 => 'de',
    2 => 'en',
    3 => 'es',
    4 => 'fr',
    5 => 'pl',
    6 => 'ru',
    7 => 'tr',
    8 => 'vi',
  );
  $export['mollom_languages_expected'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_log_minimum_severity';
  $strongarm->value = '4';
  $export['mollom_log_minimum_severity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_privacy_link';
  $strongarm->value = 1;
  $export['mollom_privacy_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_public_key';
  $strongarm->value = 'bda06771af750b8959395aef1d41f762';
  $export['mollom_public_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_testing_mode';
  $strongarm->value = 0;
  $export['mollom_testing_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_test_private_key';
  $strongarm->value = 'sjqbz8s93consj10kvqtdi2ojr93io8r';
  $export['mollom_test_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mollom_test_public_key';
  $strongarm->value = '1ldakpe3i3z29103w8rxouek5glh3i26';
  $export['mollom_test_public_key'] = $strongarm;

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
