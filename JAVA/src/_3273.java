import java.util.Arrays;
import java.util.Scanner;

// 두 수의 합
public class _3273 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int x = sc.nextInt();

        Arrays.sort(arr);

        // 투 포인터 알고리즘
        int cnt = 0;
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int sum = arr[start] + arr[end];
           if (sum > x) {
               end--;
           }
           else {
               if (sum == x) {
                   cnt++;
               }
               start++;
           }
        }

        System.out.print(cnt);
    }
}
