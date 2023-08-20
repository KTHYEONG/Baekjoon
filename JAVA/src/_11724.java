import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 연결 요소의 개수
public class _11724 {
    public static boolean[] visit;

    // 1부터 n까지의 정점 중 방문하지 않은 노드를 시작노드로 설정 및 탐색
    public static int solution(boolean[][] graph, int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                bfs(graph, n, i);
                ans++;
            }
        }

        return ans;
    }

    public static void bfs(boolean[][] graph, int n, int v) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(v);
        visit[v] = true;
        while (!queue.isEmpty()) {
            int data = queue.poll();
            for (int i = 1; i <= n; i++) {
                if (!visit[i] && graph[data][i] == true) {
                    visit[i] = true;
                    queue.offer(i);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        visit = new boolean[n + 1];
        boolean[][] graph = new boolean[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int u = Integer.parseInt(input[0]);
            int v = Integer.parseInt(input[1]);
            // 방향 없는 그래프 --> u -> v, v -> u 모두 체크
            graph[u][v] = true;
            graph[v][u] = true;
        }

        System.out.println(solution(graph, n));
    }
}

/*
// DFS
public static boolean[] visit;

    // 1부터 n까지의 정점 중 방문하지 않은 노드를 시작노드로 설정 및 탐색
    public static int solution(boolean[][] graph, int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                dfs(graph, n, i);
                ans++;
            }
        }

        return ans;
    }

    public static void dfs(boolean[][] graph, int n, int v) {
        visit[v] = true;
        for (int i = 1; i <= n; i++) {
            if (!visit[i] && graph[v][i] == true) {
                dfs(graph, n, i);
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        visit = new boolean[n + 1];
        boolean[][] graph = new boolean[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            // 방향 없는 그래프 --> u -> v, v -> u 모두 체크
            graph[u][v] = true;
            graph[v][u] = true;
        }

        System.out.println(solution(graph, n));
    }
 */
