#pragma once
#include "Types.h"
#include "Sprite.h"
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

class Timer : public Node
{
public:
	int Addpos;
	int Addnum;
	int Addp;
	Timer();
	void Start(master* m);
	void Add(master* m);
	void Load(master* m);
	void Output(master* m, vector2 vec);
	vector<Sprite*> sp;
};

