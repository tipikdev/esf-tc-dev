<?php

/**
 * @file
 * esf_tc_content_types.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function esf_tc_content_types_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'esf_teaser';
  $ds_view_mode->label = 'ESF teaser';
  $ds_view_mode->entities = array(
    'profile2' => 'profile2',
    'user' => 'user',
  );
  $export['esf_teaser'] = $ds_view_mode;

  return $export;
}
