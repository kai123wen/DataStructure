//get all the arrangement of array
#include<iostream>
using namespace std;
void getAllArrange(int a[],int n,int k);
int main(){
	int a[5] = {1,2,3,4,5};
	getAllArrange(a,5,4);
	return 0;
}

//the function
void getAllArrange(int a[],int n,int k){
	if (k == 0){
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	else{
		for (int j=0;j<k;j++){
			swap(a[j],a[k]);
			getAllArrange(a,n,k-1);
			swap(a[j],a[k]);
		}
	}
}