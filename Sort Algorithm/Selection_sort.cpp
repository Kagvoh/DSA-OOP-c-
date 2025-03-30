#include <iostream>
#include <vector>
using namespace std;

void Selection_sort(vector<int> &v, int n){
  int min;
  for (int i = 0 ; i < n-1; i++){
    min = i;
    for (int j = i+1; j < n; j++){
        if (v[min] > v[j]){
          min = j;
        }
    }
    if (i != min){
      int temp = v[i];
      v[i] = v[min]; 
      v[min] = temp;
    }
  }
}

int main(){
  vector<int> v;
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++){
    cin >> x;
    v.push_back(x);
  }
  Selection_sort(v,n);
  for (int i : v){
    cout << i << " ";
  }
  return 0;
}