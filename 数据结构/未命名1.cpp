void DeletNode(BSTree *parent, BSTree *cur, int DelData)
 4 {
 5     BSTree *SNode = NULL; //后继节点
 6     BSTree *PSNode = NULL;    //后继节点的父节点
 7 
 8     if (cur == NULL)
 9     {
10         printf("删除节点不存在\n");
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
23         if (cur->left == NULL && cur->right == NULL)    //待删除节点为叶子节点
24         {
25             if (parent->left == cur)    //如果该节点是父节点的左子树
26             {
27                 parent->left = NULL;
28             }
29             else if (parent->right == cur)    //如果该节点是父节点的右子树
30             {
31                 parent->right = NULL;
32             }
33         }
else if(cur->left != NULL && cur->right == NULL)    //待删除节点只有左子树
 2         {
 3             if (parent->left == cur)
 4             {
 5                 parent->left = cur->left;
 6             }
 7             else if (parent->right == cur)
 8             {
 9                 parent->right = cur->left;
10             }
11             free(cur);    //释放待删除节点
12         }
13         else if(cur->left == NULL && cur->right != NULL)    //待删除节点只有右子树
14         {
15             if (parent->left == cur)
16             {
17                 parent->left = cur->right;
18             }
19             else if (parent->right == cur)
20             {
21                 parent->right = cur->right;
22             }
23             free(cur);    //释放待删除节点
24         }
else if(cur->left != NULL && cur->right != NULL)    //待删除节点既有左子树也有右子树
 2         {
 3             SNode = SearchSuccessorNode(cur->right);    //搜索后继节点
 4             PSNode = SearchParentofSNode(cur->right, cur->right);    //搜索后继节点的父节点
 5 
 6             if (cur->right == SNode)    //后继节点为待删除节点的右子树（后继节点有右子树和没有右子树的操作相同）
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
else if (cur->right != SNode && SNode->right == NULL)    //后继节点不为待删除节点的右子树，并且该后继节点没有右子树
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
