import java.io.*;

// 골드바흐의 추측
public class _6588 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 에라토스테네스의 체 이용
        boolean[] arr = new boolean[1000001];
        arr[0] = arr[1] = true;
        for (int i = 2; i * i <= 1000000; i++) {
            // i가 소수인 경우 --> i의 배수는 소수가 아님
            if (!arr[i]) {
                for (int j = i * i; j <= 1000000; j += i) {
                    arr[j] = true;
                }
            }
        }

        int input;
        while ((input = Integer.parseInt(br.readLine())) != 0) {
            for (int i = 2; i < input / 2; i++) {
                if (!arr[i] && !arr[input - i]) {
                    bw.write(input + " = " + i + " + " + (input - i) + "\n");
                    break;
                }
            }
        }

        bw.flush();
        bw.close();
    }
}