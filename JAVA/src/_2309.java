import java.io.*;
import java.util.Arrays;

// 일곱 난쟁이
public class _2309 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int sum = 0;
        int[] arr = new int[9];
        for (int i = 0; i < 9; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }
        Arrays.sort(arr);

        // 키의 합에서 2명을 뺀 결과가 100이라는 의미 --> 그 2명만 없으면 완벽 == 가짜
        int fake1 = 0, fake2 = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (sum - (arr[i] + arr[j]) == 100) {
                    fake1 = i;
                    fake2 = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (i != fake1 && i != fake2) {
                bw.write(arr[i] + "\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
