import java.io.*;

// 날짜 계산
public class _1476 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int e = Integer.parseInt(input[0]);
        int s = Integer.parseInt(input[1]);
        int m = Integer.parseInt(input[2]);

        int ans = 0;
        int e_temp = 0, s_temp = 0, m_temp = 0;
        while (!(e == e_temp && s == s_temp && m == m_temp)) {
            e_temp++; s_temp++; m_temp++;
            if (e_temp > 15)
                e_temp = 1;
            if (s_temp > 28)
                s_temp = 1;
            if (m_temp > 19)
                m_temp = 1;

            ans++;
        }
        bw.write(ans + "");


        bw.flush();
        bw.close();
    }
}
