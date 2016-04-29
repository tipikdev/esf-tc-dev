<?php
/**
 * @file
 * esf_tc_content_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function esf_tc_content_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_organisations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_org_contact_legal_name' => 'field_org_contact_legal_name',
    'field_org_contact' => 'field_org_contact',
    'field_org_additional_contacts' => 'field_org_additional_contacts',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_contact_legal_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_contact' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_additional_contacts' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_org_contact_target_id']['id'] = 'field_org_contact_target_id';
  $handler->display->display_options['relationships']['field_org_contact_target_id']['table'] = 'field_data_field_org_contact';
  $handler->display->display_options['relationships']['field_org_contact_target_id']['field'] = 'field_org_contact_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_org_contact_legal_name']['id'] = 'field_org_contact_legal_name';
  $handler->display->display_options['fields']['field_org_contact_legal_name']['table'] = 'field_data_field_org_contact_legal_name';
  $handler->display->display_options['fields']['field_org_contact_legal_name']['field'] = 'field_org_contact_legal_name';
  $handler->display->display_options['fields']['field_org_contact_legal_name']['label'] = '';
  $handler->display->display_options['fields']['field_org_contact_legal_name']['element_label_colon'] = FALSE;
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_org_contact']['id'] = 'field_org_contact';
  $handler->display->display_options['fields']['field_org_contact']['table'] = 'field_data_field_org_contact';
  $handler->display->display_options['fields']['field_org_contact']['field'] = 'field_org_contact';
  $handler->display->display_options['fields']['field_org_contact']['label'] = 'Legal contact : ';
  $handler->display->display_options['fields']['field_org_contact']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_org_contact']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Additional  contacts */
  $handler->display->display_options['fields']['field_org_additional_contacts']['id'] = 'field_org_additional_contacts';
  $handler->display->display_options['fields']['field_org_additional_contacts']['table'] = 'field_data_field_org_additional_contacts';
  $handler->display->display_options['fields']['field_org_additional_contacts']['field'] = 'field_org_additional_contacts';
  $handler->display->display_options['fields']['field_org_additional_contacts']['label'] = 'Additional  contacts :';
  $handler->display->display_options['fields']['field_org_additional_contacts']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_org_additional_contacts']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_org_additional_contacts']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_org_additional_contacts']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_org_additional_contacts']['delta_offset'] = '0';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_organisation' => 'esf_tnc_organisation',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-organisations';
  $export['all_organisations'] = $view;

  $view = new view();
  $view->name = 'call_for_project';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'call for project ( project type)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'call for project ( project type)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_call_for_projects_target_id']['id'] = 'field_project_call_for_projects_target_id';
  $handler->display->display_options['relationships']['field_project_call_for_projects_target_id']['table'] = 'field_data_field_project_call_for_projects';
  $handler->display->display_options['relationships']['field_project_call_for_projects_target_id']['field'] = 'field_project_call_for_projects_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Call for projects */
  $handler->display->display_options['fields']['field_call_coordinated_calls']['id'] = 'field_call_coordinated_calls';
  $handler->display->display_options['fields']['field_call_coordinated_calls']['table'] = 'field_data_field_call_coordinated_calls';
  $handler->display->display_options['fields']['field_call_coordinated_calls']['field'] = 'field_call_coordinated_calls';
  $handler->display->display_options['fields']['field_call_coordinated_calls']['label'] = '';
  $handler->display->display_options['fields']['field_call_coordinated_calls']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_call_coordinated_calls']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_call_coordinated_calls']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_call_coordinated_calls']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_call_coordinated_calls']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Country (field_esf_country_ref) */
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['id'] = 'field_esf_country_ref_tid';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['table'] = 'field_data_field_esf_country_ref';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['field'] = 'field_esf_country_ref_tid';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_esf_country_ref_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_global_call' => 'esf_tnc_global_call',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_call_status) */
  $handler->display->display_options['filters']['field_call_status_value']['id'] = 'field_call_status_value';
  $handler->display->display_options['filters']['field_call_status_value']['table'] = 'field_data_field_call_status';
  $handler->display->display_options['filters']['field_call_status_value']['field'] = 'field_call_status_value';
  $handler->display->display_options['filters']['field_call_status_value']['value'] = array(
    'open' => 'open',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_call_coordinated_calls' => 'field_call_coordinated_calls',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_call_coordinated_calls' => 'field_call_coordinated_calls',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['call_for_project'] = $view;

  $view = new view();
  $view->name = 'contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    7 => '7',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['contact'] = $view;

  $view = new view();
  $view->name = 'esf_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_esf_event_start_date' => 'field_esf_event_start_date',
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  /* Relationship: Content: Linked TN (field_esf_linked_tn) */
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['id'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['table'] = 'field_data_field_esf_linked_tn';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['field'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['required'] = TRUE;
  /* Field: Content: Start date */
  $handler->display->display_options['fields']['field_esf_event_start_date']['id'] = 'field_esf_event_start_date';
  $handler->display->display_options['fields']['field_esf_event_start_date']['table'] = 'field_data_field_esf_event_start_date';
  $handler->display->display_options['fields']['field_esf_event_start_date']['field'] = 'field_esf_event_start_date';
  $handler->display->display_options['fields']['field_esf_event_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_esf_event_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_esf_event_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Start date -  start date (field_esf_event_start_date) */
  $handler->display->display_options['sorts']['field_esf_event_start_date_value']['id'] = 'field_esf_event_start_date_value';
  $handler->display->display_options['sorts']['field_esf_event_start_date_value']['table'] = 'field_data_field_esf_event_start_date';
  $handler->display->display_options['sorts']['field_esf_event_start_date_value']['field'] = 'field_esf_event_start_date_value';
  $handler->display->display_options['sorts']['field_esf_event_start_date_value']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_event' => 'esf_tnc_event',
  );

  /* Display: Events by networking thematic */
  $handler = $view->new_display('block', 'Events by networking thematic', 'block_1');
  $export['esf_events'] = $view;

  $view = new view();
  $view->name = 'esf_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_esf_news_date' => 'field_esf_news_date',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  /* Relationship: Content: Linked TN (field_esf_linked_tn) */
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['id'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['table'] = 'field_data_field_esf_linked_tn';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['field'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['relationships']['field_esf_linked_tn_tid']['required'] = TRUE;
  /* Field: Content: Date of news */
  $handler->display->display_options['fields']['field_esf_news_date']['id'] = 'field_esf_news_date';
  $handler->display->display_options['fields']['field_esf_news_date']['table'] = 'field_data_field_esf_news_date';
  $handler->display->display_options['fields']['field_esf_news_date']['field'] = 'field_esf_news_date';
  $handler->display->display_options['fields']['field_esf_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_esf_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_esf_news_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Date of news (field_esf_news_date) */
  $handler->display->display_options['sorts']['field_esf_news_date_value']['id'] = 'field_esf_news_date_value';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['table'] = 'field_data_field_esf_news_date';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['field'] = 'field_esf_news_date_value';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_news' => 'esf_tnc_news',
  );

  /* Display: News by networking thematic */
  $handler = $view->new_display('block', 'News by networking thematic', 'block_1');
  $export['esf_news'] = $view;

  $view = new view();
  $view->name = 'hp_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hp_slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'body',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_hp_slide_description']['id'] = 'field_hp_slide_description';
  $handler->display->display_options['fields']['field_hp_slide_description']['table'] = 'field_data_field_hp_slide_description';
  $handler->display->display_options['fields']['field_hp_slide_description']['field'] = 'field_hp_slide_description';
  $handler->display->display_options['fields']['field_hp_slide_description']['label'] = '';
  $handler->display->display_options['fields']['field_hp_slide_description']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_hp_slide' => 'esf_tnc_hp_slide',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['hp_slider'] = $view;

  $view = new view();
  $view->name = 'organisations_selected_in_the_thematic';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'organisations selected in the Thematic';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'published_organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_organisation' => 'esf_tnc_organisation',
  );
  /* Filter criterion: Content: Type of organisation (field_org_type_of_organisation) */
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['id'] = 'field_org_type_of_organisation_tid';
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['table'] = 'field_data_field_org_type_of_organisation';
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['field'] = 'field_org_type_of_organisation_tid';
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['value'] = array(
    229 => '229',
    228 => '228',
  );
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_org_type_of_organisation_tid']['vocabulary'] = 'organisation_types';

  /* Display: ER_organisation for coordinated call */
  $handler = $view->new_display('entityreference', 'ER_organisation for coordinated call', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Organisations of type MA/IB for the selected country (call)';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['organisations_selected_in_the_thematic'] = $view;

  $view = new view();
  $view->name = 'published_organisations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'published_organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'published_organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Acronym or short denomination */
  $handler->display->display_options['fields']['field_org_acronym']['id'] = 'field_org_acronym';
  $handler->display->display_options['fields']['field_org_acronym']['table'] = 'field_data_field_org_acronym';
  $handler->display->display_options['fields']['field_org_acronym']['field'] = 'field_org_acronym';
  $handler->display->display_options['fields']['field_org_acronym']['label'] = '';
  $handler->display->display_options['fields']['field_org_acronym']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'esf_tnc_organisation' => 'esf_tnc_organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: ER Ma organisations */
  $handler = $view->new_display('entityreference', 'ER Ma organisations', 'entityreference_ma_organisation');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'MA Organisation';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['published_organisations'] = $view;

  return $export;
}
