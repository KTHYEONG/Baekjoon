import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// 쇠막대기
public class _10799 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Character> stack = new Stack<>();

        int ans = 0;
        String input = br.readLine();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '(') {
                stack.push('(');
            }
            else if (input.charAt(i) == ')') {
                stack.pop();

                // 레이저인 경우
                if (input.charAt(i - 1) == '(') {
                    ans += stack.size();
                }
                // 막대기가 끝난 경우
                else {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
