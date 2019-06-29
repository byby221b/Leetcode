/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/06/19 10:36
	Description: 
*/


#include <iostream> 
#include <cstring>

using namespace std;

int graph[505][505];
int team[505];
int pathCount[505];
int teamMax[505];

void djk(int src,int dst,int n){
	bool *mark = new bool[n];
	int *dis = new int[n];
	
	for(int i=0;i<n;i++){
		pathCount[i] = 0;
		teamMax[i] = 0;
		mark[i] = false;
		dis[i] = 1e6;
	}
	
	mark[src] = true;
	dis[src] = 0;
	pathCount[src] = 1;
	teamMax[src] = team[src];
	for(int i=0;i<n;i++){
		if(graph[src][i]>0){
			dis[i] = graph[src][i];
			pathCount[i] = pathCount[src];
			teamMax[i] = teamMax[src] + team[i];
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
				pathCount[i] = pathCount[minIdx];
				teamMax[i] = teamMax[minIdx] + team[i];
			}else if(graph[minIdx][i]>0 && dis[minIdx]+graph[minIdx][i] == dis[i]){
				pathCount[i] += pathCount[minIdx];
				teamMax[i] = (teamMax[minIdx] + team[i] > teamMax[i]) ? teamMax[minIdx] + team[i] : teamMax[i];
			}
		} 
	}
	
	delete [] mark;
	delete [] dis;
	
	//return dis[dst];
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
		}
	}
	
	for(int i=0;i<m;i++){
		int c1,c2,length;
		cin >> c1 >> c2 >> length;
		graph[c1][c2] = length;
		graph[c2][c1] = length;
	}
	
	djk(src,dst,n);
	
//	cout << minDis << endl;
	cout << pathCount[dst] << " " << teamMax[dst] << endl;
	return 0;
}

