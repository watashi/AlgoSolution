#include <cstdio>
#include <cstring>

const char* condition[3] = {
  " arbitary",
  ">=0",
  "<=0"
};

const char* restriction[3] = {
  "=",
  ">=",
  "<="
};

void readFunction(int a[], int d) {
  char ch;
  int c, x;

  for (int i = 1; i <= d; ++i) {
    a[i] = 0;
  }
  scanf(" ");
  ch = getchar();
  if (ch == '0') {
    return;
  } else if (ch != '+' && ch != '-') {
    ungetc(ch, stdin);
    ch = '+';
  }
  do {
    c = 1;
    scanf("%d", &c);
    getchar();	// == 'x'
    scanf("%d", &x);	// == 1
    a[x] += (ch == '+') ? c : -c;
    ch = getchar();
    if (ch != '+' && ch != '-') {
      ungetc(ch, stdin);
      break;
    }
  } while (true);
}

void writeFunction(int a[], int d) {
  bool b = false;

  for (int i = 1; i <= d; ++i) {
    if (a[i] == 0) {
      continue;
    }
    if (a[i] == 1) {
      if (b) {
        putchar('+');
      }
    } else if (a[i] == -1) {
      putchar('-');
    } else if (b) {
      printf("%+d", a[i]);
    } else {
      printf("%d", a[i]);
    }
    printf("y%d", i);
    b = true;
  }
  if (!b) {
    putchar('0');
  }
}

int main() {
  int n, m, a[128][128], aa[128][128], b[128], bb[128], c[128], cc[128];
  int tmp;
  char minmax[16], buf[32], ch;

  freopen("dual.in", "r", stdin);
  freopen("dual.out", "w", stdout);
  scanf("%d%d", &n, &m);
  scanf("%s", minmax);
  readFunction(a[0], n);
  scanf(" with");
  for (int i = 1; i <= n; ++i) {
    scanf(" x%d%[^\n]", &tmp, buf);
    switch (buf[0]) {
    case ' ': c[i] = 0; break;
    case '>': c[i] = 1; break;
    case '<': c[i] = 2; break;
    }
  }
  scanf(" under");
  for (int i = 1; i <= m; ++i) {
    readFunction(a[i], n);
    ch = getchar();
    switch (ch) {
    case '=': b[i] = 0; break;
    case '>': b[i] = 1; getchar(); break;
    case '<': b[i] = 2; getchar(); break;
    }
    scanf("%d", &a[i][0]);
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      aa[j][i] = a[i][j];
    }
  }
  // WA
  /*		for (int i = 1; i <= m; ++i) {
        cc[i] = b[i];
        }
        for (int i = 1; i <= n; ++i) {
        bb[i] = (c[i] == 0 ? 0 : 3 - c[i]);
        }
        */		if (strcmp(minmax, "min") == 0) {
          for (int i = 1; i <= m; ++i) {
            cc[i] = b[i];
          }
          for (int i = 1; i <= n; ++i) {
            bb[i] = (c[i] == 0 ? 0 : 3 - c[i]);
          }
        } else {
          for (int i = 1; i <= m; ++i) {
            cc[i] = (b[i] == 0 ? 0 : 3 - b[i]);
          }
          for (int i = 1; i <= n; ++i) {
            bb[i] = c[i];
          }
        }


        printf("%d %d\n", m, n);
        if (strcmp(minmax, "min") == 0) {
          printf("max ");
        } else {
          printf("min ");
        }
        writeFunction(aa[0], m);
        printf("\nwith\n");
        for (int i = 1; i <= m; ++i) {
          printf("y%d%s\n", i, condition[cc[i]]);
        }
        printf("under\n");
        for (int i = 1; i <= n; ++i) {
          writeFunction(aa[i], m);
          printf("%s%d\n", restriction[bb[i]], aa[i][0]);
        }

        return 0;
}

