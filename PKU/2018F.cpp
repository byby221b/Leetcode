/*
	Name: 
	Copyright: 
	Author: 
	Date: 22/06/19 10:15
	Description: 单源最短路
				注意读题，最小化的是times of switch changes 
				题目并不是按照难度递增排序的？此题相对逆序对比较简单 
*/

#include <iostream> 

using namespace std;

int graph[105][105];

int main(){
	int N,A,B;
	cin >> N >> A >> B;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			graph[i][j] = -1;
		}
	}
	
	for(int i=1;i<=N;i++){
		int total,target;
		cin >> total;
//		cout << total;
		for(int j=0;j<total;j++){
			cin >> target;
			if(j==0){
				graph[i][target] = 0;	
			}else{
				graph[i][target] = 1;	
			}
		}
	}
	
	if(A==B){
		cout << "0" << endl;
		return 0;
	}
	
	int dis[105];
	bool mark[105];
	for(int i=1;i<=N;i++){
		if(graph[A][i]!=-1){
			dis[i] = graph[A][i];
		}else{
			dis[i] = 105;
		}
		mark[i] = false;
	}
	
	mark[A] = true;
	bool flag = true;
	while(flag){
		int min_dis = 105;
		int min_idx = -1;
		flag = false;
		
		//寻找距离最小的点 
		for(int i=1;i<=N;i++){
			if(!mark[i] && dis[i]<min_dis){
				min_dis = dis[i];
				min_idx = i;
				flag = true;
			}
		}
		
		//松弛 
		if(flag){
			mark[min_idx] = true;
			for(int i=1;i<=N;i++){
				if(graph[min_idx][i]!=-1 && dis[min_idx]+graph[min_idx][i]<dis[i]){
					dis[i] = dis[min_idx] + graph[min_idx][i];
				}
			}
		}
	}
	
	if(dis[B]>=105){
		cout << "-1" << endl;
	}else{
		cout << dis[B] << endl;
	}
	
	return 0;
}
 
