#include "Firearms.h"
#include <iostream>

TFirearms::TFirearms() 
{
	ammunition = 10;
	weight = 5;
	kitCount = 0;
	kits = nullptr;
}

TFirearms::TFirearms(int _ammunition, int _kitCount) : TFirearms()
{
	SetAmmunition(_ammunition);
	SetKitCount(_kitCount);
}

TFirearms::TFirearms(const TFirearms& p)
{
	ammunition = p.ammunition;
	weight = p.weight;
	kitCount = p.kitCount;
	kits = new char[kitCount];
	for (int i = 0; i < kitCount; i++) 
		kits[i] = p.kits[i]; 
}

TFirearms::TFirearms(double _weight) : TFirearms()
{
	SetWeight(_weight);
}

TFirearms::TFirearms(TFirearms&& p)
{
	ammunition = p.ammunition;
	weight = p.weight;
	kitCount = p.kitCount;
	kits = p.kits;
	p.kitCount = 0;
	p.kits = 0;
}

TFirearms::~TFirearms()
{
	ammunition = 0;
	weight = 0;
	kitCount = 0;
	if(kits != nullptr)
		delete[] kits;
}

void TFirearms::SetAmmunition(int _ammunition)
{
	if (_ammunition >= 0)	this->ammunition = _ammunition;
	else std::cout << "Invalid input";
}

void TFirearms::SetWeight(double _weight)
{
	if (_weight > 0)	this->weight = _weight;
	else std::cout << "Invalid input";
}

void TFirearms::SetKitCount(int _kitCount)
{
	if (_kitCount >= 0) 
	{
		char* tmp = new char[_kitCount];
		int ind = (kitCount > _kitCount) ? _kitCount : kitCount;
		for (int i = 0; i < ind; i++) {
			tmp[i] = kits[i];
		}
		delete[] kits;
		kits = tmp;
		this->kitCount = _kitCount;
	}
	else std::cout << "Invalid input";
}

void TFirearms::SetKit(int _kit, int i)
{
	if (i >= 0 && _kit > 0 && _kit < 5) {
		kits[i] = _kit;
	}
	else std::cout << "Invalid input";
}


int TFirearms::GetAmmunition()
{
	return ammunition;
}

double TFirearms::GetWeight()
{
	return weight;
}

int TFirearms::GetKitCount()
{
	return kitCount;
}

char* TFirearms::GetKits()
{
	return kits;
}

