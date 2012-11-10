using System;

public class F {
  public static void Main(string[] args) {
    int n = Int32.Parse(Console.ReadLine());

    double[,] choose = new double[n + 1, n + 1];
    for (int i = 0; i <= n; ++i) {
      choose[i, 0] = 1;
      for (int j = 1; j <= i; ++j) {
        choose[i, j] = choose[i - 1, j - 1] + choose[i - 1, j];
      }
    }

    double[] dp = new double[n + 1];
    for (int i = 2; i <= n; ++i) {
      double r = 0.0;
      double s = Math.Pow(3, i - 1);
      for (int j = 1; j < i; ++j) {
        r += choose[i, j];
        dp[i] += dp[j] * choose[i, j];
      }
      dp[i] = (dp[i] + s) / r;
    }
    Console.WriteLine(dp[n]);
  }
}

//ID	Date	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4612221	18:11:51  10 Nov 2012	watashi	1936. Roshambo	C#	Accepted		0.14	2 148 KB

