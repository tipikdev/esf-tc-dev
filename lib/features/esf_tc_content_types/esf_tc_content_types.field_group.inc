<?php

/**
 * @file
 * esf_tc_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function esf_tc_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_org_legal_contact|node|esf_tnc_organisation|form';
  $field_group->group_name = 'group_org_legal_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esf_tnc_organisation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legal contact',
    'weight' => '13',
    'children' => array(
      0 => 'field_org_contact',
      1 => 'field_org_contact_account',
      2 => 'field_org_contact_legal_email',
      3 => 'field_org_contact_legal_name',
      4 => 'field_org_contact_legal_role',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Legal contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-org-legal-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_org_legal_contact|node|esf_tnc_organisation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact_token|profile2|contact_profile|form';
  $field_group->group_name = 'group_profile_contact_token';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'contact_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Token',
    'weight' => '8',
    'children' => array(
      0 => 'field_token_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Token',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-profile-contact-token field-group-fieldset',
        'description' => 'Enter the token received in the email to link your account with an organisation.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_contact_token|profile2|contact_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_content_en|node|esf_tnc_project|form';
  $field_group->group_name = 'group_project_content_en';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'esf_tnc_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project content in English',
    'weight' => '18',
    'children' => array(
      0 => 'field_project_idea_summary',
      1 => 'field_project_problem_addressed',
      2 => 'field_project_results',
      3 => 'field_project_objectives',
      4 => 'field_project_activities',
      5 => 'field_project_experience',
      6 => 'field_project_expected_partners',
      7 => 'field_project_general_comments',
      8 => 'field_project_activities_list',
      9 => 'field_project_links',
      10 => 'field_project_attachments',
      11 => 'field_project_logo',
      12 => 'field_project_hight_promo_txt',
      13 => 'field_project_flag_featured',
      14 => 'field_project_logo_promo_sec',
      15 => 'field_project_high_promo_txt',
      16 => 'field_project_target_groups',
      17 => 'field_project_other_activity',
      18 => 'field_project_indicative_budget_',
      19 => 'field_esf_themes_ref',
      20 => 'field_project_searching',
      21 => 'field_project_end_date_activity',
      22 => 'field_proj_attachments',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-project-content-en field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_project_content_en|node|esf_tnc_project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Legal contact');
  t('Project content in English');
  t('Token');

  return $field_groups;
}
