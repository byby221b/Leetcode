/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/09/19 09:03
	Description: Finish: 9:32
				Í¨¹ý²âÊÔµã10/10
*/


#include <iostream>
#include <cstdio>

using namespace std;

int trans(int k){
	switch(k){
		case 1:return 0;
		case 2:return 2;
		case 3:return 1;
	}
	
	return 1;
}

int main(){
	int last[3];
	cin >> last[0] >> last[2] >> last[1];
	int roundTime = (last[0] + last[1] + last[2]);
	long long time = 0;
	int n;
	cin >> n;
	int k,state;
	long long t;
	for(int i=0;i<n;i++){
		cin >> k >> t;
		if(k==0) time += t;
		else{
			state = trans(k);
			
			long long round = time/roundTime;
			long long modTime = time - round * roundTime;
			
//			cout << ">>" << round << " " << modTime << endl;
			
			while(t<modTime){
				state = (state + 1)%3;
				t += last[state];
			}
			
			if(state==0) time = t + round*roundTime;
			else if(state==2) time = t + last[0] + round*roundTime;
			
		}
		
	}
	
	cout << time << endl;
	
	return 0;
}
