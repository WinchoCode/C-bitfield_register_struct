#include "exercises/exercise1/exercise1.h"
#include "exercises/exercise2/exercise2.h"
#include "exercises/exercise3/exercise3.h"
#include <stdint.h>
#include <stdio.h>

void call_exercise1(void);
void call_exercise2(void);
void call_exercise3(void);

int main(void) {
  printf("This program is intended to demonstrate the use of bitfield register "
         "structs.\n");
  printf("It contains only 3 exercises that you can call by typing 1 or 2. You "
         "can also type 0 to exit the program.\n");
  int choice = -1;
  while (choice != 0) {
    printf("Bitfield register structs exercises menu:\n");
    printf("1. Simple Status Register\n");
    printf("2. Bit Control Register With Unions\n");
    printf("3. Full Peripheral Register Map\n");
    printf("Enter exercise number to run or 0 to exit: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      call_exercise1();
      break;
    case 2:
      call_exercise2();
      break;
    case 3:
      call_exercise3();
      break;
    case 0:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }

  return 0;
}

void call_exercise1(void) {
  status_reg_t reg = {0};

  set_mode_exercise1(&reg, 1);
  reg.error = 1;

  print_status_exercise1(reg);
}

void call_exercise2(void) {
  control_reg_t reg = {0};

  set_speed(&reg, 10);
  enable_device(&reg, 1);
  set_interrupt(&reg, 1);
  set_priority(&reg, 2);

  print_control_reg(reg);
}

void call_exercise3(void) {
  peripheral_reg_t peripheral;

  int choice = -1;

  while (choice != 0) {
    printf("Exercise 3 Menu:\n");
    printf("1. Initialize Peripheral\n");
    printf("2. Start Peripheral\n");
    printf("3. Print Peripheral Status\n");
    printf("4. Set Peripheral Speed\n");
    printf("5. Set Peripheral Mode\n");
    printf("6. Reset Peripheral\n");
    printf("7. Enable Peripheral\n");
    printf("8. Disable Peripheral\n");
    printf("9. Read Peripheral Data\n");
    printf("10. Write Peripheral Data\n");
    printf("0. Exit Exercise 3\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      initialize_peripheral(&peripheral);
      print_peripheral_status(&peripheral);
      break;
    case 2:
      start_peripheral(&peripheral);
      print_peripheral_status(&peripheral);
      break;
    case 3:
      print_peripheral_status(&peripheral);
      break;
    case 4: {
      int speed;
      printf("Enter speed (0-15): ");
      scanf("%d", &speed);
      peripheral.config_reg.speed = speed;
      set_peripheral_speed(&peripheral, speed);
      print_peripheral_status(&peripheral);
      break;
    }
    case 5: {
      int mode;
      printf("Enter mode (0-3): ");
      scanf("%d", &mode);
      peripheral.config_reg.mode = mode;
      set_peripheral_mode(&peripheral, mode);
      print_peripheral_status(&peripheral);
      break;
    }
    case 6:
      reset_peripheral(&peripheral);
      print_peripheral_status(&peripheral);
      break;
    case 7:
      enable_peripheral(&peripheral, 1);
      print_peripheral_status(&peripheral);
      break;
    case 8:
      disable_peripheral(&peripheral);
      print_peripheral_status(&peripheral);
      break;
    case 9:
      read_peripheral_data(&peripheral);
      break;
    case 10: {
      uint32_t data;
      printf("Enter data to write: ");
      scanf("%u", &data);
      peripheral.data = data;
      write_peripheral_data(&peripheral, 1234);
      print_peripheral_status(&peripheral);
      break;
    }
    case 0:
      printf("Exiting Exercise 3.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }
}