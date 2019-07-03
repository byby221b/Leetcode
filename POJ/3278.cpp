/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/07/19 14:14
	Description: BFS 
				用STL会MLE
*/

#include <iostream>

#include <cstring>
using namespace std;

int mark[100005];
int queue[100005];
int time[100005];

int main(){
	int n,k;
	
	cin >> n >> k;
	
	memset(mark,0,sizeof(mark));
	memset(queue,-1,sizeof(queue));
	memset(time,-1,sizeof(time));
	
	int front = 0,tail = -1;
	queue[++tail] = n;
	time[n] = 0;
	mark[n] = 1;
	
	
	while(front<=tail){
		//出队 
		int curr = queue[front];
		
//		cout << curr << endl;
		
		front ++;
		
		if(curr==k){
			cout << time[k] << endl;
			break;
		}
		
		if(curr-1>=0 && !mark[curr-1]){
			queue[++tail] = curr - 1;
			time[curr-1] = time[curr] + 1;
			mark[curr-1] = 1;
		}
		
		if(curr+1<=100000 && !mark[curr+1]){
			queue[++tail] = curr + 1;
			time[curr+1] = time[curr] + 1;
			mark[curr+1] = 1;
		}
		
		if(curr*2<=100000 && curr*2!=0 && !mark[curr*2]){
			queue[++tail] = curr * 2;
			time[curr*2] = time[curr] + 1;
			mark[curr*2] = 1;
		}
		
	}
	
	return 0;
}
