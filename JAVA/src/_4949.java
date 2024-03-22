import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// 균형잡인 세상
public class _4949 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder ans = new StringBuilder();
        while (true) {
            String data = br.readLine();
            if (data.equals(".")) {
                break;
            }

            ans.append(solution(data) + "\n");
        }

        System.out.println(ans);
    }

    public static String solution(String data) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < data.length(); i++) {
            if (data.charAt(i) == '(' || data.charAt(i) == '[') {
                stk.push(data.charAt(i));
            } else if (data.charAt(i) == ')') {
                if (!stk.isEmpty() && stk.peek() == '(') {
                    stk.pop();
                } else {
                    return "no";
                }
            } else if (data.charAt(i) == ']') {
                if (!stk.isEmpty() && stk.peek() == '[') {
                    stk.pop();
                } else {
                    return "no";
                }
            }
        }

        if (stk.isEmpty()) {
            return "yes";

        } else {
            return "no";
        }
    }
}
