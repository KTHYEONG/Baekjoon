import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 이항 계수 1
public class _11050 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int a = 1, b = 1;
        for (int i = K; i > 0; i--) {
            a *= N--;
            b *= i;
        }

        System.out.println(a / b);
    }
}
