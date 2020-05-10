#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	string a;
	cin >> a;
	int ans = 0;
	for(int l = 0;l < a.size();l++){
		if(a[l]=='Q')
			for(int r = l+1;r < a.size();r++){
				if(a[r]=='A')
					for(int n = r+1;n < a.size();n++){
						if(a[n]=='Q') ans++;
					}
			}
	}
	cout << ans;
}

int main(){
	fastio
	solve();
}
