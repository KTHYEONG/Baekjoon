import java.util.Scanner;

public class $2562 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int arr[] = new int[9];
        int max = -1, idx = 0;
        for (int i = 0; i < 9; i++)
        {
            arr[i] = sc.nextInt();
            if (arr[i] > max){
                max = arr[i];
                idx = i;
            }
        }
        System.out.printf("%d %d", max, idx + 1);
    }
}