import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 토마토
public class _7576 {
    public static int[] dx = {1, -1, 0, 0};
    public static int[] dy = {0, 0, 1, -1};

    public static int bfs(int[][] graph, Queue<int[]> queue, int n, int m) {
        while (!queue.isEmpty()) {
            int[] data = queue.poll();
            for (int i = 0; i < 4; i++) {
                int move_x = data[0] + dx[i];
                int move_y = data[1] + dy[i];
                if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m) {
                    if (graph[move_x][move_y] == 0) {
                        queue.add(new int[]{move_x, move_y});
                        graph[move_x][move_y] = graph[data[0]][data[1]] + 1;
                    }
                }
            }
        }

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 안익은 토마토가 존재하는 경우
                if (graph[i][j] == 0) {
                    return -1;
                }

                max = Math.max(max, graph[i][j]);
            }
        }

        if (max == 1) {
            return 0;
        } else {
            return max - 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] graph = new int[n][m];
        Queue<int[]> queue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                graph[i][j] = sc.nextInt();
                if (graph[i][j] == 1) {
                    queue.add(new int[]{i, j});
                }
            }
        }

        System.out.println(bfs(graph, queue, n, m));

    }
}
