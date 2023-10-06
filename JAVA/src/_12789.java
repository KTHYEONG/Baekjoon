import java.util.Scanner;
import java.util.Stack;

// 도키도키 간식드리미
public class _12789 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Stack<Integer> tempLine = new Stack<>();

        int num = 1;
        for (int i = 0; i < n; i++) {
            int order = sc.nextInt();

            // 올바른 순서의 사람은 간식 받으러 가기
            if (num == order) {
                num++;
            } else {
                if (tempLine.isEmpty())
                    tempLine.push(order);
                else if (tempLine.peek() > order)
                    tempLine.push(order);
                else {
                    while (!tempLine.isEmpty() && num == tempLine.peek()) {
                        num++;
                        tempLine.pop();
                    }
                    tempLine.push(order);
                }
            }

        }

        // 임시 대기열에 남은 사람들이 올바른 순서대로 간식받을 차례
        while (!tempLine.isEmpty() && num == tempLine.peek()) {
            num++;
            tempLine.pop();
        }

        // stack이 비어있다 -> 임시대기열에 남은 사람들이 순서대로 간식을 받아감 -> Nice
        if (tempLine.isEmpty())
            System.out.println("Nice");
        else
            System.out.println("Sad");

    }
}
