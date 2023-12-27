import java.util.Scanner;

// 터렛
public class _1002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int r1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            int r2 = sc.nextInt();
            
            // 두 원의 접점 개념 이용
            double distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            int ans = 0;
            if (x1 == x2 && y1 == y2 && r1 == r2) {
                ans = -1;
            }
            // 서로 만나지 않을 때
            else if (distance > r1 + r2 || distance < Math.abs(r2 - r1)) {
                ans = 0;
            }
            // 외접 && 내접
            else if (distance == r1 + r2 || distance == Math.abs(r2 - r1)) {
                ans = 1;
            }
            else
                ans = 2;
            System.out.println(ans);
        }
    }
}
