#include <iostream>
using namespace std;

int main() {
  int N;
  int row = 1;
  int col;
  cout << "Input no. of rows : ";
  cin >> N;

  // cout << row;
  while (row <= N) {

    col = 1;
    while (col <= N) {

      cout << col << " ";
      col = col + 1;
    }
    cout << "\n";
    row = row + 1;
  }

  return 0;
}