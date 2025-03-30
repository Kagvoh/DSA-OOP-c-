#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int T, n;
  priority_queue<int, vector<int>, greater<int>> tmp; 
  cin >> T;
  while(T--){
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n; i++){
      cin >> v[i];
      tmp.push(v[i]);
    }
    for (int i = 0 ; i < n; i++){
      v[i] = tmp.top();
      tmp.pop();
    }
    if (n < 2) cout << "0" << "\n";
    else{
      if (n == 2) cout << v[1] - v[0] << "\n";
      else cout << v[n-1] - v[0] + v[n - 2] - v[1] << "\n"; 
    }
  }
  return 0;
}