#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long timcap(vector<int> &h, int n){
  long long kq = 0;
  stack<int> height;
  stack<int> dem;
  for (int i = 0; i < n; i++){
    int count = 1;
    while (!height.empty() && height.top() <= h[i]){
      kq += dem.top();
      if (height.top() == h[i]){
         count += dem.top();
      }
      height.pop();
      dem.pop();
    }
    if (!height.empty()){
      kq++;
    }
    height.push(h[i]);
    dem.push(count);
  }
  return kq;
}

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  cout << timcap(h,n);
}