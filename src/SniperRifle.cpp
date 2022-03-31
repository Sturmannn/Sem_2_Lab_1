#include "SniperRifle.h"
#include <iostream>

TSniperRifle::TSniperRifle() :TRangedWeapon()
{
  weight = 4.52;
  length = 1220;
  caliber = 7.62;
}

TSniperRifle::TSniperRifle(int _length, int _caliber, double _range) : TRangedWeapon()
{
  SetLength(_length);
  SetCaliber(_caliber);
  SetRange(_range);
}

TSniperRifle::TSniperRifle(const TSniperRifle& p) : TRangedWeapon(p)
{
  length = p.length;
  caliber = p.caliber;
}

TSniperRifle::TSniperRifle(double _ammunition)
{
  this->ammunition = _ammunition;
}

TSniperRifle::TSniperRifle(TSniperRifle&& p)
{
  length = p.length;
  caliber = p.caliber;
  range = p.range;
  load = p.load;
  ammunition = p.ammunition;
  weight = p.weight;
  kitCount = p.kitCount;
  kits = p.kits;
  p.kitCount = 0;
  p.kits = 0;
}

TSniperRifle::~TSniperRifle()
{
  length = 0;
  caliber = 0;
}

void TSniperRifle::SetCaliber(double _caliber)
{
  this->caliber = _caliber;
}

double TSniperRifle::GetCaliber()
{
  return caliber;
}

void TSniperRifle::SetLength(double _length)
{
  this->length = _length;
}

double TSniperRifle::GetLength()
{
  return length;
}

void TSniperRifle::Shoot()
{
  if (ammunition > 0) 
  {
  	std::cout << "BANG" << std::endl;
  	ammunition -= 1;
  }
  else  std::cout << "Misfire\n";
}

void TSniperRifle::Print()
{
  std::cout << "Sniper Rifle:\n";
  TRangedWeapon::Print();
  std::cout << "Length = " << this->GetLength() << " mm" << "\n"
  	<< "Caliber = " << this->GetCaliber() << " mm" << "\n";
}
