<?php

/**
 * @file
 * esf_tc_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function esf_tc_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
