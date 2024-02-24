import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 뒤집기
public class _1439 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        int zero = 0, one = 0;

        if (S.charAt(0) == '0') {
            zero++;
        }
        else {
            one++;
        }
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i - 1) != S.charAt(i)) {
                if (S.charAt(i) == '0') {
                    zero++;
                }
                else {
                    one++;
                }
            }
        }

        System.out.println(Math.min(zero, one));
    }
}
