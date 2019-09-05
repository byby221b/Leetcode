/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/09/19 21:24
	Description: AVL Tree
*/

#include <iostream>

using namespace std;

struct TreeNode{
	int id,priority;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int i,int p) : id(i), priority(p), left(NULL), right(NULL){}
};

class System{
	public:
		System(){
			root = NULL;
		}
		
		TrrNode* balanceNode(TreeNode *currRoot){
			updateHeight(currRoot);
			
			int balance = getBalance(currRoot);
			
			if(balance < -1){
				if(getBalance(currRoot->left)>0){
					currRoot->left = leftRotate(currRoot);	
				}
				return rightRotate(currRoot);
			}else if(balance > 1){
				if(getBalance(currRoot->right)<0){
					currRoot->right = rightRotate(currRoot->right);
				}
				return leftRotate(currRoot);
			}
		}
		
		TreeNode* addClient(TreeNode *currRoot,int id,int p){
			if(currRoot==NULL){
				currRoot = new TreeNode(id,p);
			}
			
			if(p<(currRoot->priority)){
				addClient(currRoot->left,id,p);
			}else{
				addClient(currRoot->right,id,p);
			}
			
			return balanceNode(currRoot);
		}
	private:
		TreeNode* root;
		
};



int main(){
	return 0;
}

