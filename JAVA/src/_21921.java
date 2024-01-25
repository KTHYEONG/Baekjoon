import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 블로그
public class _21921 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int X = Integer.parseInt(input[1]);
        String[] data = br.readLine().split(" ");

        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
                arr[i] = arr[i - 1] + Integer.parseInt(data[i - 1]);
        }

        int cnt = 0, ans = 0;
        for (int i = X; i <= N; i++) {
            int num = arr[i] - arr[i - X];
            if (num > ans) {
                ans = num;
                cnt = 0;
            }

            if (ans == num) {
                cnt++;
            }
        }

        if (ans == 0) {
            System.out.println("SAD");
        }
        else {
            System.out.println(ans + "\n" + cnt);
        }
    }
}