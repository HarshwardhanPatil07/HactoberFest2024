#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
const int MAX = 1000006;

/// all are 0-index based
/// find summation of all cnt[x]*cnt[x]*x, where x is any element in range l....r
int block, n, q, arr[MAX], cnt[MAX];
ll answer, ans[MAX];
vector < pair < pii , int > > query;
bool cmp(pair < pii , int > x, pair < pii , int > y){
    int a = x.first.first/block;
    int b = y.first.first/block;
    if(a == b) return x.first.second < y.first.second;
    else return a < b;
}
void add(int x){
    answer -= 1ll*cnt[x]*cnt[x]*x;
    cnt[x]++;
    answer += 1ll*cnt[x]*cnt[x]*x;
}
void remove(int x){
    answer -= 1ll*cnt[x]*cnt[x]*x;
    cnt[x]--;
    answer += 1ll*cnt[x]*cnt[x]*x;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r; l--, r--;
        query.pb(mp(mp(l,r),i));
    }
    block = sqrt(n);
    sort(all(query),cmp);
    int lft=0, rgt=-1;
    for(int i=0; i<q; i++){
        int l = query[i].first.first;
        int r = query[i].first.second;
        while(rgt < r){
            rgt++;
            add(arr[rgt]);
        }
        while(rgt > r){
            remove(arr[rgt]);
            rgt--;
        }
        while(lft < l){
            remove(arr[lft]);
            lft++;
        }
        while(lft > l){
            lft--;
            add(arr[lft]);
        }
        ans[query[i].second] = answer;
    }
    for(int i=0; i<q; i++) cout<<ans[i]<<endl;
	return 0;
}
