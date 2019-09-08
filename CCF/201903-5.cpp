#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 0xfff3fff

/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/09/19 15:05
	Description: Í¨¹ý3/10,MLE 
*/


using namespace std;

int *graph;
int *dist;		 
int *mark;
int n,m,k;

void dijkstra(int src){
	memset(mark,0,sizeof(int)*(n+5));
	for(int i=1;i<=n;i++) dist[src*n+i] = graph[src*n+i];
	
	mark[src] = 1;
	while(true){
		bool flag = false;
		
		int minVal = -1,minIdx = -1;
		for(int i=1;i<=n;i++){
			if(!mark[i] && (!flag || dist[src*n+i]<minVal)){
				flag = true;
				minVal = dist[src*n+i];
				minIdx = i;
			}
		}
		
		if(flag){
			mark[minIdx] = 1;
			for(int i=1;i<=n;i++){
				if(!mark[i] && dist[src*n+i] > dist[src*n+minIdx] + graph[minIdx*n+i]){
					dist[src*n+i] = dist[src*n+minIdx] + graph[minIdx*n+i];
				}
			}
		}
		
		if(!flag) break;
	}
	
}

int main(){

	scanf("%d%d%d",&n,&m,&k);
	
	int *kind = new int[n+5];
	mark = new int[n+5];
	graph = new int[(n+5)*(n+5)];
	dist = new int[(n+5)*(n+5)];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) graph[i*n+j] = 0;
			else{
				 graph[i*n+j] = MAX;
				 graph[j*n+i] = MAX;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d",&kind[i]);
	}
	
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(graph[u*n+v]>w){
			graph[u*n+v] = w;
			graph[v*n+u] = w;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(kind[i]) dijkstra(i); 
	}
	
	
	for(int i=1;i<=n;i++){
		priority_queue<int,vector<int>,greater<int> > q;
		for(int j=1;j<=n;j++){
			if(kind[j] && dist[j*n+i]<MAX) {
				q.push(dist[j*n+i]);
			}
		}
		
		long long res = 0;
		for(int i=0;i<k;i++){
			if(q.empty()) break;
			res += q.top();
			q.pop();
		}
		
		printf("%lld\n",res);
	}
	
	return 0;
}
