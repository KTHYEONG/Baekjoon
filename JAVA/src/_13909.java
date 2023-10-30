import java.util.Scanner;

/*

[첫 풀이] 이중 반복문 + 배열에 저장하는 방법 --> 실패 by 메모리 초과(because n 범위가 21억까지 가능)

 */

// 창문 닫기
public class _13909 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            ans++;
        }

        System.out.println(ans);
    }
}
