#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,t;
	cin >> n >> t;
	int arr[n];
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	int l = 0,r = 0, ans = 0, time = 0;
	while(l < n){
		while(r < n&&time+arr[r]<=t){
			time+=arr[r];
			r++;
		}
		ans = max(ans,r-l);
		time-=arr[l];
		l++;
	}
	cout << ans << "\n";
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}