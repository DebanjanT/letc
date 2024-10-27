# FSKV - File System Key-Value Store

FSKV is a simple in-memory key-value store for C, designed to store key-value pairs in memory while providing file-based persistence. This allows data to be retained between program executions, making it useful for lightweight storage needs without a full database.

## Function List

- [FSKV - File System Key-Value Store](#fskv---file-system-key-value-store)
  - [Function List](#function-list)
  - [Features](#features)
  - [Requirements](#requirements)
  - [Installation](#installation)
    - [`int fskv_set(const char *key, const char *value);`](#int-fskv_setconst-char-key-const-char-value)
    - [`const char *fskv_get(const char *key);`](#const-char-fskv_getconst-char-key)
    - [`void fskv_print();`](#void-fskv_print)

## Features

- **In-Memory Storage**: Fast access to key-value pairs within the program's runtime.
- **File-Based Persistence**: Saves key-value pairs to a file (`.dtkvstore`) for data persistence across program executions.
- **Simple API**: Functions for setting, retrieving, and printing key-value pairs.
- **Basic Error Handling**: Prevents segmentation faults and other common errors from invalid keys or values.

## Requirements

- C Compiler (GCC, Clang, or others)

## Installation

Clone this repository and compile the code:

```bash
git clone https://github.com/yourusername/fskv.git
cd fskv
gcc main.c -o fskv
```

---

### `int fskv_set(const char *key, const char *value);`

**Description**: Sets a key-value pair in file memory. If the key already exists, the value is updated. New pairs are added if space allows.

- **Parameters**:

  - `key`: (const char \*) - Key to be stored. Should be non-empty and non-NULL.
  - `value`: (const char \*) - Value to be stored for the given key. Should be non-empty and non-NULL.

- **Returns**:

  - `0` on success.
  - `1` on failure (e.g., invalid key/value, exceeded storage limit).

- **Error Handling**: Checks if `key` and `value` are valid (non-NULL and non-empty). Ensures there is space in the store before adding a new key-value pair.

---

### `const char *fskv_get(const char *key);`

**Description**: Retrieves the value associated with a given key from file.

- **Parameters**:

  - `key`: (const char \*) - Key for which the value needs to be fetched. Should be non-empty and non-NULL.

- **Returns**:

  - A pointer to the associated value (const char \*) if the key exists.
  - `NULL` if the key does not exist or is invalid.

- **Error Handling**: Ensures `key` is non-NULL and non-empty. If the key is not found, returns `NULL` and prints an error message.

---

### `void fskv_print();`

**Description**: Prints all key-value pairs currently stored in file memory to standard output.

- **Parameters**: None

- **Returns**: Nothing (void).

- **Output Format**: Each key-value pair is printed in the format:  
  `🔑 Key: [key], 📈 Value: [value]`

- **Example Output**:
  ```plaintext
  Key-Value Store
   🔑 Key: username, 📈 Value: johndoe
   🔑 Key: password, 📈 Value: 12345
  ```
