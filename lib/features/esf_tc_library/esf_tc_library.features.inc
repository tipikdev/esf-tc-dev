<?php
/**
 * @file
 * esf_tc_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function esf_tc_library_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function esf_tc_library_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
