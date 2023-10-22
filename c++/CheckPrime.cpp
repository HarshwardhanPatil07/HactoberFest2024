#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;

u64 modPow(u64 a, u64 b, u64 p){
   u64 ans = 1;
   while(b != 0){
      if((b&1)){
            ans =  (u128)a * ans %p;
      }
      a = (u128)a * a %p;
      b >>= 1;
   }
   return ans%p;
}
bool checkcomposite(u64 a, u64 d, u64 s, u64 p){
    u64 x = modPow(a, d, p);
    if(x == p-1 || x == 1){
        return false;
    }
    for(int i = 1; i < s; i++){
        x = (u128)x *x % p;
        if(x == p-1){
            return false;
        }
    }
    return true;
}
bool MillerRabinNonDeterministic(u64 p, int iter = 5){
    if(p <= 4){
        return p == 2 || p == 3;
    }
    u64 d = p-1;
    u64 s = 0;
    while((d&1) == 0){
        d>>=1; s++;
    }
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (p-3);
        if(checkcomposite(a, d, s, p)){
            return false;
        }
    }
    return true;
}

int main(){

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

int tt; cin>>tt;
while(tt--){
  u64 n;
  cin>>n;
  if(MillerRabinNonDeterministic(n)){
    cout<<"YES"<<endl;
  }else
    cout<<"NO"<<endl;
}

return 0;
}
