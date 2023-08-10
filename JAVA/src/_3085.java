import java.io.*;

// 사탕 게임
public class _3085 {
    public static int max = 1;
    public static void check(char[][] board, int n) {
        int cnt = 1;
        // 가로 방향으로 확인
        for (int i = 0; i < n; i++) {
            cnt = 1;
            for (int j = 0; j < n - 1; j++) {
                // 같은 사탕이 이어지는 경우 cnt 증가
                if (board[i][j] == board[i][j + 1]) {
                    cnt++;
                // 다른 사탕이 나온 경우 cnt 초기화
                } else {
                    cnt = 1;
                }
                max = Math.max(max, cnt);
            }
        }

        // 세로 방향으로 확인
        for (int i = 0; i < n; i++) {
            cnt = 1;
            for (int j = 0; j < n - 1; j++) {
                if (board[j][i] == board[j + 1][i]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                max = Math.max(max, cnt);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            String temp = br.readLine();
            for (int j = 0; j < temp.length(); j++) {
                board[i][j] = temp.charAt(j);
            }
        }

        // 가로 교환 및 체크
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                char temp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = temp;

                check(board, n);

                // 원상태 복구
                temp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = temp;
            }
        }

        // 세로 교환 및 체크
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                char temp = board[j][i];
                board[j][i] = board[j + 1][i];
                board[j + 1][i] = temp;

                check(board, n);

                temp = board[j][i];
                board[j][i] = board[j + 1][i];
                board[j + 1][i] = temp;
            }
        }

        bw.write(max + "");

        bw.flush();
        bw.close();
    }
}
