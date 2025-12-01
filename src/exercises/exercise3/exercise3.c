#include <stdio.h>
#include "exercise3.h"

void print_config_reg(const volatile config_reg_t *config);
void print_full_status_reg(const volatile full_status_reg_t *status);

void initialize_peripheral(peripheral_reg_t *peripheral)
{
    peripheral->config_reg = (config_reg_t){0};
    peripheral->full_status_reg = (full_status_reg_t){0};
    peripheral->data = 0;
}

void start_peripheral(peripheral_reg_t *peripheral)
{
    peripheral->config_reg.enable = 1;
    peripheral->full_status_reg.busy = 1;
    peripheral->full_status_reg.complete = 0;
}

void print_peripheral_status(const peripheral_reg_t *peripheral)
{
    print_config_reg(&peripheral->config_reg);
    print_full_status_reg(&peripheral->full_status_reg);
    printf("Data: %u\n", peripheral->data);
}

void set_peripheral_speed(peripheral_reg_t *peripheral, unsigned speed)
{
    if (speed > 15) {
        printf("Invalid speed value. Speed must be between 0 and 15.\n");
        return;
    }
    
    peripheral->config_reg.speed = speed;
}

void set_peripheral_mode(peripheral_reg_t *peripheral, unsigned mode)
{
    if (mode > 3) {
        printf("Invalid mode value, mode must be between 0 and 3.\n");
        return;
    }
    
    peripheral->config_reg.mode = mode;
}

void reset_peripheral(peripheral_reg_t *peripheral)
{
    peripheral->config_reg.reset = 1;
    peripheral->full_status_reg.busy = 0;
    peripheral->full_status_reg.error = 0;
    peripheral->full_status_reg.complete = 0;
    peripheral->data = 0;
    peripheral->config_reg.reset = 0;
}

void enable_peripheral(peripheral_reg_t *peripheral, unsigned enable)
{
    peripheral->config_reg.enable = enable ? 1 : 0;
}

void disable_peripheral(peripheral_reg_t *peripheral)
{
    peripheral->config_reg.enable = 0;
}

void read_peripheral_data(const peripheral_reg_t *peripheral)
{
    printf("Peripheral Data: %u\n", peripheral->data);
}

void write_peripheral_data(peripheral_reg_t *peripheral, uint32_t data)
{
    peripheral->data = data;
}

void print_config_reg(const volatile config_reg_t *config)
{
    printf("Config Register:\n");
    printf("  Enable: %u\n", config->enable);
    printf("  Reset: %u\n", config->reset);
    printf("  Speed: %u\n", config->speed);
    printf("  Mode: %u\n", config->mode);
    printf("  Reserved: %u\n", config->reserved);
}

void print_full_status_reg(const volatile full_status_reg_t *status)
{
    printf("Full Status Register:\n");
    printf("  Busy: %u\n", status->busy);
    printf("  Error: %u\n", status->error);
    printf("  Complete: %u\n", status->complete);
    printf("  Reserved: %u\n", status->reserved);
}