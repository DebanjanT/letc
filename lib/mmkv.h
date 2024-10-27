#ifndef _MMKV_H_
#define _MMKV_H_

#define MAX_ALLOWED_PAIRS 100 // Max number of key-value pairs allowed to store
#define MAX_KEY_LENGTH 50     // length of single key to be stored
#define MAX_VALUE_LENGTH 100  // length of single value to be stored

// set key value to memory
int mmkv_set(const char *key, const char *value);

// get the value from memory by key
const char *mmkv_get(const char *key);

// Print the full key-value store
void mmkv_print();

// Key Value Pair Struct
typedef struct
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

#endif