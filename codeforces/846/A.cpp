#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


const int N = 105;
int a[N];
int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1,tmp;i <= n;i++){
		cin >> tmp;
		a[i] = a[i-1] + tmp;
	}
	int ans = 0;
	for(int i = 0;i <= n;i++) ans = max(ans,i-a[i]+a[n]-a[i]);
	cout << ans << "\n";
}