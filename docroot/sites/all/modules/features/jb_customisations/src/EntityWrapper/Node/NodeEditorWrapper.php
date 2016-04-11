<?php
/**
 * @file Node wrapper class
 */

namespace Drupal\jb_customisations\EntityWrapper\Node;

use \EntityDrupalWrapper;
use \EntityFieldQuery;

class NodeEditorWrapper extends EntityDrupalWrapper {

  /**
   * Wrap a node object.
   *
   * @param int|object $data
   *   A nid or node object.
   */
  public function __construct($data) {
    parent::__construct('node', $data);
  }

  /**
   * Send an email to all editors of this content type.
   *
   * @param array $some_args
   * @return array
   */
  public function emailEditors() {
    $emails_sent = array();
    if ($this->dataAvailable()) {
      foreach ($this->getNodeTypeEditors() as $editor) {
        $emails_sent[] = $this->email($editor);
      }
    }
    return $emails_sent;
  }

  /**
   * Send an email to this editor.
   *
   * @param array $some_args
   */
  public function email($editor) {
    // Call something like drupal_mail() here;
    // Return messages from drupal_mail().
    $account = user_load($editor->uid);
    return t('Some magic happened for @username.', array('@username' => $account->name));
  }

  /**
   * Get a list of editors for nodes of this type.
   *
   * @return UserWrapper[]
   *   An array UserWrappers.
   */
  public function getNodeTypeEditors() {
    $bundle = $this->getBundle();
    // Get UID of node author
    $author_info = $this->getPropertyInfo('author');
    $uid = $this->getPropertyValue('author', $author_info);
    // Get all users marked as editors, except for node author
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'user')
      ->propertyCondition('uid', $uid, '!=')
      ->fieldCondition('field_editor', 'value', 1)
      ->fieldCondition('field_edit_content_types', 'value', $bundle);

    $editors = $query->execute();

    if (isset($editors['user'])) {
      return $editors['user'];
    }
    return array();
  }

}
