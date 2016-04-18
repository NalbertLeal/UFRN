#include <iostream>
#include <string>

// #include "dal.h"
#include "dal.h"
#include "dsal.h"

class MyKeyComparator {
  public:
    int operator()(int lhs, int rhs) {
      if(lhs < rhs) return -1;
      else if(lhs == rhs) return 0;
      else return 1; //lhs > rhs
    }
};

main() {

  bool a, b, c, d, e, f, g, h, i;
  string v, k, m, l;

  DSAL<int, string, MyKeyComparator> objeto(100);

  a = objeto.insert(0, "Nalbert");
  b = objeto.search(0, v);
  c = objeto.remove(0, k);
  d = objeto.insert(20150304, "Gabriel");
  g = objeto.search(20150304, l);
  e = objeto.insert(4, "Nalbert");
  f = objeto.search(4, m);
  h = objeto.insert(5, "Nalbert");
  i = objeto.search(5, m);
  // cout << objeto.min(); << endl << endl;

  cout << objeto << endl << endl;

  cout << a << "  " << b << " remove  "<< c  << "  " << d << " " << e << "  " << f << " " << g << " " << i << " teste1 " << v << " teste2 " << k << " teste3 " << m  << " teste4 " << l << endl;
  return EXIT_SUCCESS;

  // bool a, b, c, d, e, f;
  // string v, k, m;
  //
  // DAL<std::string> objeto(100);
  //
  // a = objeto.insert(0, "Nalbert");
  // b = objeto.search(0, v);
  // c = objeto.insert(3, "jojo");
  // d = objeto.search(3, k);
  // e = objeto.insert(4, "Nalbert");
  // f = objeto.search(4, m);
  //
  // cout << a << "  " << b << "  "<< c  << "  " << d << "  " << e << "  " << f << " teste1 " << v << " teste2 " << k << " teste3 " << m << endl;
  // return EXIT_SUCCESS;
}
