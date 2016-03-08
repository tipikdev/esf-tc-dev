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
  $items['rules_publish_content_type'] = entity_import('rules_config', '{ "rules_publish_content_type" : {
      "LABEL" : "Publish all content type ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_insert--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" },
        "node_update--esf_tnc_organisation" : { "bundle" : "esf_tnc_organisation" },
        "node_insert--esf_tnc_project" : { "bundle" : "esf_tnc_project" },
        "node_update--esf_tnc_project" : { "bundle" : "esf_tnc_project" },
        "node_insert--esf_tnc_global_call" : { "bundle" : "esf_tnc_global_call" },
        "node_update--esf_tnc_global_call" : { "bundle" : "esf_tnc_global_call" },
        "node_insert--esf_tnc_tca" : { "bundle" : "esf_tnc_tca" },
        "node_update--esf_tnc_tca" : { "bundle" : "esf_tnc_tca" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "node:field-esf-editorial-status" ], "value" : "published" } }
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
