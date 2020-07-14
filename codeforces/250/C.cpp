#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int N = 1e5+5;
int s[N],a[N];
int main(){
	fastio
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		int j = i;
		while(a[j]==a[i])j++;
		if(a[i-1]==a[j]) s[a[i]] += 2;
		else s[a[i]]++;
		i = j-1;
	}
	int ans = 1;
	for(int i = 2;i <= k;i++){
		if(s[i]>s[ans]) ans = i;
	}
	cout << ans << "\n";
}