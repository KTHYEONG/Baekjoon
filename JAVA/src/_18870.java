import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// 좌표 압축
public class _18870 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int[] temp = arr.clone();
        Arrays.sort(temp);

        // Key값 중복 x 특징 이용 --> Map
        Map<Integer, Integer> table = new HashMap<>();
        int num = 0;
        for (int element : temp) {
            if (!table.containsKey(element)) {
                table.put(element, num++);
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int element : arr) {
            ans.append(table.get(element)).append(' ');
        }
        System.out.print(ans.toString());
    }
}
