/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 15:02
	Description: һ��dfs������ڵ�,����Ҫ���� 
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char buf1[30],buf2[3];

//n:���Ľ����Ŀ a:ǰ��ͷ b:����ͷ 
void dfs(int n,char *a,char *b){
	if(n<=0){
		return;
	}
	
	int left = 0;
	while(*(b+left)!=a[0]) left++;
	
	dfs(left,a+1,b);
	dfs(n-1-left,a+1+left,b+1+left);
	
	printf("%c",a[0]);
	
}

int main(){
	
	while(scanf("%s%s",buf1,buf2)!=EOF){
		dfs(strlen(buf1),buf1,buf2);
		printf("\n");
	}
	
	return 0;
}

