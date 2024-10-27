#include "lib/mmkv.c"
#include <stdio.h>

int main() {
  // Set key-value pairs
  mmkv_set("username", "ananda6851");
  mmkv_set("password", "12345");
  mmkv_set("email", "riju@gmail.com");

  // Get and print values by key
  printf("Username: %s\n", mmkv_get("username"));
  printf("Password: %s\n", mmkv_get("password"));
  printf("Email: %s\n", mmkv_get("email"));

  return 0;
}