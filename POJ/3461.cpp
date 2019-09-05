
/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/09/19 21:40
	Description: KMP算法,注意查找过程 
*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char word[10005];
char text[1000005];
int kmpNext[10005];

void countKmpNext(char *word){
	int i = 0;
	int j = -1;
	kmpNext[0] = -1;
	
	while(word[i]!='\0'){
		while(j>-1 && word[i]!=word[j]){
			j = kmpNext[j];
		}
		
		i++;
		j++;
		
		if(word[i]==word[j]){
			kmpNext[i] = kmpNext[j];
		}else{
			kmpNext[i] = j;
		}
	}
	
}


void run(){
	scanf("%s%s",word,text);
//	printf(">>%s\n",word);
//	printf(">>%s\n",text);
	int count = 0;
//	char *start = text;
	
	int textLen = strlen(text);
	int wordLen = strlen(word);
	
	countKmpNext(word);
	
//	while(start-text<textLen){
//		char *textPtr = start;
//		char *wordPtr = word;
//		while(*wordPtr!='\0' && *textPtr!='\0' && (*textPtr)==(*wordPtr)){
//			textPtr ++;
//			wordPtr ++;
//		}
//		
//		if(*wordPtr=='\0') count++;
//		
//		if(*textPtr=='\0') break;
//		
//		int wordIdx = wordPtr - word;
//		start += (wordIdx - kmpNext[wordIdx]);
//	}
	
	int i=0,j=0;
	while(j<textLen){
		while(i>-1 && word[i]!=text[j]){
			i = kmpNext[i];
		}
		
		i++;
		j++;
		
		if(i>=wordLen){
			count ++;
			i = kmpNext[i];
		}
	}
	printf("%d\n",count);
	
}



int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		run();
	}
	
	return 0;
}
