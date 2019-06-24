/*
	Name: 
	Copyright: 
	Author: 
	Date: 24/06/19 11:23
	Description: 注意递推的思路 
*/

#include <iostream>

using namespace std;

void run(){
	int m;
	int zero = 1 , one = 1;
	cin >> m;
	for(int i=2;i<=m;i++){
		int tmpZero = zero;
		zero = zero + one;
		one = tmpZero;
	}
	
	cout << zero + one << endl;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		run();
	}
	return 0;
}



