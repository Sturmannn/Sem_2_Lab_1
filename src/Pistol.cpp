#include "Pistol.h"
#include <iostream>

TPistol::TPistol()
{
  weight = 0.81;
  barrelLength = 93.5;
  initialVelocity = 315;
}

TPistol::TPistol(double _barrelLength, double _initialVelocity)
{
  this->barrelLength = _barrelLength;
  this->initialVelocity = _initialVelocity;
}

TPistol::TPistol(const TPistol& p) : TMeleeWeapon(p)
{
  initialVelocity = p.initialVelocity;
}

TPistol::TPistol(double _ammunition) : TPistol()
{
  this->ammunition = _ammunition;
}

TPistol::TPistol(TPistol&& p)
{
  initialVelocity = p.initialVelocity;
  barrelLength = p.barrelLength;
  load = p.load;
  ammunition = p.ammunition;
  weight = p.weight;
  kitCount = p.kitCount;
  kits = p.kits;
  p.kitCount = 0;
  p.kits = 0;
}

TPistol::~TPistol()
{
  initialVelocity = 0;
}

void TPistol::SetInitialVelocity(double _initialVelocity)
{
  this->initialVelocity = _initialVelocity;
}

double TPistol::GetInitialVelocity()
{
  return initialVelocity;
}

void TPistol::Shoot()
{
  if (ammunition > 0)
  {
    std::cout << "KA-BOOM" << std::endl;
  	ammunition -= 1;
  }
  else  std::cout << "Misfire\n";
}

void TPistol::Print()
{
  std::cout << "Pistol:\n";
  TMeleeWeapon::Print();
  std::cout << "Initial Velocity = " << this->GetInitialVelocity() << " m/sec\n";
}
