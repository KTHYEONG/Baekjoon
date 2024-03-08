import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 숨바꼭질 6
public class _17087 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int S = Integer.parseInt(input[1]);
        String[] data = br.readLine().split(" ");

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Math.abs(S - Integer.parseInt(data[i]));
        }

        int ans = arr[0];
        for (int i = 0; i < N; i++) {
            ans = gcd(ans, arr[i]);
        }

        System.out.println(ans);
    }

    public static int gcd(int a, int b) {
        int c;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

        return a;
    }
}
