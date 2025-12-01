#include <stdint.h>

typedef union
{
    uint16_t register_value;
    struct
    {
        unsigned speed: 4;
        unsigned enable: 1;
        unsigned interrupt: 1;
        unsigned priority: 2;
        unsigned reserved: 8;
    } bits;
} control_reg_t;

void print_control_reg(control_reg_t reg);
void set_speed(control_reg_t *reg, unsigned speed);
void enable_device(control_reg_t *reg, unsigned enable);
void set_interrupt(control_reg_t *reg, unsigned interrupt);
void set_priority(control_reg_t *reg, unsigned priority);