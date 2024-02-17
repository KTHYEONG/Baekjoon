import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 귀찮아 (SIB)
public class _14929 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");

        int[] prefixSum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + Integer.parseInt(data[i - 1]);
        }

        long sum = 0;
        for (int i = 1; i <= n; i++) {
            int temp = prefixSum[n] - prefixSum[i];
            sum += Integer.parseInt(data[i - 1]) * temp;
        }

        System.out.println(sum);
    }
}
