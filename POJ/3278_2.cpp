/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/07/19 14:14
	Description: BFS
				剪枝+不使用结构体可以通过 
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mark[100005];
int time[100005];

int main(){
	int n,k;
	
	cin >> n >> k;
	
	queue<int> q;
	memset(mark,0,sizeof(mark));
	
	if(n>=k){
		cout << n-k << endl;
		return 0;
	}
	
	
	mark[n] = 1;
	time[n] = 0;
	q.push(n);
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		
		if(curr == k){
			cout << time[curr] << endl;
			break;
		}
		
		if(curr-1>=0 && !mark[curr-1]){
			time[curr - 1] = time[curr] + 1;
			mark[curr - 1] = 1;
			q.push(curr - 1);
		}
		
		if(curr+1<=k && !mark[curr+1]){
			time[curr+1] = time[curr] + 1;
			mark[curr + 1] = 1;
			q.push(curr+1);
		}
		
		if(curr*2<=k*2 && curr*2<=100000 && curr*2!=0 && !mark[curr*2]){
			time[curr*2] = time[curr] + 1;
			mark[curr * 2] = 1;
			q.push(curr*2);
		}		
	}
	
	return 0;
}
