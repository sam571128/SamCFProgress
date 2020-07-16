#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
multiset<int>s;
int a[100005];
int main(){
    int mi,ma,n,l,ans;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    mi=ma=a[1],s.insert(a[1]),l=1,ans=1;
    for(int i=2;i<=n;i++){
        mi=min(a[i],mi);
        ma=max(a[i],ma);
        if(ma-mi<=1){
            s.insert(a[i]);
            ans=max(ans,(int)s.size());
            continue;
        }
        s.insert(a[i]);
        while(s.size()>0&&ma-mi>1){
            auto it=s.find(a[l]);
            s.erase(it);
            l++;
            auto it1=s.begin();
            auto it2=s.end();
            it2--;
            mi=*it1;
            ma=*it2;
        }
        ans=max(ans,(int)s.size());
    }
    cout<<ans<<endl;
}