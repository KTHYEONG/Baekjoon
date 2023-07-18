import java.io.*;
import java.util.Stack;

// 오등큰수
public class _17299 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        // cnt 배열에 숫자가 나온 횟수를 count한 값 저장
        int[] cnt = new int[1000001];
        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
        }

        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && (cnt[arr[stack.peek()]] < cnt[arr[i]])) {
                ans[stack.pop()] = arr[i];
            }

            stack.push(i);
        }

        while (!stack.isEmpty()) {
            ans[stack.pop()] = -1;
        }

        for (int num : ans) {
            bw.write(num + " ");
        }

        bw.flush();
        bw.close();
    }
}
