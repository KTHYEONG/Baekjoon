import java.io.*;
import java.util.Stack;

// 후위 표기식2
public class _1935 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String input = br.readLine();
        Stack<Double> stack = new Stack<>();

        // arr에 피연산자 저장
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < input.length(); i++) {
            char data = input.charAt(i);
            // 피연산자의 경우 --> stack에 push
            if (data >= 'A' && data <= 'Z') {
                stack.push((double) arr[data - 'A']);
            }
            // 연산자의 경우
            else {
                double num1 = stack.pop();
                double num2 = stack.pop();
                double res = 0.0;
                switch (data) {
                    case '*':
                        res = num1 * num2;
                        break;
                    case '/':
                        res = num2 / num1;
                        break;
                    case '+':
                        res = num1 + num2;
                        break;
                    case '-':
                        res = num2 - num1;
                }
                stack.push(res);
            }
        }

        String ans = String.format("%.2f", stack.pop());
        bw.write(ans);

        bw.flush();
        bw.close();

    }
}