import java.io.*;

// 카드 구매하기 2
public class _16194 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] arr = new int[n + 1];
        int[] ans = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            arr[i] = Integer.parseInt(input[i - 1]);
            ans[i] = Integer.MAX_VALUE;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                ans[i] = Math.min(ans[i], ans[i - j] + arr[j]);
            }
        }
        bw.write(ans[n] + "");

        bw.flush();
        bw.close();
    }
}
