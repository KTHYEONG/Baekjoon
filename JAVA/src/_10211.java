import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Maximum Subarray
public class _10211 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N + 1];
            String[] data = br.readLine().split(" ");
            int max = -1001;
            for (int j = 1; j <= N; j++) {
                arr[j] = arr[j - 1] + Integer.parseInt(data[j - 1]);
                max = Math.max(max, arr[j]);
            }

            for (int j = 1; j <= N; j++) {
                for (int k = N; k > j; k--) {
                    max = Math.max(max, arr[k] - arr[j]);
                }
            }

            ans.append(max + "\n");
        }

        System.out.println(ans);
    }
}
