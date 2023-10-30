import java.util.Arrays;
import java.util.Scanner;
/*
행렬을 Matrix라는 Class를 생성하여 표현 후 곱셈을 처리함
*/

// 행렬 곱셈
public class _2740 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        Matrix A = new Matrix(n, m, true);

        int k = sc.nextInt();
        Matrix B = new Matrix(m, k, true);

        Matrix ans = Matrix.MatrixMul(A, B);
        System.out.println(ans.arr.toString());
    }
}

class Matrix {
    Scanner sc = new Scanner(System.in);
    int n, m;
    int arr[][] = new int[n][m];

    public Matrix(int n, int m, boolean flag) {
        this.n = n;
        this.m = m;
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
                res.arr[i][j] = A.arr[j][i] * B.arr[i][j];
            }
        }

        return res;
    }
}
