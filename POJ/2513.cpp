/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 11:12
	Description: 并查集+trie树+欧拉回路
				并查集,判断图是否联通(维护一个count变量记录合并次数即可,联通图合并次数等于节点数-1) 
				trie树,用于将颜色字符串映射到数字id 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define ALPHANUM 26
#define MAXNUM 500005
using namespace std;

typedef struct trieNode{
	int id;
	struct trieNode* child[ALPHANUM];
} *TN;

class TrieTree{
public:
	int total;
	int *count;
	TrieTree(){
		count = new int[MAXNUM];
		root = createNode();
		total = 0;
		memset(count,0,sizeof(int)*MAXNUM);
	}
	
	int insert(char *word){
		char *p = word;
		TN r = root;
		while(*p!='\0'){
			if(!(r->child[*p-'a'])){
				r->child[*p-'a'] = createNode();
			}
			r = r->child[*p-'a'];
			p ++;
		
		}
		if(r->id==-1) {
			r->id = total;
			total ++;
			count[r->id] = 1;
		}else{
			count[r->id] ++;
		}
		
		return (r->id);
	}
	
private:
	TN root;
	TN createNode(){
		TN p = new struct trieNode;
		p->id = -1;
		memset(p->child,0,sizeof(p->child));
		return p;
	}
};

class QU{
public:
	int count;
	QU(){
		count = 0;
		sz = new int[MAXNUM];
		id = new int[MAXNUM];
		for(int i=0;i<MAXNUM;i++){
			sz[i] = 1;
			id[i] = i;
		}
	}
	
	int find(int p){
		int tmp = p;
		while(id[p]!=p){
			p = id[p];
		}
		id[tmp] = p;
		return p;
	}
	
	void Union(int p,int q){
		int idp = find(p);
		int idq = find(q);
		if(idp!=idq){
			if(sz[idp]<sz[idq]){
				id[idp] = idq;
				sz[idq] += sz[idp];
			}else{
				id[idq] = idp;
				sz[idp] += sz[idq];
			}
			count ++;
		}
	}
	
private:
	int *sz;
	int *id;
};

int main(){
	TrieTree trieHelper = TrieTree();
	QU quHelper = QU();
	
	char buf[15];
	while(scanf("%s",buf)!=EOF){
		int idp = trieHelper.insert(buf);
		scanf("%s",buf);
		int idq = trieHelper.insert(buf);
		quHelper.Union(idp,idq);
	}
	
	bool flag = false;
	int colorNum = trieHelper.total;
	if(colorNum==0){
		flag = true;
	}else if(colorNum-quHelper.count==1){
		int oddCount = 0;
		for(int i=0;i<colorNum;i++){
			if(trieHelper.count[i]&1){
				oddCount ++;
			}
		}
		if(oddCount==0 || oddCount==2){
			flag = true;
		}
	}
	
	if(flag){
		printf("Possible\n");
	}else{
		printf("Impossible\n");
	}
	
	return 0;
}

