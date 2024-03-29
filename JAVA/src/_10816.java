import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 숫자 카드 2
public class _10816 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");
        int[] card = new int[N];
        for (int i = 0; i < N; i++) {
            card[i] = Integer.parseInt(data[i]);
        }

        Arrays.sort(card);

        int M = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        String[] find = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            int num = Integer.parseInt(find[i]);
            ans.append(upperBound(card, num, N) - lowerBound(card, num, N)).append(' ');
        }

        System.out.println(ans);
    }

    public static int lowerBound(int[] arr, int findNum, int n) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (findNum <= arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    public static int upperBound(int[] arr, int findNum, int n) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (findNum < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}
