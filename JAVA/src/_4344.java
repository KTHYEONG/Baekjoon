import java.util.ArrayList;
import java.util.Scanner;

public class _4344 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int c = sc.nextInt();
        for (int i = 0; i < c; i++)
        {
            ArrayList<Integer> arr = new ArrayList<>();
            int n = sc.nextInt();
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                int num = sc.nextInt();
                arr.add(num);
                sum += num;
            }

            double avg = (double) (sum / n);
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if ((double) arr.get(j) > avg) {
                    cnt++;
                }
            }
            System.out.printf("%.3f%%\n", (double)cnt / n * 100);
        }
    }
}
