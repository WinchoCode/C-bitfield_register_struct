#include "exercises/exercise1/exercise1.h"
#include "exercises/exercise2/exercise2.h"
#include <stdio.h>

void call_exercise1(void);
void call_exercise2(void);

int main(void) {
  printf("This program is intended to demonstrate the use of bitfield register "
         "structs.\n");
  printf("It contains only 2 exercises that you can call by typing 1 or 2. You "
         "can also type 0 to exit the program.\n");
  int choice = -1;
  while (choice != 0) {
    printf("Enter exercise number to run (1 or 0 to exit): ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      call_exercise1();
      break;
    case 2:
      call_exercise2();
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