import java.util.Scanner;

public class _1157 {
    public static void Solution(String str) {
        int[] check_arr = new int[26];
        // 알파뱃 개수 확인하기
        for (int i = 0; i < str.length(); i++) {
            check_arr[str.charAt(i) - 'A']++;
        }

        // 가장 많이 나온 알파뱃의 개수와 인덱스 파악
        int max_cnt = 0;
        int max_idx = 0;
        for (int i = 0; i < 26; i++) {
            if (check_arr[i] > max_cnt) {
                max_cnt = check_arr[i];
                max_idx = i;
            }
        }

        // 가장 많이 나온 알파뱃이 여러 개인지 파악
        int flag = 0;
        for (int i = 0; i < 26; i++) {
            if (flag > 1)
                break;

            if (check_arr[i] == max_cnt)
                flag++;
        }

        if (flag > 1)
            System.out.println('?');
        else
            System.out.println((char) ('A' + max_idx));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = new String();
        input = sc.nextLine().toUpperCase();

        Solution(input);
    }
}