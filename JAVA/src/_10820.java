import java.io.*;

// 문자열 분석
public class _10820 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input;
        while ((input = br.readLine()) != null) {
            int[] arr = new int[4];
            for (int i = 0; i < input.length(); i++) {
                char data = input.charAt(i);
                if (data >= 'a' && data <= 'z') {
                    arr[0]++;
                }
                else if (data >= 'A' && data <= 'Z') {
                    arr[1]++;
                }
                else if (data >= '0' && data <= '9') {
                    arr[2]++;
                }
                else {
                    arr[3]++;
                }
            }

            for (int num : arr) {
                bw.write(num + " ");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }
}