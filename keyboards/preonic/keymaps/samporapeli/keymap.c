/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_finnish.h"

enum preonic_layers {
  _QWERTY,
  _DVORAK,
  _MIDI,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  MIDI,
  LOWER,
  RAISE,
  BACKLIT,
  CADEL,
  BCKTCK,
  TILDE,
  M_CIRC,
  CSLEFT,
  CSRIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Ö   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ä  |Rsft/-|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   '  | RCtrl|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower |    Space    |    Enter    |Raise | Bksp |Alt Gr|  <   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FI_PLUS,
  KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FI_ODIA,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    FI_ADIA, MT(MOD_RSFT, FI_MINS),
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  FI_QUOT, KC_RCTL,
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT,  RAISE,   KC_BSPC, KC_ALGR, FI_LABK
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Ö  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Rsft/-|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Ä  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RCtrl|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower |    Space    |    Enter    |Raise | Bksp |Alt Gr|RSft/<|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FI_PLUS,
  KC_CAPS, FI_ODIA, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    FI_QUOT,
  KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    MT(MOD_RSFT, FI_MINS),
  KC_LCTL, FI_ADIA, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RCTL,
  KC_LCTL,KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT,  RAISE,   KC_BSPC, KC_ALGR, MT(MOD_RSFT, FI_LABK)
),

/* MIDI
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Ö  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  C0  |  C#0 |  D0  |  D#0 |  E0  |  F0  |  F#0 |  G0  |  G#0 |  A0  |  A#0 |  B0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |DVORAK|      |      |Lower |    Space    |    Enter    |Raise |      | OCT- | OCT+ |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_preonic_grid(
  MI_C3,   MI_Cs3,  MI_D3,   MI_Ds3,  MI_E3,   MI_F3,   MI_Fs3,  MI_G3,   MI_Gs3,  MI_A3,   MI_As3,  MI_B3,
  MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,   MI_Fs2,  MI_G2,   MI_Gs2,  MI_A2,   MI_As2,  MI_B2,
  MI_C1,   MI_Cs1,  MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,  MI_G1,   MI_Gs1,  MI_A1,   MI_As1,  MI_B1,
  MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
  DVORAK,  XXXXXXX, XXXXXXX, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT,  RAISE,   XXXXXXX, MI_OCTD, MI_OCTU
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |MW Lft|MW Dwn|MW Up |MW Rgt|  ´/~ |  m`  |   !  |   {  |   }  |   $  |   %  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  M1  |M Left|M Down| M Up |M Rght|  M2  |  m^  |   &  |   [  |   ]  |   *  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  M3  |      |      |  Å   |  §   |  ¨/^ |  m~  |   _  |   (  |   )  |   #  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ^   | Alt  | GUI  |Lower |    Space    |    Enter    |Raise | Bksp |Alt Gr|RSft/<|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_ESC, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, FI_ACUT, BCKTCK,  FI_EXLM, FI_LCBR,   FI_RCBR, FI_DLR,  FI_PERC,
  KC_MS_BTN1,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_MS_BTN2, M_CIRC, FI_AMPR, FI_LBRC, FI_RBRC, FI_ASTR, FI_AT,
  KC_MS_BTN3,_______, _______, FI_ARNG, FI_SECT, FI_DIAE, TILDE, FI_UNDS, FI_LPRN, FI_RPRN, FI_HASH, FI_PIPE,
  FI_CIRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |CAlDel|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  <-- | Left | Down |  Up  |Right | -->  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   +  |   -  |   <  |   >  |   =  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Å   | Alt  | GUI  |Lower |    Space    |    Enter    |Raise | Del  |Alt Gr|RSft/<|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CADEL, \
  _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______, CSLEFT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CSRIGHT, \
  _______, _______, _______, _______, _______, _______, FI_PLUS, FI_MINS, FI_LABK, FI_RABK, FI_EQL,  FI_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DEL, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |togRGB|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  RGB_TOG,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  DVORAK,  DVORAK,  MIDI,    _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case MIDI:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MIDI);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
        case BCKTCK: // `
          if (record->event.pressed)
            SEND_STRING(SS_LSFT(SS_TAP(X_EQL) " "));
          else { /* when keycode is released */ }
          return false;
          break;
        case TILDE: // ~
          if (record->event.pressed)
            SEND_STRING(SS_ALGR(SS_TAP(X_RBRC) " "));
          else { /* when keycode is released */ }
          return false;
          break;
        case M_CIRC: // ^
          if (record->event.pressed)
            SEND_STRING(SS_LSFT(SS_TAP(X_RBRC) " "));
          else { /* when keycode is released */ }
          return false;
          break;
        // send control-alt-delete
        case CADEL:
          // when keycode is pressed
          if (record->event.pressed)
            tap_code16(LCTL(LALT(KC_DEL)));
          else { /* when keycode is released */ }
          return false;
          break;

        case CSLEFT:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_LEFT)));
          else { /* when keycode is released */ }
          return false;
          break;

        case CSRIGHT:
          if (record->event.pressed)
            tap_code16(LCTL(LGUI(KC_RIGHT)));
          else { /* when keycode is released */ }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 0;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
