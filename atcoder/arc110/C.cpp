#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
bitset<N> used;
vector<int> v[N];
int bit[N];
 
void update(int pos, int val){
	while(pos < N){
		bit[pos] += val;
		pos += pos&-pos;
	}
}
 
int query(int pos){
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos&-pos;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int arr[n];
	bool ok = true;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		int tmp = i+1;
		if(i+1>=arr[i]&&(i+1)-arr[i] < query(n-arr[i]+1)){
			ok = false;
		}
		while(arr[i] > tmp){
			if(used[tmp]){
				ok = false;
				break;
			}
			used[tmp] = 1;
			v[arr[i]].push_back(tmp);
			tmp++;
		}
		update(n-arr[i]+1,1);
	}
	for(int i = 1;i < n;i++){
		if(!used[i]) ok = false;
	}
	if(!ok){
		cout << -1 << "\n";
		return;
	}
	for(int i = n;i;i--){
		for(auto x : v[i]) cout << x << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}

/*
if(i+1>=arr[i]&&(i+1)-arr[i] < query(n-arr[i]+1)){
			ok = false;
		}
		int tmp = i+1;
		while(arr[i] > tmp){
			v[arr[i]].push_back(tmp);
			tmp++;
		}
		update(n-arr[i]+1,1);
*/