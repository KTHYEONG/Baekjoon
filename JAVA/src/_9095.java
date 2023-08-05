import java.io.*;

// 1, 2, 3 더하기
public class _9095 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[12];
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int i = 4; i <= 11; i++) {
            arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
        }

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            bw.write(arr[n] + "\n");
        }

        bw.flush();
        bw.close();
    }
}
