import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

// 요세푸스 문제 0
public class _11866 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        Deque<Integer> dq = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            dq.addLast(i);
        }

        StringBuilder ans = new StringBuilder();

        int cnt = 1;
        ans.append("<");
        while (!dq.isEmpty()) {
            if (cnt == K && dq.size() != 1) {
                ans.append(dq.pollFirst() + ", ");
                cnt = 1;
            }
            else if (dq.size() == 1) {
                ans.append(dq.pollFirst());
            }
            else {
                dq.addLast(dq.pollFirst());
                cnt++;
            }
        }
        ans.append(">");

        System.out.println(ans);
    }
}
