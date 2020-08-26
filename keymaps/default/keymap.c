#include "kb.h"

enum layers {
	_NUMPAD = 0,
	_NAVIGATION,
	_SPECTACLE,
	_PREF,
};

enum custom_keycodes {
	M_SP_FULL = SAFE_RANGE,
	M_SP_LEFT,
	M_SP_RIGHT,
	M_SP_UP,
	M_SP_DOWN,
	M_SP_UPLEFT,
	M_SP_UPRIGHT,
	M_SP_DNLEFT,
	M_SP_DNRIGHT,
	M_SP_LARGER,
	M_SP_SMALLER,
	M_SP_NEXTDSPL,
	M_SP_PREVDSPL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Numpad
	 * ,---------------------------.
	 * |   7  |   8  |   9  |   *  |
	 * |------+------+------+------|
	 * |   4  |   5  |   6  |   +  |
	 * |------+------+------+------|
	 * |   1  |   2  |   3  |   -  |
	 * |------+------+------+------|
	 * |   0  |   .  |   =  |  (/) |
	 * `---------------------------'
	 */
	[_NUMPAD] = KEYMAP(
		KC_P7, KC_P8, KC_P9, KC_PAST,
		KC_P4, KC_P5, KC_P6, KC_PPLS,
		KC_P1, KC_P2, KC_P3, KC_PMNS,
		KC_P0, KC_PDOT, KC_PEQL, LT(_PREF, KC_PSLS)
	),

	/* Navigation
	 * ,---------------------------.
	 * | Home | Tab  | PgUp |      |
	 * |------+------+------+------|
	 * | End  |  Up  | PgDn |      |
	 * |------+------+------+------|
	 * | Left | Down |Right |Shift |
	 * |------+------+------+------|
	 * |  Alt |  Cmd |      |  ()  |
	 * `---------------------------'
	 */
	[_NAVIGATION] = KEYMAP(
		KC_HOME, KC_TAB, KC_PGUP, XXXXXXX,
		KC_END, KC_UP, KC_PGDN, XXXXXXX,
		KC_LEFT, KC_DOWN, KC_RIGHT, KC_LSFT,
		KC_LALT, KC_LGUI, XXXXXXX, LT(_PREF, XXXXXXX)
	),

	/* Spectacle
	 * ,---------------------------.
	 * | uLeft|  Up  | uRght| Lrgr |
	 * |------+------+------+------|
	 * | Left | Full | Rght | Smlr |
	 * |------+------+------+------|
	 * | lLeft| Down | lRght|      |
	 * |------+------+------+------|
	 * | Full |PrvDsp|NxtDsp|  ()  |
	 * `---------------------------'
	 */
	[_SPECTACLE] = KEYMAP(
		M_SP_UPLEFT, M_SP_UP, M_SP_UPRIGHT, M_SP_LARGER,
		M_SP_LEFT, M_SP_FULL, M_SP_RIGHT, M_SP_SMALLER,
		M_SP_DNLEFT, M_SP_DOWN, M_SP_DNRIGHT, XXXXXXX,
		M_SP_FULL, M_SP_PREVDSPL, M_SP_NEXTDSPL, LT(_PREF, XXXXXXX)
	),

	/* Preferences
	 * ,---------------------------.
	 * |AuTog |      |      |Reset |
	 * |------+------+------+------|
	 * |CkTog |CkDwn |CkUp  |      |
	 * |------+------+------+------|
	 * |MuTog |MuMod |      |      |
	 * |------+------+------+------|
	 * |Numpad|Nvgtn |Spctcl|      |
	 * `---------------------------'
	 */
	[_PREF] = KEYMAP(
		AU_TOG, XXXXXXX, XXXXXXX, RESET,
		CK_TOGG, CK_DOWN, CK_UP, XXXXXXX,
		MU_TOG, MU_MOD, XXXXXXX, XXXXXXX,
		TO(_NUMPAD), TO(_NAVIGATION), TO(_SPECTACLE), _______
	),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
		switch (keycode) {
			case M_SP_FULL:
			  	SEND_STRING(SS_LALT(SS_LGUI("f")));
			  break;
			case M_SP_LEFT:
			  	SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_LEFT))));
			  break;
			case M_SP_RIGHT:
			  	SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_RIGHT))));
			  break;
			case M_SP_UP:
			  	SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_UP))));
			  break;
			case M_SP_DOWN:
			  	SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_DOWN))));
			  break;
			case M_SP_UPLEFT:
			  	SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
			  break;
			case M_SP_UPRIGHT:
			  	SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RIGHT))));
			  break;
			case M_SP_DNLEFT:
			  	SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_LEFT)))));
			  break;
			case M_SP_DNRIGHT:
			  	SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_RIGHT)))));
			  break;
			case M_SP_LARGER:
			  	SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_RIGHT)))));
			  break;
			case M_SP_SMALLER:
			  	SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_LEFT)))));
			  break;
			case M_SP_NEXTDSPL:
			  	SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_RIGHT)))));
			  break;
			case M_SP_PREVDSPL:
			  	SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_LEFT)))));
		  	break;
		}
	}

	return true;
}
