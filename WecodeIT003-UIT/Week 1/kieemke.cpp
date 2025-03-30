#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Merge(vector<string> &mahang, int l, int m, int r){
  int x = m - l + 1;
  int y = r - m;
  vector<string> L(x) , R (y);
  for (int i = 0; i < x; i++) {
      L[i] = mahang[l + i];  
  }
  for (int j = 0; j < y; j++){
      R[j] = mahang[m + j + 1];
  }
  int i = 0, j = 0, k = l;
  while (i < x && j < y){
    if (L[i] <= R[j]){
      mahang[k++] = L[i++];
    }
    else{
      mahang[k++] = R[j++];
    }
  }
  while (i < x){
    mahang[k++] = L[i++];
  }
  while (j < y){
    mahang[k++] = R[j++];
  }
}
void MergeSort(vector<string> &mahang, int l, int r){
  if (l < r){
    int m = (r+l)/2;
    MergeSort(mahang, l, m);
    MergeSort(mahang, m+1, r);
    Merge(mahang, l, m, r);
}
}

int main(){
  int n; cin >> n;
  vector<string> mahang(n);
  for (int i = 0; i < n; i++) {
      cin >> mahang[i];
  }
  MergeSort(mahang,0,n-1);
  int dem = 1;
  for (int i = 1; i < n; i++){
    if (mahang[i] != mahang[i-1]){
      dem++;
    }
  }
  cout << dem;
  return 0;
}