#include <iostream>

int main(int argc, char const *argv[]) {
  using namespace std;

  int v[10] = { 1, 2, 3, };
  for (size_t i = 0; i < 10; ++i)
    cout << v[i] << ' ';
  cout << endl;
  return 0;
}
