/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 10:46
	Description: (����ʹ��LCS+��������)
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
char t[100005];

int main(){
	while(scanf("%s %s",s,t)!=EOF){
		char *ps = s;
		char *pt = t;
		while((*ps)!='\0' && (*pt)!='\0'){
			if((*ps)==(*pt)){
				ps ++;
				pt ++;
			}else{
				pt ++;
			}
		}
		
		if((*ps)=='\0'){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}
