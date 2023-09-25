/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum unicode_names {
    ae,
    oe,
    aa,
    AE,
    OE,
    AA
};

const uint32_t PROGMEM unicode_map[] = {
    [ae]  = 0xE6,  // æ
    [oe] = 0xF8,  // ø
    [aa]  = 0xE5, // å
    [AE]  = 0xC6,  // Æ
    [OE] = 0xD8,  // Ø
    [AA]  = 0xC5, // Å
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, MO(2),   KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD,    KC_VOLU,    KC_F20,  _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, RESET,            _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,    XP(aa, AA), _______,                   _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, XP(oe, OE), XP(ae, AE), _______, _______,          _______,
        _______, _______, _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______,    _______,             _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______,    _______,    _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        G(KC_ESC),  G(KC_F1),   G(KC_F2),   G(KC_F3),   G(KC_F4),   G(KC_F5),   G(KC_F6),   G(KC_F7),   G(KC_F8),   G(KC_F9),   G(KC_F10),  G(KC_F11),  G(KC_F12),  G(KC_PSCR),            G(KC_MUTE),
        G(KC_GRV),  G(KC_1),    G(KC_2),    G(KC_3),    G(KC_4),    G(KC_5),    G(KC_6),    G(KC_7),    G(KC_8),    G(KC_9),    G(KC_0),    G(KC_MINS), G(KC_EQL),  G(KC_BSPC),            G(KC_DEL),
        G(KC_TAB),  G(KC_Q),    G(KC_W),    G(KC_E),    G(KC_R),    G(KC_T),    G(KC_Y),    G(KC_U),    G(KC_I),    G(KC_O),    G(KC_P),    G(KC_LBRC), G(KC_RBRC),                        G(KC_PGUP),
        G(KC_CAPS), G(KC_A),    G(KC_S),    G(KC_D),    G(KC_F),    G(KC_G),    G(KC_H),    G(KC_J),    G(KC_K),    G(KC_L),    G(KC_SCLN), G(KC_QUOT), G(KC_NUHS), G(KC_ENT),             G(KC_PGDN),
        G(KC_LSFT), G(KC_GRV),  G(KC_Z),    G(KC_X),    G(KC_C),    G(KC_V),    G(KC_B),    G(KC_N),    G(KC_M),    G(KC_COMM), G(KC_DOT),  G(KC_SLSH),             G(KC_RSFT), G(KC_UP),  G(KC_END),
        G(KC_LCTL), G(KC_LGUI), G(KC_LALT),                            G(KC_SPC),                                   G(KC_RALT), KC_NO,      G(KC_RCTL), G(KC_LEFT), G(KC_DOWN), G(KC_RGHT)
    ),


};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif

#ifdef RGB_MATRIX_ENABLE
void suspend_power_down_kb(void) {
      rgb_matrix_set_suspend_state(true);
          suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
      rgb_matrix_set_suspend_state(false);
          suspend_wakeup_init_user();
}
#endif // RGB_MATRIX_ENABLE

