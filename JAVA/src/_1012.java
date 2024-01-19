import java.util.Scanner;

// 유기농 배추
public class _1012 {
    static int[] dx = {0, -1, 0, 1};
    static int[] dy = {1, 0, -1, 0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int M = sc.nextInt();
            int N = sc.nextInt();
            int K = sc.nextInt();

            boolean[][] graph = new boolean[M][N];
            boolean[][] visit = new boolean[M][N];
            for (int j = 0; j < K; j++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                graph[x][y] = true;
            }

            int ans = solution(graph, visit, M, N);
            System.out.println(ans);
        }
    }

    public static int solution(boolean[][] graph, boolean[][] visit, int m, int n) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && graph[i][j] == true) {
                    dfs(graph, visit, m, n, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    public static void dfs(boolean[][] graph, boolean[][] visit, int m, int n, int x, int y) {
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int moveX = x + dx[i];
            int moveY = y + dy[i];

            if (moveX >= 0 && moveY >= 0 && moveX < m && moveY < n) {
                if (!visit[moveX][moveY] && graph[moveX][moveY] == true) {
                    dfs(graph, visit, m, n, moveX, moveY);
                }
            }
        }
    }
}
