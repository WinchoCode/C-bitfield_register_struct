#include "exercise1.h"

void print_status_exercise1(status_reg_t reg) {
  printf("Status Register:\n");
  printf("  Ready: %u\n", reg.ready);
  printf("  Error: %u\n", reg.error);
  printf("  Mode: %u\n", reg.mode);
  printf("  Reserved: %u\n", reg.reserved);
}

void set_mode_exercise1(status_reg_t *reg, unsigned mode) {
  if (mode < 4) { // mode is 2 bits, so valid values are 0-3
    reg->mode = mode;
  }
}