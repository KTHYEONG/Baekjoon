import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

// 보물
public class _1026 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] A = new int[N];
        Integer[] B = new Integer[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            B[i] = sc.nextInt();
        }

        // A의 작은 수와 B의 큰 수 끼리 곱하기
        Arrays.sort(A);
        Arrays.sort(B, Collections.reverseOrder());

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i] * B[i];
        }

        System.out.print(sum);
    }
}
