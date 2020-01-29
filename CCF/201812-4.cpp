#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int graph[1005][1005];
int n,m,root;
int dist[1005];
int mark[1005];

int prime(){
	mark[root] = 1;
	
	bool flag = true;
	int select = root;
	int maxDist = -1;
	while(flag){
		flag = false;
		
		//更新最小距离 
		for(int i=1;i<=n;i++){
			if(!mark[i] && graph[select][i]>0 && (dist[i]<0 || dist[i]>graph[select][i])){
				dist[i] = graph[select][i];
			}
		}
		
		//寻找下一个候选点
		int minDis = -1,minIdx = -1;
		for(int i=1;i<=n;i++) {
			if(!mark[i] && (minIdx==-1 || minDis>dist[i])){
				flag = true;
				minIdx = i;
				minDis = dist[i];
			}
		}
		
		if(flag){
			select = minIdx;
			mark[select] = 1;
			if(minDis>maxDist) maxDist = minDis;
		}
	}
	
	return maxDist;
}

int main(){
	scanf("%d%d%d",&n,&m,&root);
	
	memset(graph,-1,sizeof(graph));
	memset(dist,-1,sizeof(dist));
	memset(mark,0,sizeof(mark));
	
	int u,v,t;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v,&u,&t);
		if(graph[u][v]<0 || graph[u][v]>t){
			graph[u][v] = t;
			graph[v][u] = t;
		}
	}
	
	cout << prime() << endl;
	return 0;
}
