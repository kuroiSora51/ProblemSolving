#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p 1000000007
#define ll long long
#define pb(x) push_back(x)
#define dlt() pop_back()
#define print(x) for(int z=0;z<n;z++) cout<<x[z]<<" "; cout<<"\n"

vector<int> permutation;
vector<bool> chosen;
vector<int> fact = {1,1,2,6,24,120,720,5040,40320};
string S,X;
unordered_map<string,int> mark;

ll countPermutations(const string& str){
	unordered_map<char,int> freq;
	for(char c: str)
		freq[c]++;
		
	ll numerator = fact[str.length()];
	ll denominator = 1;
	
	for(const auto& pair: freq){
		denominator *= fact[pair.second];
	}
	return numerator / denominator;
}

void search(){
	int n = S.size();
	if(X.size() == n and mark[X] == 0){
		cout<<X<<"\n";
		mark[X]++;
	}
	else{
		for(int i=0;i<n;i++){
			if (chosen[i]) continue;
			chosen[i] = true;
			X += S[i];
			search();
			chosen[i] = false;
			X.dlt();
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>S;
	sort(S.begin(),S.end());
	chosen.resize(S.size(), false);
	ll ans = countPermutations(S);
	cout<<ans<<"\n";
	search();

}