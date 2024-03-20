import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 달팽이는 올라가고 싶다
public class _2869 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] data = br.readLine().split(" ");

        int A = Integer.parseInt(data[0]);
        int B = Integer.parseInt(data[1]);
        int V = Integer.parseInt(data[2]);

        // 정상에 도달하기 하루 전 까지 걸린 일수
        int day = (V - A) / (A - B);

        if ((V - A) % (A - B) != 0) {
            day++;
        }

        // 마지막날 오른 일수 추가
        System.out.println(day + 1);
    }
}
