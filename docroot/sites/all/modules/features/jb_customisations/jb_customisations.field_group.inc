<?php
/**
 * @file
 * jb_customisations.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jb_customisations_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specials|node|article|form';
  $field_group->group_name = 'group_specials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Special articles',
    'weight' => '5',
    'children' => array(
      0 => 'field_special',
      1 => 'field_publish_special_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-specials field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Special articles');

  return $field_groups;
}
