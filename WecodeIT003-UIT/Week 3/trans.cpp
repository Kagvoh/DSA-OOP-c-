#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Chuyendoi(int x){
  stack<int> cd;
  while (x > 0){
    int a = x % 2;
    cd.push(a);
    x/=2;
  }
  while(!cd.empty()){
    cout << cd.top();
    cd.pop();
  }
}

int main(){
  int x;
  cin >> x;
  Chuyendoi(x);
  return 0;
}