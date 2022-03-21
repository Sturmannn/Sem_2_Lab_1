#pragma once
#include "MeleeWeapon.h"

class TPistol : public TMeleeWeapon {

public:

	TPistol();
	TPistol(double _barrelLength, double _initialVelocity);
	TPistol(const TPistol& p);
	TPistol(double _ammunition);
	TPistol(TPistol&& p);
	~TPistol();
	void SetInitialVelocity(double _initialVelocity);
	double GetInitialVelocity();
	void Shoot() override;
	void Print() override;

protected:

	double initialVelocity;
};