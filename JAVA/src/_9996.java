import java.util.Scanner;

// 한국이 그리울 땐 서버에 접소하지
public class _9996 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        String pattern = sc.next();

        StringBuilder front = new StringBuilder();
        StringBuilder back = new StringBuilder();
        boolean flag = true;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            if (c == '*') {
                flag = false;
            } else if (c != '*' && flag == true) {
                front.append(c);
            } else {
                back.append(c);
            }
        }

        for (int i = 0; i < N; i++) {
            boolean correct = true;
            String fileName = sc.next();
            int fileLen = fileName.length();
            
            // fileName이 주어진 패턴을 만족할 수 없는 경우
            if (front.length() + back.length() > fileLen) {
                correct = false;
            } else {
                // * 앞부분 체크
                for (int j = 0; j < front.length(); j++) {
                    if (front.charAt(j) != fileName.charAt(j)) {
                        correct = false;
                        break;
                    }
                }

                // * 뒷부분 체크
                for (int j = 0; j < back.length(); j++) {
                    if (back.charAt(back.length() - j - 1) != fileName.charAt(fileLen - j - 1)) {
                        correct = false;
                        break;
                    }
                }
            }

            if (correct == true) {
                System.out.println("DA");
            } else {
                System.out.println("NE");
            }
        }
    }
}
