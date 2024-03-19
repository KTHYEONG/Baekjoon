import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 블랙잭
public class _2798 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        String[] data = br.readLine().split(" ");
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(data[i]);
        }

        int ans = 0;
        int sum = 0;
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    sum = arr[i] + arr[j] + arr[k];
                    if (sum == M) {
                        System.out.println(sum);
                        return;
                    }

                    if (sum < M && ans < sum) {
                        ans = sum;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
