import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 어두운 건 무서워
public class _16507 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int R = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);
        int Q = Integer.parseInt(input[2]);

        int[][] picture = new int[R + 1][C + 1];
        for (int i = 1; i <= R; i++) {
            String[] data = br.readLine().split(" ");
            for (int j = 1; j <= C; j++) {
                picture[i][j] = picture[i][j - 1] + Integer.parseInt(data[j - 1]);
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            String[] pixel = br.readLine().split(" ");
            int r1 = Integer.parseInt(pixel[0]);
            int c1 = Integer.parseInt(pixel[1]);
            int r2 = Integer.parseInt(pixel[2]);
            int c2 = Integer.parseInt(pixel[3]);

            int sum = 0;
            for (int j = r1; j <= r2; j++) {
                sum += picture[j][c2] - picture[j][c1 - 1];
            }
            ans.append(sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) + "\n");
        }

        System.out.println(ans);
    }
}
