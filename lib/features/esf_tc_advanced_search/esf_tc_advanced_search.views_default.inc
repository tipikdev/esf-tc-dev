<?php
/**
 * @file
 * esf_tc_advanced_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function esf_tc_advanced_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'esf_events_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events and News Search';
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
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Country (field_esf_event_country) */
  $handler->display->display_options['filters']['field_esf_event_country_tid']['id'] = 'field_esf_event_country_tid';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['table'] = 'field_data_field_esf_event_country';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['field'] = 'field_esf_event_country_tid';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_esf_event_country_tid']['expose']['operator_id'] = 'field_esf_event_country_tid_op';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['expose']['label'] = 'Country ';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['expose']['operator'] = 'field_esf_event_country_tid_op';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['expose']['identifier'] = 'field_esf_event_country_tid';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_esf_event_country_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_esf_event_country_tid']['vocabulary'] = 'esf_countries_regions';
  /* Filter criterion: Content: Linked TN (field_esf_linked_tn) */
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['id'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['table'] = 'field_data_field_esf_linked_tn';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['field'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['value'] = '';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['operator_id'] = 'field_esf_linked_tn_tid_op';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['label'] = 'Linked Thematic Network';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['operator'] = 'field_esf_linked_tn_tid_op';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['identifier'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['vocabulary'] = 'forums';
  /* Filter criterion: Content: Start date -  start date (field_esf_event_start_date) */
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['id'] = 'field_esf_event_start_date_value';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['table'] = 'field_data_field_esf_event_start_date';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['field'] = 'field_esf_event_start_date_value';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['expose']['operator_id'] = 'field_esf_event_start_date_value_op';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['expose']['operator'] = 'field_esf_event_start_date_value_op';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['expose']['identifier'] = 'field_esf_event_start_date_value';
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_esf_event_start_date_value']['form_type'] = 'date_popup';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Events Search';

  /* Display: Events Page */
  $handler = $view->new_display('page', 'Events Page', 'esf_events_view_page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'events';

  /* Display: News Page */
  $handler = $view->new_display('page', 'News Page', 'esf_news_view_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date of news (field_esf_news_date) */
  $handler->display->display_options['sorts']['field_esf_news_date_value']['id'] = 'field_esf_news_date_value';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['table'] = 'field_data_field_esf_news_date';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['field'] = 'field_esf_news_date_value';
  $handler->display->display_options['sorts']['field_esf_news_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Linked TN (field_esf_linked_tn) */
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['id'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['table'] = 'field_data_field_esf_linked_tn';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['field'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['value'] = '';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['operator_id'] = 'field_esf_linked_tn_tid_op';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['label'] = 'Linked Thematic Network';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['operator'] = 'field_esf_linked_tn_tid_op';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['identifier'] = 'field_esf_linked_tn_tid';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_esf_linked_tn_tid']['vocabulary'] = 'forums';
  /* Filter criterion: Content: Date of news (field_esf_news_date) */
  $handler->display->display_options['filters']['field_esf_news_date_value']['id'] = 'field_esf_news_date_value';
  $handler->display->display_options['filters']['field_esf_news_date_value']['table'] = 'field_data_field_esf_news_date';
  $handler->display->display_options['filters']['field_esf_news_date_value']['field'] = 'field_esf_news_date_value';
  $handler->display->display_options['filters']['field_esf_news_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_esf_news_date_value']['expose']['operator_id'] = 'field_esf_news_date_value_op';
  $handler->display->display_options['filters']['field_esf_news_date_value']['expose']['label'] = 'Date ';
  $handler->display->display_options['filters']['field_esf_news_date_value']['expose']['operator'] = 'field_esf_news_date_value_op';
  $handler->display->display_options['filters']['field_esf_news_date_value']['expose']['identifier'] = 'field_esf_news_date_value';
  $handler->display->display_options['filters']['field_esf_news_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_esf_news_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'news';
  $export['esf_events_search'] = $view;

  return $export;
}
