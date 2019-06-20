/*
	Name: 
	Copyright: 
	Author: BY
	Date: 20/06/19 15:44
	Description: 计算两个日期之间的天数 (Codeup有50%数据未通过) 
*/
 
#include <iostream> 
using namespace std;


int year_days(int y){
	int days = 365;
	if(y%400==0){
		days = 366;
	}else if(y%4==0 && y%100!=0){
		days = 366;
	}
	
	return days;
}

int ymd_days(int y,int m,int d){
	int days_list[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(year_days(y)==366){
		days_list[1] = 29;
	}
	
	int days = d;
	for(int i=1;i<m;i++){
		days += days_list[i-1];
	}
	
	return days;
}

int char2int(char a){
	return a - '0';
}

int main(){
	
	int y1,m1,d1;
	int y2,m2,d2;
	
	//cin >> y1 >> m1 >> d1;
	//cin >> y2 >> m2 >> d2;
	
	/*
	For code up
	*/
	string buff;
	cin >> buff;
	y1 = 1000*char2int(buff[0]) + 100*char2int(buff[1]) + 10*char2int(buff[2]) + char2int(buff[3]);
	m1 = 10 * char2int(buff[4]) + char2int(buff[5]);
	d1 = 10 * char2int(buff[6]) + char2int(buff[7]);
	
	cin >> buff;	
	y2 = 1000*char2int(buff[0]) + 100*char2int(buff[1]) + 10*char2int(buff[2]) + char2int(buff[3]);
	m2 = 10 * char2int(buff[4]) + char2int(buff[5]);
	d2 = 10 * char2int(buff[6]) + char2int(buff[7]);
	
//	cout << y1 << " " << m1 << " " << d1 << endl;
//	cout << y2 << " " << m2 << " " << d2 << endl;
	
	int sum = ymd_days(y2,m2,d2) - ymd_days(y1,m1,d1);
	for(int i=y1;i<y2;i++){
		sum += year_days(i);
	}
	
	//cout << sum;
	/*For code up*/
	cout << sum + 1;
	
	return 0;
}
