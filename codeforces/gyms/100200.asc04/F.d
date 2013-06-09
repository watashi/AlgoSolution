import std.conv;
import std.stdio;
import std.process;

void main() {
  if (getenv("USER") != "watashi") {
    stdin = File("positive.in", "r");
    stdout = File("positive.out", "w");
  }

  string s = readln();
  int n = parse!int(s);
  string t = readln();
  foreach (c; t) {
    if (c == '-') {
      n -= 2;
    }
  }
  if (n < 0) {
    n = 0;
  }
  writefln("%d", n);
}
