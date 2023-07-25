import java.io.*;

// 소수 찾기
public class _1978 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int ans = 0;
        for (String temp : input) {
            int data = Integer.parseInt(temp);
            for (int i = 2; i <= data; i++) {
                if (i == data) {
                    ans++;
                }

                if (data % i == 0) {
                    break;
                }
            }
        }
        bw.write(ans + "");

        bw.flush();
        bw.close();
    }
}
