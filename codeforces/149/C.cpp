#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	vector<array<ll,2>> a(n);
	for(ll i = 0;i < n;i++){
		cin >> a[i][0];
		a[i][1] = i;
	}
	sort(a.begin(),a.end());
	ll ma = a[0][0];
	vector<array<ll,2>> v1;
	ll sum1 = 0;
	vector<array<ll,2>> v2;
	ll sum2 = 0;
	for(ll i = 0, t = 1;i < n;i++){
		if(t){
			v1.push_back(a.back()),sum1+=a.back()[0],a.pop_back();
		}else{
			v2.push_back(a.back()),sum2+=a.back()[0],a.pop_back();
		}
		t^=1;
	}
	while(sum1-sum2>ma&&v2.size()<v1.size()){
		sum1 -= v1.back()[0], sum2 += v1.back()[0];
		v2.push_back(v1.back()); v1.pop_back();
	}
	cout << v1.size() << "\n";
	for(auto x : v1) cout << x[1]+1 << " ";
	cout << '\n' << v2.size() << "\n";
	for(auto x : v2) cout << x[1]+1 << " ";
}