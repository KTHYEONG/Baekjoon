import java.io.*;

// 소수 구하기
public class _1929 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int m = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);

        boolean[] arr = new boolean[n + 1];
        arr[0] = arr[1] = true;
        for (int i = 2; i * i <= n; i++) {
            // 소수인 경우 --> 해당 수의 배수를 모두 체크(소수가 아님)
            if (!arr[i]) {
                for (int j = i * i; j <= n; j += i) {
                    arr[j] = true;
                }
            }
        }

        for (int i = m; i <= n; i++) {
            if (!arr[i]) {
                bw.write(i + "\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
