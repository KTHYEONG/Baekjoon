import java.io.*;
import java.util.Stack;

// 단어 뒤집기 2
// STACK
public class _17413 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String input = br.readLine();
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < input.length(); i++) {
            char data = input.charAt(i);
            if (data == '<') {
                // '<' 이전에 알파벳이 나온 경우 처리해주기(먼저 출력)
                while (!stack.isEmpty()) {
                    bw.write(stack.pop());
                }
                // '<' 나타난 경우 '>' 등장 전까지 그래도 출력하기(공백 상관 x)
                while (data != '>') {
                    bw.write(data);
                    data = input.charAt(++i);
                }
                bw.write('>');
            }
            // 공백이 나타난 경우 stack에 담았던 내용 출력(한단어 종료)
            else if (data == ' ') {
                while (!stack.isEmpty()) {
                    bw.write(stack.pop());
                }
                bw.write(' ');
            }
            else {
                stack.push(data);
            }
        }
        // stack의 남은 data 모두 출력하기
        while (!stack.isEmpty()) {
            bw.write(stack.pop());
        }

        bw.flush();
        bw.close();
    }
}
