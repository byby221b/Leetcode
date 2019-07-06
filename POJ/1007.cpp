/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 11:05
	Description: 根据数据量级判断可以使用for循环计算逆序数、使用冒泡排序进行排序 
*/

#include <iostream> 
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

char *data[105];
int sortedness[105];



int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){
		data[i] = new char[n+5];
		scanf("%s",data[i]);
	}
	
	for(int i=0;i<m;i++){
		int count = 0;
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(data[i][j] > data[i][k]){
					count ++;
				}
			}
		}
		sortedness[i] = count;
	}
	
	
	
	bool flag = false;
	for(int bound=m-1;bound>0;bound--){
		flag = false;
		for(int i=0;i<bound;i++){
			if(sortedness[i]>sortedness[i+1]){
				char *tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
				int stmp = sortedness[i];
				sortedness[i] = sortedness[i+1];
				sortedness[i+1] = stmp;
				flag = true;
			}
		}	
		if(!flag) break;
	}
	
	
	for(int i=0;i<m;i++){
		printf("%s\n",data[i]);
	}
	
	for(int i=0;i<m;i++){
		delete [] data[i];
	}
	
	return 0;
}
