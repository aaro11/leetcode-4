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

	//ƽ������� -- ����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ�������
    bool isBalanced(TreeNode *root) 
    {
		int height = 0;
		return IsAVL(root, height);
    }

	bool IsAVL(TreeNode * pRoot, int & height)
	{
		if (pRoot == NULL) // ������������  
		{
			height = 0;
			return true;
		}
		int heightLeft;
		bool resultLeft = IsAVL(pRoot->left, heightLeft);
		int heightRight;
		bool resultRight = IsAVL(pRoot->right, heightRight);
		if (resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) // ������������������AVL�����Ҹ߶�������1��������  
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
	    if(pRoot == NULL) // �ݹ����  
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