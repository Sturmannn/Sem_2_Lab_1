#pragma once
#include "RangedWeapon.h"

class TCarbine : public TRangedWeapon {
public:

	TCarbine();
	TCarbine(double _rateOfFire, double _range);
	TCarbine(const TCarbine& p);
	TCarbine(double _ammunition);
	TCarbine(TCarbine&& p);
	~TCarbine();
	void SetRateOfFire(double _rateOfFire);
	double GetRateOfFire();
	void Shoot() override;
	void Print() override;

protected:
	double rateOfFire;
};