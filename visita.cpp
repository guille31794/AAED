#include "visita.hpp"

void visita (const char* arg)
{
  using namespace std;
  cout << "Visita: " << arg << endl;
  ++Visitas;
}

int main(int argc, const char* argv[])
{
  using namespace std;
  Visitas = 0;
  while (*++argv)
  {
    visita(*argv);
  }
  cout << "Visitas: " << Visitas << endl;
  return 0;
}
