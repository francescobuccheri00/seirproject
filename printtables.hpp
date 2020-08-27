#ifndef PRINTTABLES_HPP
#define PRINTTABLES_HPP

void printTables(std::vector<Seir> const &numbers) {
  std::cout << "    (S)    "
            << "      (E)     "
            << "   (I)      "
            << "  (R)     "
            << "     R0"
            << "\n";
  for (auto const &n : numbers) {
    std::cout << std::to_string(n.s) << " | " << std::to_string(n.e) << " | "
              << std::to_string(n.i) << " | " << std::to_string(n.r) << " "
              << " | " << std::to_string(n.r0) << "\n"
              << "-------------------------------------------------------------"
                 "-------" << "\n";
  }
  std::cout << "\n";
  std::cout << "Reinserisci il totale di giorni che hai voluto controllare e "
               "visualizzerai il numero massimo di infetti : ";
  int nm;
  std::cin >> nm;
  auto const &i = numbers[nm];
  std::cout << "\n";
  std::cout << "Numero massimo di infetti : ";
  std::cout << i.max_i << "\n\n";
}
#endif




