#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Max 1000000

void Counting_sort(vector<int> &v, int n, int exp){
  vector<int> tmp(n);
  int count[10] = {0};
  
  for (int i = 0; i < n; i++){
    int index = (v[i]/exp) % 10;
    count[index]++;
  }

  for(int i = 1; i < 10; i++){
    count[i] += count[i - 1]; 
  }
  for (int i = n - 1; i >= 0; i--){
    int digit = (v[i]/exp) % 10;
    tmp[count[digit] - 1] = v[i];
    count[digit]--;
  }
  for (int i = 0; i < n; i++){
    v[i] = tmp[i];
  }
}

void Radix_sort(vector<int> &v, int n){
  int maxVal = *max_element(v.begin(), v.end());
  for (int exp = 1; maxVal/exp > 0; exp *= 10){
    Counting_sort(v,n,exp);
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
  Radix_sort(v,n);
  for (auto i : v){
    cout << i << " ";
  }
}