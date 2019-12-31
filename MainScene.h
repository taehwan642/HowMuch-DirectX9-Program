#pragma once
#include "Scene.h"
#include "Director.h"
#include "GameScene.h"
#include "Sprite.h"
#include "Timer.h"

class MainScene : public Scene
{
public:
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

