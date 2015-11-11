<?php
/**
 * @file
 * location_webform.features.inc
 */

/**
 * Implements hook_default_entityform_type().
 */
function location_webform_default_entityform_type() {
  $items = array();
  $items['submit_location_'] = entity_import('entityform_type', '{
    "type" : "submit_location_",
    "label" : "Submit location ",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "Submit location ",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Thank you for subitting your location to our website!",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EWe recieved your submisson, we will review it and we will notify you if your location is available online.\\u003C\\/p\\u003E\\r\\n",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" },
      "anonymous_links" : 0,
      "session_save" : 0
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}
