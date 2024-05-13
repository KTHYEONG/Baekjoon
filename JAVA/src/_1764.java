import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 듣보잡
public class _1764 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        Set<String> table = new HashSet<>();
        for (int i = 0; i < N; i++) {
            table.add(br.readLine());
        }

        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String data = br.readLine();
            if (table.contains(data)) {
                ans.add(data);
            }
        }
        Collections.sort(ans);

        System.out.println(ans.size());
        for (String str : ans) {
            System.out.println(str);
        }
    }
}
