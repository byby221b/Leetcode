#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/09/19 13:52
	Description: Í¨¹ýÑùÀý4/5£¬TLE 
*/


using namespace std;
int T,n;

char buf[100];

struct Msg{
	char kind;
	int pid;
	Msg(char k,int p): kind(k), pid(p){}
};

bool isDigit(char a){
	return (a>='0' && a<='9');
}

void run(){
	Msg *msgs[10005][10];
	int count[10005];
	int top[10005];
	Msg *s[10005];
	
	memset(count,0,sizeof(count));
	memset(top,0,sizeof(top));
	for(int i=0;i<n;i++){
		s[i] = new Msg('R',-1);
	}
	
	for(int i=0;i<n;i++){
		fgets(buf,100,stdin);
		int idx = 0,state = 0;
		char *ptr = buf;
		char k;
		int pid = 0;
		bool flag = true;
		while(flag){
			switch(state){
				case 0: {
					if(*ptr=='R' || *ptr=='S'){
						k = *ptr;
						pid = 0;
						state = 1;
					}
					break;
				}
				case 1: {
					if(isDigit(*ptr)){
						pid = pid * 10 + (*ptr - '0');
						state = 2;
					}
					break;
				}
				case 2:{
					if(isDigit(*ptr)){
						pid = pid * 10 + (*ptr - '0');
						state = 2;
					}else if(*ptr==' ' || *ptr=='\0'){
						state = (*ptr==' ') ? 0 : 3;
						msgs[i][idx] = new Msg(k,pid);
						idx ++;
					}
					break;
				}
				case 3:{
					count[i] = idx;
					flag = false;
					break;
				}
				
			}
			ptr++;
		}
	}
	
	
	while(true){
		bool flag = false;		
		bool finish = true;
		bool allIdle = true;
		int i;
		for(i=0;i<n;i++){
			if((s[i]->pid)!=-1){
				allIdle = false;
			}
			if(top[i]<count[i]) {
				finish = false;
				if(s[i]->pid==-1){
					flag = true;
					break;
				}
			}
		}
		
		if(flag){
			Msg *curr = msgs[i][top[i]];
			top[i] ++;
			
			if((s[curr->pid]->pid) == i && (s[curr->pid]->kind )== (curr->kind)){
				s[curr->pid]->pid = -1;
				s[i]->pid = -1;
			}else{
				s[i]->pid = curr->pid;
				s[i]->kind = (curr->kind=='S') ? 'R' : 'S';
			}
		}else{
			
			if(finish && allIdle) printf("0\n");
			else printf("1\n");
			
			break;
		}
	}
//	for(int i=0;i<n;i++){
//		cout << count[i] << ":" ;
//		for(int j=0;j<count[i];j++){
//			cout << msgs[i][j]->kind << msgs[i][j]->pid << " ";
//		}
//		cout << endl;
//	}
}


int main(){
	scanf("%d%d",&T,&n);
	
	fgets(buf,100,stdin);
	for(int i=0;i<T;i++){
		run();
	}
	
	return 0;
}
