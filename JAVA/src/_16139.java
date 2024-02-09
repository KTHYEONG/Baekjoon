import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 인간-컴퓨터 상호작용
public class _16139 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        int q = Integer.parseInt(br.readLine());

        // 문자열의 각 위치까지의 알파벳의 개수를 누적합으로 저장
        int[][] cnt = new int[S.length() + 1][26];
        for (int i = 1; i <= S.length(); i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] = cnt[i - 1][j];
            }
            cnt[i][S.charAt(i - 1) - 'a'] += 1;
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < q; i++) {
            String[] data = br.readLine().split(" ");
            int alpha = data[0].charAt(0) - 'a';
            int l = Integer.parseInt(data[1]);
            int r = Integer.parseInt(data[2]);

            ans.append(cnt[r + 1][alpha] - cnt[l][alpha] + "\n");
        }

        System.out.println(ans);
    }
}
