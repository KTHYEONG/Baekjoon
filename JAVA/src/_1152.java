import java.util.Scanner;
import java.util.StringTokenizer;

public class _1152 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = new String();

        // 문자열 입력 받고 띄어쓰기를 기준으로 토큰으로 분리
        str = sc.nextLine();
        StringTokenizer ST = new StringTokenizer(str);
        System.out.println(ST.countTokens());
    }
}