#include <iostream>
#include <vector>
using namespace std;

int Search(vector<int> v, int n, int k){
  for (int i = 0 ; i < n; i++){
    if (v[i] == k) return i;
  }
  return -1;
}

int main(){
  int n, k;
  cin >> n;
  vector<int> v;
  int x;
  for (int i = 0 ; i< n; i++){
    cin >> x;
    v.push_back(x);
  }
  cin >> k;
  cout << Search (v,n,k) << endl;
  swap(v[0] , v[1]);
  for ( int i : v){
    cout << i << " ";
  }
}
