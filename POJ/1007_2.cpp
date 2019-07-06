/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 11:29
	Description: 改进:
				逆序对数目采用类似BIT的做法,复杂度为O(n)(只有四个字母) 
				排序采用stl中的stable_sort 
						
*/
#include <iostream> 
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm> 

using namespace std;


//int sortedness[105];

struct DNA{
	char str[55];
	int sortedness;
};

typedef struct DNA* DNAinfo;

DNAinfo data[105];

bool cmp(const DNAinfo a,const DNAinfo b){
	return ((a->sortedness) < (b->sortedness));
}

int ch2idx(char ch){
	int res;
	switch(ch){
		case 'A': res = 0;break;
		case 'C': res = 1;break;
		case 'G': res = 2;break;
		case 'T': res = 3;break;
		default : res = -1;break;
	}
	return res;
}

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){
		data[i] = new struct DNA;
		scanf("%s",data[i]->str);
	}
	
	int letCount[5];
	for(int i=0;i<m;i++){
		int count = 0;
		memset(letCount,0,sizeof(letCount));
		for(int j=n-1;j>=0;j--){
			int idx = ch2idx((data[i]->str)[j]);
			for(int k=0;k<idx;k++){
				count += letCount[k];
			}
			letCount[idx] += 1;
		}
		data[i]->sortedness = count;
	}
	
	stable_sort(data,data+m,cmp);
	
	for(int i=0;i<m;i++){
		printf("%s\n",data[i]->str);
	}
	
	for(int i=0;i<m;i++){
		delete data[i];
	}
	
	return 0;
}
