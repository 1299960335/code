#include<stdio.h>
typedef char BTDataType ;
typedef struct BinaryTreeNode{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
void PrevOrder(BTNode* root)
{
	printf("%d", root->_data);
	if (root == NULL) {
		return;
	}
	printf("%d", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int size = 0;
//	++size;
//	TreeSize(root->_left);
//}
BTNode* CreateNpde(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int main()
{
	return 0;
}
int TreeleafSize(BTNode* root)
{
	if (root == NULL) {
		return 0;
	}
	if (root->_left == NULL) {
		return 1;
	}
	if (root->_right == NULL) {
		return 1;
	}
	return TreeleafSize(root->_left) + TreeleafSize(root->_right);

}