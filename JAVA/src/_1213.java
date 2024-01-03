import java.util.Scanner;

// 팰린드롬 만들기
public class _1213 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String name = sc.next();

        // input 문자열의 알파벳 개수 카운트
        int[] AlphabetCnt = new int[26];
        for (int i = 0; i < name.length(); i++) {
            AlphabetCnt[name.charAt(i) - 'A']++;
        }

        int odd = 0;
        int midNum = 0;
        for (int i = 0; i < AlphabetCnt.length; i++) {
            // 알파벳의 개수가 홀수인지 체크
            if (AlphabetCnt[i] % 2 != 0) {
                odd++;
                midNum = i;
            }

            // 개수가 홀수인 알파벳이 2개 이상이면 팰린드롬 만들기 불가능
            if (odd >= 2) {
                System.out.println("I'm Sorry Hansoo");
                return;
            }
        }

        Make_Palindrome(name, AlphabetCnt, midNum, odd);
    }

    public static void Make_Palindrome(String str, int[] arr, int mid, int odd) {
        StringBuilder FrontStr = new StringBuilder();

        // 팰린드롬의 앞쪽 절반만 먼저 채우기
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i] / 2; j++) {
                FrontStr.append((char) (i + 'A'));
            }
        }

        // 홀수 -> 중간(mid)과 나머지 절반 채우기
        // 짝수 -> 뒤쪽 절반을 reverse 하여 채우기
        String ans = FrontStr.toString();
        StringBuilder RemainStr = FrontStr.reverse();

        if (odd == 1) {
            ans += (char) (mid + 'A');
        }
        ans += (RemainStr);

        System.out.println(ans);
    }
}
