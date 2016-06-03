<?php
/**
 * @file
 * esf_tc_content_types.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function esf_tc_content_types_default_rules_configuration() {
  $items = array();
  $items['esf_tc_content_types_notify_forum_moderator_on_new_comment'] = entity_import('rules_config', '{ "esf_tc_content_types_notify_forum_moderator_on_new_comment" : {
      "LABEL" : "Notify forum moderator on new comment",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "user", "type" : "user" },
        "emails" : { "label" : "emails", "type" : "list\\u003Ctext\\u003E" },
        "thematic" : { "label" : "thematic", "type" : "taxonomy_term" },
        "node" : { "label" : "node", "type" : "node" },
        "comment" : { "label" : "comment", "type" : "comment" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "emails" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:value]",
                  "subject" : "ESF-TC: new comment on the network",
                  "message" : "Dear forum moderator,\\r\\n\\r\\nA user has added a new comment on the network:\\r\\n\\r\\n- user: [user:field_lastname] [user:field_firstname]\\r\\n- Thematic: [thematic:name]\\r\\n- Topic: [node:title]\\r\\n- Comment subject: [comment:subject]\\r\\n\\r\\nThe comment is available at this address: [comment:url]\\r\\n\\r\\nESF-TC Admin Team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "drupal_message" : { "message" : "The forum moderator has been notified." } }
      ]
    }
  }');
  $items['esf_tc_content_types_notify_forum_moderator_on_new_post'] = entity_import('rules_config', '{ "esf_tc_content_types_notify_forum_moderator_on_new_post" : {
      "LABEL" : "Notify forum moderator on new post",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "user", "type" : "user" },
        "emails" : { "label" : "emails", "type" : "list\\u003Ctext\\u003E" },
        "thematic" : { "label" : "thematic", "type" : "taxonomy_term" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "emails" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:value]",
                  "subject" : "ESF-TC: new post on the network",
                  "message" : "Dear forum moderator,\\r\\n\\r\\nA user has added a new content on the network:\\r\\n\\r\\n- user: [user:field_lastname] [user:field_firstname]\\r\\n- Thematic: [thematic:name]\\r\\n- Title: [node:title]\\r\\n\\r\\nESF-TC Admin Team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "drupal_message" : { "message" : "The forum moderator has been notified." } }
      ]
    }
  }');
  $items['esf_tc_content_types_notify_forum_moderator_to_add_user'] = entity_import('rules_config', '{ "esf_tc_content_types_notify_forum_moderator_to_add_user" : {
      "LABEL" : "Notify forum moderator to add user",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "user", "type" : "user" },
        "thematic" : { "label" : "thematic", "type" : "taxonomy_term" },
        "emails" : { "label" : "emails", "type" : "list\\u003Ctext\\u003E" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "emails" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:value]",
                  "subject" : "ESF-TC: a contact would like to join a network",
                  "message" : "Dear forum moderator,\\r\\n\\r\\nA user is asking to join a network:\\r\\n\\r\\n- User: [user:field_lastname] [user:field_firstname]\\r\\n- Thematic: [thematic:name]\\r\\n\\r\\nYou can manage the networking access of the user at the following address: [site:url]\\/user\\/[user:uid]\\/sections\\r\\n\\r\\nESF-TC Admin Team",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "drupal_message" : { "message" : "The forum moderator has been notified regarding your request." } }
      ]
    }
  }');
  return $items;
}
