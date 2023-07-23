import java.io.*;

// 최대공약수와 최소공배수
public class _2609 {
    // 유클리드 호제법
    public static int gcd(int a, int b) {
        int c;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

        return a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int num1 = Integer.parseInt(input[0]);
        int num2 = Integer.parseInt(input[1]);

        int gcd = gcd(num1, num2);
        int lcm = num1 * num2 / gcd;
        bw.write(gcd + "\n" + lcm);


        bw.flush();
        bw.close();
    }
}
