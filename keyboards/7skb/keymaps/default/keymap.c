#include QMK_KEYBOARD_H
#include "twpair_on_jis.h"

static bool lower_pressed = false; 

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FN,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

#define CL_G_R LCTL(LGUI(KC_RGHT)) // Ctrl+Windows+Right
#define CL_G_L LCTL(LGUI(KC_LEFT)) // Ctrl+Windows+Left
#define GUI_RT LGUI(KC_RGHT)       // Windows+Right
#define GUI_LT LGUI(KC_LEFT)       // Windows+Left
#define GUI_UP LGUI(KC_UP)         // Windows+Up
#define GUI_DW LGUI(KC_DOWN)       // Windows+Down
#define ZEN_HN LALT(KC_GRV)        // ALT+`
#define CTLSFM LCTL(LSFT(KC_M))    // Ctrl+Shift+M
#define TBSC_1 LGUI(KC_1)          // Windows+1 (Task Bar Short Cut 1)
#define TBSC_2 LGUI(KC_2)          // Windows+2 (Task Bar Short Cut 2)
#define TBSC_3 LGUI(KC_3)          // Windows+3 (Task Bar Short Cut 3)
#define TBSC_4 LGUI(KC_4)          // Windows+4 (Task Bar Short Cut 4)
#define TBSC_5 LGUI(KC_5)          // Windows+5 (Task Bar Short Cut 5)
#define TBSC_6 LGUI(KC_6)          // Windows+6 (Task Bar Short Cut 6)
#define TBSC_7 LGUI(KC_7)          // Windows+7 (Task Bar Short Cut 7)
#define TBSC_8 LGUI(KC_8)          // Windows+8 (Task Bar Short Cut 8)
#define TBSC_9 LGUI(KC_9)          // Windows+9 (Task Bar Short Cut 9)
#define TBSC_0 LGUI(KC_0)          // Windows+0 (Task Bar Short Cut 10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,  TG(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                GUI_LT, KC_LALT,  _LOWER,  ZEN_HN,              KC_BSPC,  _RAISE,          KC_RGUI,   GUI_RT 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                GUI_LT, KC_LALT,  _LOWER,  ZEN_HN,              KC_BSPC,  _RAISE,          KC_RGUI,   GUI_RT 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TAB , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_COLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  CTLSFM, XXXXXXX,  KC_DOT, KC_PSLS, XXXXXXX, TO(_ADJUST),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                CL_G_L, XXXXXXX, XXXXXXX,  KC_DEL,              KC_BSPC, XXXXXXX,          XXXXXXX,  CL_G_R
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TAB ,  TBSC_6,  TBSC_7,  TBSC_8,  TBSC_9,  TBSC_0,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,  TBSC_1,  TBSC_2,  TBSC_3,  TBSC_4,  TBSC_5,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_ENT,  KC_APP,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX,    KC_C,    KC_V, XXXXXXX,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_HOME,  KC_END, TO(_ADJUST),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                GUI_DW, XXXXXXX, XXXXXXX,  KC_DEL,              KC_BSPC, XXXXXXX,          XXXXXXX,  GUI_UP 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TAB , RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, XXXXXXX,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_ENT,  KC_APP,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_HOME,  KC_END, TO(_QWERTY),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          KC_STOP, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  )
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_sethsv_at(HSV_AZURE, 0);
}


bool on_jis = false;
//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      if( on_jis ) {
        on_jis = false;
      } else {
        on_jis = true;
      }
      break;
    case _LOWER:
      rgblight_sethsv_at(HSV_WHITE, 0);
      break;
    case _RAISE:
      rgblight_sethsv_at(HSV_YELLOW, 0);
      break;
    case _ADJUST:
      rgblight_sethsv_at(HSV_GREEN, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at(HSV_AZURE, 0);
      break;
    }
    rgblight_set_effect_range( 1, 11);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;

  if (on_jis)
    if (!twpair_on_jis(keycode, record))
      return false;

  switch (keycode) {
    case _QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case _LOWER:
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        // http://okapies.hateblo.jp/entry/2019/02/02/133953
        if (lower_pressed) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        lower_pressed = true;
      }
      return false;
      break;
    case _RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      if (record->event.pressed) {
        // reset the flag
        lower_pressed = false;
      }

      result = true;
      break;
  }

  return result;
}
