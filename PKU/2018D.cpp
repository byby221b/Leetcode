/*
	Name: 
	Copyright: 
	Author: 
	Date: 20/06/19 19:42
	Description: 百练/BFS 
	注意不能只在 [1,100]范围内BFS，由于存在负数的钱，可能大于100的值也可以成为中间结点 
*/
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

bool isLegal(int value){
	return (value>=1 && value<=200);
}

void run(){
	int value[6];
	int min_dis[105];
	
	for(int i=1;i<=100;i++){
		min_dis[i] = 1e6;
	}
	
	for(int i=0;i<6;i++){
		cin >> value[i];
	}
	
	for(int i=0;i<6;i++){
		int base = value[i];
		int dis[205];
//		bool mark[105];
		queue<int> q;
		
		for(int j=1;j<=200;j++){
			dis[j] = 1e6;
//			mark[j] = false;
		}
		
		dis[base] = 1;
//		mark[dis] = true;
		q.push(base);
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			for(int j=0;j<6;j++){
				int add_v = curr + value[j];
				int sub_v = curr - value[j];
				if(isLegal(add_v) && (dis[curr]+1<dis[add_v])){
					dis[add_v] = dis[curr] + 1;
					q.push(add_v);
				}
				if(isLegal(sub_v) && (dis[curr]+1<dis[sub_v])){
					dis[sub_v] = dis[curr] + 1;
					q.push(sub_v);
				}
			}
		}
		
		for(int j=1;j<=100;j++){
			if(dis[j]<min_dis[j]){
				min_dis[j] = dis[j];
			}
		}
	}
	
	int max_dis = 0;
	int sum_dis = 0;
	for(int i=1;i<=100;i++){
		sum_dis += min_dis[i];
		if(min_dis[i]>max_dis){
			max_dis = min_dis[i];
		}
	}
	
	printf("%.2f %d\n",float(sum_dis)/100.0,max_dis);
//	cout << float(sum_dis)/100.0 << " " << max_dis << endl;
}


int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		run();
	}
	return 0;
}

