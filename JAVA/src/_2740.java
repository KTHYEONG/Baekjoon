import java.util.Scanner;
/*

행렬 A, B를 2차원배열로 생성 후 연산하여 2차원 배열 C에 저장

 */
// 행렬 곱셈
public class _2740 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] A = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = sc.nextInt();
            }
        }

        int M = sc.nextInt();
        int k = sc.nextInt();
        int[][] B = new int[M][k];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < k; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        // 연산의 핵심 부분
        int[][] C = new int[n][k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int sum = 0;
                for (int l = 0; l < m; l++) {
                    sum += A[i][l] * B[l][j];
                }
                C[i][j] = sum;
            }
        }
        for (int[] temp : C) {
            for (int num : temp) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

/*
행렬을 Matrix라는 Class를 생성하여 표현 후 곱셈을 처리함 // 채점에서 negativeindex error 발생

public class _2740 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        Matrix A = new Matrix(n, m, true);

        int M = sc.nextInt();
        int k = sc.nextInt();
        Matrix B = new Matrix(M, k, true);

        Matrix ans = Matrix.MatrixMul(A, B);
        System.out.println(ans.toString());
    }
}

class Matrix {
    Scanner sc = new Scanner(System.in);
    int n, m;
    int arr[][];

    public Matrix(int n, int m, boolean flag) {
        this.n = n;
        this.m = m;
        arr = new int[n][m];
        if (flag)
            GetElement(n, m);
    }

    public void GetElement(int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this.arr[i][j] = sc.nextInt();
            }
        }
    }

    public static Matrix MatrixMul(Matrix A, Matrix B) {
        // (n x m) X (m x k) --> (n x k)
        Matrix res = new Matrix(A.n, B.m, false);

        for (int i = 0; i < A.n; i++) {
            for (int j = 0; j < B.m; j++) {
                int sum = 0;
                for (int k = 0; k < A.m; k++) {
                    sum += A.arr[i][k] * B.arr[k][j];
                }
                res.arr[i][j] = sum;
            }
        }

        return res;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.append(arr[i][j]).append(" ");
            }
            result.append("\n");
        }
        return result.toString();
    }
}
*/