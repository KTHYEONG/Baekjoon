import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 마인크래프트
public class _18111 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int B = Integer.parseInt(input[2]);

        int max = 256;
        int min = 0;
        int[][] arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            String[] data = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(data[j]);
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }

        int minTime = Integer.MAX_VALUE;
        int height = 0;
        for (int i = min; i <= max; i++) {
            int increase = 0;   // 시간
            int decrease = B;   // 블럭
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (arr[j][k] < i) {
                        increase += i - arr[j][k];
                        decrease -= i - arr[j][k];
                    } else if (arr[j][k] > i) {
                        increase += (arr[j][k] - i) * 2;
                        decrease += arr[j][k] - i;
                    }
                }
            }

            // 블럭 부족한 경우
            if (decrease < 0) continue;

            if (minTime >= increase) {
                minTime = increase;
                height = Math.max(height, i);
            }
        }

        System.out.println(minTime + " " + height);
    }
}
