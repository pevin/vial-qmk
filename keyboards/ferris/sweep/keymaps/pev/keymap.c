#include QMK_KEYBOARD_H
#include "vial.h"

/* ───────────────────────────────
 * Layers
 * ─────────────────────────────── */
enum layers {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
    // _EXTRA, // blank layer
};

/* ───────────────────────────────
 * Macros
 * ─────────────────────────────── */
enum {
    M0,
    M1,
    M2,
    M3,
    M4,
    M5,
    M6,
    M7,
    M8,
    M9,
    M10,
    M11,
    M12,
    M13,
    M14,
    M15,
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (!record->event.pressed) return true;
//
//     switch (keycode) {
//         case M0: SEND_STRING(SS_TAP(X_ENTER)); layer_move(_BASE); break;
//         case M1: SEND_STRING("123qwe!@#QWE"); break;
//         case M2: SEND_STRING("123ldw@#*LDW"); break;
//         case M3: SEND_STRING(SS_TAP(X_SPACE)); layer_move(_BASE); break;
//         case M4:
//             register_mods(MOD_LGUI | MOD_LCTL | MOD_LSFT);
//             tap_code(KC_4);
//             unregister_mods(MOD_LGUI | MOD_LCTL | MOD_LSFT);
//             break;
//         case M5: SEND_STRING(SS_TAP(X_ENTER)); layer_move(_BASE); break;
//         case M6: SEND_STRING(SS_TAP(X_J)); layer_move(_BASE); break;
//         case M7: SEND_STRING(SS_TAP(X_K)); layer_move(_BASE); break;
//         case M8:
//             tap_code(KC_ESC);
//             SEND_STRING(":w");
//             tap_code(KC_ENTER);
//             break;
//         case M9: SEND_STRING(SS_LSFT("g")); layer_move(_BASE); break;
//         case M10: SEND_STRING(SS_TAP(X_Q)); layer_move(_BASE); break;
//         case M14: SEND_STRING(SS_TAP(X_L)); layer_move(_BASE); break;
//         case M15: SEND_STRING(SS_TAP(X_ENTER)); layer_move(_BASE); break;
//     }
//     return false;
// }

/* ───────────────────────────────
 * Tap Dance
 * ─────────────────────────────── */
// tap_dance_action_t tap_dance_actions[VIAL_TAP_DANCE_ENTRIES] = {
//     [0] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_Z), M4),
//     [1] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_V), LGUI(KC_C)),
//     [2] = ACTION_TAP_DANCE_DOUBLE(KC_BTN3, KC_BTN2),
//     [3] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_W), KC_LSFT),
// };

/* ───────────────────────────────
 * Combos
 * ─────────────────────────────── */
// const uint16_t PROGMEM combo_0[] = {KC_F, KC_O, KC_U, COMBO_END};
// const uint16_t PROGMEM combo_1[] = {KC_R, KC_T, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_2[] = {KC_C, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_3[] = {LT(1, KC_C), LT(1, KC_P), COMBO_END};
// const uint16_t PROGMEM combo_4[] = {KC_6, KC_KP_DOT, COMBO_END};
// const uint16_t PROGMEM combo_5[] = {LT(1, KC_P), KC_DOT, COMBO_END};
//
// combo_t key_combos[VIAL_COMBO_ENTRIES] = {
//     COMBO(combo_0, M8),
//     COMBO(combo_1, OSL(_NUM)),
//     COMBO(combo_2, TO(_NUM)),
//     COMBO(combo_3, TO(_NUM)),
//     COMBO(combo_4, M1),
//     COMBO(combo_5, KC_ENTER),
// };

/* ───────────────────────────────
 * Key Overrides
 * ─────────────────────────────── */
const key_override_t quote_dash_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_UNDS);

const key_override_t minus_quote_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_DQUO);

const key_override_t *key_overrides[] = {
    &quote_dash_override,
    &minus_quote_override,
};

/* ───────────────────────────────
 * Keymaps
 * ─────────────────────────────── */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x5_2(
 KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,          KC_QUOTE, KC_F,    KC_O,    KC_U,    KC_J,
 KC_N,    KC_R,    KC_T,    KC_S,    KC_G,          KC_Y,     KC_H,    KC_A,    KC_E,    KC_I,
 KC_Q,    KC_X,    KC_M,    LT(1,KC_C), KC_V,       KC_K,     LT(1,KC_P), KC_DOT, KC_MINUS, KC_SLASH,
                             MO(2),   MEH_T(KC_SPACE),    OSM(MOD_LSFT), OSM(MOD_LCTL)
),

[_SYM] = LAYOUT_split_3x5_2(
 LSFT(KC_SLASH), LSFT(KC_SCLN), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_7),    LSFT(KC_EQL), LSFT(KC_6), LSFT(KC_4), LSFT(KC_5), LSFT(KC_1),
 LSFT(KC_GRV),   LSFT(KC_8),    KC_EQL,        LSFT(KC_3),   KC_BSLS,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_COMM, KC_SCLN, LSFT(KC_9), LSFT(KC_0), LSFT(KC_BSLS),                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                TO(0), _______,                               _______, _______
),

[_NAV] = LAYOUT_split_3x5_2(
 LGUI(KC_GRV), SGUI(KC_LBRC), SGUI(KC_RBRC), KC_ESC, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_DEL,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,                                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                          TO(0), KC_NO,                                       _______, _______
),

[_NUM] = LAYOUT_split_3x5_2(
 KC_NO, M0, KC_NO, KC_ESC, KC_NO,                                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_1, KC_2, LALT_T(KC_3), KC_4, M9,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 M10, KC_NO, KC_NO, KC_5, KC_NO,                                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                    TO(0), M3,                                                _______, _______
),

// [_EXTRA] = LAYOUT_split_3x5_2(
//  _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______,
//                             _______, _______,                                 _______, _______
// )

};
