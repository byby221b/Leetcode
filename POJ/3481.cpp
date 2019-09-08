/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/09/19 21:24
	Description: AVL Tree
*/

#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode{
	int id,priority,height;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int i,int p) : id(i), priority(p), height(1), left(NULL), right(NULL){}
};

class System{
	public:
		TreeNode* root;
		System(){
			root = NULL;
		}
		
		TreeNode* addNode(TreeNode *currRoot,int id,int p){
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
		
		TreeNode* popMinNode(TreeNode *currRoot,int &val){
			if(currRoot==NULL) val = 0;
			
			if(currRoot->left){
				currRoot->left = popMinNode(currRoot->left,val);
			}else{
				val = currRoot->id;
				if(currRoot->right){
					TreeNode *newRoot = currRoot->right;
					delete currRoot;
					currRoot = newRoot;
				}
			}
			
			return balanceNode(currRoot);
		}
		
		TreeNode *popMaxNode(TreeNode *currRoot,int &val){
			if(currRoot==NULL) val = 0;
			
			if(currRoot->right){
				currRoot->right = popMaxNode(currRoot->right,cal);
			}else{
				val = currRoot->id;
				if(currRoot->left){
					TreeNode *newRoot = currRoot->left;
					delete currRoot;
					currRoot = newRoot;
				}
			}
			
			return balanceNode(currRoot);
		}
	private:
		int getHeight(TreeNode *currRoot){
			return (currRoot==NULL) ? 0 : currRoot->height;
		}
		
		int getBalance(TreeNode *currRoot) {
			/*
			* - h(left) > h(right)
			* 0  h(left) = h(right)
			* +  h(left) < h(right)
			*/
			return getHeight(currRoot->right) - getHeight(currRoot->left);
		}
		
		void updateHeight(TreeNode *currRoot) {
			currRoot->height = max(getHeight(currRoot->left),getHeight(currRoot->right)) + 1;
		}
		
		TreeNode* rightRotate(TreeNode *currRoot){
			TreeNode *newRoot = currRoot->left;
			currRoot->left = newRoot->right;
			newRoot->right = currRoot;
			
			updateHeight(currRoot);
			updateHeight(newRoot);
			
			return newRoot;
		}
		
		TreeNode* leftRotate(TreeNode *currRoot){
			TreeNode *newRoot = currRoot->right;
			currRoot->right = newRoot->left;
			newRoot->left = currRoot;
			
			updateHeight(currRoot);
			updateHeight(newRoot);
			
			return newRoot;
		}
		
		TreeNode* balanceNode(TreeNode *currRoot){
			if(currRoot==NULL) return NULL;
			
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
		
};



int main(){
	
	System sys = System();
	int op;
	int K,P;
	while(true){
		scanf("%d",&op);
		if(op==0) break;
		else if(op==1){
			scanf("%d%d",&K,&P);
			sys.addNode(sys.root,K,P);
		}else if(op==2){
			cout << sys.popMaxNode(sys.root) << endl;
		}else if(op==3){
			cout << sys.popMinNode(sys.root) << endl;
		}
	}
	
	return 0;
}

