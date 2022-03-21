#pragma once
#include "RangedWeapon.h"

class TSniperRifle : public TRangedWeapon {
public:
	TSniperRifle();
	TSniperRifle(int _length, int _caliber, double _range);
	TSniperRifle(const TSniperRifle& p);
	TSniperRifle(double _ammunition);
	TSniperRifle(TSniperRifle&& p);
	~TSniperRifle();
	void SetCaliber(double _caliber);
	double GetCaliber();
	void SetLength(double _length);
	double GetLength();
	void Shoot() override;
	void Print() override;

protected:
	double caliber;
	double length;
};
