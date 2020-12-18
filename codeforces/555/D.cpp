#include <bits/stdc++.h>
#include <bits/extc++.h>

//#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

signed main(){	
	fastio
	int n,m;
	cin >> n >> m;
	int arr[n+1];
	vector<pair<int,int>> v;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		v.push_back({arr[i],i});
	}
	sort(v.begin(),v.end());
	int cnt = 1;
	gp_hash_table<int,int> id, idx;
	for(auto x : v){
		id[x.first] = x.second;
		idx[x.second] = cnt++;
	}
	sort(arr+1,arr+n+1);
	while(m--){
		int now, L;
		cin >> now >> L;
		now = idx[now];
		bool stop = false;
		for(int i = 0;i < 2;i++){
			int pos = (L < 0 ? lower_bound(arr+1,arr+n+1,arr[now]+L)-arr : upper_bound(arr+1,arr+n+1,arr[now]+L)-arr-1);
			//cout << arr[now] << " " << L << "\n";
			if(pos==now){
				if(stop){
					cout << id[arr[now]] << "\n";
					goto next;
				}else{
					int sign = L/abs(L);
					L = abs(arr[pos]-(arr[now]+L));
					L *= sign*-1;
					now = pos;
					stop = true;
				}
			}else{
				int sign = L/abs(L);
				L = abs(arr[pos]-(arr[now]+L));
				L *= sign*-1;
				now = pos;
				stop = false;
			}
			if(L==0){
				cout << id[arr[now]] << "\n";
				goto next;
			}
		}
		while(true){

			int pos = (L < 0 ? lower_bound(arr+1,arr+n+1,arr[now]+L)-arr : upper_bound(arr+1,arr+n+1,arr[now]+L)-arr-1);
			//cout << arr[now] << " " << L << "\n";
			if(pos==now){
				cout << id[arr[now]] << "\n";
				goto next;
			}else{
				int sign = L/abs(L);
				L = abs(L);
				int tmp = abs(arr[pos]-arr[now]);
				if(2*tmp >= L){
					L -= tmp;
					now = pos;
					L *= sign*-1;
				}else{
					if(L/tmp%2){
						L%=tmp;
						now = pos;
						L *= sign*-1;
					}else{
						L%=tmp;
						L *= sign;
					}
				}
			}
			if(L==0){
				cout << id[arr[now]] << "\n";
				goto next;
			}
		}
		next:;
	}
}