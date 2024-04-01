import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// Hashing
public class _15829 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int L = Integer.parseInt(br.readLine());
        String data = br.readLine();

        long sum = 0;
        long pow = 1;
        for (int i = 0; i < data.length(); i++) {
            sum += ((data.charAt(i) - 96) * pow);
            pow = (pow * 31) % 1234567891;
        }
        System.out.println(sum % 1234567891);
    }
}
