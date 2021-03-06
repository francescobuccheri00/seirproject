#ifndef EPIDEMIC_HPP
#define EPIDEMIC_HPP

#include "seirstruct.hpp"
#include <cmath>
#include <vector>
#include <cassert>

template <class Virus> 
class Epidemic {
private:
  Seir seir_;
  double tau_; // tempo medio di malattia in giorni
  double P_;  //probabilità (costante per tutta l'epidemia) di essere infettato
  double t_; // periodo medio di incubazione
public:
  Epidemic(Virus const &seir, double tau, double P, double t)
      : seir_{seir}, tau_{tau}, P_{P}, t_{t} {}
  
   std::vector<Virus> createTable(int n) {

    constexpr double lambda = 10;   // numero di nascite gionaliere costante
     assert(lambda > 0); // controllo a compiletime
    constexpr double mi = 0.01; // tasso mortalità giornaliero costante
     assert(mi > 0);
    constexpr int ni = 5; // numero medio di persone incontrate al giorno da un soggetto
     assert(ni > 0); // le tre costanti devono ovviamente essere maggiori di zero
    double beta = ni * P_; // parametro che indica la probabilità di contagiarsi
     assert(beta > 0 && beta < 1); // condizioni d'utilizzo
    double gamma = 1 / tau_; // probbilità di guarire dopo la durata della malattia
     assert(gamma > 0 && gamma < 1);
    double alfa = 1 / t_;
     assert(alfa > 0);

    std::vector<Seir> people{seir_}; // vettore inizializzato coi parametri della struct
    for (int i = 1; i <= n; i++) {
      Virus p;
      Virus const &prev = people.back();
      p.s = prev.s + lambda - (mi * prev.s) - ((beta) * (prev.i) * (prev.s));
      p.e = prev.e + (beta * prev.s * prev.i) - ((alfa + mi) * prev.e);
      p.i = prev.i + (alfa * prev.e) - ((gamma + mi) * (prev.i));
      p.r = prev.r + ((gamma) * (prev.i)) - (mi * prev.r);
      p.r0 = prev.s * ((beta * alfa) / ((gamma + mi) * (alfa + mi)));
       if (prev.e<p.e){p.max_e=p.e;}
       if (prev.i<p.i){p.max_i=p.i;}
      
      if (p.r0 < 1) {
        p.s = prev.s;
        p.e = prev.e - (alfa * prev.e);
        p.i = prev.i + (alfa * prev.e) - ((gamma) * (prev.i));
        p.r = prev.r + ((gamma) * (prev.i));
         if (prev.e<p.e){p.max_e=p.e;}
         if (prev.i<p.i){p.max_i=p.i;}
      }
      // poichè la probabilità di essere contagiati diventa idealmente zero

      people.push_back(p); // aggiungiamo l'istanza p al vettore
    }

    return people;
  }
};
#endif
