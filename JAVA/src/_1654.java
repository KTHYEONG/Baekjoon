import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 랜선 자르기
public class _1654 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int K = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        long[] arr = new long[K];
        for (int i = 0; i < K; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        Arrays.sort(arr);

        System.out.println(BinarySearch(arr, N, K));
    }

    public static long BinarySearch(long[] arr, int n, int k) {
        long left = 1;
        long right = arr[k - 1];
        long ans = 1;
        while (left <= right) {
            long mid = (left + right) / 2;

            long cnt = 0;
            for (int i = 0; i < k; i++) {
                cnt += arr[i] / mid;
            }

            if (cnt >= n) {
                ans = Math.max(ans, mid);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
}
