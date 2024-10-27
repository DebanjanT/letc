//
//   * This file is a part of letc
//   * fskv.h created by Debanjan Tewary on 10/27/2024
//   * Copyright © 2024 DTDigital. All rights reserved.
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