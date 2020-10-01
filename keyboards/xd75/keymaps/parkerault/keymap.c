/* Copyright 2017 Wunder
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

enum layers {
  _0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7
};

// Macros: https://beta.docs.qmk.fm/features/feature_macros
enum keycodes {
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
#define QUO_L5 LT(_5, KC_QUOT)
#define DESKTP1 MEH(KC_1)
#define DESKTP2 MEH(KC_2)
#define DESKTP3 MEH(KC_3)
#define DESKTP4 MEH(KC_4)
#define DESKTP5 MEH(KC_5)
#define WINLOCK LGUI(KC_L)
// #define LPR_L3 LT(_3, KC_9)
// #define RPR_L4 LT(_4, KC_0)
#define CTRLESC LCTL_T(KC_ESC)
#define MEH_EQL MEH_T(KC_EQL)
#define HPR_MIN HYPR_T(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_0] = LAYOUT_ortho_5x15(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F10,  KC_F11,  KC_F12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F9,   KC_F8,   KC_F9,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F4,   KC_F5,   KC_F6,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUO_L5,  \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1,   KC_F2,   KC_F3,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_CAPS, XXXXXXX, KC_LALT, KC_LGUI, ENT_L1,  EQL_L3,  DF(_6),  XXXXXXX, KC_BSLS, MIN_L4,  SPC_L2,  KC_MEH,  KC_HYPR, KC_MPLY, KC_DEL   \
  ),

  [_1] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, \
  XXXXXXX, M_XPDEF, M_XPORT, M_IF,    M_ELSIF, M_ELSE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_PAST, \
  _______, M_CONST, M_ARROW, M_GEN,   M_FUNC,  M_BLOCK, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_PMNS, \
  _______, XXXXXXX, XXXXXXX, M_TRY,   M_CATCH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_3,    XXXXXXX, KC_PPLS, \
  XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_COMM, KC_PDOT, XXXXXXX, KC_PENT  \
  ),

  [_2] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
  _______, KC_LCBR, KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC, KC_RCBR, KC_RSFT, \
  RESET,   XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  [_3] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  XXXXXXX, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  [_4] = LAYOUT_ortho_5x15(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  [_5] = LAYOUT_ortho_5x15(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  DEBUG,   XXXXXXX, _______, _______, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  [_6] = LAYOUT_ortho_5x15(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F10,  KC_F11,  KC_F12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F7,   KC_F8,   KC_F9,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F4,   KC_F5,   KC_F6,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1,   KC_F2,   KC_F3,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_MINS, KC_EQL,  KC_LALT, KC_LGUI, KC_ENT,  KC_SPC,  DF(_0),  KC_LBRC, KC_RBRC, KC_DOWN, KC_LEFT, KC_UP,   KC_RGHT, KC_GRV,  KC_DEL   \
  ),

  [_7] = LAYOUT_ortho_5x15(
  DF(_0),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

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

// This is how you use actions in matrix_scan_user
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














/*
KC_NO,
KC_TRANSPARENT,
KC_TRNS,
KC_A,
KC_B,
KC_C,
KC_D,
KC_E,
KC_F,
KC_G,
KC_H,
KC_I,
KC_J,
KC_K,
KC_L,
KC_M,
KC_N,
KC_O,
KC_P,
KC_Q,
KC_R,
KC_S,
KC_T,
KC_U,
KC_V,
KC_W,
KC_X,
KC_Y,
KC_Z,
KC_1,
KC_2,
KC_3,
KC_4,
KC_5,
KC_6,
KC_7,
KC_8,
KC_9,
KC_0,
KC_ENTER,
KC_ENT,
KC_ESCAPE,
KC_ESC,
KC_BSPACE,
KC_BSPC,
KC_TAB,
KC_SPACE,
KC_SPC,
KC_MINUS,
KC_MINS,
KC_EQUAL,
KC_EQL,
KC_LBRACKET,
KC_LBRC,
KC_RBRACKET,
KC_RBRC,
KC_BSLASH,
KC_BSLS,
KC_NONUS_HASH,
KC_NUHS,
KC_SCOLON,
KC_SCLN,
KC_QUOTE,
KC_QUOT,
KC_GRAVE,
KC_GRV,
KC_ZKHK,
KC_COMMA,
KC_COMM,
KC_DOT,
KC_SLASH,
KC_SLSH,
KC_CAPSLOCK,
KC_CLCK,
KC_CAPS,
KC_F1,
KC_F2,
KC_F3,
KC_F4,
KC_F5,
KC_F6,
KC_F7,
KC_F8,
KC_F9,
KC_F10,
KC_F11,
KC_F12,
KC_PSCREEN,
KC_PSCR,
KC_SCROLLLOCK,
KC_SLCK,
KC_BRMD,
KC_PAUSE,
KC_PAUS,
KC_BRK,
KC_BRMU,
KC_INSERT,
KC_INS,
KC_HOME,
KC_PGUP,
KC_DELETE,
KC_DEL,
KC_END,
KC_PGDOWN,
KC_PGDN,
KC_RIGHT,
KC_RGHT,
KC_LEFT,
KC_DOWN,
KC_UP,
KC_NUMLOCK,
KC_NLCK,
KC_KP_SLASH,
KC_PSLS,
KC_KP_ASTERISK,
KC_PAST,
KC_KP_MINUS,
KC_PMNS,
KC_KP_PLUS,
KC_PPLS,
KC_KP_ENTER,
KC_PENT,
KC_KP_1,
KC_P1,
KC_KP_2,
KC_P2,
KC_KP_3,
KC_P3,
KC_KP_4,
KC_P4,
KC_KP_5,
KC_P5,
KC_KP_6,
KC_P6,
KC_KP_7,
KC_P7,
KC_KP_8,
KC_P8,
KC_KP_9,
KC_P9,
KC_KP_0,
KC_P0,
KC_KP_DOT,
KC_PDOT,
KC_NONUS_BSLASH,
KC_NUBS,
KC_APPLICATION,
KC_APP,
KC_POWER,
KC_KP_EQUAL,
KC_PEQL,
KC_F13,
KC_F14,
KC_F15,
KC_F16,
KC_F17,
KC_F18,
KC_F19,
KC_F20,
KC_F21,
KC_F22,
KC_F23,
KC_F24,
KC_EXECUTE,
KC_EXEC,
KC_HELP,
KC_MENU,
KC_SELECT,
KC_SLCT,
KC_STOP,
KC_AGAIN,
KC_AGIN,
KC_UNDO,
KC_CUT,
KC_COPY,
KC_PASTE,
KC_PSTE,
KC_FIND,
KC__MUTE,
KC__VOLUP,
KC__VOLDOWN,
KC_LOCKING_CAPS,
KC_LCAP,
KC_LOCKING_NUM,
KC_LNUM,
KC_LOCKING_SCROLL,
KC_LSCR,
KC_KP_COMMA,
KC_PCMM,
KC_KP_EQUAL_AS400,
KC_INT1,
KC_RO,
KC_INT2,
KC_KANA,
KC_INT3,
KC_JYEN,
KC_INT4,
KC_HENK,
KC_INT5,
KC_MHEN,
KC_INT6,
KC_INT7,
KC_INT8,
KC_INT9,
KC_LANG1,
KC_HAEN,
KC_LANG2,
KC_HANJ,
KC_LANG3,
KC_LANG4,
KC_LANG5,
KC_LANG6,
KC_LANG7,
KC_LANG8,
KC_LANG9,
KC_ALT_ERASE,
KC_ERAS,
KC_SYSREQ,
KC_CANCEL,
KC_CLEAR,
KC_CLR,
KC_PRIOR,
KC_RETURN,
KC_SEPARATOR,
KC_OUT,
KC_OPER,
KC_CLEAR_AGAIN,
KC_CRSEL,
KC_EXSEL,
KC_LCTRL,
KC_LCTL,
KC_LSHIFT,
KC_LSFT,
KC_LALT,
KC_LGUI,
KC_LCMD,
KC_LWIN,
KC_RCTRL,
KC_RCTL,
KC_RSHIFT,
KC_RSFT,
KC_RALT,
KC_ALGR,
KC_RGUI,
KC_RCMD,
KC_RWIN,
KC_SYSTEM_POWER,
KC_PWR,
KC_SYSTEM_SLEEP,
KC_SLEP,
KC_SYSTEM_WAKE,
KC_WAKE,
KC_AUDIO_MUTE,
KC_MUTE,
KC_AUDIO_VOL_UP,
KC_VOLU,
KC_AUDIO_VOL_DOWN,
KC_VOLD,
KC_MEDIA_NEXT_TRACK,
KC_MNXT,
KC_MEDIA_PREV_TRACK,
KC_MPRV,
KC_MEDIA_STOP,
KC_MSTP,
KC_MEDIA_PLAY_PAUSE,
KC_MPLY,
KC_MEDIA_SELECT,
KC_MSEL,
KC_MEDIA_EJECT,
KC_EJCT,
KC_MAIL,
KC_CALCULATOR,
KC_CALC,
KC_MY_COMPUTER,
KC_MYCM,
KC_WWW_SEARCH,
KC_WSCH,
KC_WWW_HOME,
KC_WHOM,
KC_WWW_BACK,
KC_WBAK,
KC_WWW_FORWARD,
KC_WFWD,
KC_WWW_STOP,
KC_WSTP,
KC_WWW_REFRESH,
KC_WREF,
KC_WWW_FAVORITES,
KC_WFAV,
KC_MEDIA_FAST_FORWARD,
KC_MFFD,
KC_MEDIA_REWIND,
KC_MRWD,
KC_BRIGHTNESS_UP,
KC_BRIU,
KC_BRIGHTNESS_DOWN,
KC_BRID,
KC_GESC,
KC_LSPO,
KC_RSPC,
KC_LCPO,
KC_RCPC,
KC_LAPO,
KC_RAPC,
KC_SFTENT,
KC_LEAD,
KC_LOCK,
KC_TRNS,
KC_MS_UP,
KC_MS_U,
KC_MS_DOWN,
KC_MS_D,
KC_MS_LEFT,
KC_MS_L,
KC_MS_RIGHT,
KC_MS_R,
KC_MS_BTN1,
KC_BTN1,
KC_MS_BTN2,
KC_BTN2,
KC_MS_BTN3,
KC_BTN3,
KC_MS_BTN4,
KC_BTN4,
KC_MS_BTN5,
KC_BTN5,
KC_MS_WH_UP,
KC_WH_U,
KC_MS_WH_DOWN,
KC_WH_D,
KC_MS_WH_LEFT,
KC_WH_L,
KC_MS_WH_RIGHT,
KC_WH_R,
KC_MS_ACCEL0,
KC_ACL0,
KC_MS_ACCEL1,
KC_ACL1,
KC_MS_ACCEL2,
KC_ACL2,
KC_MEH,
KC_HYPR,
KC_TILDE,
KC_TILD,
KC_EXCLAIM,
KC_EXLM,
KC_AT,
KC_HASH,
KC_DOLLAR,
KC_DLR,
KC_PERCENT,
KC_PERC,
KC_CIRCUMFLEX,
KC_CIRC,
KC_AMPERSAND,
KC_AMPR,
KC_ASTERISK,
KC_ASTR,
KC_LEFT_PAREN,
KC_LPRN,
KC_RIGHT_PAREN,
KC_RPRN,
KC_UNDERSCORE,
KC_UNDS,
KC_PLUS,
KC_LEFT_CURLY_BRACE,
KC_LCBR,
KC_RIGHT_CURLY_BRACE,
KC_RCBR,
KC_PIPE,
KC_COLON,
KC_COLN,
KC_DOUBLE_QUOTE,
KC_DQUO,
KC_DQT,
KC_LEFT_ANGLE_BRACKET,
KC_LABK,
KC_LT,
KC_RIGHT_ANGLE_BRACKET,
KC_RABK,
KC_GT,
KC_QUESTION,
KC_QUES
*/
