#include <cstdio>
class BigInteger
{
private:
 static const int LEN = 77;
 static const int MOD = 10000000;
 int len;
 int a[LEN];
public:
 BigInteger()
 {
  BigInteger(0);
 }
 explicit BigInteger(const int& rhs)
 {
  len = 1;
  a[0] = rhs;
 }
 BigInteger(const BigInteger& rhs)
 {
  len = rhs.len;
  for (int i = 0; i < len; i++)
   a[i] = rhs.a[i];
 }
 void doit(const BigInteger& rhs)
 {
  int i, c = 0;
  for (i = 0; i < len && i < rhs.len; i++) {
   a[i] += rhs.a[i] + c;
   if(a[i] >= MOD) {
    a[i] -= MOD;
    c = 1;
   }
   else
    c = 0;
  }
  while(i < len) {
   a[i] += c;
   if(a[i] >= MOD) {
    a[i] -= MOD;
    c = 1;
   }
   else
    c = 0;
   i++;
  }
  while(i < rhs.len) {
   a[i] = rhs.a[i] + c;
   if(a[i] >= MOD) {
    a[i] -= MOD;
    c = 1;
   }
   else
    c = 0;
   i++;
  }
  if(c > 0)
   a[i++] = c;
  len = i;
 }
 void doit(const BigInteger& rhs, const int n)
 {
  int i, c = 0;
  for (i = 0; i < len && i < rhs.len; i++) {
   a[i] += rhs.a[i] * n + c;
   c = a[i] / MOD;
   a[i] %= MOD;
  }
  while(i < len) {
   a[i] += c;
   if(a[i] >= MOD) {
    a[i] -= MOD;
    c = 1;
   }
   else
    c = 0;
   i++;
  }
  while(i < rhs.len) {
   a[i] = rhs.a[i] * n + c;
   c = a[i] / MOD;
   a[i] %= MOD;
   i++;
  }
  if(c > 0)
   a[i++] = c;
  len = i;
 }
 void show() const
 {
  printf("%d", a[len - 1]);
  for (int i = len - 2; i >= 0; i--)
   printf("%07d", a[i]);
  printf("\n");
 }
};
BigInteger dp[202][202];
int main(void)
{
 int n;
 for (int i = 1; i <= 200; i++) {
  dp[i][1] = (BigInteger)1;
  for (int j = 2; j <= i; j++) {
   dp[i][j].doit(dp[i - 1][j - 1], j);
   dp[i][j].doit(dp[i - 1][j], j);
  }
 }
 for (int i = 1; i <= 200; i++)
  for (int j = 2; j <= 200; j++)
   dp[i][j].doit(dp[i][j - 1]);
 while(scanf("%d", &n) != EOF && n > 0)
  dp[n][n].show();
 return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2801286 2008-03-25 08:57:36 Accepted 1475 C++ 00:00.09 12864K ¤ï¤¿¤·

// 2012-09-07 00:50:09 | Accepted | 1475 | C++ | 20 | 12612 | watashi | Source
