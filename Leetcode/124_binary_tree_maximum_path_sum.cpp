#include <iostream>

#define MAX 0xfff3fff
using namespace std;

/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/08/19 13:15
	Description: 对于每个子树的根节点，四种情况:
				1.左子树最大路径+根节点 
				2.右子树最大路径+根节点
				3.左子树最大路径+根节点+右子树最大路径
				4.根节点 
*/


/**
 * Definition for a binary tree node.
 * 
 */
 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int dfs(TreeNode* root){
		int v = root->val;
		
		if(root->left==NULL && root->right==NULL){
			if(v > maxSum) maxSum = v;
			return v;
		}
		
		int leftRes = -MAX, rightRes = -MAX;
		if(root->left!=NULL){
			leftRes = dfs(root->left);
		}
		if(root->right!=NULL){
			rightRes = dfs(root->right);
		}
		
		if((root->left!=NULL)&&(root->left!=NULL)&&(leftRes+v+rightRes>maxSum)){
			maxSum = leftRes + v + rightRes;
		}
		
		int res = (leftRes > rightRes) ? leftRes+v : rightRes + v;
		res = (res > v) ? res : v;
		
		if(res>maxSum) maxSum = res;
		
		return res;
	}
	
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        int res = dfs(root);
        if(res>maxSum) maxSum = res;
        return maxSum;
    }
private:
	int maxSum;
};

int main(){
//	TreeNode *root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);

//	TreeNode *root = new TreeNode(-10);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
	
	TreeNode *root = new TreeNode(-10);
	
	Solution su = Solution();
	int res = su.maxPathSum(root);
	
	cout << res << endl;
	
	return 0;
}
