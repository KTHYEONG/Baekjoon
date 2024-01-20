import java.util.Scanner;

// 바이러스
public class _2606 {
    static int cnt = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int pcNum = sc.nextInt();
        int n = sc.nextInt();

        boolean[][] graph = new boolean[pcNum + 1][pcNum + 1];
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            graph[x][y] = true;
            graph[y][x] = true;
        }

        boolean[] visit = new boolean[pcNum + 1];
        dfs(graph, visit, n, pcNum, 1);

        System.out.println(cnt);
    }

    public static void dfs(boolean[][] graph, boolean[] visit, int n, int pcNum, int v) {
        visit[v] = true;
        for (int i = 1; i <= pcNum; i++) {
            if (!visit[i] && graph[v][i] == true) {
                dfs(graph, visit, n, pcNum, i);
                cnt++;
            }
        }
    }
}
