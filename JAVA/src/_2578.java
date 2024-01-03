import java.util.Scanner;

// 빙고
public class _2578 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] arr = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int callCnt = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                callCnt++;
                changeToMinus(arr, sc.nextInt());
                if (check(arr) >= 3) {
                    System.out.println(callCnt);
                    return;
                }
            }
        }
    }
    public static void changeToMinus(int[][] arr, int num) {
        // 목표 숫자 찾아서 -1로 설정
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] == num) {
                    arr[i][j] = -1;
                }
            }
        }
    }
    public static int check(int[][] arr) {
        int row, col, diagonal1, diagonal2;
        int cnt = 0;
        int idx = 0;
        diagonal1 = 0;
        diagonal2 = 0;
        for (int i = 0; i < 5; i++) {
            row = 0;
            col = 0;
            for (int j = 0; j < 5; j++) {
                // 가로, 세로 빙고 체크를 위한 덧셈
                row += arr[i][j];
                col += arr[j][i];

                // 대각 빙고 체크를 위한 덧셈
                if (i == j) {
                    diagonal1 += arr[i][j];
                }
                if (i == idx && j == 4 - idx) {
                    diagonal2 += arr[i][j];
                    idx++;
                }
            }

            // 가로, 세로, 대각 빙고 체크(-5 == 1줄 완성)
            if (row == -5) {
                cnt++;
            }
            if (col == -5) {
                cnt++;
            }
            if (diagonal1 == -5) {
                cnt++;
            }
            if (diagonal2 == -5) {
                cnt++;
            }
        }

        return cnt;
    }
}
