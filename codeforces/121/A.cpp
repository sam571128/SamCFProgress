#include <bits/stdc++.h>
 
#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
 
/********SAM571128's SOLUTION**********/
ll nums[1024];
ll f(int n)
{
	if(n==0)
		return 0;
	int i;
	ll ans=0;
	for(int i=1;i<=1024;i++)
	{
		if(nums[i]<n)
		{
			ans+=nums[i]*(nums[i]-nums[i-1]);
		}
		else
		{
			ans+=nums[i]*(n-nums[i-1]);
			break; 
		}
	}
	return ans;
}
 
int main(){
	fastio;
	nums[1] = 4;
	nums[2] = 7;
	int t = 3;
	for(int i = 1;i < 512;i++){
		nums[t++] = nums[i]*10+4;
		nums[t++] = nums[i]*10+7;
	}
	ll int a,b;
	cin >> a >> b;
	cout << f(b)-f(a-1);
	
}