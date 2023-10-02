import java.util.Arrays;
import java.util.Scanner;

// 숫자 카드
public class _10815 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] myNum = new int[n];
        for (int i = 0; i < n; i++) {
            myNum[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        int[] searchNum = new int[m];
        for (int i = 0; i < m; i++) {
            searchNum[i] = sc.nextInt();
        }

        // 이분탐색 조건 - 정렬
        Arrays.sort(myNum);

        for (int i = 0; i < m; i++) {
            if (Arrays.binarySearch(myNum, searchNum[i]) < 0) {
                System.out.print(0 + " ");
            }
            else {
                System.out.print(1 + " ");
            }
        }
    }
}
