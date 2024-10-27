#include "lib/fskv.c"
#include <stdio.h>

int main() {
  // Set key-value pairs
  fskv_set("username", "ananda6851");
  fskv_set("password", "12345");
  fskv_set("email", "riju@gmail.com");

  // Get and print values by key
  printf("Username: %s\n", fskv_get("username"));
  printf("Password: %s\n", fskv_get("password"));
  printf("Email: %s\n", fskv_get("email"));

  return 0;
}