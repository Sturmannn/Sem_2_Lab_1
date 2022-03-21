#pragma once
#include "Firearms.h"

class TMeleeWeapon : public TFirearms {
public:

	TMeleeWeapon();
	TMeleeWeapon(int _ammunition, double _barrelLength);
	TMeleeWeapon(const TMeleeWeapon& p);
	TMeleeWeapon(double _weight);
	TMeleeWeapon(TMeleeWeapon&& p);
	~TMeleeWeapon();
	void SetBarrelLength(double _barrelLength);
	double GetBarrelLength();
	char* Load(int _ammunition);
	void Shoot() override;
	void Print() override;

protected:
	char* load;
	double barrelLength;
};