import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 나이트의 이동
public class _7562 {
    static int[] dx = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int l = sc.nextInt();

            int[][] graph = new int[l + 1][l + 1];
            int cur_x = sc.nextInt();
            int cur_y = sc.nextInt();

            int goal_x = sc.nextInt();
            int goal_y = sc.nextInt();

            boolean[][] visit = new boolean[l + 1][l + 1];
            bfs(graph, visit, l, cur_x, cur_y, goal_x, goal_y);

            System.out.println(graph[goal_x][goal_y]);
        }
    }

    public static void bfs(int[][] graph, boolean[][] visit, int l, int x, int y, int goal_x, int goal_y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        visit[x][y] = true;

        while (!queue.isEmpty()) {
            int[] element = queue.poll();
            int curX = element[0];
            int curY = element[1];

            for (int i = 0; i < 8; i++) {
                int moveX = curX + dx[i];
                int moveY = curY + dy[i];

                if (moveX >= 0 && moveY >= 0 && moveX < l && moveY < l) {
                    if (!visit[moveX][moveY]) {
                        queue.add(new int[]{moveX, moveY});
                        graph[moveX][moveY] = graph[curX][curY] + 1;
                        visit[moveX][moveY] = true;
                    }
                }
            }
        }
    }
}
