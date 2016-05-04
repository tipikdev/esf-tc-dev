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

  // Exported permission: 'access workbench access by role'.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      'administrator' => 'administrator',
      'contact' => 'contact',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_hp_slide content'.
  $permissions['create esf_tnc_hp_slide content'] = array(
    'name' => 'create esf_tnc_hp_slide content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_news content'.
  $permissions['create esf_tnc_news content'] = array(
    'name' => 'create esf_tnc_news content',
    'roles' => array(
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_hp_slide content'.
  $permissions['delete any esf_tnc_hp_slide content'] = array(
    'name' => 'delete any esf_tnc_hp_slide content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_news content'.
  $permissions['delete any esf_tnc_news content'] = array(
    'name' => 'delete any esf_tnc_news content',
    'roles' => array(
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_hp_slide content'.
  $permissions['delete own esf_tnc_hp_slide content'] = array(
    'name' => 'delete own esf_tnc_hp_slide content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_news content'.
  $permissions['delete own esf_tnc_news content'] = array(
    'name' => 'delete own esf_tnc_news content',
    'roles' => array(
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_hp_slide content'.
  $permissions['edit any esf_tnc_hp_slide content'] = array(
    'name' => 'edit any esf_tnc_hp_slide content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_news content'.
  $permissions['edit any esf_tnc_news content'] = array(
    'name' => 'edit any esf_tnc_news content',
    'roles' => array(
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

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_hp_slide content'.
  $permissions['edit own esf_tnc_hp_slide content'] = array(
    'name' => 'edit own esf_tnc_hp_slide content',
    'roles' => array(
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_news content'.
  $permissions['edit own esf_tnc_news content'] = array(
    'name' => 'edit own esf_tnc_news content',
    'roles' => array(
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

  // Exported permission: 'flag esf_tc_favorites'.
  $permissions['flag esf_tc_favorites'] = array(
    'name' => 'flag esf_tc_favorites',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
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
