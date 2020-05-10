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
	int n,t;
	cin >> n >> t;
	int pref[n];
	cin >> pref[0];
	for(int i = 1;i < n;i++){
		cin >> pref[i];
		pref[i] += pref[i-1];
	}
	int ans = 0;
	for(int l = 0;l < n;l++){
		int low = l;
		int high = n-1;
		int mid = (low+high)/2;
		while(low<=high){
			mid = (low+high)/2;
			if(pref[mid]-(l==0 ? 0 : pref[l-1])==t){
				ans = max(ans,mid-l+1);
				break;
			}else if(pref[mid]-(l==0 ? 0 : pref[l-1])<t){
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		ans = max(ans,min(low,high)-l+1);
	}
	cout << ans;
}
