#include <iostream>
#include "Firearms.h"
#include "RangedWeapon.h"
#include "MeleeWeapon.h"
#include "SniperRifle.h"
#include "Carbine.h"
#include "Shotgun.h"
#include "Pistol.h"

inline void line()
{
  std::cout << std::endl;
}

int main() {

  TFirearms* SVD = new TSniperRifle();
  SVD->Print();
  SVD->Shoot();
  line();
  
  TFirearms* CKC = new TCarbine();
  CKC->Print();
  CKC->Shoot();
  line();
  
  TShotgun Saiga12(58, 20);
  Saiga12.Print();
  Saiga12.Shoot();
  line();
  
  TPistol PM(12);
  PM.Print();
  PM.Shoot();
  line();
  
  line();
  return 0;
}
