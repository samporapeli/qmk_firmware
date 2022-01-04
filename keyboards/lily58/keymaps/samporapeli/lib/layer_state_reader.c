#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER  (1 << 1)
#define L_RAISE  (1 << 2)
#define L_LEDS   (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI      (L_ADJUST | L_RAISE | L_LOWER)
#define L_LEDS_LOWER      (L_LEDS | L_LOWER)
#define L_LEDS_RAISE      (L_LEDS | L_RAISE)
#define L_ADJUST_TRI_LEDS (L_ADJUST | L_LEDS_RAISE | L_LEDS_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_LEDS:
  case L_LEDS_LOWER:    // acts as basic Led layer
  case L_LEDS_RAISE:    // acts as basic Led layer
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Leds");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
  case L_ADJUST_TRI_LEDS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
