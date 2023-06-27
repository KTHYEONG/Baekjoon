import java.io.*;
import java.util.Stack;

// 에디터
public class _1406 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Character> left_stk = new Stack<>();
        Stack<Character> right_stk = new Stack<>();

        // left_stk에 초기 문자열 저장
        String str = br.readLine();
        for (char temp : str.toCharArray()) {
            left_stk.push(temp);
        }

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String command = br.readLine();
            char c = command.charAt(0);

            switch (c) {
                case 'L': // 왼쪽으로 옮기는 것을 left_stk에 push하는 방식으로 구현
                    if (!left_stk.isEmpty()) {
                        right_stk.push(left_stk.pop());
                    }
                    break;
                case 'D': // 오른쪽으로 옮기는 것을 right_stk에 push하는 방식으로 구현
                    if (!right_stk.isEmpty()) {
                        left_stk.push(right_stk.pop());
                    }
                    break;
                case 'B': // 삭제
                    if (!left_stk.isEmpty()) {
                        left_stk.pop();
                    }
                    break;
                case 'P': // 추가
                    char data = command.charAt(2);
                    left_stk.push(data);
            }
        }

        // STACK의 LIFO 구조로 인하여 왼쪽스택의 내용을 오른쪽 스택으로 이동 후 출력
        while (!left_stk.isEmpty()) {
            right_stk.push(left_stk.pop());
        }
    
        // 최종 출력
        while (!right_stk.isEmpty()) {
            bw.write(right_stk.pop());
        }

        bw.flush();
        bw.close();
    }
}
