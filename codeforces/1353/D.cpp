#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


int idx = 1;
priority_queue< pair<int,int>, vector< pair<int,int> >, function<bool(pair<int,int>,pair<int,int>)> > q([](pair<int,int> a, pair<int,int> b) -> bool{
	return((a.second-a.first<b.second-b.first)||(a.first>b.first&&a.second-a.first==b.second-b.first));
});
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n]={};
		idx = 1;
		q.push(make_pair(0,n-1));
		while(!q.empty()){
			int l = q.top().first;
			int r = q.top().second;
			q.pop();
			if(l>r) continue;
			if(l==r){
				if(!arr[l]){
					arr[l] = idx;
					idx++;
				}
			}
			int mid = (l+r)/2;
			if(!arr[mid]){
				arr[mid] = idx;
				idx++;
			}
			q.push(make_pair(mid+1,r));
			q.push(make_pair(l,mid-1));
		}
		for(int x : arr){
			if(x) cout << x << " ";
			else {
				cout << idx << " ";
				idx++;
			}
		}
		cout << "\n";
	}
}