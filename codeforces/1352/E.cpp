#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n],cnt[n+1]={};
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = tmp;
			cnt[tmp]++;
		}
		int ans = 0;
		for(int l = 0;l < n;l++){
			int sum = a[l];
			for(int r = l+1;r < n;r++){
				sum+=a[r];
				if(sum<n+1){
					ans+=cnt[sum];
					cnt[sum] = 0;
				}
			}
		}
		cout << ans << "\n";
		
	} 
}
