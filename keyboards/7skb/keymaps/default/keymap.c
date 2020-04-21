#include QMK_KEYBOARD_H

static bool lower_pressed = false; 
static bool raise_pressed = false; 

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

#define GUI_LT LGUI(KC_LEFT)       // Windows+Left
#define GUI_RT LGUI(KC_RGHT)       // Windows+Right
#define CL_G_R LCTL(LGUI(KC_RGHT)) // Ctrl+Windows+Right
#define CL_G_L LCTL(LGUI(KC_LEFT)) // Ctrl+Windows+Left
#define GUI_UP LGUI(KC_UP)         // Windows+Up
#define GUI_DW LGUI(KC_DOWN)       // Windows+Down

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,

  ESCx2   // ESC x2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       ESCx2,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               GUI_LT,  KC_LALT,           _LOWER,  KC_DEL,     KC_BSPC,  _RAISE,          KC_RGUI,  GUI_RT 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TG(_ADJUST),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_PSCR, KC_SLCK,KC_PAUSE,   KC_UP, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          KC_STOP, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
        ESCx2,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_ENT ,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                CL_G_L, _______,  _LOWER,  KC_SPC,              KC_BSPC,  _RAISE,          _______, CL_G_R 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
        ESCx2,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB, _______, _______, _______, _______, _______,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2, _______,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , KC_APP , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, _______,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_HOME,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                GUI_DW, _______,  _LOWER,  KC_SPC,              KC_BSPC,  _RAISE,          _______,  GUI_UP 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______,   RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _FN:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    case _ADJUST:
      rgblight_sethsv_at(HSV_PURPLE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 4);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool result = false;
  switch (keycode) {
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
    case _ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ESCx2:
      if (record->event.pressed) {
        // when keycode ESC is pressed two times 
        // https://qiita.com/chesscommands/items/ce2883ad0a0c6c27c8de#ss_tap
        // https://github.com/qmk/qmk_firmware/blob/6590f3c81155f5d5cfb59c5b8a28610d6f3207d0/quantum/send_string_keycodes.h
        SEND_STRING(SS_TAP(X_ESCAPE));
      } else {
        // when keycode ESC is pressed two times 
        SEND_STRING(SS_TAP(X_ESCAPE));
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        lower_pressed = false;
        raise_pressed = false;
      }
      result = true;
      break;
  }

  return result;
}
