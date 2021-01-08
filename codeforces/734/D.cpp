#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a,b;
	cin >> a >> b;
	vector<pair<int,int>> lr, rl, ver, hor;
	lr.push_back({a,b});
	rl.push_back({a,b});
	ver.push_back({a,b});
	hor.push_back({a,b});
	map<pair<int,int>,char> m;
	for(int i = 0;i < n;i++){
		char c;
		int x,y;
		cin >> c >> x >> y;
		if(x-y==a-b) lr.push_back({x,y});
		if(x==a) hor.push_back({x,y});
		if(y==b) ver.push_back({x,y});
		if(x+y==a+b) rl.push_back({x,y});
		m[{x,y}] = c;
	}
	sort(lr.begin(),lr.end());
	sort(rl.begin(),rl.end());
	sort(ver.begin(),ver.end());
	sort(hor.begin(),hor.end());
	{	
		#define arr lr
		auto itr = lower_bound(arr.begin(),arr.end(),make_pair(a,b))-arr.begin();
		if(itr!=0){
			if(m[{arr[itr-1].first,arr[itr-1].second}]=='B'||m[{arr[itr-1].first,arr[itr-1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
		if(itr!=(int)arr.size()-1){
			if(m[{arr[itr+1].first,arr[itr+1].second}]=='B'||m[{arr[itr+1].first,arr[itr+1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
	}
	{	
		#define arr rl
		auto itr = lower_bound(arr.begin(),arr.end(),make_pair(a,b))-arr.begin();
		if(itr!=0){
			if(m[{arr[itr-1].first,arr[itr-1].second}]=='B'||m[{arr[itr-1].first,arr[itr-1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
		if(itr!=(int)arr.size()-1){
			if(m[{arr[itr+1].first,arr[itr+1].second}]=='B'||m[{arr[itr+1].first,arr[itr+1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
	}
	{	
		#define arr ver
		auto itr = lower_bound(arr.begin(),arr.end(),make_pair(a,b))-arr.begin();
		if(itr!=0){
			if(m[{arr[itr-1].first,arr[itr-1].second}]=='R'||m[{arr[itr-1].first,arr[itr-1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
		if(itr!=(int)arr.size()-1){
			if(m[{arr[itr+1].first,arr[itr+1].second}]=='R'||m[{arr[itr+1].first,arr[itr+1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
	}
	{	
		#define arr hor
		auto itr = lower_bound(arr.begin(),arr.end(),make_pair(a,b))-arr.begin();
		if(itr!=0){
			if(m[{arr[itr-1].first,arr[itr-1].second}]=='R'||m[{arr[itr-1].first,arr[itr-1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
		if(itr!=(int)arr.size()-1){
			if(m[{arr[itr+1].first,arr[itr+1].second}]=='R'||m[{arr[itr+1].first,arr[itr+1].second}]=='Q'){
				cout << "YES\n";
				return 0;
			}
		}
	}
	
	cout << "NO\n";
}