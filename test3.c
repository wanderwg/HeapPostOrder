typedef struct TreeNode Node;
void _PostOrder(Node* pRoot, int* pRes, int* index) {
	if (pRoot) {
		_PostOrder(pRoot->left, pRes, index);
		_PostOrder(pRoot->right, pRes, index);
		pRes[*index] = pRoot->val;
		(*index)++;
	}
}
int GetTreeSize(Node* pRoot) {
	if (pRoot == NULL)
		return 0;
	return GetTreeSize(pRoot->left) + GetTreeSize(pRoot->right) + 1;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* pRes = (int*)malloc(sizeof(int)*(*returnSize));
	if (pRes == NULL) {
		assert(0);
		return;
	}
	int index = 0;
	_PostOrder(root, pRes, &index);
	return pRes;
}

