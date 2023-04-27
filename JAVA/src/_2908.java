import java.util.Scanner;
import java.util.StringTokenizer;

public class _2908 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = new String();
        str = sc.nextLine();

        // 토큰으로 두 숫자 구분 후 StringBuffer로 저장
        StringTokenizer ST = new StringTokenizer(str);
        StringBuffer num1 = new StringBuffer(ST.nextToken());
        StringBuffer num2 = new StringBuffer(ST.nextToken());

        // 각 토큰 뒤집기
        String re_num1 = num1.reverse().toString();
        String re_num2 = num2.reverse().toString();
        
        // 문자열을 숫자로 변환 후 크기비교
        int ans1 = Integer.parseInt(re_num1);
        int ans2 = Integer.parseInt(re_num2);
        if (ans1 > ans2)
            System.out.println(ans1);
        else
            System.out.println(ans2);
    }
}