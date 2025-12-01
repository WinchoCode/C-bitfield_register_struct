#include <stdio.h>
#include "exercise2.h"

void print_control_reg(control_reg_t reg) {
    printf("Control Register:\n");
    printf("  Speed: %u\n", reg.bits.speed);
    printf("  Enable: %u\n", reg.bits.enable);
    printf("  Interrupt: %u\n", reg.bits.interrupt);
    printf("  Priority: %u\n", reg.bits.priority);
    printf("  Reserved: %u\n", reg.bits.reserved);
}

void set_speed(control_reg_t *reg, unsigned speed) {
    if (speed < 16) { // speed is 4 bits, so valid values are 0-15
        reg->bits.speed = speed;
    }
}

void enable_device(control_reg_t *reg, unsigned enable) {
    reg->bits.enable = enable ? 1 : 0;
}

void set_interrupt(control_reg_t *reg, unsigned interrupt) {
    reg->bits.interrupt = interrupt ? 1 : 0;
}

void set_priority(control_reg_t *reg, unsigned priority) {
    if (priority < 4) { // priority is 2 bits, so valid values are 0-3
        reg->bits.priority = priority;
    }
}