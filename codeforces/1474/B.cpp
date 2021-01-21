#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int isprime[N];
vector<int> primes;
void init(){
	memset(isprime,1,sizeof isprime);
	for(int i = 2;i < N;i++){
		if(isprime[i]){
			primes.push_back(i);
			for(int j = i*i;j < N;j+=i){
				isprime[j] = 0;
			}
		}
	}
}

void solve(){
	int d;
	cin >> d;
	vector<int> v;
	v.push_back(1);
	for(auto x : primes){
		if(v.size() >= 3) break;
		if(x-v.back()>=d) v.push_back(x);
	}
	int ans = 1;
	for(auto x : v){
		ans *= x;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	init();
	int t = 1;
	cin >> t;
	while(t--) solve();
}