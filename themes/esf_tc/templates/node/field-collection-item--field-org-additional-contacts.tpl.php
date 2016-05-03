<?php
/**
 * @file
 * Default theme implementation for an additional contact.
 */
?>
<?php print t('Name'); ?>: <?php print $contact_name; ?>
<br/>
<?php print t('Email'); ?>: <?php print $contact_email; ?>
<br/>
<?php print t('Role'); ?>: <?php print $content['field_fc_org_role'][0]['#markup']; ?>

