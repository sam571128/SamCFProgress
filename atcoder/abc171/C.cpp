#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	vector<char> tmp;
	while(n!=0){
		n--;
		tmp.push_back((char)(n%26+'a'));
		//cout << n%26 << " ";
		n/=26;
	}
	reverse(tmp.begin(),tmp.end());
	for(auto x : tmp) cout << x;
}