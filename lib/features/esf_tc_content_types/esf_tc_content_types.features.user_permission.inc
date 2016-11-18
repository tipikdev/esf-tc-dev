<?php

/**
 * @file
 * esf_tc_content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function esf_tc_content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editorial team member' => 'editorial team member',
      'webmaster' => 'webmaster',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editorial team member' => 'editorial team member',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'editorial team member' => 'editorial team member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contributor' => 'contributor',
      'editor' => 'editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access workbench access by role'.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      'administrator' => 'administrator',
      'contact' => 'contact',
      'webmaster' => 'webmaster',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer workbench access'.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'archive any esf_tnc_call_for_project content'.
  $permissions['archive any esf_tnc_call_for_project content'] = array(
    'name' => 'archive any esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'archive any esf_tnc_organisation content'.
  $permissions['archive any esf_tnc_organisation content'] = array(
    'name' => 'archive any esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'archive any esf_tnc_project content'.
  $permissions['archive any esf_tnc_project content'] = array(
    'name' => 'archive any esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'archive any esf_tnc_tca content'.
  $permissions['archive any esf_tnc_tca content'] = array(
    'name' => 'archive any esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'assign workbench access'.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'batch update workbench access'.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'block any esf_tnc_call_for_project content'.
  $permissions['block any esf_tnc_call_for_project content'] = array(
    'name' => 'block any esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'block any esf_tnc_organisation content'.
  $permissions['block any esf_tnc_organisation content'] = array(
    'name' => 'block any esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'block any esf_tnc_project content'.
  $permissions['block any esf_tnc_project content'] = array(
    'name' => 'block any esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'block any esf_tnc_tca content'.
  $permissions['block any esf_tnc_tca content'] = array(
    'name' => 'block any esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'create esf_tnc_call_for_project content'.
  $permissions['create esf_tnc_call_for_project content'] = array(
    'name' => 'create esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_event content'.
  $permissions['create esf_tnc_event content'] = array(
    'name' => 'create esf_tnc_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_hp_slide content'.
  $permissions['create esf_tnc_hp_slide content'] = array(
    'name' => 'create esf_tnc_hp_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_network_article content'.
  $permissions['create esf_tnc_network_article content'] = array(
    'name' => 'create esf_tnc_network_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_news content'.
  $permissions['create esf_tnc_news content'] = array(
    'name' => 'create esf_tnc_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_organisation content'.
  $permissions['create esf_tnc_organisation content'] = array(
    'name' => 'create esf_tnc_organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_project content'.
  $permissions['create esf_tnc_project content'] = array(
    'name' => 'create esf_tnc_project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_tca content'.
  $permissions['create esf_tnc_tca content'] = array(
    'name' => 'create esf_tnc_tca content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any esf_tnc_call_for_project content'.
  $permissions['delete any esf_tnc_call_for_project content'] = array(
    'name' => 'delete any esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_event content'.
  $permissions['delete any esf_tnc_event content'] = array(
    'name' => 'delete any esf_tnc_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_hp_slide content'.
  $permissions['delete any esf_tnc_hp_slide content'] = array(
    'name' => 'delete any esf_tnc_hp_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_network_article content'.
  $permissions['delete any esf_tnc_network_article content'] = array(
    'name' => 'delete any esf_tnc_network_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_news content'.
  $permissions['delete any esf_tnc_news content'] = array(
    'name' => 'delete any esf_tnc_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_organisation content'.
  $permissions['delete any esf_tnc_organisation content'] = array(
    'name' => 'delete any esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_project content'.
  $permissions['delete any esf_tnc_project content'] = array(
    'name' => 'delete any esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_tca content'.
  $permissions['delete any esf_tnc_tca content'] = array(
    'name' => 'delete any esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own esf_tnc_call_for_project content'.
  $permissions['delete own esf_tnc_call_for_project content'] = array(
    'name' => 'delete own esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_event content'.
  $permissions['delete own esf_tnc_event content'] = array(
    'name' => 'delete own esf_tnc_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_hp_slide content'.
  $permissions['delete own esf_tnc_hp_slide content'] = array(
    'name' => 'delete own esf_tnc_hp_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_network_article content'.
  $permissions['delete own esf_tnc_network_article content'] = array(
    'name' => 'delete own esf_tnc_network_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_news content'.
  $permissions['delete own esf_tnc_news content'] = array(
    'name' => 'delete own esf_tnc_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_organisation content'.
  $permissions['delete own esf_tnc_organisation content'] = array(
    'name' => 'delete own esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_project content'.
  $permissions['delete own esf_tnc_project content'] = array(
    'name' => 'delete own esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_tca content'.
  $permissions['delete own esf_tnc_tca content'] = array(
    'name' => 'delete own esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete terms in call_types'.
  $permissions['delete terms in call_types'] = array(
    'name' => 'delete terms in call_types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in esf_countries_regions'.
  $permissions['delete terms in esf_countries_regions'] = array(
    'name' => 'delete terms in esf_countries_regions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in esf_themes'.
  $permissions['delete terms in esf_themes'] = array(
    'name' => 'delete terms in esf_themes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in organisation_types'.
  $permissions['delete terms in organisation_types'] = array(
    'name' => 'delete terms in organisation_types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in project_activities'.
  $permissions['delete terms in project_activities'] = array(
    'name' => 'delete terms in project_activities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in project_target_groups'.
  $permissions['delete terms in project_target_groups'] = array(
    'name' => 'delete terms in project_target_groups',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any contact_profile profile'.
  $permissions['edit any contact_profile profile'] = array(
    'name' => 'edit any contact_profile profile',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any esf_tnc_call_for_project content'.
  $permissions['edit any esf_tnc_call_for_project content'] = array(
    'name' => 'edit any esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_event content'.
  $permissions['edit any esf_tnc_event content'] = array(
    'name' => 'edit any esf_tnc_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_hp_slide content'.
  $permissions['edit any esf_tnc_hp_slide content'] = array(
    'name' => 'edit any esf_tnc_hp_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_network_article content'.
  $permissions['edit any esf_tnc_network_article content'] = array(
    'name' => 'edit any esf_tnc_network_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_news content'.
  $permissions['edit any esf_tnc_news content'] = array(
    'name' => 'edit any esf_tnc_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_organisation content'.
  $permissions['edit any esf_tnc_organisation content'] = array(
    'name' => 'edit any esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_project content'.
  $permissions['edit any esf_tnc_project content'] = array(
    'name' => 'edit any esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_tca content'.
  $permissions['edit any esf_tnc_tca content'] = array(
    'name' => 'edit any esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own contact_profile profile'.
  $permissions['edit own contact_profile profile'] = array(
    'name' => 'edit own contact_profile profile',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'contact' => 'contact',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own esf_tnc_call_for_project content'.
  $permissions['edit own esf_tnc_call_for_project content'] = array(
    'name' => 'edit own esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_event content'.
  $permissions['edit own esf_tnc_event content'] = array(
    'name' => 'edit own esf_tnc_event content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_hp_slide content'.
  $permissions['edit own esf_tnc_hp_slide content'] = array(
    'name' => 'edit own esf_tnc_hp_slide content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_network_article content'.
  $permissions['edit own esf_tnc_network_article content'] = array(
    'name' => 'edit own esf_tnc_network_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_news content'.
  $permissions['edit own esf_tnc_news content'] = array(
    'name' => 'edit own esf_tnc_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_organisation content'.
  $permissions['edit own esf_tnc_organisation content'] = array(
    'name' => 'edit own esf_tnc_organisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_project content'.
  $permissions['edit own esf_tnc_project content'] = array(
    'name' => 'edit own esf_tnc_project content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_tca content'.
  $permissions['edit own esf_tnc_tca content'] = array(
    'name' => 'edit own esf_tnc_tca content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in call_types'.
  $permissions['edit terms in call_types'] = array(
    'name' => 'edit terms in call_types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in esf_countries_regions'.
  $permissions['edit terms in esf_countries_regions'] = array(
    'name' => 'edit terms in esf_countries_regions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in esf_themes'.
  $permissions['edit terms in esf_themes'] = array(
    'name' => 'edit terms in esf_themes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in organisation_types'.
  $permissions['edit terms in organisation_types'] = array(
    'name' => 'edit terms in organisation_types',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in project_activities'.
  $permissions['edit terms in project_activities'] = array(
    'name' => 'edit terms in project_activities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in project_target_groups'.
  $permissions['edit terms in project_target_groups'] = array(
    'name' => 'edit terms in project_target_groups',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flag esf_tc_favorites'.
  $permissions['flag esf_tc_favorites'] = array(
    'name' => 'flag esf_tc_favorites',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'republish any esf_tnc_call_for_project content'.
  $permissions['republish any esf_tnc_call_for_project content'] = array(
    'name' => 'republish any esf_tnc_call_for_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'republish any esf_tnc_organisation content'.
  $permissions['republish any esf_tnc_organisation content'] = array(
    'name' => 'republish any esf_tnc_organisation content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'republish any esf_tnc_project content'.
  $permissions['republish any esf_tnc_project content'] = array(
    'name' => 'republish any esf_tnc_project content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'republish any esf_tnc_tca content'.
  $permissions['republish any esf_tnc_tca content'] = array(
    'name' => 'republish any esf_tnc_tca content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'esf_tc_content_types',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'unflag esf_tc_favorites'.
  $permissions['unflag esf_tc_favorites'] = array(
    'name' => 'unflag esf_tc_favorites',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view any contact_profile profile'.
  $permissions['view any contact_profile profile'] = array(
    'name' => 'view any contact_profile profile',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own contact_profile profile'.
  $permissions['view own contact_profile profile'] = array(
    'name' => 'view own contact_profile profile',
    'roles' => array(
      'administrator' => 'administrator',
      'contact' => 'contact',
      'webmaster' => 'webmaster',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view workbench access information'.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'view workbench taxonomy pages'.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  return $permissions;
}
