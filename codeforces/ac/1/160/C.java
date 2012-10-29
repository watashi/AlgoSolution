import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt();
            long m = in.nextLong();
            int q = (int)(m / n);
            int r = (int)(m % n);
            System.out.println(1L * n * q + r);
            System.out.println((int)(1L * n * q + r));
            int s = (int)(1L * n * q + r) / n;
            System.out.println(s);
        }
    }
}

