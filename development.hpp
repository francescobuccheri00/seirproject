#ifndef DEVELOPMENT_HPP
#define DEVELOPMENT_HPP

#include "map.hpp"


template <typename MAP>

inline void swap(Matrix<MAP> &map1, Matrix<MAP> &map2)//serve a "incollare" il nuovo stato della matrice in quello vecchio e consentire la progressione
{
  std::swap(map1.nRighe_, map2.nRighe_); //algoritmo std::swap che scambia i valori/simboli di mappa 1, originale, coi valori/simboli di mappa 2 nuova
  std::swap(map1.nColonne_, map2.nColonne_);
  std::swap(map1.mappa_, map2.mappa_);
}

typedef Matrix<char> Table;

inline bool operator==(Table const& table1, Table const& table2)
{
  return table1.getNumRows() == table2.getNumRows()
    && table1.getNumCols() == table2.getNumCols()
    && table1.get() == table2.get();
}

inline std::ostream& operator<<(std::ostream &image, Table const& tab)
{
  for (size_t i = 1, nRighe = tab.getNumRows() - 1; i < nRighe; ++i) {
    for (size_t j = 1, nColonne = tab.getNumCols() - 1; j < nColonne; ++j) {
      image << ' ' << tab[i][j];
    }
    image << '\n';
  }
  return image;
}//visualizza la mappa, restituisce in output la struttura tabellare creata


inline void develop(Table const& table, Table & table1)
{
  assert(table.getNumRows() == table1.getNumRows());
  assert(table.getNumCols() == table1.getNumCols());
 
  for (size_t i = 1, nRows = table.getNumRows() - 1; i < nRows; ++i) {
    for (size_t j = 1, nCols = table.getNumCols() - 1; j < nCols; ++j) {
      const char person = table[i][j];//punto nella matrice
      char person1 = person;
      switch (person) {
        case '.': { //cerca vicini esposti/infetti
          bool infect = false;
          for (int i2 = -1; !infect && i2 <= 1; ++i2) {
            for (int j2 = -1; !infect && j2 <= 1; ++j2) {
              infect = table[i + i2][j + j2] == 'x';
            }
          }
          person1 = infect ? 'x' : '.';
        } break;
        case 'x':

        case 'o':
          person1 = 'o';
          break;
      }
      table1[i][j] = person1;
    }
  }
}
#endif
