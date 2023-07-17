import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

// 오큰수
public class _17298 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        Stack<Integer> stack = new Stack<>();

        // stack에 index 저장
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && input[stack.peek()] < input[i]) {
                input[stack.pop()] = input[i];
            }

            stack.push(i);
        }

        // 오큰수가 없는 수 -> -1
        while (!stack.isEmpty()) {
            input[stack.pop()] = -1;
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans.append(input[i]).append(" ");
        }
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}