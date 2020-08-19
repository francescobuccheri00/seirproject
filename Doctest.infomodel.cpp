#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>

TEST_CASE("Parameters test") {
  std::cout << "Nel presente codice verrano chiariti brevemente alcuni "
               "parametri utilizzati nella funzione main del file seir.cpp"
            << "\n";
  double Si = 5000;  // numero di persone suscettibili iniziale preso a scelta
  double Ei = 4;     // Numero di persone esposte iniziale preso a scelta
  double beta = 0.1; // probabilità di contagiarsi presa a scelta
  double ni = 6; // numero medio di persone incontrate nel corso di una giornata
  double k = 1.331468638;//ricavavto per via calcolistica
  double Pr = 6 / (10 * Si);//10 dipende dal beta scelto
  double Pr2 = (beta * ((2 * Si * Ei) / ((Si + Ei) * (Si + Ei - 1))) * (1 / k));
  CHECK(Pr <= Pr2); // <= per approssimazione
  std::cout << "Pr : " << Pr << " | Pr2 :" << Pr2 << "\n";

  double tau = 10; // periodo medio della malattia preso a scelta
  double gamma = 1 / tau;
  double res = 0;
  for (int i = 0; i <= 500000; i++) {
    res += i * pow(1 - gamma, i - 1) * gamma;
  }
  CHECK(tau >= res); // >= per approssimazione
  std::cout << "tau : " << tau << " | tau ricavato come sommatoria : " << res
            << "\n\n";
  std::cout << "Formule probabilità : Pr=ni*beta/Si "
               "Pr2=beta*2*Si*Ei/((Si+Ei)*(Si+Ei-1))*k"
            << "\n";
  std::cout << "Formule periodo medio della malattia per soggetto : "
               "tau=costante tau2=sommatoria per k che va da 0 a un N molto "
               "grande di k*(1-1/tau)^(k-1) * (1/tau)"
            << "\n";
}

