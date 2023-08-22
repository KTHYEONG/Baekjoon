import java.util.Arrays;
import java.util.Scanner;

// 단지번호붙이기
public class _2667 {
    public static boolean[][] visit;
    public static int[] ans = new int[25 * 25];
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static void solution(int[][] graph, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && graph[i][j] != 0) {
                    dfs(graph, n, i, j, cnt);
                    cnt++;
                }
            }
        }
        System.out.println(cnt);

        Arrays.sort(ans);
        for (int i = 0; i < ans.length; i++) {
            if (ans[i] != 0) {
                System.out.println(ans[i]);
            }
        }
    }

    public static void dfs(int[][] graph, int n, int x, int y, int cnt) {
        visit[x][y] = true;
        ans[cnt]++;
        for (int i = 0; i < 4; i++) {
            int move_x = dx[i] + x;
            int move_y = dy[i] + y;
            if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < n) {
                if (!visit[move_x][move_y] && graph[move_x][move_y] != 0) {
                    dfs(graph, n, move_x, move_y, cnt);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            String input = sc.next();
            for (int j = 0; j < n; j++) {
                graph[i][j] = input.charAt(j) - '0';
            }
        }

        visit = new boolean[n][n];

        solution(graph, n);


    }
}
