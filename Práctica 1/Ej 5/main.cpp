#include <iostream>

int main(int argc, char const *argv[]) {
  using namespace std;
  int v[10] = {1, 2, 3, };
  for (int i = 0; i < 10 ; ++i)
    std::cout << v[i] << ' ';
  cout << endl;
}
