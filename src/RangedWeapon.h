#pragma once
#include "Firearms.h"

class TRangedWeapon : public TFirearms {
public:

	TRangedWeapon();
	TRangedWeapon(int _ammunition, int _kitCount, double _range);
	TRangedWeapon(const TRangedWeapon& p);
	TRangedWeapon(double _weight);
	TRangedWeapon(TRangedWeapon&& p);
	~TRangedWeapon();
	void SetRange(double _range);
	double GetRange();
	char* Load(int _ammunition);
	void Shoot() override;
	void Print() override;
	
protected:
	char* load;
	double range;
};