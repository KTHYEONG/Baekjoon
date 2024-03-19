import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 벌집
public class _2292 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        if (N == 1) {
            System.out.println(1);
        }
        else {
            int cnt = 1;
            int temp = 0;
            for (int i = 2; i <= N; i += temp) {
                temp += 6;
                cnt++;
            }
            System.out.println(cnt);
        }
    }
}
