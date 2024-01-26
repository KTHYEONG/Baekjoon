import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 합 구하기
public class _11441 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = arr[i - 1] + Integer.parseInt(data[i - 1]);
        }

        StringBuilder ans = new StringBuilder();
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            String[] temp = br.readLine().split(" ");
            int start = Integer.parseInt(temp[0]);
            int end = Integer.parseInt(temp[1]);
            int sum = arr[end] - arr[start - 1];
            ans.append(sum + "\n");
        }

        System.out.println(ans);
    }
}
