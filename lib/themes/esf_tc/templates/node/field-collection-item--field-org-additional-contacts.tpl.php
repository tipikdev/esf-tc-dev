<?php
/**
 * @file
 * Default theme implementation for an additional contact.
 */
?>
<?php if (isset($contact_name)): ?>
  <?php print t('Name'); ?>: <?php print $contact_name; ?>
<br/>
<?php endif; ?>
<?php if (isset($contact_email)): ?>
  <?php print t('Email'); ?>: <?php print $contact_email; ?>
<br/>
<?php endif; ?>
<?php if (isset($content['field_fc_org_role'][0]['#markup'])): ?>
  <?php print t('Role'); ?>: <?php print $content['field_fc_org_role'][0]['#markup']; ?>
<?php endif; ?>
