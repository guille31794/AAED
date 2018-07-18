#include <iostream>

using namespace std;

const char* SOS();

int main()
{
  cout << SOS() << endl;

  return 0;
}

const char* SOS() { return "...___..."; }
