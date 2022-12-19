#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#include "bongo.h"
#endif

uint16_t last_key_down;

enum layers {
    _DF,
    _MC,
    _GM,
    _FN
};

enum custom_keycodes {
    TS_LBRC,
    TS_RBRC,
    TS_COMM,
    TS_DOT
};

// Windows
#define TSW_SAV C(KC_S)
#define TSW_END A(KC_F4)
#define TSW_CUT C(KC_X)
#define TSW_CPY C(KC_C)
#define TSW_PST C(KC_V)
#define TSW_LCK G(KC_L)

// Mac
#define TSM_SAV G(KC_S)
#define TSM_END G(KC_Q)
#define TSM_CUT G(KC_X)
#define TSM_CPY G(KC_C)
#define TSM_PST G(KC_V)
#define TSM_LCK G(C(KC_Q))

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DF] = LAYOUT(
        TSW_SAV,KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_GRV ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,TSW_END,
        TSW_CUT,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_LBRC,KC_RBRC,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,KC_DEL ,
        TSW_CPY,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,TS_LBRC,TS_RBRC,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_QUOT,KC_ENT ,KC_BSPC,
        TSW_PST,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_HOME,KC_END ,KC_N   ,KC_M   ,TS_COMM,TS_DOT ,KC_SLSH,KC_RSFT,KC_PSCR,
        TSW_LCK,KC_CAPS,KC_APP ,TO(_MC),MO(_FN),KC_LGUI,KC_LALT,KC_SPC ,KC_BSPC,MO(_FN),TG(_FN),KC_LOCK,TO(_GM),KC_MPLY,KC_MNXT,KC_MUTE
    ),
    [_MC] = LAYOUT(
        TSM_SAV,KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_GRV ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,TSM_END,
        TSM_CUT,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_LBRC,KC_RBRC,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,KC_DEL ,
        TSM_CPY,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,TS_LBRC,TS_RBRC,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_QUOT,KC_ENT ,KC_BSPC,
        TSM_PST,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_HOME,KC_END ,KC_N   ,KC_M   ,TS_COMM,TS_DOT ,KC_SLSH,KC_RSFT,KC_PSCR,
        TSM_LCK,KC_CAPS,KC_APP ,TO(_DF),MO(_FN),KC_LGUI,KC_LALT,KC_SPC ,KC_BSPC,MO(_FN),TG(_FN),KC_LOCK,TO(_GM),KC_MPLY,KC_MNXT,KC_MUTE
    ),
    [_GM] = LAYOUT(
        TSW_SAV,KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_MINS,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_LBRC,KC_RBRC,TSW_END,
        TSW_CUT,KC_TAB ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_EQL ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_SLSH,KC_DEL ,
        TSW_CPY,KC_LSFT,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_BSLS,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_QUOT,KC_ENT ,KC_BSPC,
        TSW_PST,KC_LCTL,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_HOME,KC_END ,KC_B   ,KC_N   ,KC_M   ,TS_COMM,TS_DOT ,KC_RSFT,KC_PSCR,
        TSW_LCK,KC_CAPS,KC_APP ,TO(_MC),MO(_FN),KC_LALT,KC_LALT,KC_SPC ,KC_BSPC,MO(_FN),TG(_FN),KC_LOCK,TO(_DF),KC_MPLY,KC_MNXT,KC_MUTE
    ),
    [_FN] = LAYOUT(
        QK_BOOT,_______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,_______,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,QK_BOOT,
        KC_NUM ,_______,_______,_______,KC_UP  ,_______,_______,_______,_______,KC_COMM,KC_P7  ,KC_P8  ,KC_P9  ,KC_PMNS,KC_PSLS,KC_NUM ,
        _______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,KC_PDOT,KC_P4  ,KC_P5  ,KC_P6  ,KC_PENT,KC_PAST,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_P0  ,KC_P1  ,KC_P2  ,KC_P3  ,KC_PPLS,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    )
};

// additional keypress checks
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // update last pressed key (for bongo)
    if (record->event.pressed && last_key_down != keycode) last_key_down = keycode;

    // save active mods
    uint16_t mods;
    mods = get_mods();

    // handle special keys
    switch (keycode) {
        case TS_LBRC: // ( <
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    register_code(KC_COMM);
                    unregister_code(KC_COMM);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_9);
                    unregister_code(KC_9);
                    unregister_code(KC_LSFT);
                }
            }
            return false;

        case TS_RBRC: // ) >
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    register_code(KC_DOT);
                    unregister_code(KC_DOT);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_0);
                    unregister_code(KC_0);
                    unregister_code(KC_LSFT);
                }
            }
            return false;

        case TS_COMM: // , ;
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                    set_mods(mods);
                } else {
                    register_code(KC_COMMA);
                    unregister_code(KC_COMMA);
                }
            }
            return false;

        case TS_DOT: // . :
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                } else {
                    register_code(KC_DOT);
                    unregister_code(KC_DOT);
                }
            }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE
// init OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_180 : OLED_ROTATION_270;
}

// update OLED output
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        draw_bongo(last_key_down != 0);
        last_key_down = 0;

    } else {
        // layer
        oled_write_ln_P(PSTR("LAYER"), false);
        oled_write_ln_P(PSTR("====="), false);
        switch (get_highest_layer(layer_state)) {
            case _DF:
                oled_write_ln_P(PSTR("WIN "), false);
                break;

            case _MC:
                oled_write_ln_P(PSTR("MAC "), false);
                break;

            case _GM:
                oled_write_ln_P(PSTR("Game"), false);
                break;

            case _FN:
                oled_write_ln_P(PSTR("FN  "), false);
                break;

            default:
                oled_write_ln_P(PSTR("N/A "), false);
        }

        // pad indicators
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR(""), false);

        // caps + num
        oled_write_ln_P(host_keyboard_led_state().num_lock  ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_ln_P(host_keyboard_led_state().caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    }

    return false;
}
#endif

#ifdef ENCODER_ENABLE
// rotary encoder mapping
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0: // undo / redo
            if (get_highest_layer(layer_state) == _MC) {
                register_code(KC_LCMD);
                if (clockwise) register_code(KC_LSFT);
                register_code(KC_Z);
                unregister_code(KC_Z);
                if (clockwise) unregister_code(KC_LSFT);
                unregister_code(KC_LCMD);                
            } else {
                register_code(KC_LCTL);
                register_code(clockwise ? KC_Y : KC_Z);
                unregister_code(clockwise ? KC_Y : KC_Z);
                unregister_code(KC_LCTL);
            }
            break;

        case 1: // mouse wheel up / down
            tap_code(clockwise ? KC_WH_U : KC_WH_D);
            break;

        case 2: // arrow up / down
            tap_code(clockwise ? KC_UP : KC_DOWN);
            break;

        case 5: // arrowleft / right
            tap_code(clockwise ? KC_RIGHT : KC_LEFT);
            break;

        case 4: // mouse wheel left / right
            tap_code(clockwise ? KC_WH_R : KC_WH_L);
            break;

        case 3: // page up / down
            tap_code(clockwise ? KC_PGUP : KC_PGDN);
            break;
    }
    return false;
}
#endif