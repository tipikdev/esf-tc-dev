<?php

/**
 * @file
 * esf_tc_advanced_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function esf_tc_advanced_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_default_search_page';
  $strongarm->value = 'partners_search';
  $export['apachesolr_search_default_search_page'] = $strongarm;

  return $export;
}
