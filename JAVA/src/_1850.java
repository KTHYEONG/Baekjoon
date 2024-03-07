import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 최대공약수
public class _1850 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] data = br.readLine().split(" ");
        long A = Long.parseLong(data[0]);
        long B = Long.parseLong(data[1]);

        long cnt1 = gcd(A, B);

        StringBuilder ans = new StringBuilder();
        for (long i = 0; i < cnt1; i++) {
            ans.append("1");
        }

        System.out.println(ans);
    }

    public static long gcd(long a, long b) {
        long c;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

        return a;
    }
}
