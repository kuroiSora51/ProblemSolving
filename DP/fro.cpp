#include <iostream>
using namespace std;

int dp[10000000];

int main(){
	int n;
	cin>>n;
	int array[n+5];
	for(int i=0;i<n;++i){
		cin>>array[i];
	}
	
	dp[0]=0;
	dp[1]=abs(array[0]-array[1]);
	
	for(int i=2;i<n;++i){
		dp[i]=min(dp[i-2]+abs(array[i]-array[i-2]),dp[i-1]+abs(array[i]-array[i-1]));
	}
	cout<<dp[n-1];
	
	//6
	//30 10 60 10 60 50

	
}