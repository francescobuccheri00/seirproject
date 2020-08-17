#ifndef DEVELOPMENT_HPP
#define DEVELOPMENT_HPP

#include "map.hpp"


template <typename MAP>

inline void swap(Matrix<MAP> &map1, Matrix<MAP> &map2)//serve a "incollare" il nuovo stato della matrice in quello vecchio e consentire la progressione
{
  std::swap(map1.nRighe_, map2.nRighe_);
  std::swap(map1.nColonne_, map2.nColonne_);
  swap(map1.mappa_, map2.mappa_);
}

typedef Matrix<char> Board;

bool operator==(Board const& board1, Board const& board2)
{
  return board1.getNumRows() == board2.getNumRows()
    && board1.getNumCols() == board2.getNumCols()
    && board1.get() == board2.get();
}

std::ostream& operator<<(std::ostream &image, Board const& board)
{
  for (size_t i = 1, nRighe = board.getNumRows() - 1; i < nRighe; ++i) {
    for (size_t j = 1, nColonne = board.getNumCols() - 1; j < nColonne; ++j) {
      image << ' ' << board[i][j];
    }
    image << '\n';
  }
  return image;
}//visualizza la board matrice con algortitmo


inline void develop(Board const& board, Board & board1)
{
  assert(board.getNumRows() == board1.getNumRows());
  assert(board.getNumCols() == board1.getNumCols());
  
  for (size_t i = 1, nRows = board.getNumRows() - 1; i < nRows; ++i) {
    for (size_t j = 1, nCols = board.getNumCols() - 1; j < nCols; ++j) {
      const char person = board[i][j];//punto nella matrice
      char person1 = person;
      switch (person) {
        case '.': { //cerca vicini esposti/infetti
          bool infect = false;
          for (int iP = -1; !infect && iP <= 1; ++iP) {
            for (int jP = -1; !infect && jP <= 1; ++jP) {
              infect = board[i + iP][j + jP] == 'x';
            }
          }
          person1 = infect ? 'x' : '.';
        } break;
        case 'x': 

        case 'o': 
          person1 = 'o';
          break;
        //default: assert(false);
      }
      board1[i][j] = person1;
    }
  }
}
#endif
