#include "Carbine.h"
#include <iostream>

TCarbine::TCarbine() :TRangedWeapon()
{
	weight = 3.9;
	rateOfFire = 30;
}

TCarbine::TCarbine(double _rateOfFire, double _range) : TRangedWeapon()
{
	SetRateOfFire(_rateOfFire);
	SetRange(_range);
}

TCarbine::TCarbine(const TCarbine& p) : TRangedWeapon(p)
{
	rateOfFire = p.rateOfFire;
}

TCarbine::TCarbine(double _ammunition) : TCarbine()
{
	this->ammunition = _ammunition;
}

TCarbine::TCarbine(TCarbine&& p)
{
	rateOfFire = p.rateOfFire;
	range = p.range;
	load = p.load;
	ammunition = p.ammunition;
	weight = p.weight;
	kitCount = p.kitCount;
	kits = p.kits;
	p.kitCount = 0;
	p.kits = 0;
}

TCarbine::~TCarbine()
{
	rateOfFire = 0;
}

void TCarbine::SetRateOfFire(double _rateOfFire)
{
	this->rateOfFire = _rateOfFire;
}

double TCarbine::GetRateOfFire()
{
	return rateOfFire;
}


void TCarbine::Shoot()
{
	if (ammunition > 0) {
		std::cout << "BANG BANG" << std::endl;
		ammunition -= 1;
	}
	else
		std::cout << "Misfire\n";
}

void TCarbine::Print()
{
	std::cout << "Carbine:\n";
	TRangedWeapon::Print();
	std::cout << "Rate Of Fire = " << this->GetRateOfFire() << " v/m\n";
}
