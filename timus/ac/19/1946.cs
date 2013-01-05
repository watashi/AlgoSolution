using System;

public class F {
  const int INF = 1024;
  const int MOD = 1000000007;

  // http://oeis.org/A047729
  public static int Gao(int n) {
    int[,,] dp = new int[n + 1, INF, INF];
    dp[0, 0, 0] = 1;

    for (int k = 0; k <= n; ++k) {
      for (int i = 0; i < INF; ++i) {
        for (int j = 1; j < INF; ++j) {
          dp[k, i, j] = (dp[k, i, j] + dp[k, i, j - 1]) % MOD;
        }
        if (k < n) {
          for (int j = 0; j < INF; ++j) {
            int d = Math.Max(2 * j - i - 3, 0);
            if (d < INF) {
              dp[k + 1, j, d] = (dp[k + 1, j, d] + dp[k, i, j]) % MOD;
            }
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < INF; ++i) {
      ans = (ans + dp[n, i, 0]) % MOD;
    }
    return ans;
  }

  public static void Main(string[] args) {int[] ans = new int[50]{
      1, 2, 8, 37, 198,
      1178, 7548, 50944, 357855, 2595250,
      19313372, 146815503, 136158488, 927025933, 65653738,
      215408350, 746589264, 724066327, 631274816, 422001336,
      7146650, 407217283, 393518927, 965151303, 895251280,
      864749285, 934373752, 467108499, 418735743, 451847922,
      890597718, 824730990, 739940095, 858720713, 600431442,
      577631035, 867745635, 3561686, 302514002, 527947240,
      805543258, 150530321, 534209877, 85487795, 939816214,
      315353659, 496074452, 538654703, 326456510, 82203529,
    };
    int n = int.Parse(Console.ReadLine());
    Console.WriteLine(ans[n - 1]);
  }
}
/*
id => 4706659
date => 20:48:335 Jan 2013
user => watashi
pname => Chinese Hockey 3
lang => C#
status => Accepted
testid => 
time => 0.156
mem => 1 988 KB
pid => 1946
*/
