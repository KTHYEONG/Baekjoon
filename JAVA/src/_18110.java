import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// solved.ac
public class _18110 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        int start = (int) Math.round((double) n * 15 / 100);
        int end = n - start - 1;

        double sum = 0.0;
        int cnt = 0;
        while (start <= end) {
            sum += arr[start++];
            cnt++;
        }

        System.out.println(Math.round(sum / cnt));
    }
}
