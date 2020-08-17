#ifndef EPIDEMIC_HPP
#define EPIDEMIC_HPP

#include "seirstruct.hpp"
#include <cmath>
#include <vector>
#include <cassert>

template <class Virus> 
class Epidemic {
private:
  Seir sir_;
  double tau_; // tempo medio di malattia in giorni, ad esempio
  double P_;  //probabilità (costante per tutta l'epidemia) di essere infettato
  double t_; // periodo medio di incubazione
public:
  Epidemic(Virus const &sir, double tau, double P, double t)
      : sir_{sir}, tau_{tau}, P_{P}, t_{t} {}
  
   std::vector<Virus> createTable(int n) {

    constexpr double lambda = 50;   // numero di nascite costante
    constexpr double mi = 0.01; // tasso mortalità
    constexpr int ni = 5;     
// numero medio di persone incontrate al giorno da un infetto, supposto costante
    double beta = ni * P_;
    assert(beta > 0 && beta < 1);
    double gamma = 1 / tau_;
    assert(gamma > 0 && gamma < 1);
    double alfa = 1 / t_;

    std::vector<Seir> people{sir_};
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
      // poichè la probabilità di essere contagiati diventa zero

      people.push_back(p);
    }

    return people;
  }
};
#endif
