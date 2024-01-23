import java.util.Scanner;

// 수열
public class _2559 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        // 누적합을 배열에 저장
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = arr[i - 1] + sc.nextInt();
        }

        int ans = -(1000000 * 100 + 1);
        for (int i = K; i <= N; i++) {
            int sum = arr[i] - arr[i - K];
            ans = Math.max(ans, sum);
        }
        
        System.out.println(ans);
    }
}
