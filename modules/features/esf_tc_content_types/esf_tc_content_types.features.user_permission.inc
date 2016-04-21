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

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_event content'.
  $permissions['create esf_tnc_event content'] = array(
    'name' => 'create esf_tnc_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create esf_tnc_global_call content'.
  $permissions['create esf_tnc_global_call content'] = array(
    'name' => 'create esf_tnc_global_call content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
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
    'roles' => array(),
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

  // Exported permission: 'delete any esf_tnc_event content'.
  $permissions['delete any esf_tnc_event content'] = array(
    'name' => 'delete any esf_tnc_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_global_call content'.
  $permissions['delete any esf_tnc_global_call content'] = array(
    'name' => 'delete any esf_tnc_global_call content',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any esf_tnc_news content'.
  $permissions['delete any esf_tnc_news content'] = array(
    'name' => 'delete any esf_tnc_news content',
    'roles' => array(),
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
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_event content'.
  $permissions['delete own esf_tnc_event content'] = array(
    'name' => 'delete own esf_tnc_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_global_call content'.
  $permissions['delete own esf_tnc_global_call content'] = array(
    'name' => 'delete own esf_tnc_global_call content',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own esf_tnc_news content'.
  $permissions['delete own esf_tnc_news content'] = array(
    'name' => 'delete own esf_tnc_news content',
    'roles' => array(),
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

  // Exported permission: 'edit any esf_tnc_event content'.
  $permissions['edit any esf_tnc_event content'] = array(
    'name' => 'edit any esf_tnc_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_global_call content'.
  $permissions['edit any esf_tnc_global_call content'] = array(
    'name' => 'edit any esf_tnc_global_call content',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any esf_tnc_news content'.
  $permissions['edit any esf_tnc_news content'] = array(
    'name' => 'edit any esf_tnc_news content',
    'roles' => array(),
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
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_event content'.
  $permissions['edit own esf_tnc_event content'] = array(
    'name' => 'edit own esf_tnc_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own esf_tnc_global_call content'.
  $permissions['edit own esf_tnc_global_call content'] = array(
    'name' => 'edit own esf_tnc_global_call content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
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
    'roles' => array(),
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

  return $permissions;
}
