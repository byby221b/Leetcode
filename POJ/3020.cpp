/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/07/19 10:39
	Description: 有点难度
				point of interest是点,如果两个点之间可以有antennas则有边,求的是最小边覆盖
				最小边覆盖=顶点数-最大匹配数 
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int total = 0;
int graph[405][405];
int map[45][15];
int h,w;
int cx[405],cy[405];
int mark[405];

bool isLegal(int i,int j){
	return (i>=0 && i<h && j>=0 && j<w);
}

int dfs(int u){
	for(int v=0;v<total;v++){
		if(graph[u][v] && !mark[v]){
			mark[v] = 1;
			if(cy[v]==-1 || dfs(cy[v])){
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	
	return 0;
}

void run(){
	
	scanf("%d%d",&h,&w);
	
	memset(map,-1,sizeof(map));
	
	//input
	total = 0;
	char buf[15];
	for(int i=0;i<h;i++){
		scanf("%s",buf);
		for(int j=0;j<w;j++){
			if(buf[j]=='*'){
				map[i][j] = total;
				total ++;
			}
		}
	}
	
	//graph
	memset(graph,0,sizeof(graph));
	int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j]>=0){
				for(int k=0;k<4;k++){
					int next_i = i + offset[k][0];
					int next_j = j + offset[k][1];
					if(isLegal(next_i,next_j) && map[next_i][next_j]>=0){
						graph[map[i][j]][map[next_i][next_j]] = 1;
						graph[map[next_i][next_j]][map[i][j]] = 1;
					}
				}
			}
		}
	}
	
//	for(int i=0;i<h;i++){
//		for(int j=0;j<w;j++){
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for(int i=0;i<total;i++){
//		for(int j=0;j<total;j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << endl;
//	}

	
	//match
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	int res = 0;
	for(int i=0;i<total;i++){
		if(cx[i]==-1){
			memset(mark,0,sizeof(mark));
			res += dfs(i);
		}
	}
	
	printf("%d\n",total-res/2);
}

int main(){
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		run();
	}
	return 0;
}

