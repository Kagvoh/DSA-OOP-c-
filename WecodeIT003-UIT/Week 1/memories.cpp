#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

bool Checkpage(vector<ll> &pages, int n, int k, ll maxpages){
  int dem = 1;
  ll tap = 0;
  for (int i = 0 ; i < n; i++){
    if(tap + pages[i] > maxpages){
      dem++;
      tap = pages[i];
      if (dem > k) return 0; 
    }
    else{
      tap += pages[i];
    }
  }
  return 1;
}

ll FindtheMinpage(vector<ll> &pages, int n, int k, ll sum){
  ll min = *max_element(pages.begin(),pages.end());
  ll max = sum;
  ll tmp = max;
  while (min <= max){
    ll mid = min + (max - min)/2;
    if (Checkpage(pages,n,k,mid)){
      tmp = mid;
      max = mid - 1;
    }
    else{
      min = mid + 1;
    }
  }
  return tmp;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> pages(n);
  ll sum = 0;
  for (int i = 0 ; i < n; i++){
    cin >> pages[i];
    sum += pages[i];
  }
  cout << FindtheMinpage(pages,n,k,sum);
  return 0;
}