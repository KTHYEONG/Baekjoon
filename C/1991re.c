#include <stdio.h>  // 트리 순회  // 이진트리 개념, 구현 복습
#include <stdlib.h>

typedef struct node
{
	struct node* left;
	struct node* right;
	char data;
}node;

node* newnode(char data)
{
	node* New;
	New = (node*)malloc(sizeof(node));
	New->data = data;
	New->left = NULL;
	New->right = NULL;
	return New;
}

node* search(node* Nn, char data)
{
	if (Nn != NULL)
	{
		if (Nn->data == data)
		{
			return Nn;
		}
		else
		{
			node* Nn2 = search(Nn->left, data);
			if (Nn2 != NULL)
			{
				return Nn2;
			}
			return search(Nn->right, data);
		}
	}
	else
		return NULL;
}

void setnode(node* Nn, char a, char b, char c)
{
	Nn->data = a;
	if (b != '.')
	{
		Nn->left = newnode(b);
	}
	if (c != '.')
	{
		Nn->right = newnode(c);
	}
}

void preorder(node* Nn)
{
	if (Nn != NULL)
	{
		printf("%c", Nn->data);
	}
	if (Nn->left != NULL)
	{
		preorder(Nn->left);
	}
	if (Nn->right != NULL)
	{
		preorder(Nn->right);
	}
}

void inorder(node* Nn)
{
	if (Nn->left != NULL)
	{
		inorder(Nn->left);
	}
	if (Nn != NULL)
	{
		printf("%c", Nn->data);
	}
	if (Nn->right != NULL)
	{
		inorder(Nn->right);
	}
}

void postorder(node* Nn)
{
	if (Nn->left != NULL)
	{
		postorder(Nn->left);
	}
	if (Nn->right != NULL)
	{
		postorder(Nn->right);
	}
	if (Nn != NULL)
	{
		printf("%c", Nn->data);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	getchar();

	node* Nn = newnode(NULL);
	node* temp;

	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar();

		temp = search(Nn, a);
		if (temp != NULL)
		{
			setnode(temp, a, b, c);
		}
		else
		{
			setnode(Nn, a, b, c);
		}
	}

	preorder(Nn);
	printf("\n");
	inorder(Nn);
	printf("\n");
	postorder(Nn);

	return 0;
}

/*void preorder(node* Nn)
{
	if (Nn == NULL)
	{
		return;
	}
	else
	{
		printf("%c", Nn->data);
		preorder(Nn->left);
		preorder(Nn->right);
	}
}

void inorder(node* Nn)
{
	if (Nn == NULL)
	{
		return;
	}
	else
	{
		inorder(Nn->left);
		printf("%c", Nn->data);
		inorder(Nn->right);
	}
}

void postorder(node* Nn)
{
	if (Nn == NULL)
	{
		return;
	}
	else
	{
		postorder(Nn->left);
		postorder(Nn->right);
		printf("%c", Nn->data);
	}
}*/