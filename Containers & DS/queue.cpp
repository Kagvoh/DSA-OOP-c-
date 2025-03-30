#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
  int n,k;
  cin >> n;
  int a[n];
  int c[1001];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> k;
  queue<int> b;
  for (int  i = 0; i < 1001; i++){
		c[i] = false;
	}
  for (int i = 0; i < n; i++){
    if (!c[a[i]]){
      if (b.size() < k){
        c[a[i]] = true;
        b.push(a[i]);
      }
      else{
        c[b.front()] = false;
        c[a[i]] = true;
        b.push(a[i]);
        b.pop();
      }
    }
  }
  while (!b.empty()){
    cout << b.front() << " ";
    b.pop();
  }

  return 0;
}