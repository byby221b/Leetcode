/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 09:01
	Description: bfs,���������С 
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n==0) break;
		
		queue<long long> q;
		q.push(1);
		
		while(!q.empty()){
			long long curr = q.front();
			q.pop();
			
			if(curr%n==0){
				cout << curr << endl;
				break;
			}
			
			q.push(curr*10);
			q.push(curr*10+1);
			
		}
	}
	return 0;
}

