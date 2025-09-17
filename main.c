#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void trim_newline(char *str) {
  size_t len = strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}

int main() {
  const char *inventory[] = {
      "hydraulic pump",
      "PLC module",
      "servo motor",
  };
  const int inventory_size = 3;
  char input[100];

  printf("Hej. Welcome to the spare parts inventory!\n");

  while (1) {
    printf("which part do you need?");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }
    trim_newline(input);

    if (strcasecmp(input, "do you actually have any parts?") == 0) {
      printf("We have %d part(s)1\n", inventory_size);
      for (int i = 0; i < inventory_size; i++) {
        printf("%s\n", inventory[i]);
      }
      continue;
    }

    int found = 0;
    for (int i = 0; i < inventory_size; i++) {
      if (strcmp(input, inventory[i]) == 0) {
        printf("I've got %s here for you. bye!\n", inventory[i]);
        found = 1;
        break;
      }
    }

    if (found) {
      break;
    } else {
      printf("I am afraid we don't have any %s in the inventory\n", input);
    }
  }
  return 0;
}