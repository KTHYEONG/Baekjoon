import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 약수의 합
public class _17425 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        StringBuilder ans = new StringBuilder();
        // 각 약수들의 합을 배열에 저장하기
        long[] num = new long[1000001];
        Arrays.fill(num, 1);
        for (int i = 2; i < 1000001; i++) {
            for (int j = 1; i * j < 1000001; j++) {
                num[i * j] += i;
            }
        }

        // 약수들의 합을 누적합으로 저장하기
        long[] sum = new long[1000001];
        for (int i = 1; i < 1000001; i++) {
            sum[i] = sum[i - 1] + num[i];
        }

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            ans.append(sum[N] + "\n");
        }

        System.out.println(ans);
    }
}