#include <stdio.h>
#include <string.h>

#ifndef __WATASHI__
struct $ {
  $(const char* input, const char* output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
  }
} $("positive.in", "positive.out");
#endif

int main(void) {
  int n;
  static char s[1 << 20];

  scanf("%d ", &n);
  fgets(s, sizeof(s), stdin);
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == '-') {
      n -= 2;
    }
  }
  if (n < 0) {
    n = 0;
  }
  printf("%d\n", n);

  return 0;
}
