<?php
/**
 * @file
 * Template file for article full view.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <article>
    <div class="media">
      <div class="pull-right">
        <?php print render($content['field_image']); ?>
      </div>
      <div class="media-body">
        <h1><?php print $title; ?></h1>
        <?php if (isset($content['field_subtitle'])): ?>
          <h2><?php print render($content['field_subtitle']); ?></h2>
        <?php endif; ?>
        <div class="byline pull-left">
          <h5><?php print render($author['name']); ?></h5>
          <?php print render($author['embed']); ?>
        </div>
        <?php print render($content['body']); ?>
      </div>
    </div>
  </article>
</div>
