#ifndef SEIRSTRUCT_HPP
#define SEIRSTRUCT_HPP

// struttura dati che inglomba le quattro possibili condizioni di salute di un
// soggetto, il numero di riproduzione di base r0 e il 
//numero massimo di esposti e infetti toccato durante l'epidemia

struct Seir {
  double s;
  double e; // esposti modello seir
  double i;
  double r;
  double r0;
  double max_e;
  double max_i;
};
#endif
