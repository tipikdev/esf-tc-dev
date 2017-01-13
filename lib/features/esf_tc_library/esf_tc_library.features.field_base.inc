<?php
/**
 * @file
 * esf_tc_library.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function esf_tc_library_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_esf_tnc_forum'.
  $field_bases['field_esf_tnc_forum'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_esf_tnc_forum',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 1,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'forums',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
