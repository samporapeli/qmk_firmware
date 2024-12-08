#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>

#define L_BASE   0
#define L_LOWER  (2 << 1)
#define L_RAISE  (2 << 2)
#define L_ADJUST (2 << 3)
#define L_LEDS   (2 << 4)
#define L_ADJUST_TRI      (L_ADJUST | L_RAISE | L_LOWER)
#define L_LEDS_LOWER      (L_LEDS | L_LOWER)
#define L_LEDS_RAISE      (L_LEDS | L_RAISE)
#define L_ADJUST_TRI_LEDS (L_ADJUST | L_LEDS_RAISE | L_LEDS_LOWER)


char layer_state_str[24];

const char *read_layer_state(layer_state_t current_base_layer) {
  switch (layer_state)
  {
  case L_BASE:
    if (current_base_layer == 0) {
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Dvorak");
    } else if (current_base_layer == 1) {
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    } else {
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base-%u", current_base_layer);
    }
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  // Tri state not properly set up with non-base layers
  case L_LEDS:
  case L_ADJUST_TRI_LEDS:
  case L_LEDS_LOWER:
  case L_LEDS_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Leds");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
