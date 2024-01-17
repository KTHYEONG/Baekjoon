import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 신입 사원
public class _1946 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            int[][] arr = new int[N][2];
            for (int j = 0; j < N; j++) {
                String[] input = br.readLine().split(" ");
                arr[j][0] = Integer.parseInt(input[0]);
                arr[j][1] = Integer.parseInt(input[1]);
            }

            // 서류심사 성적 기준 오름차순
            Arrays.sort(arr, (o1, o2) -> {
                return o1[0] - o2[0];
            });

            // 서류심사 1등을 먼저 뽑는다고 가정 --> 서류 1등의 면접 점수보다 등수가 좋은 인원만 뽑기 가능
            int cnt = 1;
            int cmpSecEle = arr[0][1];
            for (int j = 1; j < N; j++) {
                if (cmpSecEle > arr[j][1]) {
                    cnt++;
                    cmpSecEle = arr[j][1];
                }
            }

            System.out.println(cnt);
        }
    }
}
