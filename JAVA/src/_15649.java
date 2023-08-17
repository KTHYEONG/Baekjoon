import java.io.*;

// N과 M (1)
public class _15649 {
    public static boolean[] visit;
    public static StringBuilder ans = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        visit = new boolean[n];
        int[] arr = new int[m];
        dfs(arr, n, m, 0);
        System.out.println(ans);
    }

    public static void dfs(int[] arr, int n, int m, int depth) {
        if (depth == m) {
            for (int temp : arr) {
                ans.append(temp + " ");
            }
            ans.append("\n");
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr[depth] = i + 1;
                dfs(arr, n, m, depth + 1);
                visit[i] = false;
            }
        }
    }
}
