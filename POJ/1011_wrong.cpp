/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 21:32
	Description: dfs + ºÙ÷¶ 
					Wrong Answer
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

int data[70];
int mark[70];
int path[70];
int n;
bool flag;
ofstream fout("output.txt");

void dfs(int level,int *mark,int sum,int target){
	for(int i=0;i<level;i++){
		fout << data[path[i]] << " ";
		
	}
	fout << flag << endl;
	
	if(level>n || sum>target || flag){
		return;
	}
	
	if(sum==target){
		if(level==n){
			flag = true;
			return;
		}else{
			sum = 0;
		}
	}
	
	if(level==n) return;
	
	if(sum==0){
		int i = 0;
		while(mark[i]) {
			i++;
		}
		path[level] = i;
		mark[i] = 1;
		dfs(level+1,mark,sum+data[i],target);
		mark[i] = 0;
	}else{
		int record = -1;
		for(int i=0;i<n;i++){
			if(!mark[i] && sum+data[i]<=target && record!=data[i]){
				path[level] = i;
				mark[i] = 1;
				dfs(level+1,mark,sum+data[i],target);
				mark[i] = 0;
				record = data[i];
				if(sum+data[i]==target){
					break;
				}
			}
			if(flag) break;
		}
	}
	
}

bool cmp(int a,int b){
	return a>b;
}

bool run(){
	
	cin >> n;
//	cout << "n:" << n << endl;
	if(n==0){
		return false;
	}
	
	int sum = 0;
	int max = 0;
	for(int i=0;i<n;i++){
		cin >> data[i];
		sum += data[i];
		if(data[i]>max) max = data[i];
	}
	
	sort(data,data+n,cmp);
	
	for(int i=max;i<=sum/2;i++){
		flag = false;
		if(sum%i==0){
			memset(mark,0,sizeof(mark));
			path[0] = 0;
			mark[0] = 1;
			dfs(1,mark,data[0],i);
			mark[0] = 0;
		}
		if(flag){
			cout << i << endl;
//			fout << i << endl;
			break;
		}
	}
	
	if(!flag){
		cout << sum << endl;
//		fout << sum << endl;
	}
	
	return true;
}

int main(){
	while(run());
	return 0;
}

