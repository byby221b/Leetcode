/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 10:40
	Description:简单的二叉树遍历，主题题目要求root-to-leaf，
				因此必须加到叶结点才判断和是否相等
				Leetcode 113  
				
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
//  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	
	void dfs(TreeNode *curr_root,int curr_sum,vector<int> path){
		if(curr_root==NULL){
			return;
		}
		
		path.push_back(curr_root->val);
		if(curr_sum+(curr_root->val)==target && isLeaf(curr_root)){
			result.push_back(path);
			return;
		}
		
		dfs(curr_root->left,curr_sum+(curr_root->val),path);
		dfs(curr_root->right,curr_sum+(curr_root->val),path);
	}
	
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		target = sum;
        result.clear();
        vector<int> path;
        dfs(root,0,path);
        
        return result;
    }
    
private:
	int target;
	vector<vector<int>> result;
	bool isLeaf(TreeNode *root){
		return ((root!=NULL) && (root->left == NULL) && (root->right == NULL));
	};
};

int main(){
	
	/*test case 1
	struct TreeNode data [10];
	int value[10] = {5,4,8,11,13,4,7,2,5,1};
	for(int i=0;i<10;i++){
		data[i].val = value[i];
		data[i].left = NULL;
		data[i].right = NULL;
	}
	
	data[0].left = &(data[1]);
	data[0].right = &(data[2]);
	data[1].left = &(data[3]);
	data[2].left = &(data[4]);
	data[2].right = &(data[5]);
	data[3].left = &(data[6]);
	data[3].right = &(data[7]);
	data[5].left = &(data[8]);
	data[5].right = &(data[9]);
	*/
	struct TreeNode data [2];
	int value[10] = {1,2};
	for(int i=0;i<2;i++){
		data[i].val = value[i];
		data[i].left = NULL;
		data[i].right = NULL;
	}
	data[0].left = &(data[1]);
	
	
	Solution su = Solution();
	vector<vector<int>> res = su.pathSum(&(data[0]),22);
	cout << "size: " <<  res.size() << endl;
	for(int i=0;i<res.size();i++){
		vector<int> ans = res[i];
		for(int j=0;j<ans.size();j++){
			cout << ans[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

