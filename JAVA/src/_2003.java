import java.util.Scanner;

// 수들의 합 2
public class _2003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] arr = new int[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int sum = 0;
        int start = 0, end = 0;
        int cnt = 0;
        while (true) {
            if (sum >= M) {
                sum -= arr[start++];
            }
            else if (end == N) {
                break;
            }
            else {
                sum += arr[end++];
            }

            if (sum == M) {
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}
