import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

// 수 찾기
public class _1920 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        // Arraylist -> 시간초과
        HashSet<Integer> arr = new HashSet<>();
        String[] data = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr.add(Integer.parseInt(data[i]));
        }

        int M = Integer.parseInt(br.readLine());

        StringBuilder ans = new StringBuilder();
        String[] find = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            if (arr.contains(Integer.parseInt(find[i]))) {
                ans.append("1\n");
            }
            else {
                ans.append("0\n");
            }
        }

        System.out.println(ans);
    }
}
