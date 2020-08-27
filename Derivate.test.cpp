#include "derivate.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("derivate test") {
Constants k;
CHECK(k.lam2==10);
CHECK(k.mi2==0.01);
CHECK(k.ni2==5);
CHECK(k.alfa2==0.25);
CHECK(k.gamma2==0.143);
//Controlla che le costanti siano tali

double S,E,I,R;
std::cout<<"Controllo della correttezza del coefficiente angolare/andamento delle quattro derivate. Scegli un punto a piacere"<<"\n";
std::cout<<"Inserire SUSCETTIBILI (di quel punto) : ";
std::cin>>S;
std::cout<<"Inserire ESPOSTI (di quel punto) : ";
std::cin>>E;
std::cout<<"Inserire INFETTI (di quel punto) : ";
std::cin>>I;
std::cout<<"Inserire GUARITI/MORTI (di quel punto) : ";
std::cin>>R;
std::cout<<"Di default, si sono considerati: dsdt<0 dedt>0 didt>0 drdt>0. Se si visualizzano messaggi di fallimento, sono da considerarsi i casi opposti"<<"\n";
CHECK(dsdt(S,I)<0);
CHECK(dedt(I,S,E)>0);
CHECK(didt(E,I)>0);
CHECK(drdt(I,R)>0);
}
