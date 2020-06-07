#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct Tree
{
	int x,h;
};
Tree arr[100005];
int main(){
	fastio
	int n;
	cin >> n;
	
	for(int i = 1,x,y; i <= n;i++) cin >> x >> y, arr[i] = {x,y};
	arr[0].x = INT_MIN;
	arr[n+1].x = INT_MAX;
 	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(arr[i].x-arr[i].h>arr[i-1].x){
			ans++;
			continue;
		}
		if(arr[i].x+arr[i].h<arr[i+1].x){
			ans++;
			arr[i].x+=arr[i].h;
		}
	}
	cout << ans << "\n";
}