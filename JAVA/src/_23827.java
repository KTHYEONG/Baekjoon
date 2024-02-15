import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 수열 (Easy)
public class _23827 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");

        long[] arr = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(data[i - 1]);
        }

        long[] prefixSum = new long[N + 2];
        for (int i = N; i >= 1; i--) {
            prefixSum[i] += prefixSum[i + 1] + arr[i];
        }

        long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += arr[i] * prefixSum[i + 1];
            sum %= 1000000007;
        }
        System.out.println(sum);
    }
}
