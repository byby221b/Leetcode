/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 19:45
	Description: 
*/

#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

struct snowflake{
	int arm[6];
};

typedef struct snowflake SF;

SF data[200005];

bool cmp(SF a,SF b){
	for(int i=0;i<6;i++){
		if((a.arm[i])<(b.arm[i])){
			return true;
		}
		if((a.arm[i])>(b.arm[i])){
			return false;
		}
	}
	return false;
}

bool equal(SF a,SF b){
	for(int i=0;i<6;i++){
		if((a.arm[i])!=(b.arm[i])){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	
	int tmp[6];
	for(int i=0;i<n;i++){
		
		int minIdx = -1;
		int minVal = 0;
		for(int j=0;j<6;j++){
			scanf("%d",&tmp[j]);
			if(minIdx==-1 || minVal>tmp[j]){
				minIdx = j;
				minVal = tmp[j];
			}
		}
		
		for(int j=0;j<6;j++){
			(data[2*i]).arm[j] = tmp[(minIdx+j)%6];
			(data[2*i+1]).arm[j] = tmp[(minIdx-j+6)%6];
		}
	}
	
	sort(data,data+(2*n),cmp);
	
	bool flag = false;
	for(int i=0;i<2*n-1;i++){
		if(equal(data[i],data[i+1])){
			flag = true;
			break;
		}
	}	
	
	if(flag){
		printf("Twin snowflakes found.\n");
	}else{
		printf("No two snowflakes are alike.\n");
	}
	
//	for(int i=0;i<2*n;i++){
//		for(int j=0;j<6;j++){
//			cout << data[i]->arm[j] << " ";
//		}
//		cout << endl;
//	}
//	for(int i=0;i<2*n;i++){
//		delete data[i];
//	}
//	
	return 0;
}

