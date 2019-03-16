#include<iostream>
using namespace std;
 int getMin(int a[],int n);
int main(){
	int a[5] = {2,1,3,5,6};
	cout<<getMin(a,4);
}
//得到数组中的最小值
int getMin(int a[],int n){
	
	int m;	
	if (n == 0){
		return a[0];
	}
	else{
	 m = getMin(a,n-1);
	 if(m>a[n]){
	 	return a[n];
	 }else{
	 	return m;
	 }
		
	}
}
