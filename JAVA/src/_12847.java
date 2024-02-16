import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 꿀 아르바이트
public class _12847 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(data[i]);
        }

        long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        long max = sum;
        for (int i = m; i < n; i++) {
            sum += (arr[i] - arr[i - m]);
            max = Math.max(max, sum);
        }

        System.out.println(max);
    }
}
