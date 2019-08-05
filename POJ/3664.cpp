/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/07/19 20:14
	Description: 
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef struct cow{
	int id,voteA,voteB;
}CS;

CS* data[50005];

void swap(int a,int b){
	CS *tmp;
	tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

void threeMid(int left,int right){
	int mid = left + (right - left)/2;
	//mid <= right
	if((data[mid]->voteA) > (data[right]->voteA)){
		swap(mid,right);
	}
	
	//left <= right
	if((data[left]->voteA) > (data[right]->voteA)){
		swap(left,right);
	}
	
	//mid <= left
	if((data[mid]->voteA) > (data[left]->voteA)){
		swap(mid,left);
	}
}

void qsort(int left,int right){
	if(left >= right){
		return;
	}
	
	threeMid(left,right);
	
	int key = data[left]->voteA;
	int i = left + 1, j = right;
	while(i<j){
		while((data[i]->voteA)>key && i<right){
			i++;
		}
		while((data[j]->voteA)<key && j>left ){
			j--;
		}
		
		if(i<j){
			swap(i,j);
		}
	}
	swap(left,j);
	
	qsort(left,j-1);
	qsort(j+1,right);
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
		
	for(int i=0;i<n;i++){
		data[i] = new CS;
		scanf("%d%d",&(data[i]->voteA),&(data[i]->voteB));
		data[i]->id = i;
	}
	
	qsort(0,n-1);
	
	int maxV = -1;
	int maxId = -1;
	for(int i=0;i<k;i++){
		if((data[i]->voteB)>maxV){
			maxV = data[i]->voteB;
			maxId = data[i]->id;
		}
	}
	
	printf("%d\n",maxId+1);
	
	for(int i=0;i<n;i++){
		delete data[i];
	}
	return 0;
}

