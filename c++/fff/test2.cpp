
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
	bool hasPathSum(TreeNode *root, int sum) {
		int tmpSum = 0;
		TreeNode *p = root;
		while (p)
		{
			tmpSum += p->val;
			if ((p->right == NULL) || (p->left == NULL))
			{
				p = root;
				if (sum == tmpSum)
				{
					sum = 0;
					return true;
				}
				sum = 0;
			}
			else if (p->left == NULL)
			{
				p = p->right;
			}
			else if (p->right == NULL)
			{
				p = p->left;
			}			
		}

		return false;

	}
};

int main2()
{
	TreeNode a5(5);
	TreeNode a4(4);
	TreeNode a11(11);
	TreeNode a7(7);
	TreeNode a2(2);
	TreeNode a8(8);
	TreeNode a13(13);
	TreeNode a4_r(4);
	TreeNode a1(1);


	a5.left = &a4;
	a4.left = &a11;
	a11.left = &a7;
	a11.right = &a2;

	a5.right = &a8;
	a8.left = &a13;
	a8.right = &a4_r;
	a4_r.right = &a1;

	Solution s;
	s.hasPathSum(&a5, 22);

	


	return 0;
}