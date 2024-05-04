import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class _1620 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        HashMap<String, Integer> table1 = new HashMap<>();
        HashMap<Integer, String> table2 = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            String data = br.readLine();
            table1.put(data, i);
            table2.put(i, data);
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < M; i++) {
            String check = br.readLine();
            // 숫자인 경우
            if (check.charAt(0) >= 49 && check.charAt(0) <= 57) {
                ans.append(table2.get(Integer.parseInt(check))).append("\n");
            }
            // 문자열인 경우
            else {
                ans.append(table1.get(check)).append("\n");
            }
        }
        System.out.println(ans);
    }
}
