import java.util.Arrays;
import java.util.Scanner;

// 단어 정렬
public class _1181 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        String[] table = new String[N];
        for (int i = 0; i < N; i++) {
            table[i] = sc.next();
        }

        // String 정렬
        Arrays.sort(table, (o1, o2) -> {
            if (o1.length() != o2.length()) {
                return o1.length() - o2.length();
            } else {
                return o1.compareTo(o2);
            }
        });

        // 중복 단어 제외 출력
        System.out.println(table[0]);
        for (int i = 1; i < N; i++) {
            if (!table[i].equals(table[i - 1]))
            System.out.println(table[i]);
        }
    }
}
