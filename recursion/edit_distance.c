#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int edit_distance(const char *str1, const char *str2, int m, int n) {
  if (m == 0) {
    return n; // Base case: Insert all characters of str2
  } else if (n == 0) {
    return m; // Base case: Delete all characters of str1
  }

  if (str1[m - 1] == str2[n - 1]) {
    // If characters match, no edit needed
    return edit_distance(str1, str2, m - 1, n - 1);
  }

  // Calculate edit distance for three possible operations (insertion, deletion,
  // replacement)
  // Insert character from str2
  int insert_cost = 1 + edit_distance(str1, str2, m, n - 1);
  // Delete character from str1
  int delete_cost = 1 + edit_distance(str1, str2, m - 1, n);
  // Replace character in str1
  int replace_cost = 1 + edit_distance(str1, str2, m - 1, n - 1);

  // Return minimum edit distance
  return MIN(insert_cost, MIN(delete_cost, replace_cost));
}

int main() {
  char str1[] = "algorithm";
  char str2[] = "algebra";

  int m = strlen(str1);
  int n = strlen(str2);

  int distance = edit_distance(str1, str2, m, n);

  printf("The edit distance betwn '%s' and '%s' is %d\n", str1, str2, distance);

  return 0;
}
