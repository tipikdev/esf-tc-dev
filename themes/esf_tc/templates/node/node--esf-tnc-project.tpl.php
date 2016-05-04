<?php
/**
 * @file
 * Ec_resp's theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $display_user_picture: Whether node author's picture should be displayed.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<div id="node-<?php print $node->nid; ?>"
     class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content clearfix"<?php print $content_attributes; ?>>
    <?php if ($prefix_display): ?>
      <div class="node-private label label-default clearfix">
        <span class="glyphicon glyphicon-lock"></span>
        <?php print t('This content is private'); ?>
      </div>
    <?php endif; ?>

    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    ?>
  </div>

  <?php if ($view_mode == 'full'): ?>
    <div
      class="abstract"><?php print render($content['field_project_idea_summary']); ?></div>
    <table class="standard-table" cellpadding="0" cellspacing="0">
      <?php if (isset($content['field_esf_country_ref'])) : ?>
        <tr>
          <th><?php print render($content['field_esf_country_ref']['#title']); ?></th>
          <td><?php if (['field_esf_country_ref'] == 'Other countries') : ?>
              <?php print render($content['field_project_other_countries']); ?>
            <?php else : ?>
              <?php print render($content['field_esf_country_ref']); ?>
            <?php endif; ?>
          </td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_call_for_projects'])) : ?>
        <tr>
          <th><?php print render($content['field_project_call_for_projects']['#title']); ?></th>
          <td><?php print render($content['field_project_call_for_projects']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_esf_type_call'])) : ?>
        <tr>
          <th><?php print render($content['field_esf_type_call']['#title']); ?></th>
          <td><?php print render($content['field_esf_type_call']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_title_vo'])) : ?>
        <tr>
          <th><?php print render($content['field_project_title_vo']['#title']); ?></th>
          <td><?php print render($content['field_project_title_vo']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_acronym'])) : ?>
        <tr>
          <th><?php print render($content['field_project_acronym']['#title']); ?></th>
          <td><?php print render($content['field_project_acronym']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_ma_responsible'])) : ?>
        <tr>
          <th><?php print render($content['field_project_ma_responsible']['#title']); ?></th>
          <td><?php print render($content['field_project_ma_responsible']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_project_measure_en'])) : ?>
        <tr>
          <th><?php print render($content['field_project_measure_en']['#title']); ?></th>
          <td><?php print render($content['field_project_measure_en']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field__project_measure_vo'])) : ?>
        <tr>
          <th><?php print render($content['field__project_measure_vo']['#title']); ?></th>
          <td><?php print render($content['field__project_measure_vo']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_submitted_ma'])) : ?>
        <tr>
          <th><?php print render($content['field_project_submitted_ma']['#title']); ?></th>
          <td><?php print render($content['field_project_submitted_ma']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_national_number'])) : ?>
        <tr>
          <th><?php print render($content['field_project_national_number']['#title']); ?></th>
          <td><?php print render($content['field_project_national_number']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_lead_organisation'])) : ?>
        <tr>
          <th><?php print render($content['field_project_lead_organisation']['#title']); ?></th>
          <td><?php print render($content['field_project_lead_organisation']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_manager'])) : ?>
        <tr>
          <th><?php print render($content['field_project_manager']['#title']); ?></th>
          <td><?php print render($content['field_project_manager']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_operat_contact'])) : ?>
        <tr>
          <th><?php print render($content['field_project_operat_contact']['#title']); ?></th>
          <td><?php print render($content['field_project_operat_contact']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_esf_languages_ref'])) : ?>
        <tr>
          <th><?php print render($content['field_esf_languages_ref']['#title']); ?></th>
          <td><?php print render($content['field_esf_languages_ref']); ?><?php print render($content['field_project_other_language'][0]['#markup']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_esf_themes_ref'])) : ?>
        <tr>
          <th><?php print render($content['field_esf_themes_ref']['#title']); ?></th>
          <td><?php print render($content['field_esf_themes_ref']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_project_status'])) : ?>
        <tr>
          <th><?php print render($content['field_project_status']['#title']); ?></th>
          <td><?php print render($content['field_project_status']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_project_idea_summary'])) : ?>
        <tr>
          <th><?php print render($content['field_project_idea_summary']['#title']); ?></th>
          <td><?php print render($content['field_project_idea_summary']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_problem_addressed'])) : ?>
        <tr>
          <th><?php print render($content['field_project_problem_addressed']['#title']); ?></th>
          <td><?php print render($content['field_project_problem_addressed']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_objectives'])) : ?>
        <tr>
          <th><?php print render($content['field_project_objectives']['#title']); ?></th>
          <td><?php print render($content['field_project_objectives']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_results'])) : ?>
        <tr>
          <th><?php print render($content['field_project_results']['#title']); ?></th>
          <td><?php print render($content['field_project_results']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_activities'])) : ?>
        <tr>
          <th><?php print render($content['field_project_activities']['#title']); ?></th>
          <td><?php print render($content['field_project_activities']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_project_experience'])) : ?>
        <tr>
          <th><?php print render($content['field_project_experience']['#title']); ?></th>
          <td><?php print render($content['field_project_experience']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_expected_partners'])) : ?>
        <tr>
          <th><?php print render($content['field_project_expected_partners']['#title']); ?></th>
          <td><?php print render($content['field_project_expected_partners']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_general_comments'])) : ?>
        <tr>
          <th><?php print render($content['field_project_general_comments']['#title']); ?></th>
          <td><?php print render($content['field_project_general_comments']); ?></td>
        </tr>
      <?php endif; ?>

      <?php if (isset($content['field_project_indicative_budget_'])) : ?>
        <tr>
          <th><?php print render($content['field_project_indicative_budget_']['#title']); ?></th>
          <td><?php print render($content['field_project_indicative_budget_']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_countries_looked'])) : ?>
        <tr>
          <th><?php print render($content['field_project_countries_looked']['#title']); ?></th>
          <td><?php print render($content['field_project_countries_looked']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_activities_list'])) : ?>
        <tr>
          <th><?php print render($content['field_project_activities_list']['#title']); ?></th>
          <td>
            <?php print render($content['field_project_activities_list']);
            if (isset($content['field_project_other_activity'])): print render($content['field_project_other_activity'][0]['#markup']);
            endif;
            ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_links'])) : ?>
        <tr>
          <th><?php print render($content['field_project_links']['#title']); ?></th>
          <td><?php print render($content['field_project_links']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_attachments'])) : ?>
        <tr>
          <th><?php print render($content['field_project_attachments']['#title']); ?></th>
          <td><?php print render($content['field_project_attachments']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_hight_promo_txt'])) : ?>
        <tr>
          <th><?php print render($content['field_project_hight_promo_txt']['#title']); ?></th>
          <td><?php print render($content['field_project_hight_promo_txt']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_target_groups'])) : ?>
        <tr>
          <th><?php print render($content['field_project_target_groups']['#title']); ?></th>
          <td><?php print render($content['field_project_target_groups']); ?></td>
        </tr>
      <?php endif; ?>
      <?php if (isset($content['field_project_end_date_activity'])) : ?>
        <tr>
          <th><?php print render($content['field_project_end_date_activity']['#title']); ?></th>
          <td><?php print render($content['field_project_end_date_activity']); ?></td>
        </tr>
      <?php endif; ?>

    </table>
  <?php else: ?>
    <?php if ($view_mode == 'teaser'): ?>
      <div
        class="abstract"><?php print render($content['field_project_idea_summary']); ?></div>
      <table class="standard-table" cellpadding="0" cellspacing="0">
        <?php if (isset($content['field_esf_country_ref'])) : ?>
          <tr>
            <th><?php print render($content['field_esf_country_ref']['#title']); ?></th>
            <td><?php if (['field_esf_country_ref'] == 'Other countries') : ?>
                <?php print render($content['field_project_other_countries']); ?>
              <?php else : ?>
                <?php print render($content['field_esf_country_ref']); ?>
              <?php endif ?>
            </td>
          </tr>
        <?php endif; ?>
        <?php if (isset($content['field_project_call_for_projects'])) : ?>
          <tr>
            <th><?php print render($content['field_project_call_for_projects']['#title']); ?></th>
            <td><?php print render($content['field_project_call_for_projects']); ?></td>
          </tr>
        <?php endif; ?>
        <?php if (isset($content['field_esf_type_call'])) : ?>
          <tr>
            <th><?php print render($content['field_esf_type_call']['#title']); ?></th>
            <td><?php print render($content['field_esf_type_call']); ?></td>
          </tr>
        <?php endif; ?>

      </table>
    <?php else: ?>
      <?php print render($content); ?>
    <?php endif; ?>
  <?php endif; ?>
  <?php if ($suffix_display): ?>
    <div class="row node-info">
      <div
        class="node-info-submitted col-lg-6 col-md-6 col-sm-6 col-xs-12 col-lg-offset-6 col-md-offset-6 col-sm-offset-6">
        <div class="well well-sm node-submitted clearfix">
          <small>
            <?php print $user_picture; ?>
            <?php print $submitted; ?>
          </small>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <div class="link-wrapper right">
    <?php print render($content['links']); ?>
  </div>

  <?php print render($content['comments']); ?>
</div>
