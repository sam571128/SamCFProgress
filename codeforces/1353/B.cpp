#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i = 0;i < n;i++)
			cin >> a[i];
		int b[n];
		for(int i = 0;i < n;i++)
			cin >> b[i];
		while(k--){
			sort(a,a+n);
			sort(b,b+n);
			if(a[0]>=b[n-1]){
				break;
			}
			swap(a[0],b[n-1]);
		}
		int sum = 0;
		for(int i = 0;i < n;i++){
			sum += a[i];
		}
		cout << sum << "\n";
	}
}