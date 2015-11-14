<?php
/**
 * @file
 * permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: location.
  $roles['location'] = array(
    'name' => 'location',
    'weight' => 4,
  );

  return $roles;
}
