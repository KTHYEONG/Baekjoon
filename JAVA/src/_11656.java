import java.io.*;
import java.util.Arrays;

// 접미사 배열
public class _11656 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        String[] ans = new String[input.length()];
        for (int i = 0; i < input.length(); i++) {
            ans[i] = input.substring(i, input.length());
        }

        Arrays.sort(ans);
        for (String data : ans) {
            bw.write(data + "\n");
        }

        bw.flush();
        bw.close();
    }
}