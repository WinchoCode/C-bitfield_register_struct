#include <cstdint>
#include <stdint.h>

typedef struct {
    unsigned enable: 1;
    unsigned reset: 1;
    unsigned speed: 4;
    unsigned mode: 2;
    unsigned reserved: 8;
} config_reg_t;

typedef struct 
{
    unsigned busy: 1;
    unsigned error: 1;
    unsigned complete: 1;
    unsigned reserved: 13;
} full_status_reg_t ;

typedef struct {
    volatile config_reg_t config_reg;
    volatile full_status_reg_t full_status_reg;
    volatile uint32_t data;
} peripheral_reg_t;

void initialize_peripheral(peripheral_reg_t *peripheral);
void start_peripheral(peripheral_reg_t *peripheral);
void print_peripheral_status(const peripheral_reg_t *peripheral);
void set_peripheral_speed(peripheral_reg_t *peripheral, unsigned speed);
void set_peripheral_mode(peripheral_reg_t *peripheral, unsigned mode);
void reset_peripheral(peripheral_reg_t *peripheral);
void enable_peripheral(peripheral_reg_t *peripheral, unsigned enable);
void disable_peripheral(peripheral_reg_t *peripheral);
void read_peripheral_data(const peripheral_reg_t *peripheral);
void write_peripheral_data(peripheral_reg_t *peripheral, uint32_t data);
void print_config_reg(const config_reg_t *config);
void print_full_status_reg(const full_status_reg_t *status);
