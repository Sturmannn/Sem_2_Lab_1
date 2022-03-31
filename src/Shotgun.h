#pragma once
#include "MeleeWeapon.h"

class TShotgun : public TMeleeWeapon {
public:

  TShotgun();
  TShotgun(double _barrelLength, double _accuracy);
  TShotgun(const TShotgun& p);
  TShotgun(double _ammunition);
  TShotgun(TShotgun&& p);
  ~TShotgun();

  void SetAccuracy(double _accuracy);
  double GetAccuracy();
  void Shoot() override;
  void Print() override;

protected:

  double accuracy;
}; 
