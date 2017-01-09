<?php

/**
 * @file
 * esf_tc_library.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function esf_tc_library_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_filedepot_folder';
  $strongarm->value = 1;
  $export['comment_filedepot_folder'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__filedepot_folder';
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
  $export['field_bundle_settings_node__filedepot_folder'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_auto_create_group_rootfolder_enabled';
  $strongarm->value = 0;
  $export['filedepot_auto_create_group_rootfolder_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_allow_broadcasts';
  $strongarm->value = 1;
  $export['filedepot_default_allow_broadcasts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_group';
  $strongarm->value = 'view, upload_dir';
  $export['filedepot_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_notify_filechange';
  $strongarm->value = 0;
  $export['filedepot_default_notify_filechange'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_notify_newfile';
  $strongarm->value = 0;
  $export['filedepot_default_notify_newfile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_owner';
  $strongarm->value = 'view, admin, upload_dir, upload_ver, approval';
  $export['filedepot_default_owner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_perms_data';
  $strongarm->value = 'a:3:{s:5:"owner";a:5:{i:0;s:4:"view";i:1;s:5:"admin";i:2;s:10:"upload_dir";i:3;s:10:"upload_ver";i:4;s:8:"approval";}s:5:"group";a:2:{i:0;s:4:"view";i:1;s:10:"upload_dir";}s:18:"authenticated user";a:2:{i:0;s:4:"view";i:1;s:6:"upload";}}';
  $export['filedepot_default_perms_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_default_roles';
  $strongarm->value = 'authenticated user: view, upload';
  $export['filedepot_default_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_displayorder_filesfirst';
  $strongarm->value = 1;
  $export['filedepot_displayorder_filesfirst'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_email_to';
  $strongarm->value = 'noreply@esf.dev';
  $export['filedepot_email_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_extensions';
  $strongarm->value = 'jpg=jpg.gif, gif=gif.gif, bmp=bmp.gif, doc=doc.gif, docx=doc.gif, xls=xls.gif, xlsx=xls.gif
ppt=ppt.gif, pptx=ppt.gif, mpp=mpp.gif, pdf=pdf.gif, txt=txt.gif, zip=zip.gif
';
  $export['filedepot_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_extension_data';
  $strongarm->value = 'a:13:{s:3:"jpg";s:7:"jpg.gif";s:3:"gif";s:7:"gif.gif";s:3:"bmp";s:7:"bmp.gif";s:3:"doc";s:7:"doc.gif";s:4:"docx";s:7:"doc.gif";s:3:"xls";s:7:"xls.gif";s:4:"xlsx";s:7:"xls.gif";s:3:"ppt";s:7:"ppt.gif";s:4:"pptx";s:7:"ppt.gif";s:3:"mpp";s:7:"mpp.gif";s:3:"pdf";s:7:"pdf.gif";s:3:"txt";s:7:"txt.gif";s:3:"zip";s:7:"zip.gif";}';
  $export['filedepot_extension_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_filetype_filter';
  $strongarm->value = 'jpg png doc docx xls xlsx pdf ppt pptx';
  $export['filedepot_filetype_filter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_filetype_filterdata';
  $strongarm->value = array(
    0 => 'jpg png doc docx xls xlsx pdf ppt pptx',
  );
  $export['filedepot_filetype_filterdata'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_locked_file_download_enabled';
  $strongarm->value = 1;
  $export['filedepot_locked_file_download_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_multiupload_multibuttonname';
  $strongarm->value = 'Multi Upload';
  $export['filedepot_multiupload_multibuttonname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_multiupload_shownewfilebutton';
  $strongarm->value = 1;
  $export['filedepot_multiupload_shownewfilebutton'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_notifications_enabled';
  $strongarm->value = 1;
  $export['filedepot_notifications_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_organic_group_mode_enabled';
  $strongarm->value = 0;
  $export['filedepot_organic_group_mode_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_override_folderorder';
  $strongarm->value = 0;
  $export['filedepot_override_folderorder'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_pass1_recordcount';
  $strongarm->value = '3';
  $export['filedepot_pass1_recordcount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_pass2_recordcount';
  $strongarm->value = '10';
  $export['filedepot_pass2_recordcount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_show_index_enabled';
  $strongarm->value = 0;
  $export['filedepot_show_index_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_show_recent_folders';
  $strongarm->value = 0;
  $export['filedepot_show_recent_folders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_yui_baseurl';
  $strongarm->value = 'http://yui.yahooapis.com/2.7.0/build/';
  $export['filedepot_yui_baseurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_filedepot_folder';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_filedepot_folder'] = $strongarm;

  return $export;
}
