import java.util.Scanner;

public class _2566 {
    public static void main(String[] args) {
        int arr[][] = new int[9][9];
        Scanner sc = new Scanner(System.in);

        int max = -1, x = 0, y = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                arr[i][j] = sc.nextInt();
                if (arr[i][j] > max)
                {
                    max = arr[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        
        System.out.println(max);
        System.out.printf("%d %d", x + 1, y + 1);
    }
    
}