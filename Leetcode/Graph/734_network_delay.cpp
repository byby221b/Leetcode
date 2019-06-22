#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
 *  Giggle
 *  2019-03-06 21:29:54
 */

int transfer(int a,int b,int N){
	return a*N+b;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	//process the graph
	int *timesG = new int[N*N];
	for(int i=0;i<times.size();i++){
		times[i][0] -= 1;
		times[i][1] -= 1;
	}
	K -= 1;

	for(int i=0;i<N*N;i++){
		timesG[i] = 1e6;
	}
	for(int i=0;i<N;i++){
		timesG[transfer(i,i,N)] = 0;
	}
	for(int i=0;i<times.size();i++){
		timesG[transfer(times[i][0],times[i][1],N)] = times[i][2];
	}

	//dijkstra
	bool *mark = new bool[N];
	int *dis = new int[N];
	for(int i=0;i<N;i++){
		mark[i] = false;
		dis[i] = 1e6;
	}
	dis[K] = 0;
	mark[K] = true;
	for(int i=0;i<N;i++){
		dis[i] = timesG[transfer(K,i,N)];
	}

	while(true){
		for(int i=0;i<N;i++){
			if(dis[i]==1e6){
				cout << "-1 ";
			}else{
				cout << dis[i] << " ";
			}
		}
		cout << endl;
		
		int min_dis = 1e6;
		int min_idx = -1;
		for(int i=0;i<N;i++){
			if(mark[i]) continue;
			if(dis[i]<min_dis){
				min_dis = dis[i];
				min_idx = i;
			}
		}

		if(min_idx==-1)
			break;

		mark[min_idx] = true;
		for(int i=0;i<N;i++){
			int d = timesG[transfer(min_idx,i,N)];
			if(dis[i]>dis[min_idx]+d){
				dis[i] = dis[min_idx]+d;
			}
		}
	}

	//result
	int max_time = 0;
	for(int i=0;i<N;i++){
		if(dis[i]>max_time)
			max_time = dis[i];
	}

	if(max_time>=1e6)
		return -1;
	else
		return max_time;
}

int main() {
	vector<int> link0 = {2,1,1};
	vector<int> link1 = {2,3,1};
	vector<int> link2 = {3,4,1};
	vector<vector<int> > times = {link0,link1,link2};
	int N = 4, K = 2;
	cout << networkDelayTime(times,N,K) << endl;
	
	return 0;
}
