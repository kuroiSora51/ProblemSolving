#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define N 1000000
#define TestCases(t) for(int i=0;i<t;i++)

int maxGCD(const vector<int>& A){
	int M = *max_element(A.begin(), A.end());
	vector<int> freq(M + 1, 0);
	for(int x: A) freq[x]++;
	
	for(int g=M; g>=1; g--){
		int count = 0;
		for(int m=g; m<=M; m+=g){
			count += freq[m];
			if (count >=2)
				return g; 
		}
	}
    return 1;
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
    	cin >> A[i];

    cout << maxGCD(A) << endl;

    return 0;
}
