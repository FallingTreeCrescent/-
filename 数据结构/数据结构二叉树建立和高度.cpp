#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
char a[10001], b[10001];
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Tree, *ptr;
Tree *buildTree(char *midorder, int midorderSize, char *postorder, int postorderSize) //�кͺ�
{
	if (midorderSize == 0)
	{
		return NULL;
	}
	if(midorderSize!=postorderSize)
	{
		printf("INVALID\n");
		return NULL;
	}
	Tree *root = (Tree *)malloc(sizeof(Tree));
	root->data = postorder[postorderSize - 1]; //���ں������һλ
	int flag=0;
	for(int j=0;j<midorderSize;j++)
	{
		flag=0;
		for(int o=0;o<postorderSize;o++)
		{
			if(postorder[o] == midorder[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("INVALID\n");//�ݹ�ʱ�����2�� 
			return NULL;
		}
	}
	int i = 0;
	while(i < midorderSize)//���������λ��
	{
		if (midorder[i] == postorder[postorderSize - 1])
		{
			break;
		}
		i++;
	}
	root->left = buildTree(midorder, i, postorder, i);//�ݹ鹹����� 
	root->right = buildTree(midorder + i + 1, midorderSize - i - 1, postorder + i, postorderSize - i - 1);//�ݹ鹹���ұ� 
	return root;
}
void print(Tree *p)
{
	if (p == NULL)
	{
		// printf("INVALID");
		return;
	}
	else
	{
		printf("%c", p->data);
		print(p->left);
		print(p->right);
	}
}
int height(Tree *p)
{
	if (p == NULL)
		return 0;
	return max(1 + height(p->left), height(p->right));
}
int main()
{
	while(cin >> a >> b)// a��b��
	{
	int asize = strlen(a);
	int bsize = strlen(b);
	if(asize!=bsize||a[0]!=b[0])
	{
		printf("INVALID\n");
		continue;
	}
	// cout<<n<<endl<<m;
	Tree *c;
	c = buildTree(b, bsize, a, asize);
	if(c==NULL)continue;
	int chigh=height(c); 
	if (chigh == 0)
	{
		printf("INVALID\n");
		continue;
	}
	printf("%d\n", chigh);
	print(c);
	printf("\n");
    }
	return 0;
}
/*CEFDBHGA
CBEDFAGH*/

/*EFCGIHDBA
ECFBGDHIA
*/

/*BCA
CAB*/

/*CBEDFAGH
CEFDBHGA*/
