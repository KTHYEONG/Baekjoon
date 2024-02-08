import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 이건 꼭 풀어야 해!
public class _17390 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(data[i - 1]);
        }

        Arrays.sort(arr);

        for (int i = 2; i <= N; i++) {
            arr[i] += arr[i - 1];
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            String[] LR = br.readLine().split(" ");
            int L = Integer.parseInt(LR[0]);
            int R = Integer.parseInt(LR[1]);

            ans.append(arr[R] - arr[L - 1] + "\n");
        }

        System.out.println(ans);
    }
}
