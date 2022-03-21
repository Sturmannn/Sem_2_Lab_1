#pragma once

class TFirearms
{
public:

	TFirearms();
	TFirearms(int _ammunition, int _kitCount);
	TFirearms(const TFirearms& p);
	TFirearms(double _weight);
	TFirearms(TFirearms&& p);
	~TFirearms();

	void SetAmmunition(int _ammunition);
	void SetWeight(double _weight);
	void SetKitCount(int _kitCount);
	void SetKit(int _kit, int i);
	int GetAmmunition();
	double GetWeight();
	int GetKitCount();
	char* GetKits();
	virtual void Shoot() = 0;
	virtual void Print() = 0;

protected:
	int ammunition;
	double weight;
	int kitCount;
	char* kits;
};