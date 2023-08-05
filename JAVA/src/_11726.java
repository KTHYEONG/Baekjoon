import java.io.*;

// 2xn 타일링
public class _11726 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n + 1];
        arr[0] = arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
        }
        bw.write(arr[n] + "");

        bw.flush();
        bw.close();
    }
}