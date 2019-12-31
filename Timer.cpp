#include "DXUT.h"
#include "Timer.h"

void Timer::Start()
{
	FILE* fp = fopen("HowMuch.txt", "w+");
	fclose(fp);
}

void Timer::Add(master* m)
{
	ofstream outFile("HowMuch.txt");
	string aa = to_string(m->hour) + to_string(m->hour2) +  to_string(m->minute) + to_string(m->min2) + to_string(m->second) + to_string(m->sec2);

	cout << aa << endl;
	outFile << aa;
	outFile.close();
}

void Timer::Output()
{
	char inputString[1000];

	ifstream inFile("HowMuch.txt");
	while (!inFile.eof())
	{
		inFile.getline(inputString, 100);
		cout << inputString << endl;
	}
	inFile.close();
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
