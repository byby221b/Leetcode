/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 20:19
	Description: spfa: bellman-ford的改进算法,维护队列,有结点入队次数超过N时跳出循环 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

double rate[105][105];
double commit[105][105];
int flag[105][105];
double dist[105];
bool mark[105];
int count[105];

int main(){
	int N,M,S;
	double V;
	
	cin >> N >> M >> S >> V;
	memset(flag,0,sizeof(flag));
	memset(count,0,sizeof(count));
	for(int i=1;i<N;i++) {
		dist[i] = -1e6;
		mark[i] = false;
	}
	
	int A,B;
	for(int i=0;i<M;i++){
		cin >> A >> B;
		cin >> rate[A][B] >> commit[A][B] >> rate[B][A] >> commit[B][A];
		flag[A][B] = 1;
		flag[B][A] = 1;
	}
	
	
	queue<int> q;
	q.push(S);
	mark[S] = true;
	dist[S] = V;
	count[S] ++;
	
	bool addFlag = false;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		mark[curr] = false;
		if(dist[curr]>0){
			for(int i=1;i<=N;i++){
				if(flag[curr][i] && dist[i]<(dist[curr]-commit[curr][i])*rate[curr][i]){
					dist[i] = (dist[curr]-commit[curr][i])*rate[curr][i];
					if(!mark[i]){
						q.push(i);
						mark[i] = true;
						count[i] ++;
						if(count[i]>=N) {
							addFlag = true;
							break;
						}
						
					}
				}
			}
		}
		if(addFlag) break;
	}
	
	if(addFlag){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}
