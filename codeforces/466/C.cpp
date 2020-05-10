#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	int n;
	cin >> n;
	ll int sum = 0;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if(sum%3){
		cout << 0;
		return;
	}
	sum/=3;
	ll int t = 0;
	ll int ans = 0;
	ll int cnt = 0;
	for(int i = 0;i < n-1;i++){
		t+=a[i];
		if(t == 2*sum){
			ans += cnt;
		}
		if(t == sum){
			cnt ++;
		}
	}
	cout << ans;
}

int main(){
	fastio
	solve();
}
