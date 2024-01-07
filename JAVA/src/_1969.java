import java.util.Scanner;

// DNA
public class _1969 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        String[] arr = new String[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.next();
        }

        int HD = 0;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < M; i++) {
            int[] cnt = new int[4];
            for (int j = 0; j < N; j++) {
                char c = arr[j].charAt(i);
                switch (c) {
                    case 'A':
                        cnt[0]++;
                        break;
                    case 'C':
                        cnt[1]++;
                        break;
                    case 'G':
                        cnt[2]++;
                        break;
                    case 'T':
                        cnt[3]++;
                        break;
                }
            }

            int idx = 0;
            int max = 0;
            for (int j = 0; j < 4; j++) {
                if (cnt[j] > max) {
                    max = cnt[j];
                    idx = j;
                }
            }
            HD += N - max;

            switch (idx) {
                case 0:
                    ans.append('A');
                    break;
                case 1:
                    ans.append('C');
                    break;
                case 2:
                    ans.append('G');
                    break;
                case 3:
                    ans.append('T');
                    break;
            }
        }

        System.out.println(ans);
        System.out.println(HD);
    }
}
