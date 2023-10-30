import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// 문자열 집합
public class _14425 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        Set<String> S = new HashSet<>();

        // 집합 {S} 문자열
        for (int i = 0; i < n; i++) {
            S.add(sc.next());
        }

        int ans = 0;

        // 검사 단계
        for (int i = 0; i < m; i++) {
            String check = sc.next();
            if (S.contains(check))
                ans++;
        }

        System.out.println(ans);
    }
}
