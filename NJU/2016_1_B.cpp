/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/06/19 09:38
	Description: 迪杰斯特拉的变体 
*/

#include <iostream> 
#include <cstring>

using namespace std;

int graph[505][505];
int team[505];
bool pre[505][505];

int teamMax = 0;
int pathCount = 0;

void djk(int src,int dst,int n){
	bool *mark = new bool[n];
	int *dis = new int[n];
	
	for(int i=0;i<n;i++){
		mark[i] = false;
		dis[i] = 1e6;
	}
	
	mark[src] = true;
	dis[src] = 0;
	for(int i=0;i<n;i++){
		if(graph[src][i]>0){
			pre[i][src] = true;
			dis[i] = graph[src][i];
		}
	}
	
	while(true){
		
		int minIdx = -1;
		int minDis = 1e6;
		for(int i=0;i<n;i++){
			if(dis[i]<minDis && !mark[i]){
				minIdx = i;
				minDis = dis[i];
			}
		}
		
		if(minIdx == -1){
			break;
		}
		
		mark[minIdx] = true;
		for(int i=0;i<n;i++){
			if(graph[minIdx][i]>0 && dis[minIdx]+graph[minIdx][i] < dis[i]){
				dis[i] = dis[minIdx]+graph[minIdx][i];
				for(int j=0;j<n;j++){
					pre[i][j] = false;
				}
				pre[i][minIdx] = true;
			}else if(graph[minIdx][i]>0 && dis[minIdx]+graph[minIdx][i] == dis[i]){
				pre[i][minIdx] = true;
			}
		} 
	}
	
	delete [] mark;
	delete [] dis;
	
	//return dis[dst];
}

void dfs(int curr,int src,int teamCount,int n){
	teamCount += team[curr];
	if(curr == src){
		pathCount ++;
		teamMax = (teamCount > teamMax) ? teamCount : teamMax;
		
		return;
	}
	for(int i=0;i<n;i++){
		if(pre[curr][i]){
			dfs(i,src,teamCount,n);
		}
	}
}

int main(){
	int n,m,src,dst;
	
	cin >> n >> m >> src >> dst;
	
	for(int i=0;i<n;i++){
		cin >> team[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph[i][j] = -1;
			pre[i][j] = false;
		}
	}
	
	for(int i=0;i<m;i++){
		int c1,c2,length;
		cin >> c1 >> c2 >> length;
		graph[c1][c2] = length;
		graph[c2][c1] = length;
	}
	
	djk(src,dst,n);
	
	dfs(dst,src,0,n);
	
//	cout << minDis << endl;
	cout << pathCount << " " << teamMax << endl;
	return 0;
}

