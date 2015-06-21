<?php
/**
 * Created by PhpStorm.
 * User: andreas.pinto
 * Date: 31.05.15
 * Time: 13:30
 */

function map_filter_block_ajax_response ($type = 'ajax') {
  if ($type == 'ajax') {
    $output = t("This is some content delivered via AJAX");
    $commands = array();
    // See ajax_example_advanced.inc for more details on the available commands
    // and how to use them.
    $commands[] = ajax_command_append('#myDiv', $output);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    $output = t("This is some content delivered via a page load.");
    return $output;
  }
}