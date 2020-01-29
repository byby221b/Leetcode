#include <iostream> 
#include <cstdio>
#include <algorithm>
/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/09/19 08:46
	Description: ¶þ·Ö²éÕÒ? 
*/


using namespace std;

int bound[5000];
int time[2500];

int main(){
	int n;
	scanf("%d",&n);
	
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		bound[i*2] = a;
		bound[i*2+1] = b;
		time[i] = b - a;
	}
	
	int chat = 0;
	int c,d;
	for(int i=0;i<n;i++){
		scanf("%d%d",&c,&d);
		int *c_lb = lower_bound(bound,bound+2*n,c);
		int *d_lb = lower_bound(bound,bound+2*n,d);
		
		int c_idx = (c_lb-bound)/2;
		int d_idx = (d_lb-bound)/2;
		if((c_lb-bound)%2){
			for(int j=c_idx+1;j<n && j<d_idx;j++){
				chat += time[j];
			}
			if(c_idx<d_idx){
				chat += (bound[c_idx*2+1]-c);
				if((d_lb-bound)%2){
					chat += (d - bound[d_idx*2]);	
				}
			}else{
				chat += (d-c);
			}
			
		}else{
			for(int j=c_idx;j<n && j<d_idx;j++){
				chat += time[j];
			}
			if((d_lb-bound)%2){
				chat += (d - bound[d_idx*2]);
			}
		}
	}
	
	printf("%d\n",chat);
	return 0;
}

