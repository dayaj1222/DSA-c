// Hash Table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct HashMap {
  char names[TABLE_SIZE][MAX_NAME];
  int count;
  int *age;
} HashMap;

int print(HashMap *map);
int get(char *key, HashMap *map);
int add(char *key, int value, HashMap *map);
int hash(char *name);

int print(HashMap *map) {
  for (int i = 0; i < map->count; i++) {
    printf("%s : %d \n", map->names[i], map->age[hash(map->names[i])]);
  }
  return 0;
}

int get(char *key, HashMap *map) {
  int location = hash(key);
  return map->age[location];
}

int add(char *key, int value, HashMap *map) {

  if (map->count < TABLE_SIZE) {
    for (int i = 0; i < map->count; i++) {
      if (strcmp(map->names[i], key) == 0) {
        return 0;
      }
    }

    strncpy(map->names[map->count], key, MAX_NAME - 1);
    map->names[map->count][MAX_NAME - 1] = '\0';

    map->count++;
    int location = hash(key);
    map->age[location] = value;
  }
  return 0;
};

int hash(char *name) {

  int length = strlen(name);
  int hash = 0;

  for (int i = 0; i < length; i++) {
    hash += name[i];
    hash *= name[i];
  }

  if (hash < 0) {
    hash = -hash;
  }
  hash = hash % TABLE_SIZE;
  return hash;
}

int main(int argc, char *argv[]) {

  int age[TABLE_SIZE];
  char names[TABLE_SIZE][MAX_NAME];

  HashMap *map = malloc(sizeof(HashMap));
  map->age = age;
  map->count = 0;

  add("Daya", 20, map);
  add("Bimin", 17, map);
  add("Roshan", 18, map);
  add("Vision", 18, map);

  printf("%d\n", get("Daya", map));

  print(map);

  return EXIT_SUCCESS;
}
