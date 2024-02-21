import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 폴리오미노
public class _1343 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String data = br.readLine();

        data = data.replaceAll("XXXX", "AAAA");
        data = data.replaceAll("XX", "BB");

        if (data.contains("X")) {
            System.out.println(-1);
        }
        else {
            System.out.println(data);
        }
    }
}
