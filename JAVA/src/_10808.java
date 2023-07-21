import java.io.*;

// 알파벳 개수
public class _10808 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[26];
        String input = br.readLine();
        for (int i = 0; i < input.length(); i++) {
            arr[input.charAt(i) - 'a']++;
        }

        for (int data : arr) {
            bw.write(data + " ");
        }

        bw.flush();
        bw.close();
    }
}