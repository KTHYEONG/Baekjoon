import java.io.*;

// 카드 구매하기
public class _11052 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        String[] input = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(input[i - 1]);
        }

        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                ans[i] = Math.max(ans[i], ans[i - j] + arr[j]);
            }
        }
        bw.write(ans[n] + "");

        bw.flush();
        bw.close();
    }
}
