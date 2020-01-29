#include <iostream> 
#include <cstdio>

/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/09/19 10:27
	Description: Wrong!
*/


using namespace std;

int a[100];
int b[100];
int n;
bool flag = false;

void dfs(int level){
	int low,up;
	
	if(level==n+1 || flag){
		flag = true;
		return;
	}
	
	if(level==1 || level==2){
		low = 1;
		up = 2*b[1];
	}else if(level==n || level==n-1){
		low = 1;
		up = 2*b[n];
	}else if(level==3){
		low = max(1,3*(b[2]-1)-2*(b[1]+1));
		up = 3*(b[2]+1)-2*b[1]-1;
	}else{
		low = max(a[level-3] + 3*(b[level-1]-b[level-2]-1),1);
		up =  a[level-3] + 3*(b[level-1]-b[level-2]+1) - 1;
	}
	
	if(up<=0){
		return;
	}
	
	for(int i=low;i<=up;i++){
		a[level] = i;
		
		if(level==2 && ((a[1]+a[2])/2)!=b[1]) continue;
		if(level==n && ((a[n-1]+a[n])/2)!=b[n]) continue;
		if(level>2 && ((a[level-2]+a[level-1]+a[level])/3)!=b[level-1]) continue;
		
		dfs(level+1);
	}
	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	
	dfs(1);
	
	for(int i=1;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n]);
	
	return 0;
}

