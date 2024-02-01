/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SYM,
  _LFN,   
  _ADJUST
};

// Layer Aliases 
#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define SPCSYM  LT(_SYM, KC_SPC)
#define LFN     MO(_LFN)

// Key aliases for legibility
#define ___x___ KC_NO

// NOTE keep keycode names strictly under 8 characters

// macOS shortcuts
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))
#define INDENT LGUI(KC_RBRC)    
#define OUTDENT LGUI(KC_LBRC)
#define SWAPUP G(C(KC_UP))
#define SWAPDN G(C(KC_DOWN))
#define COPYUP A(S(KC_UP))
#define COPYDN S(G(KC_D))
#define CURSUP C(S(KC_UP))
#define CURSDN C(S(KC_DOWN))
#define CMMTL G(KC_SLSH) // Toggle Line comment
#define CMMTB A(G(KC_SLSH)) // Toggle Block comment

// Browser Nav
#define NTAB A(G(KC_RGHT)) 
#define PTAB A(G(KC_LEFT))
#define WFWD G(KC_RBRC) 
#define WBAK G(KC_LBRC)

// screen capture
//#define KC_CAPW // Capture the whole screen
//#define KC_CAPA //Capture active window
//#define KC_CAPP // Capture portion of the screen (The mouse cursor selection box)

// Special Chars for Symbol Layer : These depend on MacOS
// TODO: add unicode support.
#define ES_EXC  A(KC_1)        // spanish inverted exclamation point
#define ES_QUE  LSA(KC_SLSH)     // spanish inverted question mark 
#define DE_SECT A(KC_6)       // german/euro/legal section mark
#define LGUIL   A(KC_BSLS)    // german left double guillemet
#define RGUIL   S(A(KC_BSLS))    // german left double guillemet
#define EU_EURO S(A(KC_2))   // euro currency
#define EU_GBP  A(KC_3)      // GBP currency
#define SC_DEG  LSA(KC_8)      // degrees
#define KC_APPL  LSA(KC_K)      // Apple symbol
#define UNI_BANG HYPR(KC_F11)      // Unicode Interrobang shortcut needs 

// Mod Taps                            
// -------------------                 
#define HYPTAB  HYPR_T(KC_TAB)  //Hyper (Left Control, Shift, Alt and GUI)
#define HYPDEL  HYPR_T(KC_DEL)  //Hyper (Left Control, Shift, Alt and GUI)
#define MEHESC  MEH_T(KC_ESC)  //Meh (Left Control, Shift, and Alt)
#define CAGGRV  LCAG_T(KC_GRV)
#define RS_ENT  LSFT_T(KC_ENT)   

// Preonic Number Row
#define PR_1 C_S_T(KC_1)
#define PR_2 LSA_T(KC_2)
#define PR_3 LSG_T(KC_3)
#define PR_4 MT(MOD_LSFT | MOD_LALT | MOD_LGUI, KC_4) 
#define PR_5 MT(MOD_LSFT | MOD_LCTL | MOD_LGUI, KC_5)
#define PR_6 MEH_T(KC_6)
#define PR_7 LCAG_T(KC_7)
#define PR_8 LAG_T(KC_8)
#define PR_9 LCA_T(KC_9)
#define PR_0 MT(MOD_LGUI | MOD_LCTL, KC_0)


// Special Use Combos 
#define WINCAD   C(A(KC_DEL))  // Control Alt Delete for Win Logins

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty */
[_QWERTY] = LAYOUT_preonic_grid(
CAGGRV,  PR_1,    PR_2,    PR_3,    PR_4,  PR_5,   PR_6,   PR_7,  PR_8,    PR_9,    PR_0,     HYPDEL,
HYPTAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,     KC_BSPC,
MEHESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  RS_ENT,
LFN,     KC_LCTL, KC_LOPT, KC_LGUI, LOWER, SPCSYM, SPCSYM, RAISE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),
/* Lower */
[_LOWER] = LAYOUT_preonic_grid(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,   _______,
KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_RPRN,  KC_BSPC,
_______, ES_EXC,  KC_NUBS, ES_QUE,  EU_EURO, KC_NDSH, KC_MDSH, KC_UNDS, KC_PLUS, KC_LBRC,   KC_RBRC,  KC_PIPE,
_______, UNI_BANG,SC_DEG,  KC_APPL, EU_GBP,  LGUIL,   RGUIL,   KC_MINS, KC_EQL,  G(KC_DOWN),G(KC_UP), _______,
_______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, OUTDENT, KC_PGDN,   KC_PGUP,  INDENT
),
/* Raise */
[_RAISE] = LAYOUT_preonic_grid(
_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  ___x___, _______,
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_NUBS, KC_LCBR, KC_RCBR, _______,
_______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, PTAB,    WBAK,    WFWD,    NTAB
),
/* Symbolic Code Manipulation */
[_SYM] = LAYOUT_preonic_grid(
_______, _______, _______, _______, _______, KC_LABK, KC_RABK, _______, _______, _______, _______, _______,
___x___, _______, _______, _______, _______, KC_LPRN, KC_RPRN, ___x___, ___x___, ___x___, ___x___, ___x___,
___x___, ___x___, ___x___, ___x___, ___x___, KC_LCBR, KC_RCBR, ___x___, ___x___, CURSDN,  CURSUP, ___x___,
_______, ___x___, CMMTB,   CMMTL,   ___x___, KC_LBRC, KC_RBRC, ___x___, ___x___, COPYDN,  COPYUP, _______,
___x___, _______, _______, _______, _______, _______, _______, _______, OUTDENT, SWAPDN,  SWAPUP,  INDENT
),
/* FUNCTIONs */
[_LFN] = LAYOUT_preonic_grid(       
_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
G(KC_TILD),    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  WINCAD,
G(S(KC_TILD)), KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______, _______,
_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______,       _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MUTE, KC_MPLY, KC_MFFD
),
/*---Trilayers---*/
/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_preonic_grid(
RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,
KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
_______, _______, _______, _______, _______, _______, _______, _______, ___x___, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, ___x___, ___x___, _______, _______, KC_BRID, KC_BRIU, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  /*
  state = update_tri_layer_state(state, _HYPER, _RAISE, _SUPER);
  state = update_tri_layer_state(state, _HYPER, _LOWER, _HACKER);
  state = update_tri_layer_state(state, _SUPER, _LOWER, _OMEGA);
  state = update_tri_layer_state(state, _GREEK, _ADJUST,_DELTA);
  state = update_tri_layer_state(state, _OMEGA, _GREEK, _ALPHA);
  state = update_tri_layer_state(state, _SUPER, _GREEK, _THETA);
  state = update_tri_layer_state(state, _HACKER,_GREEK, _GAMMA);
  */
  return state;
}
