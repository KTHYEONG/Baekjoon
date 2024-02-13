import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 순서쌍의 곱의 합
public class _13900 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");

        long sum = 0;
        long[] arr = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = arr[i - 1] + Integer.parseInt(data[i - 1]);
            sum += arr[i - 1] * Integer.parseInt(data[i - 1]);
        }

        System.out.println(sum);
    }
}
