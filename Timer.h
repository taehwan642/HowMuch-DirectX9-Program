#pragma once
#include "Types.h"
class master
{
public:
	master();
	float timer;
	int second;
	int sec2;
	int minute;
	int min2;
	int hour;
	int hour2;
	string str;
};

class Timer
{
public:

	void Start();
	void Add(master* m);
	void Output();
};

