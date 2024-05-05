import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// 숨바꼭질
public class _1697 {
    static boolean[] visit = new boolean[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        if (N == K) {
            System.out.println(0);
        } else {
            bfs(N, K);
        }
    }

    public static void bfs(int n, int k) {
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        visit[n] = true;

        int cnt = 0;
        while (!q.isEmpty()) {
            cnt++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.poll();
                visit[num] = true;

                // 위치 찾은 경우
                if (num - 1 == k || num + 1 == k || num * 2 == k) {
                    System.out.println(cnt);
                    return;
                }

                // -1, +1, *2 각 범위별로 체크를 위해 큐에 삽입
                if (num - 1 >= 0 && !visit[num - 1]) {
                    q.add(num - 1);
                    visit[num - 1] = true;
                }
                if (num + 1 <= 100000 && !visit[num + 1]) {
                    q.add(num + 1);
                    visit[num + 1] = true;
                }
                if (num * 2 <= 100000 && !visit[num * 2]) {
                    q.add(num * 2);
                    visit[num * 2] = true;
                }
            }
        }
    }
}
