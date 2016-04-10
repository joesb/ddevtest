<?php
/**
 * @file
 * Node template functions.
 */

/**
 * Implements hook_preprocess_node().
 */
function ddc_theme_preprocess_node(&$variables) {
  $node = $variables['node'];
  $node_type = $node->type;

  // We want to theme nodes by type and display mode.
  $variables['theme_hook_suggestions'][] = 'node__' . $node_type . '__' . $variables['view_mode'];

  $function_names = array(
    'ddc_theme_preprocess_node__' . $node_type . '__' . $variables['view_mode'],
    'ddc_theme_preprocess_node__' . $node_type,
  );

  foreach ($function_names as $function_name) {
    if (function_exists($function_name)) {
      $function_name($variables);
    }
  }
}

function ddc_theme_preprocess_node__article__teaser(&$variables) {
  $node = $variables['node'];
  // Create linked title.
  $variables['linked_title'] = l($variables['title'], 'node/' . $variables['nid']);
  if (isset($node->field_special['und'][0]['value']) && $node->field_special['und'][0]['value'] == 'yes') {
    $variables['classes_array'][] = 'bg-info';
    $variables['classes_array'][] = 'special-article';
  }
}


function ddc_theme_preprocess_node__article__full(&$variables) {
  $node = $variables['node'];
  $author = user_load($node->uid);
  $variables['author'] = array(
    'name' => l(filter_xss($author->name), 'user/' . $author->uid, array('attributes' => array('rel' => array('author')))),
    'embed' => user_view($author, 'article_embed'),
  );
}