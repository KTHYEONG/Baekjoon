import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// 두 배열의 합
public class _2143 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        int n = Integer.parseInt(br.readLine());
        String[] A_input = br.readLine().split(" ");
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(A_input[i]);
        }

        int m = Integer.parseInt(br.readLine());
        String[] B_input = br.readLine().split(" ");
        int[] B = new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(B_input[i]);
        }

        ArrayList<Integer> sumA = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += A[j];
                sumA.add(sum);
            }
        }

        ArrayList<Integer> sumB = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = i; j < m; j++) {
                sum += B[j];
                sumB.add(sum);
            }
        }

        Collections.sort(sumA);
        Collections.sort(sumB);

        int start = 0, end = sumB.size() - 1;
        long cnt = 0;
        while (start < sumA.size() && end >= 0) {
            int sum = sumA.get(start) + sumB.get(end);
            if (sum == T) {
                long elementA = sumA.get(start);
                long elementB = sumB.get(end);
                long Acnt = 0;
                long Bcnt = 0;

                // 배열에서 중복되는 수 체크
                while (start < sumA.size() && sumA.get(start) == elementA) {
                    Acnt++;
                    start++;
                }
                while (end >= 0 && sumB.get(end) == elementB) {
                    Bcnt++;
                    end--;
                }
                cnt += Acnt * Bcnt;
            } else if (sum < T) {
                start++;
            } else if (sum > T) {
                end--;
            }
        }

        System.out.println(cnt);
    }
}