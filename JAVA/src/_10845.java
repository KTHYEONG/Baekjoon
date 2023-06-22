import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class _10845 {
    public static void main(String[] args) throws IOException {
        Queue<Integer> queue = new LinkedList<>();
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        int back_data = 0;
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            switch(command) {
                case "push":
                    int data = Integer.parseInt(st.nextToken());
                    queue.offer(data);
                    back_data = data;
                    break;
                case "pop":
                    if (queue.isEmpty())
                        System.out.println(-1);
                    else
                        System.out.println(queue.poll());

                    break;
                case "size":
                    System.out.println(queue.size());

                    break;
                case "empty":
                    if (queue.isEmpty())
                        System.out.println(1);
                    else
                        System.out.println(0);

                    break;
                case "front":
                    if (queue.isEmpty())
                        System.out.println(-1);
                    else
                        System.out.println(queue.peek());

                    break;
                case "back":
                    if (queue.isEmpty())
                        System.out.println(-1);
                    else
                        System.out.println(back_data);
            }
        }
    }
}
