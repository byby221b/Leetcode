/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/07/19 14:21
	Description: 递归下降分析法
				假如使用栈的思路: 从后往前遍历,假如遇到逻辑变量,入栈;
				假如遇到逻辑运算符, 从栈中取出逻辑变量进行运算,将运算结果入栈 
*/

#include <iostream>
#include <cstdio>
#include <stack>
#include <math.h>
#include <cstring>
using namespace std;
char buf[105];
int map[26];

bool CalK(bool p,bool q){
	return (p && q);
}

bool CalA(bool p,bool q){
	return (p || q);
}

bool CalN(bool p){
	return (!p);
}

bool CalC(bool p,bool q){
	return !(p && !q);
}

bool CalE(bool p,bool q){
	return (p==q);
}

bool value(char ch,int state){
	int digt = (state >> (map[ch-'a'])) & 1;
	return (digt==1);
}

bool dfs(char *&ptr,int state){
	if(*ptr=='N'){
		ptr ++;
		return CalN(dfs(ptr,state));
	}else if(*ptr=='A' || *ptr=='K'|| *ptr=='C' || *ptr=='E'){
		char op = *ptr;
		ptr ++;
		bool numa = dfs(ptr,state);
		bool numb = dfs(ptr,state);
		switch(op){
			case 'A': return CalA(numa,numb);
			case 'K': return CalK(numa,numb);
			case 'C': return CalC(numa,numb);
			case 'E': return CalE(numa,numb);
		}
	}else{
		bool v = value(*ptr,state);
		ptr ++;
		return v;
	}
}

bool run(){
	scanf("%s",buf);
	if(buf[0]=='0'){
		return false;
	}
	
	char *ptr = buf;

	memset(map,-1,sizeof(map));
	int count = 0;
	while(*ptr){
		switch(*ptr){
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
				if(map[*ptr-'a']==-1){
					map[*ptr-'a'] = count;
					count ++;
				}
				break;
		}
		ptr ++;
	}
	
	
	bool flag = true;
	for(int i=0;i<pow(2,count);i++){
		ptr = buf;
		if(!dfs(ptr,i)){
			flag = false;
			break;
		}
	}
	
	if(flag){
		printf("tautology\n");
	}else{
		printf("not\n");
	}
	
	return true;
}

int main(){
	while(run());
	
	return 0;
} 
