/* Copyright 2021 projectcain
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
enum layers{
  BASE,
  NUM,
  SYM,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_4space(

    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
         KC_LALT,      MO(1), KC_LSFT,  KC_SPACE,       MO(2), KC_CAPS
  ),

  [NUM] = LAYOUT_split_4space(

      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_NO,    KC_LBRC,    KC_RBRC,    KC_DEL,
     KC_TAB,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_SCLN,    KC_QUOT,    KC_NUHS,
      KC_LCTL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
           KC_LALT,            KC_TRNS,  KC_TRNS,      KC_SPACE,         KC_NO, KC_NO
  ),

  [SYM] = LAYOUT_split_4space(

         KC_TILD,    KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_CIRC,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_NO,    KC_NO,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
            KC_TRNS,           KC_TRNS,   KC_TRNS,      KC_SPACE,        KC_TRNS,    KC_TRNS
  ),

};


enum combos {
  KL_SLSH,
  JK_MINUS
};

const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
  [KL_SLSH] = COMBO(kl_combo, S(KC_SLSH)),
  [JK_MINUS] = COMBO(jk_combo, KC_MINUS)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
      [NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
      [SYM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif