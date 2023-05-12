import java.util.Scanner;
import java.util.Stack;

public class _9012 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++)
            System.out.println(solution(sc.next()));
    }

    public static String solution(String str) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < str.length(); i++) 
        {
            for (int j = 0; j < str.length(); j++) {
                char c = str.charAt(j);
                // ( 이면 무조건 push
                if (c == '(')
                    stack.push(c);
                else if (stack.isEmpty())
                    return "NO";
                else
                    stack.pop();
            }
        }
        // 문자열의 요소를 모두 처리 후 stack 무언가 남아있으면 잘못된 경우
            if (stack.isEmpty())
                return "YES";
            else
                return "NO";
    }
}