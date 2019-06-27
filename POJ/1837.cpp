/*
	Name: 
	Copyright: 
	Author: 
	Date: 25/06/19 15:00
	Description: ¶¯Ì¬¹æ»® 
*/

#include <iostream>
#include <cstring> 
#define MAGIC 7500
using namespace std;

int method[25][15005];
int hooks[25];
int weights[25];

int main(){
	int C,G;
	cin >> C >> G;
	
	for(int i=1;i<=C;i++){
		cin >> hooks[i];
	}
	
	for(int i=1;i<=G;i++){
		cin >> weights[i];
	}
	
//	for(int i=0;i<=G;i++){
//		for(int j=0;j<=MAGIC*2;j++){
//			method[i][j] = 0;
//		}
//	}
	memset(method,0,sizeof(method));	
	method[0][MAGIC] = 1;
	
	for(int i=1;i<=G;i++){
		int minB = -375 * (G - 1) + MAGIC;
		int maxB = 375 * (G - 1) + MAGIC;
		for(int b=minB;b<=maxB;b++){
			for(int j=1;j<=C;j++){
				method[i][b+hooks[j]*weights[i]] += method[i-1][b];
			}
		}
	}
	
	cout << method[G][MAGIC] << endl;
	
	return 0;
}

