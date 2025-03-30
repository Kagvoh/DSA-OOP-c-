#include <iostream>
#include <vector>

using namespace std;

void CheckSub(vector<int> &v, int n, int k, vector<string> &results){
  vector<int> count(n + 1, 0);
  int dem1 = 0, dem2 = 0;
  for (int i = 0; i < n; i++){
    if (count[v[i]] == 0) dem1++;
    count[v[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (count[i] > 1) dem2++;
  }

  if (dem1 > 2 * k || dem1 < k) {
    results.push_back("NO");
  } else {
    if (2 * k - dem1 <= dem2) results.push_back("YES");
    else results.push_back("NO");
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, k;
  cin >> t;
  vector<string> results;
  while(t--){
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
      cin >> v[i];
    }
    if (n >= 2 && k <= n && k >= 1) {
      CheckSub(v, n, k, results);
    } 
    else {
      results.push_back("NO"); 
    }
  } 
  for (int i = 0; i < results.size(); i++){
    cout << results[i] << "\n";
  }
  return 0;
}