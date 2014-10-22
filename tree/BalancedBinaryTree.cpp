// Balanced Binary Tree 

#include <iostream>

using namespace std;

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	//平衡二叉树 -- 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
    bool isBalanced(TreeNode *root) 
    {
		int height = 0;
		return IsAVL(root, height);
    }

	bool IsAVL(TreeNode * pRoot, int & height)
	{
		if (pRoot == NULL) // 空树，返回真  
		{
			height = 0;
			return true;
		}
		int heightLeft;
		bool resultLeft = IsAVL(pRoot->left, heightLeft);
		int heightRight;
		bool resultRight = IsAVL(pRoot->right, heightRight);
		if (resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) // 左子树和右子树都是AVL，并且高度相差不大于1，返回真  
		{
			height = max(heightLeft, heightRight) + 1;
			return true;
		}
		else
		{
			height = max(heightLeft, heightRight) + 1;
			return false;
		}
	}

	int GetDepth(TreeNode * pRoot)
	{  
	    if(pRoot == NULL) // 递归出口  
	        return 0;  
	    int depthLeft = GetDepth(pRoot->left);  
	    int depthRight = GetDepth(pRoot->right);  
	    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
	}
	
};

int main()
{
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(6);
	TreeNode a7(7);

	//a1.left = &a2;

	Solution s;
	s.isBalanced(&a1);

	return 0;
}