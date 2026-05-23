#pragma once

/* ───────────────────────────────
 * Vial UID (REQUIRED)
 * Must be unique per keyboard
 * ─────────────────────────────── */
#define VIAL_KEYBOARD_UID { 0xAF, 0x32, 0x91, 0xB4, 0xC8, 0xD2, 0x77, 0xE1 }

/* ───────────────────────────────
 * Vial unlock combo
 * (hold these keys to unlock layout editing)
 * ─────────────────────────────── */
#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 2, 3 }

/* ───────────────────────────────
 * Tap / combo tuning
 * ─────────────────────────────── */
#define TAPPING_TERM 200
#define COMBO_TERM 35
#define COMBO_ONLY_FROM_LAYER 0

/* Better behavior for home-row mods */
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* Split behavior */
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE
