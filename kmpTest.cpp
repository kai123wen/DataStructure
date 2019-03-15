#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void getNext(char* sqstr,int next[]);
int kmp(char* s,char* t);
int main(){

	char *s = "aaaab";
    char *t = "ab";
	cout<<kmp(s,t);
	return 0;
}


//get next
void getNext(char* sqstr,int next[]){
	int j, k;
	next[0] =-1;
	j = 0;
	k = -1;
	while (j < strlen(sqstr)-1){
		if (k == -1 || sqstr[j] == sqstr[k]){
			j++;
			k++;
			next[j] = k;
		}
		else{
			k = next[k];
		}
	}
}

//kmp 
int kmp(char* s,char* t){
	int next[2];
	getNext(t,next);
	int i=0,j=0;
	while (i<strlen(s) && j<strlen(t)){
		if (j == -1 || s[i]== t[j]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	if (j >= strlen(t)){
		cout<<"成功"<<endl;
			return (i-strlen(t));
	}
	else{
		return -1;
	}
}
