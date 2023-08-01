import java.io.*;

// 소인수분해
public class _11653 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        for (int i = 2; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                bw.write(i + "\n");
                n /= i;
            }
        }

        if (n != 1) {
            bw.write(n + "");
        }

        bw.flush();
        bw.close();
    }
}
