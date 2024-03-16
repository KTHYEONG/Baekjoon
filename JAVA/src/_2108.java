import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 통계학
public class _2108 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();

        int[] arr = new int[N];
        int[] count = new int[8001];
        double sum = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            count[arr[i] + 4000]++;
            sum += arr[i];
        }

        // 산술평균
        ans.append((int) Math.round(sum / N) + "\n");

        // 중앙값
        Arrays.sort(arr);
        ans.append(arr[N / 2] + "\n");

        // 최빈값
        int max = 0;
        int idx = 0;
        boolean check = false;
        for (int i = 0; i < 8001; i++) {
            if (count[i] > 0) {
                if (count[i] > max) {
                    max = count[i];
                    idx = i - 4000;
                    check = true;
                } else if ((max == count[i]) && (check == true)) {
                    idx = i - 4000;
                    check = false;
                }
            }
        }
        ans.append(idx + "\n");

        // 범위
        ans.append(arr[N - 1] - arr[0]);

        System.out.println(ans);
    }
}
