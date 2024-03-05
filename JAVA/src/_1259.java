import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 팰린드롬수
public class _1259 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder ans = new StringBuilder();
        while (true) {
            String data = br.readLine();
            if (data.equals("0")) {
                break;
            }

            int start = 0;
            int end = data.length() - 1;
            boolean flag = true;
            while (start < end) {
                if (data.charAt(start) != data.charAt(end)) {
                    ans.append("no\n");
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            if (flag == true) {
                ans.append("yes\n");
            }
        }

        System.out.println(ans);
    }
}
