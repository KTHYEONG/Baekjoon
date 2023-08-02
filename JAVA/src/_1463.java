import java.io.*;

// 1로 만들기
public class _1463 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int x = Integer.parseInt(br.readLine());
        int[] arr = new int[x + 1];

        for (int i = 2; i <= x; i++) {
            arr[i] = arr[i - 1] + 1;
            if (i % 2 == 0) {
                arr[i] = Math.min(arr[i / 2] + 1, arr[i]);
            }
            if (i % 3 == 0) {
                arr[i] = Math.min(arr[i / 3] + 1, arr[i]);
            }
        }
        bw.write(arr[x] + "");

        bw.flush();
        bw.close();
    }
}