<?php
/**
 * @file
 * esf_tc_library.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function esf_tc_library_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-filedepot_folder-field_esf_tnc_forum'.
  $field_instances['node-filedepot_folder-field_esf_tnc_forum'] = array(
    'bundle' => 'filedepot_folder',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_esf_tnc_forum',
    'label' => 'Forum',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 32,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Forum');

  return $field_instances;
}
