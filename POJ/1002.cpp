/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 19:09
	Description: 注意输出格式,可能需要补前导零 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char buf[20];

int table[26] = {
				2,2,2,
				3,3,3,
				4,4,4,
				5,5,5,
				6,6,6,
				7,-1,7,
				7,8,8,
				8,9,9,
				9,-1};

int read(){
	scanf("%s",buf);
	int res = 0;
	for(int i=0;buf[i]!='\0';i++){
		if(buf[i]=='-') continue;
		
		int digt;
		
		if(buf[i]>='A' && buf[i]<='Z'){
			digt = table[buf[i]-'A'];
		}else{
			digt = buf[i] - '0';
		}
		
		res = res * 10 + digt;
	}
	
	return res;
}

int main(){
	
	int n;
	scanf("%d",&n);
	
	int *data = new int[n+5];
	
	
	for(int i=0;i<n;i++){
		data[i] = read();
	}
	
	sort(data,data+n);
	
//	for(int i=0;i<n;i++){
//		cout << data[i] << endl;
//	}
	
	bool flag = false;
	for(int i=0;i<n;i++){
		int curr = data[i],count = 1;
		while(i+1<n && data[i+1]==data[i]){
			count ++;
			i++;
		}
		if(count > 1){
			flag = true;
			printf("%03d-%04d %d\n",curr/10000,curr%10000,count);
		}
	}
	
	if(!flag){
		printf("No duplicates.\n");
	}
	
	delete [] data;
	return 0;
}

