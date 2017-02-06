<?php
/**
 * @file
 * esf_tc_advanced_search.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function esf_tc_advanced_search_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-esf_tnc_organisation-field_tca_is_a_tca'.
  $field_instances['node-esf_tnc_organisation-field_tca_is_a_tca'] = array(
    'bundle' => 'esf_tnc_organisation',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tca_is_a_tca',
    'label' => 'Involvement in TCA',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 30,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-esf_tnc_project-field_tca_is_a_tca'.
  $field_instances['node-esf_tnc_project-field_tca_is_a_tca'] = array(
    'bundle' => 'esf_tnc_project',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tca_is_a_tca',
    'label' => 'Involvement in TCA',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 43,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Involvement in TCA');

  return $field_instances;
}
