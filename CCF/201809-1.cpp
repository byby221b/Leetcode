#include <iostream> 
#include <cstdio>

/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/09/19 08:39
	Description: 
*/


using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int *price = new int[n+5];
	
	for(int i=0;i<n;i++){
		scanf("%d",&price[i]);
	}
	
	printf("%d ",(price[0]+price[1])/2);
	for(int i=1;i<n-1;i++){
		printf("%d ",(price[i-1]+price[i]+price[i+1])/3);
	}
	printf("%d\n",(price[n-1]+price[n-2])/2);
	
	
	delete [] price;
	return 0;
}

