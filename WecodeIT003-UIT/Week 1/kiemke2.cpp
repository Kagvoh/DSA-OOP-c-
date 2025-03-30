#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Hang{
  string mahang;
  int soluong;
};

bool compareMahang(const string &a, const string &b) {
  if (a.size() != b.size()) return a.size() < b.size();  
  return a < b; 
}

void Merge(vector<Hang> &hanghoa, int l, int m, int r){
  int x = m - l + 1;
  int y = r - m;
  vector<Hang> L(x) , R (y);
  for (int i = 0; i < x; i++) {
      L[i] = hanghoa[l + i];  
  }
  for (int j = 0; j < y; j++){
      R[j] = hanghoa[m + j + 1];
  }
  int i = 0, j = 0, k = l;
  while (i < x && j < y){
    if (L[i].soluong > R[j].soluong || L[i].soluong == R[j].soluong && compareMahang(L[i].mahang, R[j].mahang)){
      hanghoa[k++] = L[i++];
    }
    else{
      hanghoa[k++] = R[j++];
    }
  }
  while (i < x){
    hanghoa[k++] = L[i++];
  }
  while (j < y){
    hanghoa[k++] = R[j++];
  }
}

void MergeSort(vector<Hang> &hanghoa, int l, int r){
  if (l < r){
    int m = l + (r-l)/2;
    MergeSort(hanghoa, l, m);
    MergeSort(hanghoa, m+1, r);
    Merge(hanghoa, l, m, r);
  }
}

int main(){
  int n; cin >> n;
  vector<string> ma(n);
  vector<Hang> hanghoa;
  for (int i = 0; i < n; i++) {
      cin >> ma[i];
  }
  for (int i = 0; i < n; i++) {
    bool found = false;
    for (int j = 0; j < hanghoa.size(); j++) {
        if (hanghoa[j].mahang == ma[i]) {
            hanghoa[j].soluong++;
            found = true;
            break;
        }
    }
    if (!found) {
        hanghoa.push_back({ma[i], 1});
    }
  }
  if (!hanghoa.empty()) {
      MergeSort(hanghoa, 0, hanghoa.size() - 1);
  }

  for (auto &i : hanghoa){
    cout << i.mahang << " " << i.soluong << "\n"; 
  }
  
  return 0;
}
