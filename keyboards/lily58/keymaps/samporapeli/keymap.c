#include QMK_KEYBOARD_H
#include "keymap_finnish.h"

enum layer_number {
  _DVORAK = 0,
  _LOWER,
  _RAISE,
  _LEDS,
  _ADJUST,
};

enum custom_keycodes {
    CADEL = SAFE_RANGE,
    CSLEFT,
    CSRIGHT,
    BCKTCK,
    TILDE,
    M_CIRC,
    M1M1M1,
    LED_RED,
    LED_YEL,
    LED_GRE,
    LED_CYA,
    LED_BLU,
    LED_MAG,
    LED_ORA,
    LED_CHA,
    LED_SPR,
    LED_AZU,
    LED_VLT,
    LED_RSE,
    LED_FLASH,
    LED_MIN,
    LED_MAX,
    MACRO_A,
    MACRO_B,
};

bool M1M1M1_active = false;
#ifdef RGBLIGHT_ENABLE
unsigned int LED_FLASH_prev_value = 0;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TAB  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   Ö  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   O  |   U  |   E  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |RSft/-|
 * |------+------+------+------+------+------|   Å   |    |   <   |------+------+------+------+------+------|
 * |LCtrl |   Ä  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RCtrl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Alt gr|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DVORAK] = LAYOUT( \
  KC_TAB,  FI_1,   FI_2,    FI_3,    FI_4,    FI_5,                     FI_6,    FI_7,    FI_8,    FI_9,    FI_0,    FI_PLUS, \
  KC_CAPS, FI_ODIA,KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    FI_QUOT, \
  KC_LSFT, KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    MT(MOD_RSFT, FI_MINS), \
  KC_LCTRL, FI_ADIA,KC_Q,    KC_J,    KC_K,    KC_X, FI_ARNG, MT(MOD_RCTL, FI_LABK),   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RCTL, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_ALGR \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |MW Lft|MW Dwn|MW Up |MW Rgt|  ´/~ |                    |  m`  |   !  |   {  |   }  |   $  |   %  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  M1  |M Left|M Down| M Up |M Rght|  M2  |-------.    ,-------|  m^  |   &  |   [  |   ]  |   *  |   @  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  M3  |M1M1M1|      |      |  §   |  ¨/^ |-------|    |-------|  m~  |   _  |   (  |   )  |   #  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|Alt Gr|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_ESC,  KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, FI_ACUT,           BCKTCK,  FI_EXLM, FI_LCBR, FI_RCBR, FI_DLR,  FI_PERC, \
  KC_MS_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN2,M_CIRC, FI_AMPR,FI_LBRC, FI_RBRC, FI_ASTR, FI_AT, \
  KC_MS_BTN3, M1M1M1, _______, _______, FI_SECT, FI_DIAE,FI_LBRC,               FI_RBRC, TILDE, FI_UNDS, FI_LPRN, FI_RPRN, FI_HASH, FI_PIPE, \

                             _______, _______, _______, _______, _______, _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |MACROA|MACROB|      |      |      | CADel|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  <-- | Left | Down |  Up  |Right | -->  |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   -  |   <  |   >  |   =  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |Delete|Alt Gr|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     MACRO_A, MACRO_B, _______, _______, _______, CADEL, \
  _______, _______, _______, _______, _______, _______,                     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______,                      CSLEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CSRIGHT, \
  _______, _______, _______, _______, _______, _______,   FI_LCBR, FI_RCBR, FI_PLUS, FI_MINS, FI_LABK, FI_RABK, FI_EQL,  FI_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, KC_DEL,  _______ \
),
/* LEDS
 * https://docs.qmk.fm/#/feature_rgblight?id=keycodes
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |FLASH |STATIC| GRAD |SWIRL |RAINBW|BREATH|                    | SNEK |KNIGHT|TWNKLE|      |      |RGBTOG|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RED  |YELLOW|GREEN | CYAN | BLUE |MGENTA|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ORANGE|CHAGRE|SPRGRE|AZURE |VIOLET| ROSE |-------.    ,-------| MAX  |      |      | HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|  PREV |    | NEXT  |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------| MIN  |      |      | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / CLOSE /       \CLOSE \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_LEDS] = LAYOUT( \
  LED_FLASH,RGB_M_P,RGB_M_G, RGB_M_SW,RGB_M_R, RGB_M_B,                   RGB_M_SN,RGB_M_K, RGB_M_TW,XXXXXXX, XXXXXXX, RGB_TOG, \
  LED_RED, LED_YEL, LED_GRE, LED_CYA, LED_BLU, LED_MAG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  LED_ORA, LED_CHA, LED_SPR, LED_AZU, LED_VLT, LED_RSE,                   LED_MAX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,RGB_RMOD, RGB_MOD, LED_MIN, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, \
                            _______, _______, _______,TG(_LEDS),TG(_LEDS),_______, _______, _______ \
  ),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | LEDS |      |      |      |      |RGBTOG|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |MODE+ | HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |MODE- | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG(_LEDS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_rgb_info(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    oled_write_ln(read_rgb_info(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
    oled_write_ln("       sampo.website", false);
  }
}
#endif // OLED_ENABLE

// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // send control-alt-delete
        case CADEL:
            // when keycode is pressed
            if (record->event.pressed)
                SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)SS_TAP(X_DEL)SS_UP(X_LALT)SS_UP(X_LCTRL));
            else { /* when keycode is released */ }
            break;

        case CSLEFT:
            if (record->event.pressed)
                SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTRL));
            else { /* when keycode is released */ }
            break;

        case CSRIGHT:
            if (record->event.pressed)
                SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LGUI)SS_UP(X_LCTRL));
            else { /* when keycode is released */ }
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

        case M1M1M1:
            if (record->event.pressed)
                M1M1M1_active = true;
            else
                M1M1M1_active = false;
            break;

        case MACRO_A:
            if (record->event.pressed)
                SEND_STRING(SS_TAP(X_RIGHT)SS_DOWN(X_LALT)SS_DELAY(40)SS_TAP(X_TAB)SS_DELAY(40)SS_DELAY(40)SS_UP(X_LALT)SS_DELAY(40) SS_TAP(X_RIGHT) SS_DOWN(X_LALT)SS_DELAY(40)SS_TAP(X_TAB)SS_DELAY(40)SS_UP(X_LALT));
            else {}
            break;
        case MACRO_B:
            if (record->event.pressed)
                SEND_STRING(SS_TAP(X_LEFT)SS_DOWN(X_LALT)SS_DELAY(40)SS_TAP(X_TAB)SS_DELAY(40)SS_DELAY(40)SS_UP(X_LALT)SS_DELAY(40) SS_TAP(X_LEFT) SS_DOWN(X_LALT)SS_DELAY(40)SS_TAP(X_TAB)SS_DELAY(40)SS_UP(X_LALT)SS_DELAY(40));
            else {}
            break;

        #ifdef RGBLIGHT_ENABLE
        // LED layer specials
        // would be better with keycode macro like LED_H(hue_value)
        case LED_RED:
            rgblight_sethsv(0, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_YEL:
            rgblight_sethsv(43, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_GRE:
            rgblight_sethsv(85, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_CYA:
            rgblight_sethsv(127, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_BLU:
            rgblight_sethsv(169, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_MAG:
            rgblight_sethsv(201, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_ORA:
            rgblight_sethsv(21, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_CHA:
            rgblight_sethsv(64, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_SPR:
            rgblight_sethsv(106, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_AZU:
            rgblight_sethsv(148, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_VLT:
            rgblight_sethsv(180, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_RSE:
            rgblight_sethsv(222, rgblight_get_sat(), rgblight_get_val());
            break;
        case LED_FLASH:
            if (record->event.pressed) {
                LED_FLASH_prev_value = rgblight_get_val();
                rgblight_sethsv_noeeprom(rgblight_get_hue(), rgblight_get_sat(), LED_FLASH_prev_value > 0 ? 0 : 255);
            }
            else {
                rgblight_sethsv_noeeprom(rgblight_get_hue(), rgblight_get_sat(), LED_FLASH_prev_value);
            }
            break;
        case LED_MIN:
            rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0);
            break;
        case LED_MAX:
            rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 255);
            break;
        #endif
    }
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}

void matrix_scan_user(void)
{
    if (M1M1M1_active)
        tap_code16(KC_MS_BTN1);
}
