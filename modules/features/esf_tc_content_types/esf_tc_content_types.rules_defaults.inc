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
  $items['rules_notification_known_user_selected_as_organisation_contact'] = entity_import('rules_config', '{ "rules_notification_known_user_selected_as_organisation_contact" : {
      "LABEL" : "Notify known user when selected as organisation contact ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "field_collection" ],
      "ON" : { "field_collection_item_insert" : [] },
      "IF" : [
        { "entity_field_access" : {
            "entity" : [ "field-collection-item" ],
            "field" : "field_fc_org_contact",
            "account" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[field-collection-item:field_fc_org_contact]",
            "subject" : "Notify known user when selected as organisation contact ",
            "message" : "Notify known user when selected as organisation contact ",
            "language" : [ "field-collection-item:field-name" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_contacts_when_the_organisation_is_published'] = entity_import('rules_config', '{ "rules_notify_contacts_when_the_organisation_is_published" : {
      "LABEL" : "Notify contacts when the organisation is published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_insert--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" },
        "node_update--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "node:field-esf-editorial-status" ], "value" : "published" } }
      ],
      "DO" : []
    }
  }');
  $items['rules_public_forum_topic'] = entity_import('rules_config', '{ "rules_public_forum_topic" : {
      "LABEL" : "Public forum topic",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_insert--forum" : { "bundle" : "forum" },
        "node_update--forum" : { "bundle" : "forum" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "node:field-topic-public" ], "value" : "1" } },
        { "AND" : [] },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [ { "node_publish" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_update_editorial_status_when_an_organisation_is_published'] = entity_import('rules_config', '{ "rules_update_editorial_status_when_an_organisation_is_published" : {
      "LABEL" : "Update editorial status when an organisation is published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : {
        "node_insert--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" },
        "node_update--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" }
      },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "AND" : [] },
        { "NOT contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-esf-editorial-status" ], "value" : "published" } }
      ]
    }
  }');
  return $items;
}
