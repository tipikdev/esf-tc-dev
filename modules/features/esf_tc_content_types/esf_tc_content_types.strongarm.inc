<?php
/**
 * @file
 * esf_tc_content_types.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function esf_tc_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_esf_tnc_global_call';
  $strongarm->value = '0';
  $export['comment_anonymous_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_esf_tnc_hp_slide';
  $strongarm->value = '0';
  $export['comment_anonymous_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_esf_tnc_organisation';
  $strongarm->value = '0';
  $export['comment_anonymous_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_esf_tnc_project';
  $strongarm->value = '0';
  $export['comment_anonymous_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_esf_tnc_tca';
  $strongarm->value = '0';
  $export['comment_anonymous_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_esf_tnc_global_call';
  $strongarm->value = 1;
  $export['comment_default_mode_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_esf_tnc_hp_slide';
  $strongarm->value = 1;
  $export['comment_default_mode_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_esf_tnc_organisation';
  $strongarm->value = 1;
  $export['comment_default_mode_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_esf_tnc_project';
  $strongarm->value = 1;
  $export['comment_default_mode_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_esf_tnc_tca';
  $strongarm->value = 1;
  $export['comment_default_mode_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_esf_tnc_global_call';
  $strongarm->value = '50';
  $export['comment_default_per_page_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_esf_tnc_hp_slide';
  $strongarm->value = '50';
  $export['comment_default_per_page_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_esf_tnc_organisation';
  $strongarm->value = '50';
  $export['comment_default_per_page_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_esf_tnc_project';
  $strongarm->value = '50';
  $export['comment_default_per_page_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_esf_tnc_tca';
  $strongarm->value = '50';
  $export['comment_default_per_page_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_esf_tnc_global_call';
  $strongarm->value = '1';
  $export['comment_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_esf_tnc_hp_slide';
  $strongarm->value = '1';
  $export['comment_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_esf_tnc_organisation';
  $strongarm->value = '1';
  $export['comment_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_esf_tnc_project';
  $strongarm->value = '1';
  $export['comment_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_esf_tnc_tca';
  $strongarm->value = '1';
  $export['comment_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_esf_tnc_global_call';
  $strongarm->value = 1;
  $export['comment_form_location_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_esf_tnc_hp_slide';
  $strongarm->value = 1;
  $export['comment_form_location_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_esf_tnc_organisation';
  $strongarm->value = 1;
  $export['comment_form_location_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_esf_tnc_project';
  $strongarm->value = 1;
  $export['comment_form_location_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_esf_tnc_tca';
  $strongarm->value = 0;
  $export['comment_form_location_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_esf_tnc_global_call';
  $strongarm->value = '1';
  $export['comment_preview_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_esf_tnc_hp_slide';
  $strongarm->value = '0';
  $export['comment_preview_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_esf_tnc_organisation';
  $strongarm->value = '0';
  $export['comment_preview_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_esf_tnc_project';
  $strongarm->value = '1';
  $export['comment_preview_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_esf_tnc_tca';
  $strongarm->value = '0';
  $export['comment_preview_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_esf_tnc_global_call';
  $strongarm->value = 1;
  $export['comment_subject_field_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_esf_tnc_hp_slide';
  $strongarm->value = 1;
  $export['comment_subject_field_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_esf_tnc_organisation';
  $strongarm->value = 1;
  $export['comment_subject_field_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_esf_tnc_project';
  $strongarm->value = 1;
  $export['comment_subject_field_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_esf_tnc_tca';
  $strongarm->value = 0;
  $export['comment_subject_field_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__esf_tnc_global_call';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__esf_tnc_hp_slide';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__esf_tnc_organisation';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__esf_tnc_project';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'path' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__esf_tnc_tca';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_esf_tnc_global_call';
  $strongarm->value = '0';
  $export['language_content_type_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_esf_tnc_hp_slide';
  $strongarm->value = '0';
  $export['language_content_type_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_esf_tnc_organisation';
  $strongarm->value = '0';
  $export['language_content_type_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_esf_tnc_project';
  $strongarm->value = '0';
  $export['language_content_type_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_esf_tnc_tca';
  $strongarm->value = '0';
  $export['language_content_type_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_esf_tnc_global_call';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_esf_tnc_hp_slide';
  $strongarm->value = array();
  $export['menu_options_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_esf_tnc_organisation';
  $strongarm->value = array(
    0 => 'menu-left-menu',
    1 => 'main-menu',
  );
  $export['menu_options_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_esf_tnc_project';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_esf_tnc_tca';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_esf_tnc_global_call';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_esf_tnc_hp_slide';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_esf_tnc_organisation';
  $strongarm->value = 'menu-left-menu:0';
  $export['menu_parent_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_esf_tnc_project';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_esf_tnc_tca';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_nodereference';
  $strongarm->value = array(
    'esf_tnc_project' => array(
      'field_project_ma_responsible' => array(
        'referenced' => array(
          'view' => array(
            'view' => 'view',
          ),
          'update' => array(
            'update' => 'update',
            'view' => 'view',
          ),
          'delete' => array(
            'view' => 'view',
            'update' => 'update',
          ),
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
        'field_type' => 'entityreference',
      ),
      'field_project_lead_organisation' => array(
        'referenced' => array(
          'view' => array(
            'view' => 'view',
          ),
          'update' => array(
            'update' => 'update',
            'view' => 'view',
          ),
          'delete' => array(
            'view' => 'view',
          ),
          'published' => '1',
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
        'field_type' => 'entityreference',
      ),
    ),
    'esf_tnc_global_call' => array(
      'field_call_content_managers' => array(
        'referenced' => array(
          'view' => array(
            'view' => 'view',
          ),
          'update' => array(
            'update' => 'update',
            'view' => 'view',
            'delete' => 'delete',
          ),
          'published' => '1',
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
        ),
        'all' => array(
          'view' => 'view',
        ),
        'field_type' => 'entityreference',
      ),
    ),
    'esf_tnc_tca' => array(
      'field_tca_content_managers_tca' => array(
        'referenced' => array(
          'view' => array(
            'view' => 'view',
          ),
          'update' => array(
            'update' => 'update',
            'view' => 'view',
          ),
          'published' => '1',
        ),
        'author' => array(
          'view' => 'view',
        ),
        'field_type' => 'entityreference',
      ),
    ),
  );
  $export['nodeaccess_nodereference'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_nodereference_cross_access';
  $strongarm->value = array(
    'view' => TRUE,
    'update' => TRUE,
    'delete' => TRUE,
  );
  $export['nodeaccess_nodereference_cross_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeaccess_userreference';
  $strongarm->value = array(
    'esf_tnc_organisation' => array(
      'field_org_contact' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'referenced_published' => '1',
        'create' => array(
          'esf_tnc_organisation' => 'esf_tnc_organisation',
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
      ),
      'field_org_content_managers' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'referenced_published' => '1',
        'create' => array(
          'esf_tnc_organisation' => 'esf_tnc_organisation',
        ),
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
      ),
    ),
    'esf_tnc_project' => array(
      'field_project_manager' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 'update',
        ),
        'referenced_published' => '1',
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
      ),
      'field_project_operat_contact' => array(
        'referenced' => array(
          'view' => 'view',
          'update' => 'update',
        ),
        'referenced_published' => '1',
        'author' => array(
          'view' => 'view',
          'update' => 'update',
          'delete' => 'delete',
        ),
        'author_published' => '1',
        'all' => array(
          'view' => 'view',
        ),
      ),
    ),
  );
  $export['nodeaccess_userreference'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_esf_tnc_global_call';
  $strongarm->value = array();
  $export['node_options_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_esf_tnc_hp_slide';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_esf_tnc_organisation';
  $strongarm->value = array();
  $export['node_options_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_esf_tnc_project';
  $strongarm->value = array();
  $export['node_options_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_esf_tnc_tca';
  $strongarm->value = array();
  $export['node_options_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_esf_tnc_global_call';
  $strongarm->value = '0';
  $export['node_preview_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_esf_tnc_hp_slide';
  $strongarm->value = '1';
  $export['node_preview_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_esf_tnc_organisation';
  $strongarm->value = '1';
  $export['node_preview_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_esf_tnc_project';
  $strongarm->value = '1';
  $export['node_preview_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_esf_tnc_tca';
  $strongarm->value = '1';
  $export['node_preview_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_esf_tnc_global_call';
  $strongarm->value = 0;
  $export['node_submitted_esf_tnc_global_call'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_esf_tnc_hp_slide';
  $strongarm->value = 0;
  $export['node_submitted_esf_tnc_hp_slide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_esf_tnc_organisation';
  $strongarm->value = 0;
  $export['node_submitted_esf_tnc_organisation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_esf_tnc_project';
  $strongarm->value = 0;
  $export['node_submitted_esf_tnc_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_esf_tnc_tca';
  $strongarm->value = 0;
  $export['node_submitted_esf_tnc_tca'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_esf_tnc_global_call_pattern';
  $strongarm->value = 'call-[node:nid]';
  $export['pathauto_node_esf_tnc_global_call_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_esf_tnc_organisation_pattern';
  $strongarm->value = '[node:field_org_acronym]-[node:nid]';
  $export['pathauto_node_esf_tnc_organisation_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_esf_tnc_project_pattern';
  $strongarm->value = 'TPI-[node:nid]';
  $export['pathauto_node_esf_tnc_project_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_esf_tnc_tca_pattern';
  $strongarm->value = 'TCA-[node:nid]';
  $export['pathauto_node_esf_tnc_tca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_call_types_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_call_types_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_ec_world_countries_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_ec_world_countries_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_esf_countries_regions_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_esf_countries_regions_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_esf_themes_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_esf_themes_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_languages_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_languages_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_organisation_types_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_organisation_types_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_project_activities_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_project_activities_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_project_target_groups_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_project_target_groups_pattern'] = $strongarm;

  return $export;
}
