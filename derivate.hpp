#ifndef DERIVATE_HPP
#define DERIVATE_HPP

#include <cassert>
#include <iostream>
#include <math.h>
#include "structconstants.hpp"


inline double dsdt(double S, double I) {
  assert(S > 0 || I >= 0);
  Constants c;
  std::cout << "Immetti numero iniziale della popolazione nuovamente : ";
  double s;
  std::cin >> s;
  if (s < 0) {
    std::cout << "Simpatico! Hai inserito un numero sbagliato, riprovare"
              << "\n";
    return 0;
  }
  double beta = (c.ni2 * c.ni2) / (10 * s);
  return (c.lam2 - (c.mi2 * S) - (beta * I * S));
}

inline double dedt(double E, double S, double I) {
  assert(S > 0 || I >= 0 || E > 0);
  Constants c;
  std::cout << "Immetti numero iniziale della popolazione nuovamente : "
            << "\n";
  double s2;
  std::cin >> s2;
  if (s2 < 0) {
    std::cout << "Simpatico! Hai inserito un numero sbagliato, riprovare";
    return 0;
  }
  double beta = c.ni2 / (10 * s2);
  return (beta * I * S) - ((c.mi2 + c.alfa2) * E);
}

inline double didt(double I, double E) {
  assert(E > 0 || I >= 0);
  Constants c;
  return (c.alfa2 * E) - ((c.mi2 + c.gamma2) * I);
}

inline double drdt(double R, double I) {
  assert(R >= 0 || I > 0);
  Constants c;
  return (c.gamma2 * I) - (c.mi2 * R);
}
#endif
