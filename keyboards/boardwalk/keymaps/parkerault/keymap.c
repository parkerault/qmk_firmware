/* Copyright 2019 Parker Ault
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

/*
https://docs.qmk.fm/#/keycodes
https://docs.qmk.fm/#/ref_functions
*/

/*

Shrug: %AF _ %28 %u30C4 %29 _/ %AF
Creeper: %u0F3C%20%u0CA5%20%u203F%20%u0CA5%20%u0F3D
Disapprove: %u0CA0_%u0CA0
Bear: %u1D98%20%u1D52%u1D25%u1D52%u1D85
Shock: %28%u2609_%u2609%29
Happy: %u0298%20%u035C%u0296%20%u0298
Table flip: %28%u256F%u0CA0_%u0CA0%uFF09%u256F%u2312%u253B%u2501%u253B
Panic: %u30FD%u0F3C%u2609%u0277%u2299%u0F3D%uFF89
Hi: %28%20%u30FB_%u30FB%29%u30CE
you da man: %28%u261E%20%u035D%B0%20%u035C%u0296%u0361%B0%29%u261E
middle finger: %u51F8%28%20%u2022%u0300%u203F%u2022%u0301%20%29%u51F8
cry: %u0CA5_%u0CA5

1F446 :up:
1F4A9 poop
1F926 Facepalm
1F9D9 wizard
1F984 unicorn
1F914 thinking
1F600 Smile
1F601 Smile
1F602 joy
1F610 Sarcastic
1F62E Shock
1F9D0 Monocle
1F44A punch

KC_MUTE Mute
KC_VOLU Volume Up
KC_VOLD Volume Down
KC_MNXT Next Track (Windows)
KC_MPRV Previous Track (Windows)
KC_MSTP Stop Track (Windows)
KC_MPLY Play/Pause Track

KC_MS_U Mouse Cursor Up
KC_MS_D Mouse Cursor Down
KC_MS_L Mouse Cursor Left
KC_MS_R Mouse Cursor Right
KC_BTN1 Mouse Button 1
KC_BTN2 Mouse Button 2
KC_BTN3 Mouse Button 3
KC_BTN4 Mouse Button 4
KC_BTN5 Mouse Button 5
KC_WH_U Mouse Wheel Up
KC_WH_D Mouse Wheel Down
KC_WH_L Mouse Wheel Left
KC_WH_R Mouse Wheel Right
KC_ACL0 Set mouse acceleration to 0
KC_ACL1 Set mouse acceleration to 1
KC_ACL2 Set mouse acceleration to 2

MEH_T()
HYPR_T()

U+203C !!
U+2049 !?
U+26A0 warning

windows menu key KC_APPLICATION
 */

// https://beta.docs.qmk.fm/features/feature_tap_dance
// enum tapdances {
//   TD_PPNT = 0,
//   TD_LBRC,
//   TD_RBRC
// };

// qk_tap_dance_action_t tap_dance_actions[] = {
//   // Tap once for play/pause, twice for next track
//   [TD_PPNT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
//   // Tap once for curly braces, twice for brackets
//   [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
//   [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC)
// };

enum boardwalk_layers {
  _0,
  _1,
  _2,
  _3,
  _4
};

// Macros: https://beta.docs.qmk.fm/features/feature_macros
enum boardwalk_keycodes {
  M_ARROW = SAFE_RANGE,
  M_CONST,
  M_IF,
  M_ELSIF,
  M_ELSE,
  M_TRY,
  M_CATCH,
  M_BLOCK,
  M_FUNC,
  M_GEN,
  M_XPORT,
  M_XPDEF
};

// Aliases
#define ENT_L1 LT(_1, KC_ENT)
#define SPC_L2 LT(_2, KC_SPC)
#define EQL_L3 LT(_3, KC_EQL)
#define MIN_L4 LT(_4, KC_MINS)
#define CTRLESC CTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
  [_0] = LAYOUT_ergo_classic(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR, KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_CAPS, _______, KC_LALT, KC_LGUI, ENT_L1,     LPR_L3,           RPR_L4,        SPC_L2,  MEH_EQL, HPR_MIN, _______, KC_DEL   \
  ),
