#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a[105][105];

int main(){
	fastio
	int n, ans = 0;
	cin >> n;
	while(n){
		for(int i = 100;i > 0;i--){
			if(i*(i-1)*(i-2)/6<=n){
				ans += i;
				for(int u = ans-i;u < ans;u++)
					for(int v = ans-i;v < ans;v++)
						a[u][v] = (u!=v);
				n-=i*(i-1)*(i-2)/6;
				for(int j = i;j >= 2;j--){
					if(j*(j-1)/2<=n){
						ans++;
						for(int k = ans-j-1;k < ans-1;k++) a[k][ans-1] = a[ans-1][k] = 1;
						n -= j*(j-1)/2;
						for(int k = j+1;k >= 2;k--){
							if(k*(k-1)/2<=n){
								ans++;
								for(int b = ans-k-1;b < ans-1;b++) a[b][ans-1] = a[ans-1][b] = 1;
								n -= k*(k-1)/2;
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
	cout << ans << "\n";
	for(int i = 0;i < ans;i++){
		for(int j = 0;j < ans;j++) cout << a[i][j];
		cout << "\n";
	}
}