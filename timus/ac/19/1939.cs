using System;

public class I {
  const double EPS = 1e-8;

  public static void Main(string[] args) {
    double[] input = Array.ConvertAll(
        (Console.ReadLine() + " " + Console.ReadLine()).Split(),
        Double.Parse);
    // l h H v x a
    // 0 1 2 3 4 5
    double t = (input[2] - input[1]) / input[4];
    double v = input[3];
    double a = input[5];
    double s1 = v * t;
    double s2;
    if (v - a * t >= 0) {
      s2 = v * t - a * t * t / 2;
    } else {
      s2 = (v * v) / (2 * a);
    }
    Console.WriteLine(s1 - s2 > input[0] + EPS ? "Safe" : "Crash");
  }
}

//ID	Time	Author	Problem	Language	Judgement result	Test #	Execution time	Memory used
//4611696	4:00:36	watashi	I. First Seal	C#	Accepted		0.14	2 204 KB

