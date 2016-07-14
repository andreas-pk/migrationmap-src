<?php
/**
 * @file
 * location_lists.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function location_lists_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All locations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All locations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_location_address' => 'field_location_address',
    'name' => 'name',
    'field_location_email' => 'field_location_email',
    'field_location_website' => 'field_location_website',
    'field_location_teaser' => 'field_location_teaser',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location_address' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_location_teaser' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_location_category_target_id']['id'] = 'field_location_category_target_id';
  $handler->display->display_options['relationships']['field_location_category_target_id']['table'] = 'field_data_field_location_category';
  $handler->display->display_options['relationships']['field_location_category_target_id']['field'] = 'field_location_category_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_location_address']['id'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address']['field'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_location_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_location_category_target_id';
  $handler->display->display_options['fields']['name']['label'] = 'Category';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_location_email']['alter']['path'] = 'mailto:[field_location_email-email]';
  $handler->display->display_options['fields']['field_location_email']['alter']['max_length'] = '25';
  $handler->display->display_options['fields']['field_location_email']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_location_email']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_location_email']['type'] = 'email_plain';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_location_website']['id'] = 'field_location_website';
  $handler->display->display_options['fields']['field_location_website']['table'] = 'field_data_field_location_website';
  $handler->display->display_options['fields']['field_location_website']['field'] = 'field_location_website';
  $handler->display->display_options['fields']['field_location_website']['click_sort_column'] = 'url';
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_location_teaser']['id'] = 'field_location_teaser';
  $handler->display->display_options['fields']['field_location_teaser']['table'] = 'field_data_field_location_teaser';
  $handler->display->display_options['fields']['field_location_teaser']['field'] = 'field_location_teaser';
  $handler->display->display_options['fields']['field_location_teaser']['label'] = 'Description';
  $handler->display->display_options['fields']['field_location_teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_location_teaser']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_location_teaser']['settings'] = array(
    'trim_length' => '150',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'OR',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_location_category_target_id';
  $handler->display->display_options['filters']['tid']['group'] = 3;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'category';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Address - Postal code */
  $handler->display->display_options['filters']['field_location_address_postal_code']['id'] = 'field_location_address_postal_code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['filters']['field_location_address_postal_code']['field'] = 'field_location_address_postal_code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['group'] = 3;
  $handler->display->display_options['filters']['field_location_address_postal_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_location_address_postal_code']['expose']['operator_id'] = 'field_location_address_postal_code_op';
  $handler->display->display_options['filters']['field_location_address_postal_code']['expose']['label'] = 'Address - Postal code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['expose']['operator'] = 'field_location_address_postal_code_op';
  $handler->display->display_options['filters']['field_location_address_postal_code']['expose']['identifier'] = 'field_location_address_postal_code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_location_address_postal_code']['group_info']['label'] = 'Postal code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['group_info']['identifier'] = 'field_location_address_postal_code';
  $handler->display->display_options['filters']['field_location_address_postal_code']['group_info']['group_items'] = array(
    1 => array(
      'title' => '14467',
      'operator' => '=',
      'value' => '14467',
    ),
    2 => array(
      'title' => '14469',
      'operator' => '=',
      'value' => '14469',
    ),
    3 => array(
      'title' => '14471',
      'operator' => '=',
      'value' => '14471',
    ),
    4 => array(
      'title' => '14473',
      'operator' => '=',
      'value' => '14473',
    ),
    5 => array(
      'title' => '14478',
      'operator' => '=',
      'value' => '14478',
    ),
    6 => array(
      'title' => '14480',
      'operator' => '=',
      'value' => '14480',
    ),
    7 => array(
      'title' => '14482',
      'operator' => '=',
      'value' => '14482',
    ),
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 2;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Includes name, text and categories';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_location_teaser' => 'field_location_teaser',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'all-locations';
  $translatables['all_locations'] = array(
    t('Master'),
    t('All locations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Taxonomy term entity referenced from field_location_category'),
    t('Title'),
    t('Address'),
    t('Category'),
    t('Email'),
    t('Website'),
    t('Description'),
    t('Address - Postal code'),
    t('Postal code'),
    t('Search'),
    t('Includes name, text and categories'),
    t('Page'),
  );
  $export['all_locations'] = $view;

  return $export;
}
