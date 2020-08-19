#ifndef PRINTTABLES_HPP
#define PRINTTABLES_HPP

inline void printTables(std::vector<Seir> const &numbers) {
  std::cout << "    (S)    "
            << "      (E)     "
            << "   (I)      "
            << "  (R)     "
            << "     R0"
            << "\n";
  for (auto const &num : numbers) {
    std::cout << std::to_string(num.s) << " | " << std::to_string(num.e) << " | "
              << std::to_string(num.i) << " | " << std::to_string(num.r) << " "
              << " | " << std::to_string(num.r0) << "\n"
              << "-------------------------------------------------------------"
                 "------------------";
  }
  std::cout << "\n";
  std::cout << "Reinserisci il totale di giorni che hai voluto controllare e "
               "visualizzerai il numero massimo di esposti e infetti : ";
  int nm;
  std::cin >> nm;
  auto const &i = numbers[nm];
  std::cout << "\n";
  std::cout << "Numero massimo di esposti : ";
  std::cout << i.max_e << "\n";
  std::cout << "Numero massimo di infetti : ";
  std::cout << i.max_i << "\n\n";
}
#endif


