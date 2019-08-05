/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/07/19 21:03
	Description: 
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char HM[19][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", 
					"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", 
					"pax", "koyab", "cumhu","uayet"};
char TN[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", 
					"lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", 
					"cib", "caban", "eznab", "canac", "ahau"};

int str2month(char *r){
	for(int i=0;i<19;i++){
		if(strcmp(HM[i],r)==0){
			return i;
		}
	}
	return -1;
}

void run(){
	char buf[100];
	cin.getline(buf,100);
	
	int DH = 0,MH = 0,YH = 0; 
	char Mstr[10];
	char *p = buf,*r = Mstr;
	while(*p!='.'){
		DH = DH*10 + (*p - '0');
		p++;
	}
	p+=2;
	
	while(*p!=' '){
		*r = *p;
		p++;
		r++;
	}
	*r = '\0';
	p++;
	MH = str2month(Mstr);
	
	while(*p){
		YH = YH * 10 + (*p - '0');
		p++;
	}
	
	int days = YH * 365 + MH * 20 + DH;
	
	int YT = days / 260;
	days %= 260;
	int NT = days % 13 + 1;
	int NameIdx = days%20;
	
	cout << NT << " " << TN[NameIdx] << " " << YT << endl;
}

int main(){
	
	int n;
	cin >> n;
	char buf[10];
	cin.getline(buf,10);
	cout << n << endl;
	for(int i=0;i<n;i++){
		run();
	}
	return 0;
}

