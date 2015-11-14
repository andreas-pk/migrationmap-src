<?php
/**
 * @file
 * permissions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function permissions_default_rules_configuration() {
  $items = array();
  $items['rules_prepare_node'] = entity_import('rules_config', '{ "rules_prepare_node" : {
      "LABEL" : "Prepare node",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "location",
              "param_title" : "[entity:field-form-location-name]",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "node_unpublish" : { "node" : [ "entity-created" ] } }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  return $items;
}
