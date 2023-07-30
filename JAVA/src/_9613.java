import java.io.*;

// GCD 합
public class _9613 {
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

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            long sum = 0;
            String[] input = br.readLine().split(" ");
            for (int j = 1; j < Integer.parseInt(input[0]); j++) {
                for (int k = j + 1; k <= Integer.parseInt(input[0]); k++) {
                    sum += gcd(Integer.parseInt(input[j]), Integer.parseInt(input[k]));
                }
            }
            bw.write(sum + "\n");
        }


        bw.flush();
        bw.close();
    }
}
