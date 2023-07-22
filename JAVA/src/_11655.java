import java.io.*;

// ROT13
public class _11655 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char data = input.charAt(i);
            if ((data >= 'a' && data <= 'm') || (data >= 'A' && data <= 'M')) {
                ans.append((char) (data + 13));
            } else if ((data >= 'n' && data <= 'z') || (data >= 'N' && data <= 'Z')) {
                ans.append((char) (data - 13));
            } else {
                ans.append((char) data);
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}