/* PLANCK: Copyright 2015-2017 Jack Humbert
 *         Copyright 2016-2021 Steve Kuchta
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, can be used as ints in the keymap matrix.
// Can Also use builtin "enum" func to assign numbers, but I prefer the layer visibility

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FNAV,
  _JNAV,
  _ARW,
  _LFN,  
  _NUMPAD, 
  _ADJUST
};

// Layer Aliases 
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define SPCARW  LT(_ARW, KC_SPC)
#define LFN     MO(_LFN)

// Key aliases for legibility
#define ___x___ KC_NO

// NOTE keep keycode names strictly under 8 characters

// macOS shortcuts
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))
#define INDENT RGUI(KC_RBRC)
#define OUTDENT RGUI(KC_LBRC)
#define SWAPUP G(C(KC_UP))
#define SWAPDN G(C(KC_DOWN))

// screen capture
//#define KC_CAPW // Capture the whole screen
//#define KC_CAPA //Capture active window
//#define KC_CAPP // Capture portion of the screen (The mouse cursor selection box)

// Special Chars
// TODO: add unicode support.
#define ES_EXC  LOPT(KC_1)        // spanish inverted exclamation point
#define ES_QUE  LSA(KC_SLSH)     // spanish inverted question mark 
#define DE_SECT LOPT(KC_6)       // german/euro/legal section mark
#define EU_EURO LOPT(S(KC_2))   // euro currency

// Mod Taps                            //  Tap     Hold
// -------------------                 //  ------------------
#define HYPTAB  MT(MOD_HYPR, KC_TAB)   //  Tab     Hyper (Cmd+Ctrl+Alt+Shift) for L Hand
#define MEHESC  MT(MOD_MEH,  KC_ESC)   //  ESC     Meh (Ctrl+Alt+Shift), window mgmt > KM for L hand 
#define RS_ENT  MT(MOD_RSFT, KC_ENT)   //  Enter   RShift (this works ok; can't get LSHFT analog to work)

// L Hand HomeRow ModCombo-Taps:              //  Tap     Hold
// -------------------------------     //  ------------------
//#define CS_A   C_S_T(KC_A)             //  A       Ctrl+Shift
//#define SA_S   LSA_T(KC_S)             //  S       Alt+Shift
//#define SG_D   LSG_T(KC_D)             //  D       GUI+Shift
//#define SFT_F  LSFT_T(KC_F)            //  F       Shift
#define FNAV  LT(_FNAV, KC_F)

// R. Hand HomeRow ModCombo-Taps:        //  Tap     Hold
// note: using right modifiers will cause all modifiers to be created as R mods
// -------------------------------     //  ------------------
#define JNAV  LT(_JNAV, KC_J)
//#define SFT_J   LSFT_T(KC_J)           //  J       Shift
//#define CAG_K   LCAG_T(KC_K)           //  K       Ctrl+Alt+GUI
//#define AG_L    LAG_T(KC_L)            //  L       Alt+GUI
//#define CA_SC   LCA_T(KC_SCLN)         //  ;       Ctrl+Alt

// Special Use Combos 
#define WINCAD   C(A(KC_DEL))  // Control Alt Delete for Win Logins
#define PASTEX   S(A(G(KC_V))) // macOS native clean paste, no style
#define COPYHST  S(RCTL(KC_C)) // Clipboard History pane (some 3rd party)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty */
[_QWERTY] = LAYOUT_planck_grid(
    HYPTAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    MEHESC,  KC_A,    KC_S,    KC_D,    FNAV,  KC_G,   KC_H,   JNAV,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
    LFN,     KC_LCTL, KC_LOPT, KC_LGUI, LOWER, SPCARW, SPCARW, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Lower */  
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, ES_EXC,  DE_SECT, ES_QUE,  EU_EURO, KC_NDSH, KC_MDSH, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,
    KC_ENT,  ___x___, ___x___, COPYHST, PASTEX,  _______, _______, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, KC_DEL,  KC_DEL,  _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),
 /* Raise */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_ENT,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_NUHS, KC_NUBS, ___x___, ___x___, _______,
    _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______, _______, _______, _______, _______
),
/* Home Row, F activated, Right Hand navigation and shortcuts */
[_FNAV] = LAYOUT_planck_grid(
    ___x___, ___x___, ___x___, KC_WH_D, ___x___, KC_ENT,  KC_ENT,  KC_WH_R, KC_UP,   KC_WH_L, ___x___, ___x___,
    ___x___, ___x___, ___x___, KC_WH_U, _______, KC_BTN1, KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, ___x___,
    _______, ___x___, ___x___, ___x___, ___x___, KC_BTN3, KC_BTN4, ___x___, ___x___, ___x___, ___x___, _______,
    ___x___, _______, _______, _______, _______, ___x___, ___x___, _______, _______, _______, _______, _______
),
/* Home Row, J activated, Left Hand navigation and shortcuts */
[_JNAV] = LAYOUT_planck_grid(
    ___x___, ___x___, KC_WH_R, KC_UP,   KC_WH_L, KC_ENT,  KC_ENT,  ___x___, KC_WH_D, ___x___, ___x___, ___x___,
    ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_BTN1, KC_BTN2, _______, KC_WH_U, ___x___, ___x___, ___x___,
    _______, ___x___, ___x___, ___x___, ___x___, KC_BTN3, KC_BTN4, ___x___, ___x___, ___x___, ___x___, _______,
    ___x___, _______, _______, _______, _______, ___x___, ___x___, _______, _______, _______, _______, _______
),
/* Space Arrow navigation */
[_ARW] = LAYOUT_planck_grid(
    ___x___, ___x___, ___x___, KC_UP, ___x___,   KC_BTN1, KC_BTN2, ___x___, KC_UP,   ___x___, ___x___, ___x___,
    ___x___, ___x___, KC_LEFT, KC_DOWN, KC_RGHT, KC_BTN3, KC_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, ___x___, ___x___,
    _______, ___x___, ___x___, ___x___, ___x___, KC_ENT,  KC_ENT,  ___x___, ___x___, ___x___, ___x___, _______,
    ___x___, _______, _______, _______, _______, _______, _______, _______, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L
),
/* FUNCTIONs */
[_LFN] = LAYOUT_planck_grid(
    G(KC_TILD),    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  WINCAD,
    G(S(KC_TILD)), KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  _______, _______,
    KC_MUTE,       _______, _______, _______, _______, _______, _______, _______, KC_MRWD, _______, _______, KC_MFFD,
    _______,       _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT
),
/*---Trilayers---*/
/*Lower + LFunc = Numpad  */
[_NUMPAD] = LAYOUT_planck_grid(
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_CLR,  KC_P7, KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_P4, KC_P5,   KC_P6,   KC_PAST, KC_PEQL,
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_P1, KC_P2,   KC_P3,   KC_PMNS, KC_PENT,
    _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_COMM, KC_PDOT, KC_PPLS, ___x___
  ),
/* Adjust (Lower + Raise) */
[_ADJUST] = LAYOUT_planck_grid(
    KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, ___x___, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD,
    _______, _______, _______, _______, _______, ___x___, ___x___, _______, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER, _LFN, _NUMPAD);
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


