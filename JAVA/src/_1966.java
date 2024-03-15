import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

// 프린터 큐
public class _1966 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < t; i++) {
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);

            String[] data = br.readLine().split(" ");

            LinkedList<int[]> q = new LinkedList<>();
            for (int j = 0; j < N; j++) {
                q.add(new int[]{Integer.parseInt(data[j]), j});
            }

            int cnt = 0;
            while (!q.isEmpty()) {
                boolean maxCheck = true;
                int[] qdata = q.poll();
                int element = qdata[0];
                int idx = qdata[1];

                for (int j = 0; j < q.size(); j++) {
                    if (q.get(j)[0] > element) {
                        q.add(qdata);
                        for (int k = 0; k < j; k++) {
                            q.add(q.poll());
                        }

                        maxCheck = false;
                        break;
                    }
                }

                if (maxCheck == false) {
                    continue;
                }

                cnt++;
                if (idx == M) {
                    break;
                }
            }

            ans.append(cnt + "\n");
        }

        System.out.println(ans);
    }
}
