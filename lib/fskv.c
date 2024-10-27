//
//   * This file is a part of letc
//   * fskv.c created by Debanjan Tewary on 10/27/2024
//   * Copyright © 2024  DTDigital. All rights reserved.
//
//   letc is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   letc is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with letc.  If not, see <https://www.gnu.org/licenses/>.
//

#include "../include/fskv/fskv.h"
#include "stdio.h"
#include "string.h"

// Init KV Store
FsKeyValuePair kvStore[MAX_ALLOWED_PAIRS];
// Number of kv-pair stored in memory
// TODO - this value needs to te fetched from a local sqlite database
int pairCount = 0;

int fskv_set(const char *key, const char *value) {
  //   printf("[+] Key is %s\n", key);
  //   printf("[+] Value is %s\n", value);
  //   printf("[+] Length of Key is %lu\n", strlen(key));
  //   printf("[+] Length of value is %lu\n", strlen(value));
  //   printf("[+] Pair Count is %d\n", pairCount);
  //   printf("------------------------------\n");

  // Prevent SegFualt Error
  if (key == NULL || strlen(key) <= 0) {
    fprintf(stderr, "Should be a valid key. Key is\n");
    return 1;
  }

  // Prevent SegFualt Error
  if (value == NULL || strlen(value) <= 0) {
    fprintf(stderr, "Value should not be empty. Value is\n");
    return 1;
  }

  // Check if the key already exists if exists replace it with the new
  for (int i = 0; i < pairCount; i++) {
    if (strcmp(kvStore[i].key, key) == 0) {
      strncpy(kvStore[i].value, value, MAX_VALUE_LENGTH);
      // null termination
      kvStore[i].value[MAX_VALUE_LENGTH - 1] = '\0';
      return 0; // success
    }
  }

  // If key not exists create a new entry in memory
  if (pairCount < MAX_ALLOWED_PAIRS) {
    strncpy(kvStore[pairCount].key, key, MAX_KEY_LENGTH);
    kvStore[pairCount].key[MAX_KEY_LENGTH - 1] = '\0'; // null termination
    strncpy(kvStore[pairCount].value, value, MAX_VALUE_LENGTH);
    kvStore[pairCount].value[MAX_VALUE_LENGTH - 1] = '\0';
    pairCount += 1;
    return 0;
  }

  fprintf(stderr, "Maximum allowed KV-Pair limit exceeded\n");
  return 1; // Failure
}

const char *fskv_get(const char *key) {
  //   printf("Searching for key: %s\n", key);

  // Segfault Error Prevention
  if (key == NULL || strlen(key) <= 0) {
    fprintf(stderr, "Should be a valid key. Key is Empty or NULL\n");
    return NULL;
  }

  // Loop through the KV store to find the key
  for (int i = 0; i < pairCount; i++) {
    if (strcmp(kvStore[i].key, key) == 0) {
      return kvStore[i].value;
    }
  }
  fprintf(stderr, "Couldn't find the key in Key-Value Store\n");
  return NULL;
}

// Print the full key-value store
void fskv_print() {
  printf("Key-Value Store\n");
  for (int i = 0; i < pairCount; i++) {
    printf(" 🔑 Key: %s, 📈 Value: %s\n", kvStore[i].key, kvStore[i].value);
  }
}