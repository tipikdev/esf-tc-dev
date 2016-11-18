<?php

/**
 * @file
 * esf_tc_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function esf_tc_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function esf_tc_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function esf_tc_content_types_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorites".
  $flags['esf_tc_favorites'] = array(
    'entity_type' => 'node',
    'title' => 'Favorites',
    'global' => 0,
    'types' => array(
      0 => 'esf_tnc_call_for_project',
      1 => 'esf_tnc_organisation',
      2 => 'esf_tnc_project',
      3 => 'esf_tnc_tca',
    ),
    'flag_short' => 'Add to your favorites',
    'flag_long' => 'Add this item to your favorites',
    'flag_message' => '',
    'unflag_short' => 'Delete from favorites',
    'unflag_long' => 'Delete this item from your favorites',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'print' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'esf_tc_content_types',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function esf_tc_content_types_image_default_styles() {
  $styles = array();

  // Exported image style: esf_database_4_3.
  $styles['esf_database_4_3'] = array(
    'label' => 'esf_database_4_3',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 266,
          'height' => 199,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: esf_database_4_3_thumbnail.
  $styles['esf_database_4_3_thumbnail'] = array(
    'label' => 'esf_database_4_3_thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 79,
          'height' => 55,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: esf_database_logo.
  $styles['esf_database_logo'] = array(
    'label' => 'esf_database_logo',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 150,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function esf_tc_content_types_node_info() {
  $items = array(
    'esf_tnc_call_for_project' => array(
      'name' => t('Call for project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title in English'),
      'help' => '',
    ),
    'esf_tnc_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esf_tnc_hp_slide' => array(
      'name' => t('Hp_slide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esf_tnc_network_article' => array(
      'name' => t('Network article'),
      'base' => 'node_content',
      'description' => t('Use <em>network articles</em>to attach simple content to the thematic page (Forum).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esf_tnc_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esf_tnc_organisation' => array(
      'name' => t('Organisation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name in English'),
      'help' => '',
    ),
    'esf_tnc_project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'esf_tnc_tca' => array(
      'name' => t('TCA'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function esf_tc_content_types_default_profile2_type() {
  $items = array();
  $items['contact_profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "contact_profile",
    "label" : "contact",
    "weight" : "0",
    "data" : { "registration" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
