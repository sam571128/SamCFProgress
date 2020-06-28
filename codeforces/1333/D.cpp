#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,k;
	cin >> n >> k;
	vector<ll> arr(n);
	for(ll i = 0;i < n;i++){
		char tmp;
		cin >> tmp;
		arr[i] = (tmp=='R' ? 1 : 0);
	}
	queue<vector<ll>> q;
	vector<ll> v;
	ll times = 0;
	while(true){
		v.clear();
		for(ll i = 0;i < n-1;i++){
			if(arr[i]&&!arr[i+1]){
				v.push_back(i+1);
				swap(arr[i],arr[i+1]);
				i++;
			}
		}
		if(v.size()==0) break;
		times += v.size();
		q.push(v);
	}
	if(k < q.size() || k > times){
		cout << -1 << "\n";
		return 0;
	}
	ll c = k - q.size();
	while(!q.empty()){
		auto x = q.front(); q.pop();
		while(x.size() > 1 && c > 0){
			cout << "1 " << x.back() << "\n";
			x.pop_back();
			c--;
		}
		cout << x.size() << " ";
		for(auto tmp : x) cout << tmp << " ";
		cout << "\n";
	}
}