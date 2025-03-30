#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(vector<int> &v, int n){
  for (int i = n - 1; i >= 1; i--){
    bool swapped = false;
    for (int j = 0; j < i; j++){
      if (v[j] > v[j+1]){
      swap(v[j],v[j+1]);
      swapped = true;
      for (int i:v){
        cout << i << " ";
      }
      cout << endl;
      }
    }
    if (!swapped) break;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> v;
  int x;
  for (int i = 0; i < n; i++){
    cin >> x;
    v.push_back(x);
  }
  BubbleSort(v,n);
  return 0;
}
