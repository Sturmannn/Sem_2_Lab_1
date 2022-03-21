#include "Shotgun.h"
#include <iostream>

TShotgun::TShotgun()
{
	weight = 3.8;
	ammunition = 5;
	accuracy = 20;
}

TShotgun::TShotgun(double _barrelLength, double _accuracy) : TShotgun()
{
	this->barrelLength = barrelLength;
	this->accuracy = _accuracy;
}

TShotgun::TShotgun(const TShotgun& p) : TMeleeWeapon(p)
{
	accuracy = p.accuracy;
}

TShotgun::TShotgun(double _ammunition) : TShotgun()
{
	this->ammunition = _ammunition;
}

TShotgun::TShotgun(TShotgun&& p)
{
	accuracy = p.accuracy;
	barrelLength = p.barrelLength;
	load = p.load;
	ammunition = p.ammunition;
	weight = p.weight;
	kitCount = p.kitCount;
	kits = p.kits;
	p.kitCount = 0;
	p.kits = 0;
}

TShotgun::~TShotgun()
{
	accuracy = 0;
}

void TShotgun::SetAccuracy(double _accuracy)
{
	this->accuracy = _accuracy;
}

double TShotgun::GetAccuracy()
{
	return accuracy;
}

void TShotgun::Shoot()
{
	if (ammunition > 0) {
		std::cout << "BOOM BOOM" << std::endl;
		ammunition -= 1;
	}
	else
		std::cout << "Misfire\n";
}

void TShotgun::Print()
{
	std::cout << "Shotgun:\n";
	TMeleeWeapon::Print();
	std::cout << "Accuracy = " << this->GetAccuracy() << " cm\n";
}
