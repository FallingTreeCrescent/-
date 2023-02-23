#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
string a;
int b[100002];
typedef struct Tree
{
	int weight;
	int parent, lchild, rchild;
} TreeNode;
typedef struct HFTree
{
	TreeNode *data;
	int length;
} HFTree;
HFTree *initTree(int *weight, int length)//初始化哈夫曼树 
{
	HFTree *T = (HFTree *)malloc(sizeof(HFTree));
	T->data = (TreeNode *)malloc(sizeof(TreeNode) * (2 * length - 1));
	T->length = length;
	for (int i = 0; i < length; i++)
	{
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].rchild = -1;
		T->data[i].lchild = -1;
	}
	return T;
}
int *selectMin(HFTree *T)//选出第一小和第二小的值 
{
	int min = 10000;
	int secondMin = 10000;
	int minIndex;
	int secondIndex;
	for (int i = 0; i < T->length; i++)
	{
		if (T->data[i].parent == 0)
		{
			if (T->data[i].weight < min)
			{
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++)
	{
		if (T->data[i].parent == 0 && i != minIndex)//排除第一小找第二小 
		{
			if (T->data[i].weight < secondMin)
			{
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int *res = (int *)malloc(sizeof(int) * 2);//因为返回两个值 
	res[0] = minIndex;//一号元素最小
	res[1] = secondIndex;//二号元素第二小 
	return res;
}
void createTree(HFTree *T)//创建哈夫曼树 
{
	int *res;
	int min;
	int secondMin;
	int length = T->length * 2 - 1;
	for (int i = T->length; i < length; i++)
	{
		res = selectMin(T);//找两个最小数下标 
		min = res[0];
		secondMin = res[1];//赋值找到的两个最小数下标
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;//构建父亲 
		T->data[i].rchild = secondMin;
		T->data[i].lchild = min;
		T->data[min].parent = i;
		T->data[secondMin].parent = i;//指回父亲 
		T->length++;//长度+1 
	}
}
void preorder(HFTree *T,int index)//遍历哈夫曼树 
{
	if(index!=-1)
	{
		printf("%d ", T->data[index].weight);
		preorder(T,T->data[index].lchild);
		preorder(T,T->data[index].rchild);
	}
}
int main()
{
	int weight[7]={5,6,4,3,7,2,1};
	HFTree *Tree=initTree(weight,7);
	createTree(Tree);
	preorder(Tree,Tree->length-1);
	printf("\n");
	return 0;
}
