/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 22:10
	Description: 最小覆盖=最大匹配
				匈牙利算法 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int graph[505][505];
int N;
int rm[505],cm[505];
int mark[505];

int path(int u){
	for(int v=1;v<=N;v++){
		if(graph[u][v] && !mark[v]){
			mark[v] = 1;
			if(cm[v]==-1 || path(cm[v])){
				rm[u] = v;
				cm[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int K;
	scanf("%d%d",&N,&K);
	
	memset(graph,0,sizeof(graph));
	int row,col;
	for(int i=0;i<K;i++){
		scanf("%d%d",&row,&col);
		graph[row][col] = 1;
	}
	
	int res = 0;
	memset(rm,-1,sizeof(rm));
	memset(cm,-1,sizeof(cm));
	for(int i=1;i<=N;i++){
		if(rm[i]==-1){
			memset(mark,0,sizeof(mark));
			res += path(i);
		}
	}
	
	printf("%d\n",res);
	
	return 0;
}

