/*
	Name: 
	Copyright: 
	Author: 
	Date: 12/08/19 17:01
	Description: 
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 
 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct QNode{
	TreeNode* root;
	int level;
	QNode(TreeNode* r,int l) : root(r), level(l) {}
};

//class Solution {
//public:
//    vector<vector<int> > levelOrder(TreeNode* root) {
//        vector<vector<int> > res;
//		if(root==NULL) return res;
//		
//		int currLevel = 0;
//		vector<int> currNodes;
//        queue<QNode> q;
//    	
//    	QNode tmp = QNode(root,0);
//    	q.push(tmp);
//    	
//    	while(!q.empty()){
//    		QNode curr = q.front();
//    		q.pop();
//    		if(curr.level!=currLevel){
//    			res.push_back(currNodes);
//    			currNodes.clear();
//    			currLevel = curr.level;
//			}
//			
//			TreeNode *currRoot = curr.root;
//			currNodes.push_back(currRoot->val);
//			
//			if(currRoot->left!=NULL){
//				QNode tmp = QNode(currRoot->left,currLevel+1);
//				q.push(tmp);
//			}
//			if(currRoot->right!=NULL){
//				QNode tmp = QNode(currRoot->right,currLevel+1);
//				q.push(tmp);
//			}
//		}
//		res.push_back(currNodes);
//        
//        return res;
//    }
//};


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
		if(root==NULL) return res;
		
//		int currLevel = 0;
		vector<int> currNodes;
        queue<TreeNode *> q;
    	
//    	QNode tmp = QNode(root,0);
    	q.push(root);
    	
    	while(!q.empty()){
    		int size = q.size();
    		for(int i=0;i<size;i++){
    			TreeNode *curr = q.front();
    			q.pop();
    			currNodes.push_back(curr->val);
    			if(curr->left!=NULL){
    				q.push(curr->left);
				}
				if(curr->right!=NULL){
					q.push(curr->right);
				}
			}
			res.push_back(currNodes);
        	currNodes.clear();
    	}
	
        return res;
    }
};

int main(){
	
	Solution su = Solution();
	
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	
	vector<vector<int> > res = su.levelOrder(root);
	
	cout << "******** " <<  res.size() << "***********" << endl;
	for(int i=0;i<res.size();i++){
		vector<int> nodes = res[i];
		for(int j=0;j<nodes.size();j++){
			cout << nodes[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

