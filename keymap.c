#include QMK_KEYBOARD_H
#include "oneshot.h"

enum layers {
  _GALLIUM,
  _SEMIMAKJQ,
  _ERGRAM,
  _LOWER,
  _RAISE,
  _ADJUST,
  _F_ROW,
  _GAME,
  _GAME_NUM
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GALLIUM] = LAYOUT_split_3x6_3(
    KC_NO, KC_B, KC_L, KC_D, KC_W, KC_V,    KC_J, KC_Y, KC_O,    KC_U,    KC_COMM, KC_NO,
    KC_NO, KC_N, KC_R, KC_T, KC_S, KC_G,    KC_P, KC_H, KC_A,    KC_E,    KC_I,    KC_NO, 
    KC_NO, KC_X, KC_Q, KC_M, KC_C, KC_Z,    KC_K, KC_F, KC_QUOT, KC_COLN, KC_DOT,  KC_NO,
                KC_LALT, LOWER, OS_SHFT,    KC_SPC, RAISE, KC_LGUI
  ),
  
  [_SEMIMAKJQ] = LAYOUT_split_3x6_3(
    KC_NO, KC_F, KC_L, KC_H, KC_V, KC_Z,    KC_QUOT, KC_W, KC_U,    KC_O,   KC_Y,    KC_NO,
    KC_NO, KC_S, KC_R, KC_N, KC_T, KC_K,    KC_C,    KC_D, KC_E,    KC_A,   KC_I,    KC_NO,
    KC_NO, KC_X, KC_J, KC_B, KC_M, KC_Q,    KC_P,    KC_G, KC_COMM, KC_DOT, KC_COLN, KC_NO,
                KC_LALT, LOWER, OS_SHFT,    KC_SPC, RAISE, KC_LGUI
  ),
  
  [_ERGRAM] = LAYOUT_split_3x6_3(
    KC_NO, KC_B, KC_Y, KC_O, KC_U, KC_QUOT,  KC_SCLN, KC_L, KC_D, KC_W, KC_V, KC_NO,
    KC_NO, KC_C, KC_I, KC_E, KC_A, KC_COMM,  KC_DOT,  KC_H, KC_T, KC_S, KC_N, KC_NO, 
    KC_NO, KC_G, KC_X, KC_J, KC_K, KC_Z,     KC_Q,    KC_R, KC_M, KC_F, KC_P, KC_NO,
                 KC_LALT, LOWER, OS_SHFT,    KC_SPC, RAISE, KC_LGUI
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    KC_NO, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_NO,
    KC_NO, OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, KC_PERC,    KC_ESC, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_NO, 
    KC_NO, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,    KC_DEL, KC_BSPC, KC_TAB, KC_ENT,  KC_SCLN, KC_NO,
                               _______, _______, _______,   _______, _______, G(KC_SPC)
  ),
  
  [_RAISE] = LAYOUT_split_3x6_3(
    KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_TILD,    KC_CIRC, KC_AMPR, KC_QUES, KC_SLSH, KC_ASTR, KC_NO,
    KC_NO, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PERC,    KC_PIPE, OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL, KC_NO, 
    KC_NO, KC_LBRC, KC_RBRC, KC_UNDS, KC_MINS, KC_GRV,     KC_BSLS, KC_EQL,  KC_RABK, KC_LABK, KC_PLUS, KC_NO,
                           G(KC_SPC), _______, KC_SPC,     _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
    KC_NO, KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, KC_TAB,     G(KC_N), G(KC_L), G(KC_T), G(KC_W), G(KC_SPC),  KC_NO,
    KC_NO, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_Q,       C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),    KC_NO, 
    KC_NO, KC_BTN4, KC_BTN5, G(KC_C), G(KC_V), KC_ENT,     KC_DEL,  KC_BSPC, KC_LGUI, KC_LALT, MO(_F_ROW), KC_NO,
                               _______, _______, _______,   _______, _______, _______
  ),
  
  [_F_ROW] = LAYOUT_split_3x6_3(
    KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,  DF(_GALLIUM),       TG(_GAME), _______, _______, _______, QK_BOOT, KC_NO,
    KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,  DF(_ERGRAM),        _______,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_NO, 
    KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, DF(_SEMIMAKJQ),     _______,   KC_BRMD, KC_BRMU, _______, _______, KC_NO,
                               _______, _______, _______,     _______, _______, _______
  ),
  
  [_GAME] = LAYOUT_split_3x6_3(
    KC_NO, KC_LCTL, KC_Q, KC_W, KC_E, KC_R,     KC_Y, KC_U, KC_I,    KC_O,   TG(_GAME), KC_NO,
    KC_NO, KC_LSFT, KC_A, KC_S, KC_D, KC_F,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,   KC_NO, 
    KC_NO, KC_ESC,  KC_Z, KC_X, KC_C, KC_V,     KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT,   KC_NO,
            _______, MO(_GAME_NUM), KC_SPC,     KC_SPC, RAISE, _______
  ),
  
  [_GAME_NUM] = LAYOUT_split_3x6_3(
    KC_NO, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      _______, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,
    KC_NO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, 
    KC_NO, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,   _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
                             _______, _______, _______,   _______, _______, _______
  ),
};

const uint16_t PROGMEM comboGalGBspc[] = { KC_Q, KC_M, KC_QUOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalEsc[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM comboGalEnt[] = { KC_QUOT, KC_F, COMBO_END};
const uint16_t PROGMEM comboGalBsps[] = { KC_QUOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalSemi[] = { KC_DOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalCBspc[] = { KC_Q, KC_M, COMBO_END};

const uint16_t PROGMEM comboSemiGBspc[] = { KC_J, KC_B, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM comboSemiEsc[] = { KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM comboSemiEnt[] = { KC_G, KC_COMM, COMBO_END};
const uint16_t PROGMEM comboSemiBspc[] = { KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM comboSemiCBspc[] = { KC_J, KC_B, COMBO_END};

combo_t key_combos[] = {
    COMBO(comboGalGBspc, G(KC_BSPC)),
    COMBO(comboGalEsc,  KC_ESCAPE),
    COMBO(comboGalBsps, KC_BSPC),
    COMBO(comboGalEnt,  KC_ENTER),
    COMBO(comboGalSemi, KC_SCLN),
    COMBO(comboGalCBspc, A(KC_BSPC)),

    COMBO(comboSemiGBspc, G(KC_BSPC)),
    COMBO(comboSemiBspc, KC_BSPC),
    COMBO(comboSemiEsc, KC_ESCAPE),
    COMBO(comboSemiEnt, KC_ENTER),
    COMBO(comboSemiCBspc, A(KC_BSPC)),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// one shot cancel
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
        update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
// end of one shot cancel