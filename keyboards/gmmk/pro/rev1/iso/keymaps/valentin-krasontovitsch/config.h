#pragma once

/* Increase debounce time to prevent double-typing from switch bounce.
 * Default is 5ms; 8ms is more tolerant of worn or noisy switches. */
#define DEBOUNCE 10

/* Default RGB matrix configuration (applied on first boot or after EEPROM reset). */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE  191  // purple (~270° mapped to 0-255)
#define RGB_MATRIX_DEFAULT_SAT  255
#define RGB_MATRIX_DEFAULT_VAL  200
