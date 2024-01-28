import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 부분합
public class _1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int S = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        int[] arr = new int[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(data[i]);
        }

        int start = 0, end = 0, sum = 0;
        int ans = 100_000_001;
        // <= N 까지 임을 주의하기
        while (start <= N && end <= N) { 
            if (sum < S) {
                sum += arr[end++];
            } else {
                ans = Math.min(ans, end - start);
                sum -= arr[start++];
            }
        }

        if (ans == 100_000_001)
            System.out.println(0);
        else
            System.out.println(ans);
    }
}
