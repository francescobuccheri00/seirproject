#include "derivate.hpp"
#include "development.hpp"
#include "epidemic.hpp"
#include "printtables.hpp"
#include <algorithm>

int main() {
  std::cout << "---------------------------------------------------------------"
               "----------------";
  std::cout
      << "Ciao! Ecco qua un piccolo programma che ti consente di analizzare "
         "lo sviluppo di un'ipotetica epidemia, su un numero di persone scelto "
         "da te, dati dei parametri costanti modificabili solo dal codice "
         "sorgente : numero di nascite giornaliere, tempo medio di "
         "incubazione, periodo medio dell'infezione per ciascuna persona e "
         "numero medio di individui incontrati da ciascun soggetto. Avvertenza "
         ": non inserire un valore iniziale della popolaione troppo basso "
         "poiché non sarebbe conforme con il numero di nascite (50) !"
      << "\n";
  std::cout << "---------------------------------------------------------------"
               "----------------"
            << "\n\n";
  
  Seir seir0{};
  std::cout << "Inserire numero di persone della popolazione del paese : ";
  std::cin >> seir0.s;
  if (seir0.s < 0) {
    std::cout << "Numero non valido, deve essere maggiore di zero!"
              << "\n";
    return 0;
  }

  std::cout << "Inserire quante persone hanno contratto il virus e sono in "
               "incubazione : ";

  std::cin >> seir0.e;
  if (seir0.e < 0) {
    std::cout << "Numero non valido, deve essere maggiore di zero!"
              << "\n";
    return 0;
  }
  seir0.i = 0;
  seir0.r = 0;
  double Pr = 5 / (10 * seir0.s); // per maggiori informazioni consultare Doctest.infomodel.cpp
  seir0.r0 = seir0.s * ((Pr * 5 * 0.25) / ((0.143 + 0.01) * (0.25 + 0.01)));

  Epidemic<Seir> vir{seir0, 7, Pr, 4}; // seir0,duarata medio della malattia per soggetto, probabilità di infettarsi e periodo medio di incubazione

  std::cout << "La probabilità iniziale di essere infetto è : " << Pr;
  int num;
  std::cout<< "\n\n"
      << "Quanti giorni vuoi visualizzare dello sviluppo dell'epidemia? : ";
  std::cin >> num;
  auto virus_seir = vir.createTable(num);
  printTables(virus_seir);

  std::cout
      << "Saresti interessato a visualizzare il coefficiente angolare delle "
         "rette tangenti alle curve per studiarne l'andamento? : S or N"
      << "\n";

  char ans;
  std::cin >> ans;
  assert(ans == 'S' || ans == 'N');

  if (ans == 'S') {
    std::cout
        << "Scegli una delle seguenti opzioni, la lettera si riferisce al "
           "parametro di cui vuoi calcolare la derivata in un punto : s e i r"
        << "\n";
    char der;

    std::cin >> der;
    switch (der) {
    case 's':
      double res;
      std::cout << "Hai scelto : SUSCETTIBILI. Immetti il numero di "
                   "suscettibili che vuoi controllare : ";
      double S;
      std::cin >> S;
      std::cout << "  Inserire il correspondente numero di INFETTI : ";
      double I;
      std::cin >> I;
      res = dsdt(S, I);
      std::cout << "Il coefficiente angolare è : " << res << "\n";
      if (res > 0) {
        std::cout << "La curva è crescente"
                  << "\n";
      } else {
        std::cout << "La curva è decrescente"
                  << "\n";
      }
      std::cout << "A presto!"
                << "\n";

      break;

    case 'e':
      double res2;
      std::cout << "Hai scelto : ESPOSTI. Immetti il numero di esposti che "
                   "vuoi controllare : ";
      double E;
      std::cin >> E;
      std::cout
          << "  Inserire adesso il correspondente numero di SUSCETTIBILI : ";
      std::cin >> S;
      std::cout << "  Inserire infine il correspondente numero di INFETTI : ";
      std::cin >> I;
      res2 = dedt(E, S, I);
      std::cout << "Il coefficiente angolare è : " << res2 << "\n";
      if (res2 > 0) {
        std::cout << "La curva è crescente"
                  << "\n";
      } else {
        std::cout << "La curva è decrescente"
                  << "\n";
      }
      std::cout << "A presto!"
                << "\n";
      break;

    case 'i':
      double res3;
      std::cout << "Hai scelto : INFETTI. Immetti il numero di infetti che "
                   "vuoi controllare : ";
      std::cin >> I;
      std::cout << "  Inserire il correspondente numero di ESPOSTI  : ";
      std::cin >> E;
      res3 = didt(I, E);
      std::cout << "Il coefficiente angolare è : " << res3 << "\n";
      if (res3 > 0) {
        std::cout << "La curva è crescente"
                  << "\n";
      } else {
        std::cout << "La curva è decrescente"
                  << "\n";
      }
      std::cout << "A presto!"
                << "\n";
      break;

    case 'r':
      double res4;
      std::cout << "Hai scelto : GUARITI/MORTI. Immetti il numero di "
                   "guariti/morti che vuoi controllare : ";
      double R;
      std::cin >> R;
      std::cout << "  Inserire il correspondente numero di INFETTI  : ";
      std::cin >> I;
      res4 = drdt(R, I);
      std::cout << "Il coefficiente angolare è : " << res4 << "\n";
      if (res4 > 0) {
        std::cout << "La curva è crescente"
                  << "\n";
      } else {
        std::cout << "La curva è decrescente"
                  << "\n";
      }
      std::cout << "A presto!"
                << "\n";
      break;
    }
  } else if (ans == 'N') {

    std::cout << "Saresti interessato allora a visualizzare una mappa "
                 "dell'evoluzione dell'epidemia per un campione ridotto ed "
                 "esemplificativo di persone? S or N"
              << "\n";

    char ans2;
    std::cin >> ans2;
    assert(ans2 == 'S' || ans2 == 'N');
    if (ans2 == 'S') {
      size_t nRows, nCols;

      std::cout << "Inserire numero di righe della mappa: ";
      std::cin >> nRows;
      std::cout << "Inserire numero di colonne della mappa: ";
      std::cin >> nCols;

      Table table(nRows + 2, nCols + 2);
      std::fill(table[0], table[nRows + 1], '.'); // filling della mappa
      std::cout << table << '\n';

      std::cout << "I pazienti 0 saranno contrassegnati dalle x\n";

      size_t i, j;
      std::cout << "Inseriamo ora le coordinate in cui si vogliono mostrare i "
                   "primi infetti (ricorda di immettere numeri validi affinché "
                   "i pazienti zero stiano nella mappa!)"
                << "\n";
      std::cout << "Quanti pazienti zero vuoi che appaiano? : ";
      int paz;
      std::cin >> paz;
      for (int k = 1; k <= paz; k++) {
        std::cout << "Paziente " << k << "\n";
        std::cout << "Riga : ";
        std::cin >> i;
        std::cout << "Colonna : ";
        std::cin >> j;
        table[i][j] = 'x';
      }

      for (int week = 1;;) {
        std::cout << "Settimana " << week << ":\n";
        std::cout << table << '\n';
        // simula settimana successiva
        ++week;

        Table table1(table);
        develop(table,table1);
        if (table == table1){
          std::cout << "L' epidemia si estingue alla settimana " << week
                    << ".\n";
          break;
        }
        swap(table, table1); // copia la nuova mappa sulla vecchia
      }
      std::cout << "La mappatura presentata semplifica il modello SEIR nel "
                   "modello SIR, per semplicità si sono considerati insieme "
                   "gli esposti e gli infetti. Ciascuna cella infetta contagia "
                   "le altre otto immediatamente adiacenti"
                << "\n"
                << ". = suscettibili | x = infetti | o = guariti/morti"
                << "\n"
                << "A presto!";
    } else if (ans2 == 'N') {
      std::cout
          << "\n"
          << "Arrivederci! Grazie di aver utilizzato il programma, ci dispiace "
             "che tu non abbia scelto nessuna delle espansioni precedenti. Se ti "
             "interessa, il file histo.cpp presenta la possibilità di creare "
             "istogrammi esemplificativi dell'andamento delle quattro "
             "variabili dell'epidemia. Ti basterà ricreare la tabella con un "
             "numero di suscettibili iniziali non troppo alto e   "
             "inserire i "
             "corrispondenti numeri nel programma"
             "A te la scelta, a presto! "
          << "\n";
      return 0;
    }
  }
}

