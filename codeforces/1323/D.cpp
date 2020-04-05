#include<bits/stdc++.h>
using namespace std;
int a[400500];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) {
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=27; i>=0; --i) {
		for(int j=1; j<=n; ++j) {
			a[j]&=(1<<i+1)-1;
		}
		sort(a+1,a+n+1);
		for(int j=1; j<=n; ++j) {
			if((upper_bound(a+1,a+j,(1<<i+1)-1-a[j])-lower_bound(a+1,a+j,(1<<i)-a[j]))&1)ans^=(1<<i);
			if((upper_bound(a+1,a+j,(1<<i+2)-2-a[j])-lower_bound(a+1,a+j,(1<<i+1)+(1<<i)-a[j]))&1)ans^=(1<<i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
