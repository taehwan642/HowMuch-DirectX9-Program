#include "DXUT.h"
#include "Timer.h"

Timer::Timer()
{
	Addpos = 0;
	Addnum = 0;
	Addp = 0;
}

void Timer::Start(master* m)
{
	FILE* fp = fopen("HowMuch.txt", "w+");
	char a[7] = "000000";
	fputs(a, fp);
	fclose(fp);
	m->timer = 0;
	m->second = 0;
	m->sec2 = 0;
	m->minute = 0;
	m->min2 = 0;
	m->hour = 0;
	m->hour2 = 0;
}

void Timer::Add(master* m)
{
	ofstream outFile("HowMuch.txt");
	string aa = to_string(m->hour) + to_string(m->hour2) + to_string(m->minute) + to_string(m->min2) + to_string(m->second) + to_string(m->sec2);
	outFile << aa;
	outFile.close();
}

void Timer::Load(master* m)
{
	char inputString[1000];
	ifstream inFile("HowMuch.txt");
	while (!inFile.eof())
	{
		inFile.getline(inputString, 100);
	}
	m->hour = inputString[0] - 48;
	m->hour2 = inputString[1] - 48;
	m->minute = inputString[2] - 48;
	m->min2 = inputString[3] - 48;
	m->second = inputString[4] - 48;
	m->sec2 = inputString[5] - 48;

	inFile.close();
}

void Timer::Output(master* m, vector2 vec)
{
	/*char inputString[1000];

	ifstream inFile("HowMuch.txt");
	while (!inFile.eof())
	{
		inFile.getline(inputString, 100);
		cout << inputString << endl;
	}
	inFile.close();*/
	for (auto it : sp)
	{
		delete it;
	}
	sp.clear();
	string aa = to_string(m->hour) + to_string(m->hour2) + to_string(m->minute) + to_string(m->min2) + to_string(m->second) + to_string(m->sec2);
	Addpos = 0;
	Addnum = 1;
	Addp = 0;
	_position = vec;

	for (auto it : aa)
	{
		if (Addp >= 2)
		{
			Addnum++;
			Addp = 0;
		}
		Sprite* s = new Sprite;
		s->isUI = true;
		s->Create(L"font/" + to_wstring(it - 48) + L".png");
		s->_scale = { 3,3 };
		s->_position = { Addpos + (_position.x * Addnum / 3),_position.y };
		Addpos += 60;
		Addp++;
		sp.push_back(s);
	}
}

master::master()
{
	timer = 0;
	second = 0;
	sec2 = 0;
	minute = 0;
	min2 = 0;
	hour = 0;
	hour2 = 0;
	str = "000000";
}
