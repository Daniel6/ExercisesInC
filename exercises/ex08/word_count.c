#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
  printf(user_data, key, GPOINTER_TO_INT (value));
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Please provide filename as argument.\n");
    return 0;
  }

  GHashTable* table = g_hash_table_new(g_str_hash, g_str_equal);
  FILE* file = fopen(argv[1], "r");
  char buffer[256];

  // Count occurences
  while(fscanf(file, "%s", buffer) != EOF) {
    char* key = strdup(buffer);
    if (g_hash_table_contains(table, key)) {
      int count = GPOINTER_TO_INT (g_hash_table_lookup(table, key));
      g_hash_table_replace(table, key, GINT_TO_POINTER (count + 1));
    } else {
      g_hash_table_insert(table, key, GINT_TO_POINTER (1));
    }
  }

  // Print out all key value pairs
  g_hash_table_foreach(table, (GHFunc) iterator, "The word %s occurs %d times.\n");
}