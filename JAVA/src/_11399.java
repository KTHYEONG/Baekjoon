import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// ATM
public class _11399 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");

        int[] time = new int[N];
        for (int i = 0; i < N; i++) {
            time[i] = Integer.parseInt(data[i]);
        }

        Arrays.sort(time);

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += time[i];
            for (int j = 0; j < i; j++) {
                sum += time[j];
            }
        }

        System.out.println(sum);
    }
}
