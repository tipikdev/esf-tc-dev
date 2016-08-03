<?php
/**
 * @file
 * Default theme implementation for an additional contact.
 */
?>
<div class="well well-sm">
<?php if(isset($content['contact'])): ?>
  <?php print render($content['contact']); ?>
<?php endif; ?>
</div>
