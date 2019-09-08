#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int n;
	
	scanf("%d",&n);
	
	int first,last;
	double mid;
	int tmp;
	
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(i==0) first = tmp;
		if(i==n-1) last = tmp;
		if(n%2==1 && i==(n/2)){
			mid = tmp;
		}
		if(n%2==0){
			if(i==(n/2-1)) mid = tmp;
			if(i==n/2) mid = (mid+double(tmp))/2.0;
		}
	}
	
	int maxVal = (first > last) ? first : last;
	int minVal = (first < last) ? first : last;
	
	if(int(mid*10)%10==0){
		printf("%d %d %d\n",maxVal,int(mid),minVal);
	}else{
		printf("%d %.1f %d\n",maxVal,mid,minVal);
	}
	
	
	return 0;
}
