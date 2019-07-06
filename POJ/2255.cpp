/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 14:10
	Description: 前序提供根节点,中序分割左右子树 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node{
	char value;
	struct node *left,*right;
} TN;

TN allnodes[30];
int count,len;
int idx1[30],idx2[30];
char buf1[30],buf2[30];

TN *dfs(char root,int left,int right){
	TN *res = &allnodes[count++];
	res->value = root;
	res->left = NULL;
	res->right = NULL;
	
	for(int i=idx1[root-'A'];i<len;i++){
		if(idx2[buf1[i]-'A'] < idx2[root-'A'] && idx2[buf1[i]-'A']>=left && idx2[buf1[i]-'A']<=right){
			res->left = dfs(buf1[i],left,idx2[root-'A']-1);
			break;
		}
	}
	
	for(int i=idx1[root-'A'];i<len;i++){
		if(idx2[buf1[i]-'A'] > idx2[root-'A'] && idx2[buf1[i]-'A']>=left && idx2[buf1[i]-'A']<=right){
			res->right = dfs(buf1[i],idx2[root-'A']+1,right);
			break;
		}
	}
	
	return res;
	
}

void postorder(TN* root){
	if(root==NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%c",root->value);
}

int main(){
	
	while(scanf("%s%s",buf1,buf2)!=EOF){
//		memset(idx,-1,sizeof(char2idx));
		count = 0;
		len = 0;
		for(int i=0;buf2[i]!='\0';i++){
			idx1[buf1[i]-'A'] = i;
			idx2[buf2[i]-'A'] = i;
			len ++;
		}
		
		TN *root = dfs(buf1[0],0,len-1);
		postorder(root);
		printf("\n");
	}
	
	return 0;
}


