import java.util.Scanner;

// 2차원 배열의 합
public class _2167 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int arr[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();

            int sum = 0;
            for (int j = a - 1; j < x; j++) {
                for (int l = b - 1; l < y; l++) {
                    sum += arr[j][l];
                }
            }
            System.out.println(sum);
        }
    }

}
