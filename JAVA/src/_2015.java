import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

// 수들의 합 4
public class _2015 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = arr[i - 1] + Integer.parseInt(data[i - 1]);
        }

        // arr[i] - arr[j] = k --> arr[i] - k가 arr[j]인 것을 이용
        long ans = 0;
        Map<Integer, Integer> table = new HashMap<>();
        table.put(0, 1);
        for (int i = 1; i <= N; i++) {
            ans += table.getOrDefault(arr[i] - K, 0);
            table.put(arr[i], table.getOrDefault(arr[i], 0) + 1);
        }

        System.out.println(ans);
    }
}
