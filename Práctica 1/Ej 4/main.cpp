#include <visita.h>

int main(int argc, char const *argv[]) {
  using namespace std;
  Visitas = 0;
  while (*++argv) {
    visita(*argv);
    std::cout << "Visitas: " << Visitas << endl;
  }
}
