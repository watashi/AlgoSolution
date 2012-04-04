import java.math.*;

public class C {
    public static void main(String[] args) {
        BigInteger a = new BigInteger("987654321");
        for (int i = 0; i < 10; ++i) {
            a = a.nextProbablePrime();
            System.out.println("fib.push_back(" + a + ");");
        }
    }
}
