import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// 비밀번호 찾기
public class _17219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        Map<String, String> table = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String address = sc.next();
            String psw = sc.next();
            table.put(address, psw);
        }

        for (int i = 0; i < m; i++) {
            String find = sc.next();
            System.out.println(table.get(find));
        }

    }
}
