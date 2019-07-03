/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 09:01
	Description: dfs,����ֵ���,ע��ȡģ���� 
*/

#include <iostream>
#include <queue>

using namespace std;
int n;
bool flag;

void output(char *buf,int level){
	for(int i=0;i<level;i++){
		cout << buf[i];
	}
	cout << endl;
}

void dfs(char *buf,int level,int mod){
	if(level>100 || flag){
		return;
	}
	
	if(mod==0){
		output(buf,level);
		flag = true;
		return;
	}
	
	buf[level] = '0';
	dfs(buf,level+1,((mod%n)*(10%n))%n);
	buf[level] = '1';
	dfs(buf,level+1,((mod%n)*(10%n)+1)%n);
}

int main(){
	while(true){
		
		cin >> n;
		if(n==0) break;
		
		char buf[105];
		buf[0] = '1';
		flag = false;
		dfs(buf,1,1);
		
	}
	return 0;
}