*/
  [_0] = LAYOUT_ergo_classic(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPLY, KC_MNXT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLD, KC_VOLU, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_CAPS, _______, KC_LALT, KC_LGUI, ENT_L1,  EQL_L3,                    MIN_L4,  SPC_L2,  MOD_MEH, MOD_HYPR, _______, KC_DEL   \
  ),

  [_1] = LAYOUT_ergo_classic(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, _______, _______, XXXXXXX, KC_PSLS, \
  _______, M_XPORT, M_XPDEF, M_IF,    M_ELSIF, M_ELSE,  _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_PAST, \
  _______, M_GEN,   M_FUNC,  M_CONST, M_ARROW, M_BLOCK,                   _______, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_PMNS, \
  _______, _______, _______, M_TRY,   M_CATCH, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_3,    XXXXXXX, KC_PPLS, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_P0,   KC_COMM, KC_PDOT, XXXXXXX, KC_PENT  \
  ),

  [_2] = LAYOUT_ergo_classic(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_LCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RCBR, \
  RESET,   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______  \
  ),

  [_3] = LAYOUT_ergo_classic(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  KC_LBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RBRC, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______  \
  ),

  [_4] = LAYOUT_ergo_classic(
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, \
  DEBUG,   _______, _______, _______, KC_BTN2, KC_BTN1,                   _______, _______, _______, _______, _______, _______  \
  )
};
/*
  [LAYER] = LAYOUT_ergo_classic(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,    _______,          _______,       _______, _______, _______, _______, _______  \
  ) COMMA
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
      if (record->event.pressed) {
        uprintf("KL: kc: %u, col: %u, row: %u\n", keycode, record->event.key.col, record->event.key.row);
      }
      //uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif
  switch (keycode) {
    case M_ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false;
      break;
    case M_CONST:
      if (record->event.pressed) {
        SEND_STRING("const ");
      }
      return false;
      break;
    case M_IF:
      if (record->event.pressed) {
        SEND_STRING("if (");
      }
      return false;
      break;
    case M_ELSIF:
      if (record->event.pressed) {
        SEND_STRING(" else if (");
      }
      return false;
      break;
    case M_ELSE:
      if (record->event.pressed) {
        SEND_STRING(" else {"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case M_TRY:
      if (record->event.pressed) {
        SEND_STRING("try {"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case M_CATCH:
      if (record->event.pressed) {
        SEND_STRING(" catch (error) {"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case M_BLOCK:
      if (record->event.pressed) {
        SEND_STRING(") {"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case M_FUNC:
      if (record->event.pressed) {
        SEND_STRING("function ");
      }
      return false;
      break;
    case M_GEN:
      if (record->event.pressed) {
        SEND_STRING("function* ");
      }
      return false;
      break;
    case M_XPORT:
      if (record->event.pressed) {
        SEND_STRING("export ");
      }
      return false;
      break;
    case M_XPDEF:
      if (record->event.pressed) {
        SEND_STRING("export default ");
      }
      return false;
      break;
  }
  return true;
};

// Turn on layer 2 if layer 0 and 1 are both active
// uint32_t layer_state_set_user(uint32_t state) {
//   return update_tri_layer_state(state, 0, 1, 2);
// }

// This is how you use actions here
// if (keycode == KC_LEAD) {
//   action_t action;
//   action.code = ACTION_DEFAULT_LAYER_SET(0);
//   process_action(record, action);
//   return false;
// }

// /* key matrix position */
// typedef struct {
//     uint8_t col;
//     uint8_t row;
// } keypos_t;

// /* key event */
// typedef struct {
//     keypos_t key;
//     bool     pressed;
//     uint16_t time;
// } keyevent_t;
//
// /* Key record */
// typedef struct {
//     keyevent_t  event;
// #ifndef NO_ACTION_TAPPING
//     tap_t tap;
// #endif
// } keyrecord_t;


// /* equivalent test of keypos_t */
// #define KEYEQ(keya, keyb) ((keya).row == (keyb).row && (keya).col == (keyb).col)
