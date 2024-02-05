import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 꿀 따기
public class _21758 {
    static int max = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] data = br.readLine().split(" ");

        int[] arr = new int[N];
        int[] toRightarr = new int[N];
        int[] toLeftarr = new int[N];
        int temp = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(data[i]);
            temp += arr[i];
            toRightarr[i] = temp;
        }
        temp = 0;
        for (int i = N - 1; i >= 0; i--) {
            temp += arr[i];
            toLeftarr[i] = temp;
        }

        int total = toRightarr[N - 1];
        // 벌통 -> 맨 오른쪽 고정, 벌1 -> 맨 왼쪽 고정, 벌2 -> 위치 이동
        case1(arr, toRightarr, N, total);
        // 벌통 -> 맨 왼쪽 고정, 벌1 -> 맨 오른쪽 고정, 벌2 -> 위치 이동
        case2(arr, toLeftarr, N, total);
        // 벌1 -> 맨 왼쪽 고정, 벌2 -> 맨 오른쪽 고정, 벌통 -> 위치 이동
        case3(arr, toRightarr, toLeftarr, N);

        System.out.println(max);
    }

    public static void case1(int[] arr, int[] toRightarr, int n, int total) {
        int bee1, bee2;
        for (int i = 1; i < n - 1; i++) {
            bee1 = total - arr[0] - arr[i];
            bee2 = total - toRightarr[i];
            max = Math.max(max, bee1 + bee2);
        }
    }

    public static void case2(int[] arr, int[] toLeftarr, int n, int total) {
        int bee1, bee2;
        for (int i = n - 2; i > 0; i--) {
            bee1 = total - arr[n - 1] - arr[i];
            bee2 = total - toLeftarr[i];
            max = Math.max(max, bee1 + bee2);
        }
    }

    public static void case3(int[] arr, int[] toRightarr, int[] toLeftarr, int n) {
        int bee1, bee2;
        for (int i = 1; i < n - 1; i++) {
            bee1 = toRightarr[i] - arr[0];
            bee2 = toLeftarr[i] - arr[n - 1];
            max = Math.max(max, bee1 + bee2);
        }
    }
}
