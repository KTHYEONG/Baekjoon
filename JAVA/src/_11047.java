import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 동전 0
public class _11047 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int[] coin = new int[N];
        for (int i = N - 1; i >= 0; i--) {
            coin[i] = Integer.parseInt(br.readLine());
        }

        int cnt = 0;
        int idx = 0;
        while (K != 0) {
            if (coin[idx] > K) {
                idx++;
            }
            else {
                K -= coin[idx];
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
