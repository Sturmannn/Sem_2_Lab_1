#include "MeleeWeapon.h"
#include <iostream>
#include <stdlib.h>

TMeleeWeapon::TMeleeWeapon() : TFirearms(rand() % 9, rand() % 3)
{
  barrelLength = 680;
  load = nullptr;
}

TMeleeWeapon::TMeleeWeapon(int _ammunition, double _barrelLength) : TMeleeWeapon()
{
  SetAmmunition(_ammunition);
  SetBarrelLength(_barrelLength);
}

TMeleeWeapon::TMeleeWeapon(const TMeleeWeapon& p) :TFirearms(p)
{
  barrelLength = p.barrelLength;
  load = p.load;
}

TMeleeWeapon::TMeleeWeapon(double _weight)
{
  this->weight = _weight;
}

TMeleeWeapon::TMeleeWeapon(TMeleeWeapon&& p)
{
  barrelLength = p.barrelLength;
  load = p.load;
  ammunition = p.ammunition;
  weight = p.weight;
  kitCount = p.kitCount;
  kits = p.kits;
  p.kitCount = 0;
  p.kits = 0;
}

TMeleeWeapon::~TMeleeWeapon()
{
  barrelLength = 0;
  /*if (load != nullptr)
  	delete[] load;*/
}

void TMeleeWeapon::SetBarrelLength(double _barrelLength)
{
  this->barrelLength = _barrelLength;
}

double TMeleeWeapon::GetBarrelLength()
{
  return barrelLength;
}

char* TMeleeWeapon::Load(int _ammunition)
{
  load = new char[15];

  if (_ammunition > 0)	return load = "is loaded";
  else	return load = "isn't loaded";
}

void TMeleeWeapon::Shoot()
{
  std::cout << "Misfire\n";
}

void TMeleeWeapon::Print()
{
  std::cout << "Weight = " << this->GetWeight() << " kg" << "\n" << "Ammunition = " << this->GetAmmunition()
  	<< " bullets " << this->Load(ammunition) << "\n" << "Barrel Length = " << this->GetBarrelLength() << " mm" << "\n"
  	<< "Number of Kits = " << this->GetKitCount() << "\n";
}
