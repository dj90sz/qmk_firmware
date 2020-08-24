#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layers {
  _BASE,
  _NUMBERS,
  _SYMBOLS,
  _NAV,
  _FUNC,
  _NAVMOUSE,
};

enum custom_keycodes {
  CTL_CIRC = SAFE_RANGE,
  ALT_AMPR,
  SFT_ASTR,
  GUI_LPRN,
  SFT_RPRN,
  ALT_COLN
};


// Thumb mod/layer taps
#define NUM_SPC LT(_NUMBERS, KC_SPC)
#define NAV_ESC LT(_NAV, KC_ESC)
#define FUN_ENT LT(_FUNC, KC_ENT)
#define SYM_BSPC LT(_SYMBOLS, KC_BSPC)
#define GUI_DEL LGUI_T(KC_DEL)

// Homerow Mods
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define SFT_D MT(MOD_LSFT, KC_D)
#define GUI_F MT(MOD_LGUI, KC_F)
#define GUI_J MT(MOD_RGUI, KC_J)
#define SFT_K MT(MOD_RSFT, KC_K)
#define ALT_L MT(MOD_RALT, KC_L)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOT)

#define CTL_6 MT(MOD_LCTL, KC_6)
#define ALT_7 MT(MOD_LALT, KC_7)
#define SFT_8 MT(MOD_LSFT, KC_8)
#define GUI_9 MT(MOD_LGUI, KC_9)
#define CTL_SCLN MT(MOD_RCTL, KC_SCLN)

#define CTL_F6 MT(MOD_LCTL, KC_F6)
#define ALT_F7 MT(MOD_LALT, KC_F7)
#define SFT_F8 MT(MOD_LSFT, KC_F8)
#define GUI_F9 MT(MOD_LGUI, KC_F9)
#define GUI_MPLY MT(MOD_RGUI, KC_MPLY)
#define SFT_MRWD MT(MOD_RSFT, KC_MRWD)
#define ALT_MFFD MT(MOD_RALT, KC_MFFD)


// GUI + BSLS for password manager
#define GUI_BSLS LGUI(KC_BSLS)

// GUI + Arrows
#define GUI_LEFT LGUI(KC_LEFT)
#define GUI_DOWN LGUI(KC_DOWN)
#define GUI_UP LGUI(KC_UP)
#define GUI_RGHT LGUI(KC_RGHT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, GUI_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_GRV,   CTL_A,   ALT_S,   SFT_D,   GUI_F,    KC_G,                         KC_H,   GUI_J,   SFT_K,   ALT_L,CTL_QUOT, KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, NUM_SPC, NAV_ESC,    FUN_ENT,SYM_BSPC, GUI_DEL \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   CTL_6,   ALT_7,   SFT_8,   GUI_9,    KC_0,                       KC_EQL,GUI_LPRN,SFT_RPRN,ALT_COLN,CTL_SCLN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, XXXXXXX, KC_MINS, KC_PLUS,  KC_DOT,                      KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX,  KC_ESC,     KC_ENT, KC_BSPC, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,CTL_CIRC,ALT_AMPR,SFT_ASTR,GUI_LPRN, KC_RPRN,                       KC_EQL,GUI_LPRN,SFT_RPRN,ALT_COLN,CTL_SCLN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, XXXXXXX, KC_MINS, KC_PLUS,  KC_DOT,                      KC_UNDS, KC_LBRC, KC_RBRC, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  KC_SPC,  KC_ESC,     KC_ENT, XXXXXXX, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,                      XXXXXXX, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, GUI_LEFT,GUI_DOWN, GUI_UP,GUI_RGHT, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  KC_SPC, XXXXXXX,     KC_ENT, KC_BSPC, _______ \
                                      //`--------------------------'  `--------------------------'
  ),


  [_FUNC] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  CTL_F6,  ALT_F7,  SFT_F8,  GUI_F9,  KC_F10,                      XXXXXXX,GUI_MPLY,SFT_MRWD,ALT_MFFD, KC_RCTL, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12,                      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  KC_SPC,  KC_ESC,    XXXXXXX, KC_BSPC, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVMOUSE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, GUI_LEFT,GUI_DOWN, GUI_UP,GUI_RGHT, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,    KC_BTN1, KC_BTN3, KC_BTN2 \
                                      //`--------------------------'  `--------------------------'
  )
};



int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

static uint16_t mod_tap_custom_timer[6] = { 0, 0, 0, 0, 0, 0 };

void mod_type(uint16_t modcode, uint16_t keycode) {
  register_mods(MOD_BIT(modcode));
  register_code(keycode);
  unregister_code(keycode);
  unregister_mods(MOD_BIT(modcode));
}

void handle_custom_mod_tap(bool pressed, uint16_t modcode, uint16_t keycode, int timerIndex) {
  if (pressed) {
    mod_tap_custom_timer[timerIndex] = timer_read();
    register_mods(MOD_BIT(modcode));
  }
  else {
    unregister_mods(MOD_BIT(modcode));
    if (timer_elapsed(mod_tap_custom_timer[timerIndex]) < TAPPING_TERM) {
      mod_type(KC_LSFT, keycode);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch(keycode){
    case CTL_CIRC: {
      handle_custom_mod_tap(record->event.pressed, KC_LCTL, KC_CIRC, 0);
      return false;
    }
    case ALT_AMPR: {
      handle_custom_mod_tap(record->event.pressed, KC_LALT, KC_AMPR, 1);
      return false;
    }
    case SFT_ASTR: {
      handle_custom_mod_tap(record->event.pressed, KC_LSFT, KC_ASTR, 2);
      return false;
    }
    case GUI_LPRN: {
      handle_custom_mod_tap(record->event.pressed, KC_RGUI, KC_LPRN, 3);
      return false;
    }
    case SFT_RPRN: {
      handle_custom_mod_tap(record->event.pressed, KC_RSFT, KC_RPRN, 4);
      return false;
    }
    case ALT_COLN: {
      handle_custom_mod_tap(record->event.pressed, KC_RALT, KC_COLN, 5);
      return false;
    }
  }

  return true;
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_A:
        case ALT_S:
        case SFT_D:
        case GUI_F:
        case GUI_J:
        case SFT_K:
        case ALT_L:
        case CTL_QUOT:
        case CTL_6:
        case ALT_7:
        case SFT_8:
        case GUI_9:
        case CTL_SCLN:
        case CTL_F6:
        case ALT_F7:
        case SFT_F8:
        case GUI_F9:
        case GUI_MPLY:
        case SFT_MRWD:
        case ALT_MFFD:
            return true;
        default:
            return false;
    }
}