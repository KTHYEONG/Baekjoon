import java.util.Scanner;

// 수열
public class _2491 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int cnt = 1;
        int maxCnt = 1;

        // 커지는 경우
        for (int i = 0; i < N - 1; i++) {
            if (arr[i + 1] >= arr[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxCnt = Math.max(cnt, maxCnt);
        }

        // 작아지는 경우
        cnt = 1;
        for (int i = 0; i < N - 1; i++) {
            if (arr[i + 1] <= arr[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxCnt = Math.max(cnt, maxCnt);
        }
        System.out.println(maxCnt);
    }
}
