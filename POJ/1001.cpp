/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/07/19 22:00
	Description: 高精度整数(注意输出格式) 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct BigFloat{
		int digt[205];
		int floatCount,total;
} BF;

int min(int a,int b){
	return (a<b?a:b);
}

BF multi(BF num1,BF num2){
	BF res;
	memset(res.digt,0,sizeof(res.digt));
	int total = min(num1.total * num2.total,200);
	for(int i=0;i<num1.total;i++){
		for(int j=0;j<num2.total;j++){
			res.digt[i+j] += (num1.digt[i] * num2.digt[j]);
			res.digt[i+j+1] += (res.digt[i+j] / 10); //进位
			res.digt[i+j] %= 10;
		}
	}
	
	while(!res.digt[total] && total>=0){
		total --;
	}
	
	res.total = total + 1;
	res.floatCount = num1.floatCount + num2.floatCount;
	
	return res;
}

int main(){
	
	char buf[10];
	int n;
	while(scanf("%s%d",buf,&n)!=EOF){
		BF num;
		char *p = buf;
		int idx = 4;
		while(*p){
			if(*p=='.'){
				num.floatCount = 5-(p-buf);
			}else{
				num.digt[idx] = (*p) - '0';
				idx--;
			}
			p++;
		}
		
		idx = 4;
		while(!num.digt[idx] && idx>=0){
			idx --;
		}
		num.total = idx + 1;
		
		BF tmp = num;
		for(int i=0;i<n-1;i++){
			num = multi(num,tmp);
		}
		
		for(int i=num.total-1;i>=num.floatCount;i--){
			cout << num.digt[i];
		}
		int tail = 0;
		while(num.digt[tail]==0 && tail<num.floatCount){
			tail ++;
		}
		if(num.total==0 && tail==num.floatCount){
			cout << "0";
		}
		
		if(num.floatCount!=0 && tail<num.floatCount){
			cout << ".";
		}
		for(int i=num.floatCount-1;i>=tail;i--){
			cout << num.digt[i];
		}
		
		cout << endl;
		
//		cout << num.total << " " << num.floatCount << endl;
	}
	

	return 0;
}
