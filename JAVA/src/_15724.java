import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 주지수
public class _15724 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[][] arr = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            String[] data = br.readLine().split(" ");
            for (int j = 1; j <= M; j++) {
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j] + Integer.parseInt(data[j - 1]) - arr[i - 1][j - 1];
            }
        }

        StringBuilder ans = new StringBuilder();
        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            String[] range = br.readLine().split(" ");
            int x1 = Integer.parseInt(range[0]);
            int y1 = Integer.parseInt(range[1]);
            int x2 = Integer.parseInt(range[2]);
            int y2 = Integer.parseInt(range[3]);

            ans.append(arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] + "\n");
        }

        System.out.println(ans);
    }
}
