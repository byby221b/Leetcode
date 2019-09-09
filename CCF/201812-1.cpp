/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/09/19 08:54
	Description: Finsh 9:03
				Í¨¹ý²âÊÔµã10/10 
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int r,y,g;
	cin >> r >> y >> g;
	
	long long time = 0;
	int n;
	cin >> n;
	int k,t;
	for(int i=0;i<n;i++){
		cin >> k >> t;
		switch(k){
			case 0:
			case 1:
			{
				time += t;
				break;
			}
			case 2:{
				time += (t + r);
				break;
			}
			default: break;
		}
	}
	
	cout << time << endl;
	
	return 0;
}
