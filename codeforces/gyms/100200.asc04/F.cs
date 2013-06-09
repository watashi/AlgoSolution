using System;
using System.IO;

public class F {
#if !__WATASHI__
  class FakeConsole: StreamWriter {
    StreamReader reader;

    public FakeConsole(string input, string output): base(output) {
      reader = new StreamReader(input);
      AutoFlush = true;
    }

    public int Read() {
      return reader.Read();
    }

    public string ReadLine() {
      return reader.ReadLine();
    }
  }

  static FakeConsole Console = new FakeConsole("positive.in", "positive.out");
#endif

  public static void Main(String[] args) {
    int n = int.Parse(Console.ReadLine());
    string s = Console.ReadLine();
    foreach (char c in s) {
      if (c == '-') {
        n -= 2;
      }
    }
    Console.WriteLine(Math.Max(n, 0));
  }
}
