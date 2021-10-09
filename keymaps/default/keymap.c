/* Copyright 2021 Dirk Heinke
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SPECIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        MEH(KC_A), MEH(KC_B), MEH(KC_C), OSL(1), \
        MEH(KC_E), MEH(KC_F), MEH(KC_G), MEH(KC_H), \
        MEH(KC_I), MEH(KC_J), MEH(KC_K), MEH(KC_L), \
        MEH(KC_M), MEH(KC_N), MEH(KC_O), MEH(KC_P), \
        MEH(KC_Q), MEH(KC_R), MEH(KC_S), MEH(KC_T) \
    )
    ,
    [_SPECIAL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, RESET \
     )
};

void keyboard_post_init_user(void) {
    rgblight_setrgb_at(0, 0, 0, 0);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _SPECIAL:
        rgblight_setrgb_at(0, 0, 255, 0);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb_at(0, 0, 0, 0);
        break;
    }
  return state;
}
