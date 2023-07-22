import java.io.*;

// 네 수
public class _10824 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        long C = Long.parseLong(input[0] + input[1]);
        long D = Long.parseLong(input[2] + input[3]);

        bw.write(C + D + "");

        bw.flush();
        bw.close();
    }
}