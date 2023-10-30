import java.util.Scanner;

// 트리 순회
public class _1991 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Tree tree = new Tree();

        for (int i = 0; i < n; i++) {
            String[] input = sc.next().split(" ");
            char head = input[0].charAt(0);
            char left = input[1].charAt(0);
            char right = input[2].charAt(0);
            tree.CreateNode(head, left, right);
        }

        tree.preorder(tree.root);
        System.out.println();
        tree.inorder(tree.root);
        System.out.println();
        tree.postorder(tree.root);
    }
}

class Node {
    char data;
    Node left;
    Node right;

    Node(char data) {
        this.data = data;
    }
}

class Tree {
    public Node root = new Node('.');


    public void CreateNode(char data, char left, char right) {
        // 처음 트리 생성
        if (root == null) {
            root = new Node(data);

            // 왼쪽, 오른쪽 자식이 있는 경우에 추가
            if (left != '.') {
                root.left = new Node(left);
            }
            if (right != '.') {
                root.right = new Node(right);
            }
            // 새로운 노드 삽입 위치 탐색
        } else {
            search(root, data, left, right);
        }
    }

    public void search(Node root, char data, char left, char right) {
        if (root == null) {
            return;
            // 삽입할 위치 찾은 경우
        } else if (root.data == data) {
            if (left != '.') {
                root.left = new Node(left);
            }
            if (right != '.') {
                root.right = new Node(right);
            }
            // 삽입할 위치 못찾은 경우(왼쪽, 오른쪽 각각 탐색 시작)
        } else {
            search(root.left, data, left, right);
            search(root.right, data, left, right);
        }
    }

    public void preorder(Node root) {
        System.out.print(root.data);
        if (root.left != null) {
            preorder(root.left);
        }
        if (root.right != null) {
            preorder(root.right);
        }
    }

    public void inorder(Node root) {
        if (root.left != null) {
            inorder(root.left);
        }
        System.out.print(root.data);
        if (root.right != null) {
            inorder(root.right);
        }
    }
    public void postorder(Node root) {
        if (root.left != null) {
            postorder(root.left);
        }
        if (root.right != null) {
            postorder(root.right);
        }
        System.out.print(root.data);
    }

}
