	/*
		Name: 
		Copyright: 
		Author: 
		Date: 06/07/19 20:50
		Description: spfa/bellman-ford判断负环
					存疑:为何选择第一个点为源点即可 
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
			flag[i][0] = true;
			graph[0][i] = 0;
			graph[i][0] = 0;
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
		
		
		bool hitFlag = false;
//		for(int i=1;i<=N;i++){
			queue<int> q;
			memset(mark,0,sizeof(mark));
			memset(count,0,sizeof(count));
			for(int j=1;j<=N;j++){
				dist[j] = MAXPATH;
			}
			q.push(0);
			mark[0] = true;
			dist[0] = 0;
			count[0] = 1;
			while(!q.empty()){
				int curr = q.front();
				q.pop();
				mark[curr] = false;
				for(int j=1;j<=N;j++){
					if(flag[curr][j] && dist[curr]+graph[curr][j]<dist[j] && j!=curr){
						dist[j] = dist[curr] + graph[curr][j];
						if(!mark[j]){
							mark[j] = true;
							q.push(j);
							count[j] ++;
							if(count[j]>N) hitFlag = true;
						}
					}
					if(hitFlag) break;
				}
				if(hitFlag) break;
			}
//			if(hitFlag) break;
//		}
		
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
