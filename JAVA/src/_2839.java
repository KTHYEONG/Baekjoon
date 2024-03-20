import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 설탕 배달
public class _2839 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int cnt = 0;
        while (N > 0) {
            // 5KG 봉투 사용가능한 만큼 사용
            if (N % 5 == 0) {
                cnt += N / 5;
                break;
            }

            if (N < 3) {
                cnt = -1;
                break;
            }

            // 3KG 봉투 1개를 사용
            N -= 3;
            cnt++;
        }

        System.out.println(cnt);
    }
}
