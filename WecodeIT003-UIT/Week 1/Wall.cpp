#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

bool Check(vector<int> &a,vector<int> &b,int maxheight){
  int j = 0;
  for (int i = 0; i < n; i++){
    if (a[i] >= maxheight) continue;
    while(j < m && a[i] + b[j] < maxheight) j++;
      if(j >= m) return false;
      j++;
  }
  return true;
}

int Search(vector<int> &a, vector<int> &b, int sum){
  int l = *min_element(a.begin(), a.end());
  int r = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
  int tmp = l;
  while (l <= r){
    int m = l + (r-l)/2;
    if(Check(a,b,m)){
        tmp = m;
        l = m + 1;
    }
    else r = m - 1;
  }
  return tmp;
}

int main(){
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  vector<int> b(m);
  int sum = 0;
  for (int i = 0; i < m; i++){
    cin >> b[i];
    sum+= b[i];
  }
  vector<pair<int,int>> result;
  int j = 0, x = Search(a,b,sum);
  for (int i = 0 ; i < n; i++){
    if (a[i] >= x) continue;
    while(j < m && a[i] + b[j] < x)
      j++;
     if (j < m){
        result.push_back({i,j});
        j++; 
     }
  }
  cout << x << " " << result.size() << "\n";
  for (auto &i : result){
    cout << i.first + 1 << " " << i.second + 1 << "\n";
  }
  return 0;
}