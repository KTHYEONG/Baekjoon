import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Z
public class _1074 {
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int r = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);

        int size = (int) Math.pow(2, N);
        solution(size, r, c);
        System.out.println(cnt);
    }

    // 해당되는 사분면으로 재귀
    public static void solution(int s, int r, int c) {
        if (s == 1)
            return;

        // 왼쪽 위
        if (r < s / 2 && c < s / 2) {
            solution(s / 2, r, c);
        }
        // 오른쪽 위
        else if (r < s / 2 && c >= s / 2) {
            cnt += s * s / 4;
            solution(s / 2, r, c - s / 2);
        }
        // 왼쪽 아래
        else if (r >= s / 2 && c < s / 2) {
            cnt += s * s / 4 * 2;
            solution(s / 2, r - s / 2, c);
        }
        // 오른쪽 아래
        else {
            cnt += s * s / 4 * 3;
            solution(s / 2, r - s / 2, c - s / 2);
        }
    }
}
