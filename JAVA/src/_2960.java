import java.util.Scanner;

// 에라토스테네스의 체
public class _2960 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        boolean arr[] = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i] = true;
        }

        int cnt = 0;
        for (int i = 2; i <= N; i++) {
            int P = i;
            // 소수 P 판별
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    P = 0;
                    break;
                }
            }

            // 에라토스테네스의 체 적용
            if (P != 0) {
                for (; P <= N; P += i) {
                    if (arr[P] == true) {
                        arr[P] = false;
                        cnt++;
                    }

                    if (cnt == K) {
                        System.out.println(P);
                        break;
                    }
                }
            }
        }
    }
}
