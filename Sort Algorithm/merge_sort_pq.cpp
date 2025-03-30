#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void merge_sort(vector<int> &a, int l, int r){
  if (l < r){
  int m = l + (r-l)/2;
  merge_sort(a, l, m);
  merge_sort(a, m+1, r);
  priority_queue<int> pp;
  for (int i = l; i <= r; i++) pp.push(a[i]);
  for (int i = l; i <= r; i++){
    a[i] = pp.top();
    pp.pop();
  }
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    a.push_back(x);
  }
  merge_sort(a, 0, n-1);
  for (int i : a){
    cout << i << " ";
  }
  cout << endl;
  cout << a[1]; 
  return 0;
}