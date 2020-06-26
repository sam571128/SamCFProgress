#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int last = 0;
	int mi = INT_MAX;
	bool ok = true;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(!last){
			mi = tmp;
			last = tmp;
			continue;
		}
		
		if(tmp < last){
			if(tmp > mi){
				ok = false;
			}
			mi = tmp;
		}else{
			if(tmp > last+1){
				ok = false;
			}
		}
		last = tmp;
	}
	cout << (ok?"Yes\n":"No\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}