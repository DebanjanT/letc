//  Copyright 2024 Debanjan Tewary
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "./fskv_const.h"

#ifndef _FSKV_H_
#define _FSKV_H_

// set key value to memory
int fskv_set(const char *key, const char *value);

// get the value from memory by key
const char *fskv_get(const char *key);

// Print the full key-value store
void fskv_print();

// Key Value Pair Struct
typedef struct {
  char key[MAX_KEY_LENGTH];
  char value[MAX_VALUE_LENGTH];
} FsKeyValuePair;

#endif