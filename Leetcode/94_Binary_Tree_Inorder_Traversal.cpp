/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/08/19 11:11
	Description: ¶þ²æÊ÷ÖÐÐò±éÀú:µÝ¹é+µÝÍÆ 
*/

#include <iostream> 
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<int> res;
//    
//    void run(TreeNode* root){
//        if(root==NULL) return;
//        run(root->left);
//        res.push_back(root->val);
//        run(root->right);
//    }
//    
//    vector<int> inorderTraversal(TreeNode* root) {
//        run(root);
//        return res;
//    }
//};

class Solution {
public:
    vector<int> res;

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
//        if(root==NULL) return res;
        TreeNode* curr = root;
        
        while(!s.empty() || curr!=NULL){
        	if(curr!=NULL){
        		s.push(curr);
        		curr=curr->left;
			}else{
				res.push_back(s.top()->val);
				curr = s.top()->right;
				s.pop();
			}
		}
        
        return res;
    }
};


int main(){
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2) ;
	root->right->left = new TreeNode(3);
	
	Solution su = Solution();
	vector<int> result = su.inorderTraversal(root);
	
	for(auto v:result){
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
