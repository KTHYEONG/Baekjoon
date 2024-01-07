import java.util.Arrays;
import java.util.Scanner;

// 생일
public class _5635 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String trash = sc.nextLine();

        String[][] table = new String[n][4];
        for (int i = 0; i < n; i++) {
            table[i] = sc.nextLine().split(" ");
        }

        // 오름차순 정렬
        Arrays.sort(table, (a, b) -> {
            if (a[3].equals(b[3])) {
                if (a[2].equals(b[2])) {
                    return Integer.parseInt(a[1]) - Integer.parseInt(b[1]);
                }
                else {
                    return Integer.parseInt(a[2]) - Integer.parseInt(b[2]);
                }
            } else {
                return Integer.parseInt(a[3]) - Integer.parseInt(b[3]);
            }
        });

            System.out.println(table[n - 1][0]);
            System.out.println(table[0][0]);
        }
    }
