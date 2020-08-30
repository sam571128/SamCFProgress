#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=2e5+10;
int sum1[maxn];
int sum2[maxn];
int n;
int lowbit(int x){
    return x&-x;
}
void add(int *sum,int x,int v){
    while(x<=n){
        sum[x]+=v;
        x+=lowbit(x);
    }
}
int query(int *sum,int x){
    int res=0;
    while(x>0){
        res+=sum[x];
        x-=lowbit(x);
    }
    return res;
}
int pos[maxn];
signed main(){
    cin >> n;
    for(int i=1, tmp;i<=n;i++){
        cin >> tmp;
        pos[tmp]=i;
    }
    int ans1=0;
    for(int i=1;i<=n;i++){
        ans1+=i-1-query(sum1,pos[i]);
        add(sum1,pos[i],1);
        add(sum2,pos[i],pos[i]);
        int mid,l=1,r=n;
        while(l<=r){
            mid=(l+r)>>1;
            if(query(sum1,mid)*2<=i){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        int ans2=0;
        int cnt=query(sum1,mid),sum=query(sum2,mid);
        ans2+=mid*cnt-sum-cnt*(cnt-1)/2;
        cnt=i-cnt,sum=query(sum2,n)-sum;
        ans2+=sum-cnt*(mid+1)-cnt*(cnt-1)/2;
        cout << ans1 + ans2 << " ";
    }
    return 0;
}