<?php
/**
 * @file
 * Default theme implementation for the Solr sort block.
 */
?>
<div class="btn-group">
  <button type="button" class="btn btn-default dropdown-toggle"
          data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
    Sort by <span class="caret"></span>
  </button>
  <?php if (is_array($items)): ?>
    <ul class="dropdown-menu">
      <?php foreach ($items as $item): ?>
        <li><?php print $item; ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>
<?php if (!empty($reset)):?>
  <?php print $reset;?>
<?php endif;?>
