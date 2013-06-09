package main

import (
  "fmt"
  "os"
)

func main() {
  if (os.Getenv("USER") != "watashi") {
    os.Stdin, _ = os.Open("positive.in")
    os.Stdout, _ = os.Create("positive.out")
  }

  var n, m int
  fmt.Scanf("%d", &n)
  fmt.Scanln()
  m = n
  for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    if x < 0 {
      m -= 2
    }
  }
  if m < 0 {
    m = 0
  }
  fmt.Printf("%d\n", m)
}
