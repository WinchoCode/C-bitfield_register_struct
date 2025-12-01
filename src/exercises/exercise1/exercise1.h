#include <stdio.h>

typedef struct {
  unsigned ready : 1;
  unsigned error : 1;
  unsigned mode : 2;
  unsigned reserved : 4;
} status_reg_t;

void print_status_exercise1(status_reg_t reg);

void set_mode_exercise1(status_reg_t *reg, unsigned mode);