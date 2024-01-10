import java.util.Scanner;

// 팰린드롬 만들기
public class _1254 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        int SLen = S.length();
        for (int i = 0; i < SLen; i++) {
            if (isPalindrome(S.substring(i))) {
                break;
            }
            SLen++;
        }
        System.out.println(SLen);
    }

    // 팰린드롬 체크
    // substring 중 팰린드롬을 찾고,
    // 찾은 경우 앞쪽 문자열을 찾은 부분의 뒤쪽에 추가하면 팰린드롬 만들기 가능
    public static boolean isPalindrome(String str) {
        int front = 0;
        int back = str.length() - 1;
        while (front <= back) {
            if (str.charAt(front) != str.charAt(back)) {
                return false;
            }
            front++;
            back--;
        }

        return true;
    }
}
