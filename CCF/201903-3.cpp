#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/09/19 17:55
	Description: 注意条带的排布方式,从校验盘开始
				通过7/10 
*/


typedef unsigned char uchar;

uchar disk[1005][3005][4];
char buf[30005];
bool mark[1005];
int n,s,l;
int blockNum;

uchar halfByte(char ch){
	if(ch>='0' && ch<='9'){
		return ch - '0';
	}else{
		return ch - 'A' + 10;
	}
}

uchar byte(char high,char low){
	uchar hi = halfByte(high);
	uchar lo = halfByte(low);
	uchar res = (hi << 4) + lo;
	return res;
}

int readDisk(){
	fgets(buf,30005,stdin);
	int num = 0;
	char *ptr = buf;
	while(*ptr!=' '){
		num = num * 10 + (*ptr - '0');
		ptr ++;
	}
	mark[num] = true;
	ptr++;
	uchar v;
	int offset,block;
	int count = 0;
	while(*ptr!='\n'){
		v = byte(*ptr,*(ptr+1));
		offset = count % 4;
		block = count / 4;
		disk[num][block][offset] = v;
		ptr+=2;
		count ++;
//		printf("%01x",v);
	}
	
	return count/4;
//	printf("\n");
}

void fillDisk(int num){
	memset(disk[num],0,sizeof(uchar)*blockNum*4);
	for(int i=0;i<n;i++){
		if(i!=num){
			for(int j=0;j<blockNum;j++){
				for(int k=0;k<4;k++){
					disk[num][j][k] ^= disk[i][j][k];
				}
			}
		}
	}
}

void queryDisk(int bi){
	int sNum = bi / s;
	int sOff = bi % s;
	int rowNum = sNum / (n-1);
	int rowOff = sNum % (n-1);
	
	int pNum = (n-1) - (rowNum % n);
	
	rowOff = (pNum + rowOff + 1) % n;
	
	for(int i=0;i<4;i++){
		printf("%02X",disk[rowOff][rowNum*s + sOff][i]);
	}
	printf("\n");
}

int main(){

	scanf("%d%d%d",&n,&s,&l);
	
	fgets(buf,30005,stdin);
	
	for(int i=0;i<n;i++){
		mark[i] = false;
	}
	for(int i=0;i<l;i++){
		blockNum = readDisk();
	}
	
	//miss one
	if(l==n-1){
		for(int i=0;i<n;i++){
			if(!mark[i]){
				fillDisk(i);
				break;
			}
		}
	}
	
	int m,bi;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&bi);
		if(l<n-1 || bi>=(n-1)*blockNum){
			printf("-\n");
		}else{
			queryDisk(bi);
		}
	}
	
	return 0;
}
