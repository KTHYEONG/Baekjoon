import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// DFS와 BFS
public class _1260 {
    public static boolean[] visit;
    public static Queue<Integer> queue = new LinkedList<>();

    public static void dfs(boolean[][] graph, int n, int v) {
        visit[v] = true;
        System.out.print(v + " ");
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && graph[v][i] == true) {
                dfs(graph, n, i);
            }
        }
    }

    public static void bfs(boolean[][] graph, int n, int v) {
        queue.add(v);
        visit[v] = true;
        while (!queue.isEmpty()) {
            int data = queue.poll();
            System.out.print(data + " ");
            for (int i = 1; i <= n; i++) {
                if (!visit[i] && graph[data][i] == true) {
                    visit[i] = true;
                    queue.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int v = sc.nextInt();

        visit = new boolean[n + 1];
        boolean[][] graph = new boolean[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a][b] = true;
            graph[b][a] = true;
        }

        dfs(graph, n, v);

        System.out.println();
        for (int i = 0; i <= n; i++) {
            visit[i] = false;
        }

        bfs(graph, n, v);
    }
}
