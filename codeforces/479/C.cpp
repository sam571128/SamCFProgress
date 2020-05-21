#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0,t1,t2;i < n;i++) cin>>t1>>t2,v.push_back(make_pair(t1,t2));
	sort(v.begin(),v.end());
	int day = -1;
	for(int i = 0;i < n;i++){
		if(day<=v[i].second){
			day = v[i].second;
		}else{
			day = v[i].first;
		}
	}
	cout << day << "\n";
}