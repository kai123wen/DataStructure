#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
 int  getLongestStr(char *s);
int main(){
	char *a = "abcaabcd";
	cout<<getLongestStr(a)<<endl;
}

//get the longest str

int getLongestStr(char *s){
	int len =0,index= -1;
	int maxLen = 0,maxIndex = -1;
	int i=0,j;
	while(i<strlen(s)-1){
			j = i+1;
			len = 0;
		while(j < strlen(s)){
					len = 0;
				    for (int k=0;s[i+k] == s[j+k];k++){
                     len++;
                    }

		  if (maxLen < len){
                maxLen = len;
          }
			
		j++;
		}
	
		i++;
	}
	return maxLen;
}
