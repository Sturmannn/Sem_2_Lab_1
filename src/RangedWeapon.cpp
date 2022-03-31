#include "RangedWeapon.h"
#include <iostream>
#include <stdlib.h>


TRangedWeapon::TRangedWeapon() : TFirearms(rand() % 31, rand() % 5)
{
  range = 1000;
  load = 0;
}

TRangedWeapon::TRangedWeapon(int _ammunition, int _kitCount, double _range) : TRangedWeapon()
{
  SetRange(_range);
  SetAmmunition(_ammunition);
  SetKitCount(_kitCount);
}

TRangedWeapon::TRangedWeapon(const TRangedWeapon& p) : TFirearms(p)
{
  range = p.range;
  load = p.load;
}

TRangedWeapon::TRangedWeapon(double _weight) : TRangedWeapon()
{
  SetWeight(_weight);
}

TRangedWeapon::TRangedWeapon(TRangedWeapon&& p) 
{
  range = p.range;
  load = p.load;
  ammunition = p.ammunition;
  weight = p.weight;
  kitCount = p.kitCount;
  kits = p.kits;
  p.kitCount = 0;
  p.kits = 0;
}

TRangedWeapon::~TRangedWeapon()
{
  range = 0;
  if (load != 0)  delete[] load;
}

void TRangedWeapon::SetRange(double _range)
{
  if (_range > 0 && _range < 1250)  this->range = _range;
}

double TRangedWeapon::GetRange()
{
  return range;
}

char* TRangedWeapon::Load(int _ammunition)
{
  load = new char[15];
  
  if (_ammunition > 0)  return "is loaded";
  else  return "isn't loaded";
}

void TRangedWeapon::Shoot()
{
  std::cout << "Misfire\n";
}


void TRangedWeapon::Print()
{
  std::cout << "Weight = " << this->GetWeight() << " kg" << "\n" << "Ammunition = " << this->GetAmmunition()
  	<< " bullets " << this->Load(ammunition) << "\n" << "Range = " << this->GetRange() << " meters" << "\n"
  	<< "Number of Kits = " << this->GetKitCount() << "\n";
}
