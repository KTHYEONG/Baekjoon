import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// 스택 수열
public class _1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        StringBuilder ans = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        int num = 1;
        for (int i = 0; i < n; i++) {
            int arrNum = arr[i];

            // push
            while (num <= arrNum) {
                stk.push(num++);
                ans.append("+\n");
            }
            // pop
            while (!stk.isEmpty() && stk.peek() == arrNum) {
                stk.pop();
                ans.append("-\n");
            }
        }

        if (stk.isEmpty())
            System.out.println(ans);
        else
            System.out.println("NO");
    }
}
