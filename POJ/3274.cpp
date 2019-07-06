/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 21:04
	Description: hash
				转换巧妙
					假设sum[i][f]表示前i行里面feature f 出现的总次数 
					则要找最大的(j-i),使得
						sum[j][0] - sum[i][0] = sum[j][1] - sum[i][1] = ... = sum[j][f]-sum[i][f]
					转化为找最大的(j-i) ,使得
						sum[j][1] - sum[j][0] = sum[i][1] - sum[i][0]
						...
						sum[j][f] - sum[j][0] = sum[i][f] - sum[i][0]
					即差分之后寻找相等的两个数组 
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#define MOD 999991
using namespace std;

typedef struct hash{
	int idx;
	struct hash* next;
}HashTable;

int delta[100005][35];
HashTable *database[MOD];
int N,K;

int maxDist = 0;

bool cmp(int idxa,int idxb){
	for(int i=1;i<=K;i++){
		if(delta[idxa][i]!=delta[idxb][i]){
			return false;
		}
	}
	return true;
}

int abs(int a){
	return (a < 0) ? -a : a;
}

void push(int idx){
	int key = 0;
	for(int i=1;i<K;i++){
		key = (abs(key) + delta[idx][i]) % MOD;
	}
	
	if(!database[key]){
		database[key] = new HashTable;
		database[key]->idx = idx;
		database[key]->next = NULL;
	}else{
		if(cmp(database[key]->idx,idx)){
			int currDist = idx - (database[key]->idx);
			maxDist = (maxDist > currDist) ? maxDist : currDist;
		}else{
			HashTable *p = database[key];
			bool flag = false;
			while((p->next)!=NULL){
				p = p->next;
				if(cmp(p->idx,idx)){
					int currDist = idx - (p->idx);
					maxDist = (maxDist > currDist) ? maxDist : currDist;
					flag = true;
					break;
				}
			}
			
			if(!flag){
				HashTable *newp = new HashTable;
				p->next = newp;
				newp->idx = idx;
				newp->next = NULL;
			}
		}
	}
}

int main(){
	
	scanf("%d %d",&N,&K);
	
	memset(delta,0,sizeof(delta));
	memset(database,0,sizeof(database));
	
	maxDist = 0;
	
	push(0);
	
	for(int i=1;i<=N;i++){
		int tmp;
		scanf("%d",&tmp);
		int base = tmp & 1;
		for(int j=1;j<K;j++){
			int bit = (tmp & (1 << j)) >> j;
			delta[i][j] = delta[i-1][j] + bit - base;
//			cout << ">> " << base << " " << bit << " " << delta[i%2][j] << endl;
		}
		
//		cout << i << " ";
//		for(int j=1;j<K;j++){
//			cout << delta[i][j];
//		}
//		cout << endl;
		
		push(i);
	}
	
	printf("%d\n",maxDist);
	
	return 0;
}

