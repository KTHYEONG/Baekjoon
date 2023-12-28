import java.util.Scanner;

// 막대기
public class _1094 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int X = sc.nextInt();

        int cnt = 0;
        int num = 64;
        while (X > 0) {
            if (num > X) {
                num /= 2;
            }
            else {
                X -= num;
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
