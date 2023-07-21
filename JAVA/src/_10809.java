import java.io.*;
import java.util.Arrays;

// 알파벳 찾기
public class _10809 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[26];
        Arrays.setAll(arr, num -> -1);
        String input = br.readLine();
        for (int i = 0; i < input.length(); i++) {
            if (arr[input.charAt(i) - 'a'] == -1) {
                arr[input.charAt(i) - 'a'] = i;
            }
        }

        for (int data : arr) {
            bw.write(data + " ");
        }

        bw.flush();
        bw.close();
    }
}
