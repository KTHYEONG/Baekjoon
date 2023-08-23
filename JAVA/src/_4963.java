import java.util.Scanner;

// 섬의 개수
public class _4963 {
    public static int[] dx = {1, -1, 0, 0, 1, 1, -1, -1};
    public static int[] dy = {0, 0, 1, -1, 1, -1, -1, 1};
    public static boolean[][] visit;

    public static void solution(int[][] graph, int w, int h) {
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visit[i][j] && graph[i][j] == 1) {
                    dfs(graph, w, h, i, j);
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }

    public static void dfs(int[][] graph, int w, int h, int x, int y) {
        visit[x][y] = true;
        for (int i = 0; i < 8; i++) {
            int move_x = x + dx[i];
            int move_y = y + dy[i];
            if (move_x >= 0 && move_y >= 0 && move_x < h && move_y < w) {
                if (!visit[move_x][move_y] && graph[move_x][move_y] == 1) {
                    dfs(graph, w, h, move_x, move_y);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int w = sc.nextInt();
            int h = sc.nextInt();

            if (w == 0 && h == 0) {
                break;
            }

            int[][] graph = new int[h][w];
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    graph[i][j] = sc.nextInt();
                }
            }

            visit = new boolean[h][w];

            solution(graph, w, h);
        }
    }
}

/*
public static void bfs(int[][] graph, int w, int h, int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        visit[x][y] = true;
        while (!queue.isEmpty()) {
            int[] data = queue.poll();
            x = data[0];
            y = data[1];
            for (int i = 0; i < 8; i++) {
                int move_x = x + dx[i];
                int move_y = y + dy[i];
                if (move_x >= 0 && move_y >= 0 && move_x < h && move_y < w) {
                    if (!visit[move_x][move_y] && graph[move_x][move_y] == 1) {
                        visit[move_x][move_y] = true;
                        queue.add(new int[]{move_x, move_y});
                    }
                }
            }
        }
    }
 */
