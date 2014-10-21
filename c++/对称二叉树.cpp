
#include <iostream>
using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == NULL)
			return true;

		return Judge(root->left, root->right);
	}

	bool Judge(TreeNode *leftRoot, TreeNode *rightRoot)
	{
		if (leftRoot != NULL && rightRoot != NULL)
		{
			if (Judge(leftRoot->left, rightRoot->right) && Judge(leftRoot->right, rightRoot->left))
				return true;
			else
				return false;
		}
		else if (leftRoot == NULL && rightRoot == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	TreeNode a1(1);
	TreeNode a2_l(2);
	TreeNode a2_r(2);
	TreeNode a3_l(3);
	TreeNode a3_r(3);
	TreeNode a4(4);


	a1.left = &a2_l;
	a2_l.right = &a3_l;

	a1.right = &a2_r;
	a2_r.right = &a3_r;

	Solution s;
	s.isSymmetric(&a1);
	return 0;
}