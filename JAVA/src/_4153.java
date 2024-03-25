import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 직각삼각형
public class _4153 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder ans = new StringBuilder();
        while (true) {
            String[] data = br.readLine().split(" ");
            int[] arr = new int[data.length];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(data[i]);
            }

            if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
                break;
            }

            Arrays.sort(arr);

            int a = arr[0] * arr[0];
            int b = arr[1] * arr[1];
            int c = arr[2] * arr[2];

            if (c == (a + b)) {
                ans.append("right\n");
            }
            else {
                ans.append("wrong\n");
            }
        }

        System.out.println(ans);
    }
}
