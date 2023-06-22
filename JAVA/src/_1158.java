import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// 요세푸스 문제
public class _1158 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, k;
        n = sc.nextInt();
        k = sc.nextInt();

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            queue.offer(i);
        }

        System.out.print("<");
        while (queue.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                int temp = queue.poll();
                queue.offer(temp);
            }
            System.out.print(queue.poll() + ", ");
        }
        System.out.print(queue.poll() + ">");
    }
}