using System;
using System.Collections.Generic;

public class D {
    public static void Main(string[] args) {
        string[] input = Console.ReadLine().Split();
        int a = Int32.Parse(input[0]), b = a + Int32.Parse(input[1]);
        int[] x = new int[b];
        for (int i = 1; i * i < b; ++i) {
            int ii = i * i;
            for (int j = 0; j < b; j += ii) {
                x[j] = ii;
            }
        }
        long s = 0;
        for (int i = a; i < b; ++i) {
            s += i / x[i];
        }
        Console.WriteLine(s);
    }
}
