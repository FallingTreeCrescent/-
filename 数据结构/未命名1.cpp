void DeletNode(BSTree *parent, BSTree *cur, int DelData)
 4 {
 5     BSTree *SNode = NULL; //��̽ڵ�
 6     BSTree *PSNode = NULL;    //��̽ڵ�ĸ��ڵ�
 7 
 8     if (cur == NULL)
 9     {
10         printf("ɾ���ڵ㲻����\n");
11         exit(0);
12     }
13     else if (DelData > cur->data)
14     {
15         DeletNode(cur, cur->right, DelData);
16     }
17     else if (DelData < cur->data)
18     {
19         DeletNode(cur, cur->left, DelData);
20     }
21     else if(DelData == cur->data)
22     {
23         if (cur->left == NULL && cur->right == NULL)    //��ɾ���ڵ�ΪҶ�ӽڵ�
24         {
25             if (parent->left == cur)    //����ýڵ��Ǹ��ڵ��������
26             {
27                 parent->left = NULL;
28             }
29             else if (parent->right == cur)    //����ýڵ��Ǹ��ڵ��������
30             {
31                 parent->right = NULL;
32             }
33         }
else if(cur->left != NULL && cur->right == NULL)    //��ɾ���ڵ�ֻ��������
 2         {
 3             if (parent->left == cur)
 4             {
 5                 parent->left = cur->left;
 6             }
 7             else if (parent->right == cur)
 8             {
 9                 parent->right = cur->left;
10             }
11             free(cur);    //�ͷŴ�ɾ���ڵ�
12         }
13         else if(cur->left == NULL && cur->right != NULL)    //��ɾ���ڵ�ֻ��������
14         {
15             if (parent->left == cur)
16             {
17                 parent->left = cur->right;
18             }
19             else if (parent->right == cur)
20             {
21                 parent->right = cur->right;
22             }
23             free(cur);    //�ͷŴ�ɾ���ڵ�
24         }
else if(cur->left != NULL && cur->right != NULL)    //��ɾ���ڵ����������Ҳ��������
 2         {
 3             SNode = SearchSuccessorNode(cur->right);    //������̽ڵ�
 4             PSNode = SearchParentofSNode(cur->right, cur->right);    //������̽ڵ�ĸ��ڵ�
 5 
 6             if (cur->right == SNode)    //��̽ڵ�Ϊ��ɾ���ڵ������������̽ڵ�����������û���������Ĳ�����ͬ��
 7             {
 8                 if (parent->left == cur)
 9                 {
10                     parent->left = SNode;
11                     SNode->left = cur->left;
12 
13                     free(cur);
14                 }
15                 else if (parent->right == cur)
16                 {
17                     parent->right = SNode;
18                     SNode->left = cur->left;
19 
20                     free(cur);
21                 }
22             }
else if (cur->right != SNode && SNode->right == NULL)    //��̽ڵ㲻Ϊ��ɾ���ڵ�������������Ҹú�̽ڵ�û��������
 2             {
 3                 if (parent->left == cur)
 4                 {
 5                     parent->left = SNode;
 6                     SNode->left = cur->left;
 7                     SNode->right = cur->right;
 8                     PSNode->left = NULL;
 9 
10                     free(cur);
11                 }
12                 else if (parent->right == cur)
13                 {
14                     parent->right = SNode;
15                     SNode->left = cur->left;
16                     SNode->right = cur->right;
17                     PSNode->left = NULL;
18 
19                     free(cur);
20                 }
21             }
