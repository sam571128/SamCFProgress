#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int k;
	string n;
	cin >> k >> n;

	int sum = 0;
	for(int i = 0;i < n.size();i++){
		sum += n[i]-'0';
	}
	if(sum>=k) cout << 0 << "\n";
	else{
		sort(n.begin(),n.end());
		int ans = 0;
		for(int i = 0;i < n.size();i++){
			if(n[i]=='9') break;
			sum -= n[i]-'0';
			sum += 9;
			ans++;
			if(sum >= k){
				cout << ans << "\n";
				return 0;
			}
		}
		cout << ans << "\n";
	}
}