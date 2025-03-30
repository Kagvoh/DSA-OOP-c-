#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll Check(ll day , ll a, ll k, ll b, ll m){
  ll day1 = day - day/k;
  ll day2 = day - day/m;
  return day1*a + day2*b;
}

void Finddays(ll a, ll k, ll b, ll m, ll n){
  ll l = 1;
  ll r = n/min(a,b) + 1;
  ll tmp = r;
  while ( l <= r){
    ll day = (r+l)/2;
    if (Check(day,a,k,b,m) >= n){
      tmp = day;
      r = day - 1;
    }
    else{
      l = day + 1;
    }
  }
  cout << tmp;
}

int main(){
  ll a, k, b, m, n;
  cin >> a >> k >> b >> m >> n;
  Finddays(a,k,b,m,n);
  return 0;
}


