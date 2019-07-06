/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 09:14
	Description: 使用string会超时 
*/

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
using namespace std;

string int2str(int a){
	stringstream ss;
	ss << a;
	return ss.str();
}

void join(char *buf,int &top,int num){
	if(num<10){
		buf[top] = num + '0';
		top ++;
	}else{
		buf[top] = (num / 10) + '0';
		top ++;
		buf[top] = (num % 10) + '0';
		top ++;
	}
}

void inventory(char *myStr,char *res){
	int count[10];
	memset(count,0,sizeof(count));
	
	for(int i=0;myStr[i]!='\0';i++){
		count[myStr[i]-'0'] ++;
	}
	
	int top = 0;
	for(int i=0;i<10;i++){
		if(count[i]>0){
			join(res,top,count[i]);
			join(res,top,i);
		}
	}
	
	res[top] = '\0';
	
//	printf("%s\n",res);
	
}

bool run(){
	
	char buf[200];
	scanf("%s",buf);
	
	if(buf[0]=='-' && buf[1]=='1'){
		return false;
	}
	
	bool selfFlag = false;
	bool loopFlag = false;
	int i;
	int loopLength = -1;
	char record[20][200];
	strcpy(record[0],buf);
	
	char tmp[200];
	
	for(i=1;i<=15;i++){
		inventory(record[i-1],tmp);
		strcpy(record[i],tmp);
		if(strcmp(record[i],record[i-1])==0){
			selfFlag = true;
			break;
		}else{
			for(int j=0;j<i-1;j++){
				if(strcmp(record[j],record[i])==0){
					loopFlag = true;
					loopLength = i - j;
					break;
				}
			}
		}
		if(loopFlag) break;
		
//		cout << i << " " << tmp << endl;
	}
	
//	inventory(record[15],tmp);
//	if(i==16 && strcmp(tmp,record[15])){
//		selfFlag = true;
//	}
	
	if(selfFlag && i==1){
		printf("%s is self-inventorying\n",buf);
//		cout << buf << " is self-inventorying" << endl;
	}else if(selfFlag && i>1){
		printf("%s is self-inventorying after %d steps\n",buf,i-1);
//		cout << buf << " is self-inventorying after "<< i-1 <<" steps" << endl;
	}else if(loopFlag){
		printf("%s enters an inventory loop of length %d\n",buf,loopLength);
//		cout << buf << " enters an inventory loop of length " << loopLength << endl;
	}else{
		printf("%s can not be classified after 15 iterations\n",buf);
//		cout << buf << " can not be classified after 15 iterations" << endl;
	}
	
	return true;
}


int main(){
	while(run());
	return 0;
}

