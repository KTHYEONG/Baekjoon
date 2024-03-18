import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 부녀회장이 될테야
public class _2775 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int[][] arr = new int[15][15];
        for (int i = 1; i < 15; i++) {
            arr[i][1] = 1;
            arr[0][i] = i;
        }
        for (int i = 1; i < 15; i++) {
            for (int j = 2; j < 15; j++) {
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
            }
        }

        StringBuilder ans = new StringBuilder();
        while (T-- > 0) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());

            ans.append(arr[k][n] + "\n");
        }

        System.out.println(ans);
    }
}
