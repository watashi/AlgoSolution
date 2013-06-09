#include <stdio.h>
#include <string.h>

int main(void) {
  int n, i;
  static char s[1 << 20];

#ifndef __WATASHI__
  freopen("positive.in", "r", stdin);
  freopen("positive.out", "w", stdout);
#endif
  scanf("%d ", &n);
  fgets(s, sizeof(s), stdin);
  for (i = 0; s[i] != '\0'; ++i) {
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
