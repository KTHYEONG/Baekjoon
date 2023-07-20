import java.io.*;
import java.util.Stack;

// 후위 표기식
public class _1918 {
    // 연산자의 우선순위 결정
    // *, / 의 우선순위가 +, - 보다 높음 --> *, / 가 +, - 보다 먼저 출력 되어야함
    public static int priority(char operator) {
        if (operator == '+' || operator == '-') {
            return 1;
        } else if (operator == '*' || operator == '/') {
            return 2;
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char data = input.charAt(i);
            // 연산자의 경우 우선순위에 따라서 처리
            if (data == '+' || data == '-' || data == '*' || data == '/') {
                while (!stack.isEmpty() && priority(data) <= priority(stack.peek())) {
                    bw.write(stack.pop());
                }
                stack.push(data);
            } else if (data == '(') {
                stack.push(data);
            } else if (data == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    bw.write(stack.pop());
                }
                // ')' 제거
                stack.pop();
            }
            // 피연산자의 경우
            else {
                bw.write(data);
            }
        }

        while (!stack.isEmpty()) {
            bw.write(stack.pop());
        }

        bw.flush();
        bw.close();
    }
}