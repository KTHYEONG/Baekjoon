import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 체스판 다시 칠하기
public class _1018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        boolean[][] board = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            String data = br.readLine();
            for (int j = 0; j < M; j++) {
                if (data.charAt(j) == 'W') {
                    board[i][j] = true;
                } else {
                    board[i][j] = false;
                }
            }
        }

        // 검사해야 하는 경우의 수
        int checkN = N - 7;
        int checkM = M - 7;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < checkN; i++) {
            for (int j = 0; j < checkM; j++) {
                ans = Math.min(solution(board, i, j), ans);
            }
        }

        System.out.println(ans);
    }

    public static int solution(boolean[][] arr, int x, int y) {
        int endX = x + 8;
        int endY = y + 8;
        int cnt = 0;

        boolean cur = arr[x][y];

        for (int i = x; i < endX; i++) {
            for (int j = y; j < endY; j++) {
                if (arr[i][j] != cur) {
                    cnt++;
                }

                cur = !cur;
            }
            cur = !cur;
        }

        // W, B 중 적은 것 선택
        cnt = Math.min(cnt, 64 - cnt);

        return cnt;
    }
}
