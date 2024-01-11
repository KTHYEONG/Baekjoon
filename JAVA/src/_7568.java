import java.util.Scanner;

// 덩치
public class _7568 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[][] person = new int[N][2];
        for (int i = 0; i < N; i++) {
            person[i][0] = sc.nextInt();
            person[i][1] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            int curPersonWeight = person[i][0];
            int curPersonHeight = person[i][1];
            int cnt = 1;
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }

                if (person[j][0] > curPersonWeight && person[j][1] > curPersonHeight) {
                    cnt++;
                }
            }
            System.out.print(cnt + " ");
        }
    }
}
