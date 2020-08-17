#ifndef MAP_HPP
#define MAP_HPP

#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>

template <class MAP>
class Matrix; // forward declaration

template <class MAP>
void swap(Matrix<MAP>&, Matrix<MAP>&); 

template <class MAP>
class Matrix {
  friend void swap<MAP>(Matrix<MAP>&, Matrix<MAP>&);//friend serve a far accedere ai membri privati e protetti della classe corrispondente
    
  private:
    size_t nRighe_ , nColonne_;
    std::vector<MAP> mappa_;

  public:

    using Map = MAP;
    Matrix(size_t nRighe, size_t nColonne, Map mappa = 0):
      nRighe_{nRighe}, nColonne_{nColonne}, mappa_(nRighe_ * nColonne_, mappa) {}
    
    ~Matrix() = default; // distruttore in default
     Matrix( Matrix const& ) = default; // costruttore di copia
     Matrix& operator=( Matrix const& ) = default; // operatore di assegnamento
    
    size_t getNumCols() const { return nColonne_; }//tipo size_t
    size_t getNumRows() const { return nRighe_; }
    std::vector<Map> get() const { return mappa_; }

    Map* operator[](size_t i) { return &mappa_[0] + i * nColonne_; }
    const Map* operator[](size_t i) const { return &mappa_[0] + i * nColonne_; }
};//costruiamo la matrice
#endif
