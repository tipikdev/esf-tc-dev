<?php

/**
 * @file
 * esf_tc_advanced_search.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function esf_tc_advanced_search_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_tca_is_a_tca'.
  $field_bases['field_tca_is_a_tca'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tca_is_a_tca',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
