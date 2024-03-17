import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 분해합
public class _2231 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int data = Integer.parseInt(br.readLine());

        int ans = 0;
        for (int i = 0; i < data; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }

            if (sum + i == data) {
                ans = i;
                break;
            }
        }

        System.out.println(ans);
    }
}
