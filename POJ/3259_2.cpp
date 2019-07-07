/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 21:54
	Description: Bellman-ford
				为了防止不连通可以增加一个虚拟结点,到各结点的距离为0 
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define MAXPATH 0x3f3f3f3f
#define FIELD 1005
using namespace std;

int graph[FIELD][FIELD];
int flag[FIELD][FIELD];
int mark[FIELD];
int count[FIELD];
int dist[FIELD];
void run(){
	int N,M,W;
	scanf("%d%d%d",&N,&M,&W);
	
	memset(flag,0,sizeof(flag));
	
	for(int i=1;i<=N;i++){
		flag[i][i] = true;
		graph[i][i] = 0;
		flag[0][i] = true;
//		flag[i][0] = true;
		graph[0][i] = 0;
//		graph[i][0] = 0;
	}
	
	int S,E,T;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&S,&E,&T);
		if(!flag[S][E] || T<graph[S][E]){
			graph[S][E] = T;
			graph[E][S] = T;
			flag[S][E] = true;
			flag[E][S] = true;
		}
	}
	for(int i=0;i<W;i++){
		scanf("%d%d%d",&S,&E,&T);
		if(!flag[S][E] || -T<graph[S][E]){
			graph[S][E] = -T;
			flag[S][E] = true;
		}
	}
	
	for(int j=1;j<=N;j++){
		dist[j] = MAXPATH;
	}
	
	bool hitFlag = false;
	for(int k=0;k<N;k++){
		hitFlag = false;
		for(int i=0;i<=N;i++)	{
			for(int j=0;j<=N;j++){
				if(flag[i][j] && i!=j && dist[j]>dist[i]+graph[i][j]){
					dist[j] = dist[i]+graph[i][j];
					hitFlag = true;
				}
			}
		}
		if(!hitFlag) break;
	}
		
	if(hitFlag){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}


int main(){
	
	int F;
	scanf("%d",&F);
	for(int i=0;i<F;i++){
		run();
	}
	
	return 0;
}
