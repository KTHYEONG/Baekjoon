import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 개똥벌레
public class _3020 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int H = Integer.parseInt(input[1]);

        int[] stalagmite = new int[H + 2]; // 석순
        int[] stalactite = new int[H + 2]; // 종유석
        for (int i = 0; i < N / 2; i++) {
            int a = Integer.parseInt(br.readLine());
            stalagmite[a]++;

            int b = H - Integer.parseInt(br.readLine()) + 1;
            stalactite[b]++;
        }

        // 부분합 - dp
        for (int i = 1; i <= H; i++) {
            stalagmite[i] += stalagmite[i - 1];
        }
        for (int i = H; i >= 1; i--) {
            stalactite[i] += stalactite[i + 1];
        }

        int min = N + 1;
        int cnt = 0;
        for (int i = 1; i <= H; i++) {
            int goal = (stalagmite[H] - stalagmite[i - 1]) + (stalactite[1] - stalactite[i + 1]);
            if (goal < min) {
                min = goal;
                cnt = 1;
            } else if (goal == min) {
                cnt++;
            }
        }

        System.out.println(min + " " + cnt);
    }
}

/* 이진탐색
public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int H = Integer.parseInt(input[1]);

        int[] stalagmite = new int[N / 2]; // 석순
        int[] stalactite = new int[N / 2]; // 종유석
        for (int i = 0; i < N / 2; i++) {
            int a = Integer.parseInt(br.readLine());
            int b = Integer.parseInt(br.readLine());
            stalagmite[i] = a;
            stalactite[i] = b;
        }

        Arrays.sort(stalagmite);
        Arrays.sort(stalactite);

        // 1 ~ H 까지의 높이 중 각 높이 보다 큰 개수 카운트 (종유석 -> 초과 / 석순 -> 이상)
        int cnt = 0;
        int min = N;
        for (int i = 1; i <= H; i++) {
            int goal = BinarySearch(0, N / 2, i, stalagmite) + BinarySearch(0, N / 2, H - i + 1, stalactite);
            if (min > goal) {
                min = goal;
                cnt = 1;
            }
            else if (min == goal) {
                cnt++;
            }
        }
        System.out.println(min + " " + cnt);
    }

    static int BinarySearch(int left, int right, int h, int[] arr) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return arr.length - right;
    }
 */
