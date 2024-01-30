import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 나머지 합
public class _10986 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        long[] arr = new long[N + 1];
        long[] cnt = new long[M];
        long sum = 0;
        for (int i = 1; i <= N; i++) {
            arr[i] = (arr[i - 1] + Integer.parseInt(data[i - 1])) % M;
            if (arr[i] == 0) {
                sum++;
            }
            cnt[(int) arr[i]]++;
        }

        // arr[j] % M == arr[i - 1] % M && 조합(nCr, 같은 cnt중 2개 선택) 이용
        for (int i = 0; i < M; i++) {
            if (cnt[i] > 1) {
                sum += (cnt[i] * (cnt[i] - 1) / 2);
            }
        }
        System.out.println(sum);
    }
}
