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
#define CMMTL G(KC_SLSH) // Toggle Line comment
#define CMMTB A(G(KC_SLSH)) // Toggle Block comment

// Browser Nav
#define NEXTTB A(G(KC_RGHT)) 
#define PREVTB A(G(KC_LEFT))
#define WFWD G(KC_RBRC) 
#define WBAK G(KC_LBRC)

// Special Chars for Symbol Layer : These depend on MacOS
// TODO: add unicode support.
#define ES_EXC  A(KC_1)        // spanish inverted exclamation point
#define ES_QUE  LSA(KC_SLSH)     // spanish inverted question mark 
#define DE_SECT A(KC_6)       // german/euro/legal section mark
#define L_GUIL   A(KC_BSLS)    // german left double guillemet
#define R_GUIL   S(A(KC_BSLS))    // german left double guillemet
#define EU_EURO S(A(KC_2))   // euro currency
#define EU_GBP  A(KC_3)      // GBP currency
#define SC_DEG  LSA(KC_8)      // degrees
#define KC_APPL  LSA(KC_K)      // Apple symbol
#define KM_BANG HYPR(KC_F11)      // KM Hotkey; otherwise Interrobang needs Unasicode support on-keyboard
#define KC_INF  A(KC_5)      // Infinity
#define KC_SEC  A(KC_6)      // German Section marker

// Mod Taps                            
// -------------------          
//Hyper (Left Control, Shift, Alt and GUI) plus...       
#define HYPTAB  HYPR_T(KC_TAB)  
#define HYPDEL  HYPR_T(KC_DEL)  
#define HYPBSP  HYPR_T(KC_BSPC)
//Meh (Left Control, Shift, and Alt) plus... 
#define MEHESC  MEH_T(KC_ESC)  
#define CAGGRV  LCAG_T(KC_GRV) 
#define CAGDEL  LCAG_T(KC_DEL)  
#define RS_ENT  LSFT_T(KC_ENT)  
//#define LS_ENT  LSFT_T(KC_ENT)  
#define LS_ENT  MT(MOD_LSFT, KC_ENT) 

// Number Row
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


// Special Combos 
#define WINCAD   C(A(KC_DEL))  // Control Alt Delete for Win Logins

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty */
[_QWERTY] = LAYOUT_preonic_grid(
CAGGRV,  PR_1,    PR_2,    PR_3,    PR_4,  PR_5,   PR_6,   PR_7,  PR_8,    PR_9,    PR_0,    CAGDEL,
HYPTAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    HYPBSP,
MEHESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
LFN,     KC_LCTL, KC_LALT, KC_LGUI, LOWER, SPCSYM, SPCSYM, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower */
[_LOWER] = LAYOUT_preonic_grid(
KC_BSPC, ES_EXC,    ES_QUE,     EU_GBP,     EU_EURO,    KC_INF,     KC_SEC,     KM_BANG, SC_DEG,  L_GUIL,  R_GUIL,  _______,
KC_TILD, KC_EXLM,   KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
KC_TAB,  PREVTB,    WBAK,       WFWD,       NEXTTB,     KC_NDSH,    KC_MDSH,    KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,
KC_ENT,  HYPR(KC_Z),HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______,
_______, _______,   _______,    _______,    _______,    _______,    _______,    _______, OUTDENT, KC_PGDN, KC_PGUP, INDENT
),

/* Raise */
[_RAISE] = LAYOUT_preonic_grid(
KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
KC_TAB,  KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
KC_ENT,  _______, _______, _______, _______, _______, _______, _______, KC_NUBS, KC_LCBR, KC_RCBR, _______,
_______, _______, _______, _______, _______, _______, _______, _______, PREVTB,  WBAK,    WFWD,    NEXTTB
),
/* Symbolic Code Manipulation */
[_SYM] = LAYOUT_preonic_grid(
_______, _______, _______, _______, _______, KC_LABK, KC_RABK, _______, _______, _______, _______, _______,
___x___, _______, _______, _______, _______, KC_LPRN, KC_RPRN, ___x___, ___x___, ___x___, ___x___, ___x___,
___x___, ___x___, ___x___, ___x___, ___x___, KC_LCBR, KC_RCBR, ___x___, ___x___, _______, _______, ___x___,
_______, ___x___, CMMTB,   CMMTL,   ___x___, KC_LBRC, KC_RBRC, ___x___, ___x___, _______, _______, _______,
___x___, _______, _______, _______, _______, _______, _______, _______, OUTDENT, _______, _______,  INDENT
),
/* FUNCTIONs */
[_LFN] = LAYOUT_ortho_5x12(       
_______,       G(KC_F1),   G(KC_F2),  G(KC_F3),  G(KC_F4),  G(KC_F5),  G(KC_F6),  G(KC_F7),  G(KC_F8),  G(KC_F9),  G(KC_F10), _______,
G(KC_TILD),    KC_F1,      KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    WINCAD,
G(S(KC_TILD)), KC_F11,     KC_F12,    KC_F13,    KC_F14,    KC_F15,    KC_F16,    KC_F17,    KC_F18,    KC_F19,    _______,   _______,
KC_ENT,        G(KC_F11),  G(KC_F12), G(KC_F13), G(KC_F14), G(KC_F15), G(KC_F16), G(KC_F17), G(KC_F18), G(KC_F19), _______,   _______,
_______,       _______,    _______,   _______,   _______,   _______,   _______,   _______,   KC_MRWD,   KC_MUTE,   KC_MPLY,   KC_MFFD
),

/* Adjust */
[_ADJUST] = LAYOUT_ortho_5x12(
RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,
KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MUTE, KC_MPLY, KC_MFFD
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
