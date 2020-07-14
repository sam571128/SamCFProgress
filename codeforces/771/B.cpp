#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,k;
	cin >> n >> k;
	string s[n];
	for(int i = 0;i < n;i++){
		char tmp = ('A'+min(i,25));
		s[i] = tmp;
		if(i>25){
			tmp =('a'+i%26);
			s[i] += tmp;
		}
	}
	for(int i = 0;i < n-k+1;i++){
		string tmp;
		cin >> tmp;
		if(tmp=="YES") continue;
		s[i+k-1] = s[i];
	}
	for(auto x : s) cout << x << " ";
}