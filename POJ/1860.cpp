/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 19:08
	Description: Bellman-Ford Algorithm,循环V-1次,对所有边进行松弛操作,假如第V次仍能
				进行循环,说明存在负权边
				此题将最短路改为最大路即可 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double rate[105][105];
double commit[105][105];
int flag[105][105];
double dist[105];

int main(){
	int N,M,S;
	double V;
	
	cin >> N >> M >> S >> V;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<N;i++) dist[i] = -1e6;
	
	int A,B;
	for(int i=0;i<M;i++){
		cin >> A >> B;
		cin >> rate[A][B] >> commit[A][B] >> rate[B][A] >> commit[B][A];
		flag[A][B] = 1;
		flag[B][A] = 1;
	}
	dist[S] = V;
	
	bool addFlag = false;
	for(int k=0;k<N;k++){
		addFlag = false;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(flag[i][j] && dist[i]>0 && dist[j]<(dist[i]-commit[i][j])*rate[i][j]){
					dist[j] = (dist[i]-commit[i][j])*rate[i][j];
					addFlag = true;
				}
			}
		}
		if(!addFlag) break;
	}
	
	if(addFlag){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}
