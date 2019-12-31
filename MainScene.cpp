#include "DXUT.h"
#include "MainScene.h"
void MainScene::Init()
{
	cout << "MAIN" << endl;
	m = new master();
	timer = new Timer();
	howmuch = new Sprite();
	howmuch->Create(L"Howmuch.png");
	howmuch->_position = { 500,100 };
	howmuch->_scale = { 1,1 };
	howmuch->_visible = true;
	howmuch->isUI = true;
	howmuch->AddRenderTarget();

	save = new Sprite();
	save->Create(L"Save.png");
	save->_position = { 100,550 };
	save->_scale = { 0.5f,0.5f };
	save->_visible = true;
	save->isUI = true;
	save->AddRenderTarget();

	reload = new Sprite();
	reload->Create(L"Reload.png");
	reload->_position = { 300,550 };
	reload->_scale = { 0.5f,0.5f };
	reload->_visible = true;
	reload->isUI = true;
	reload->AddRenderTarget();

	restart = new Sprite();
	restart->Create(L"Restart.png");
	restart->_position = { 500,550 };
	restart->_scale = { 0.5f,0.5f };
	restart->_visible = true;
	restart->isUI = true;
	restart->AddRenderTarget();

	quit = new Sprite();
	quit->Create(L"Quit.png");
	quit->_position = { 700,550 };
	quit->_scale = { 0.5f,0.5f };
	quit->_visible = true;
	quit->isUI = true;
	quit->AddRenderTarget();

	start = new Sprite();
	start->Create(L"Start.png");
	start->_position = { 900,550 };
	start->_scale = { 0.5f,0.5f };
	start->_visible = true;
	start->isUI = true;
	start->AddRenderTarget();

	
	isStart = false;
	lab = new Label();
}

void MainScene::Update()
{
	//저장, 불러오기, 끄기, 리셋
	//저장은 하던대로 하면 되고
	//불러오기는 각 m에다가 대입하면 될것같은데 이건 forautoit 대입해서 char 형 만들어지면  - 48 해서 인트형으로넣어주기 뭔지알지?
	//리셋은그냥 말그대로 리셋 전부 0으로 조지면 될듯
	//시작하면 바로 그냥 시간입력조짐

	if (isStart)
	{
		m->timer += Time::deltaTime;
		if (m->timer > 1)
		{
			//timer->Add(m);
			//lab->Create_Label(m->hour, { 190,290 });
			//lab->Create_Label(m->hour2, { 230,290 });
			//lab->Create_Label(m->minute, { 270,290 });
			//lab->Create_Label(m->min2, { 310,290 });
			//lab->Create_Label(m->second, { 350,290 });
			//lab->Create_Label(m->sec2, { 390,290 });
			timer->Output(m, { 500,290 });
			m->sec2++;
			m->timer = 0;
		}
		if (m->sec2 >= 10)
		{
			//timer->Add(m);
			m->second++;
			m->sec2 = 0;
		}
		if (m->second >= 6)
		{
			m->min2++;
			m->second = 0;
		}
		if (m->min2 >= 10)
		{
			//timer->Add(m);
			m->minute++;
			m->min2 = 0;
		}
		if (m->minute >= 6)
		{
			m->hour2++;
			m->minute = 0;
		}
		if (m->hour2 >= 10)
		{
			m->hour++;
			m->hour2 = 0;
		}
	}
	
	if (Director::GetInstance()->OnMouseDown())
	{
		if (PtInRect(&start->GetRect(), Director::GetInstance()->p))
		{
			isStart = true;
		}
		if (PtInRect(&quit->GetRect(), Director::GetInstance()->p))
		{
			exit(1);
		}
		if (PtInRect(&save->GetRect(), Director::GetInstance()->p))
		{
			timer->Add(m);
		}
		if (PtInRect(&reload->GetRect(), Director::GetInstance()->p))
		{
			timer->Load(m);
		}
		if (PtInRect(&restart->GetRect(), Director::GetInstance()->p))
		{
			timer->Start(m);
		}
	}
}

void MainScene::OnExit()
{
	
}
