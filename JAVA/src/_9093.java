import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// 단어 뒤집기
// STACK 사용
public class _9093 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        while (n-- > 0) {
            String input = br.readLine() + '\n';
            for (int i = 0; i < input.length(); i++) {
                if (input.charAt(i) == ' ' || input.charAt(i) == '\n') {
                    while (!stack.isEmpty()) {
                        ans.append(stack.pop());
                    }
                    ans.append(input.charAt(i));
                } else {
                    stack.push(input.charAt(i));
                }
            }
        }
        System.out.print(ans);
    }

}

// reverse() 사용
/*
public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                StringBuilder temp = new StringBuilder(st.nextToken());
                ans.append(temp.reverse() + " ");
            }
            ans.append("\n");
        }
        System.out.println(ans);
    }
 */