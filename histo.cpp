#include <iostream>
#include <array>
#include <iomanip>


int main()

{

  std::array<int, 30> bar;

  int N = bar.size();
  int num;

  std::cout
      << "Inserire al massimo 30 numeri di cui si vuole mostrate l'andamento "
         "(ricorda di considerare solo una delle quattro colonne della tabella "
         "che hai prodotto e di arrotondare i numeri a interi!"
      << "\n\n";

  for (int i = 0; i < N; i++)

  {
    std::cout << i + 1 << " ";
    std::cin >> num;

    bar[i] = num;
  }

  std::cout << "\n";

  std::cout << "ISTOGRAMMA ORIZZONTALE"
            << "\n\n";

  for (int i = 0; i < N; i++)

  {

    std::cout << bar[i];

    for (int j = 0; j < bar[i]; j++)

      std::cout << '.';

    std::cout << "\n";
  }

  int max;
  max = bar[0];

  for (int i = 1; i < N; i++)

  {

    if (bar[i] > max)

      max = bar[i];
  }

  std::cout << "\n";
  std::cout << "Il valore massimo registrato è " << max << "\n\n";
}



	
	

