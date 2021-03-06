#pragma once
#include "Scene.h"
#include "Director.h"
#include "GameScene.h"
#include "Sprite.h"
#include "Timer.h"
#include "Label.h"
class MainScene : public Scene
{
public:
	Label* lab;
	Timer* timer;
	master* m;
	Sprite* howmuch;
	Sprite* save;
	Sprite* reload;
	Sprite* restart;
	Sprite* quit;
	Sprite* start;

	bool isStart;

	void Init() override;
	void Update() override;
	void OnExit() override;
};

