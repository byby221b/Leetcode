/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/07/19 11:24
	Description: 先将矩阵染成黑白色，然后构造二分图 
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int left_total = 0,right_total = 0;
int graph[405][405];
int map[45][15];
int color[45][15];
int h,w;
int cx[405],cy[405];
int mark[405];
int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isLegal(int i,int j){
	return (i>=0 && i<h && j>=0 && j<w);
}

int dfs(int u){
	for(int v=0;v<right_total;v++){
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
	
	
	//color
	color[0][0] = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(isLegal(i+1,j)){
				color[i+1][j] = (color[i][j] + 1) % 2;
			}
			if(isLegal(i,j+1)){
				color[i][j+1] = (color[i][j] + 1) % 2;
			}
		}
	}
	
	
	//input
	left_total = 0;
	right_total = 0;
	char buf[15];
	for(int i=0;i<h;i++){
		scanf("%s",buf);
		for(int j=0;j<w;j++){
			if(buf[j]=='*'){
				if(color[i][j]){
					map[i][j] = right_total;	
					right_total ++;
				}else{
					map[i][j] = left_total;	
					left_total ++;
				}
			}
		}
	}
		
	//graph
	memset(graph,0,sizeof(graph));
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j]>=0){
				for(int k=0;k<4;k++){
					int next_i = i + offset[k][0];
					int next_j = j + offset[k][1];
					if(isLegal(next_i,next_j) && map[next_i][next_j]>=0){
						if(color[i][j]){
							graph[map[next_i][next_j]][map[i][j]] = 1;	
						}else{
							graph[map[i][j]][map[next_i][next_j]] = 1;	
						}
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
	for(int i=0;i<left_total;i++){
		if(cx[i]==-1){
			memset(mark,0,sizeof(mark));
			res += dfs(i);
		}
	}
	
	printf("%d\n",left_total+right_total-res);
}

int main(){
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		run();
	}
	return 0;
}


