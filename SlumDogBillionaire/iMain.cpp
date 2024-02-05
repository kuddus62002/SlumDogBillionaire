/*
  Project Nmae : Slum Dog Billionaire
  Author       : Fahim Uddin Bin Ahmed
                 Pryonti Shaha
				 Tahmid Amir
  Language     : c/c++
  Project no   : 1
 
 */




#include "iGraphics.h"
#include<iostream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int pageLength = 1200;
int weigth = 800;
int JUMPLIMIT = 250;        
#define RockNumber = 10;


int a, b, c, d, e, f, g, h, img, j, k, l, m, n, o, p, won;
int load[7];
int kuddusRun[6];
int kuddusJump[5];
int RockCount = 0;

int Kuddusindex = 0;
int KuddusCoordinateX = 10;
int KuddusCoordinateY = 125;
int KuddusCoordinateJump = 0;
int standCounter = 0;


int indexLoad = 0;
int loadTimer = 0;
int startButtonClick = 0;
int storyButtonClick = 1;
double backgroundimage = 0;



int homePage = 1;
bool Start = false;
bool storyPage = false;
bool aboutpage = false;
bool rulepage = false;
bool level1 = false;
bool level2 = false;
bool flag = false;
bool QuizFlag1 = false;
bool gameOver = false;
bool gamewin = false;
bool barikhawa = false;
bool resetrock = false;
bool QuizFlag2 = false;

bool StandPosition = true;
bool continueDone = false;

bool jump = false;
bool jumpup = false;
//bool jumpdown = false;
int jumplimit = 50;

void fuctionForLoad();
void fuctionForLoad2();
void loadPage();
void StartPageImage();

void drawlevel1();
void drawlevel2();
void drawStartPage();
void drawStoryPage();
void drawAboutPage();
void drawRulePage();
void drawbackground1();
void drawobstacles1();
void drawobstacles2();
void drawbackground2();
void drawgameOver();
void drawyouwon();
void obstacleReset();
void GenerateRocks();



void StartButtonClickHandler();
void StoryButtonClickHandler();
void AboutButtonClickHandler();
void RuleButtonClickHandler();
void BackButtonClickHandler();
void level1ButtonClickHandler();
void level2ButtonClickHandler();
void exitButtonCliclHandler();
void youwonButtonClickHandler();
void quizwronganswer();
void quizwronganswer2();

struct Obstacle
{
	int rockX =1200;
	int rockY = 125;
	int roackIndex;
	bool rockShow;

	Obstacle(){
		;
	};

	Obstacle(int x){
		rockX = x;
	};




	void collission(){
		if ((KuddusCoordinateX + 119 >= rockX && KuddusCoordinateX + 119 <= rockX + 120) && (KuddusCoordinateY + KuddusCoordinateJump + 100 <= 315)){ /*&& (Start == true)*/
			//exit(0);
			//cout << "fahim" << endl;
			barikhawa = true;
			resetrock = true;
		}
		if (barikhawa){
			obstacleReset();
			exitButtonCliclHandler();
		}
	}

	void collission2(){
		if ((KuddusCoordinateX + 119 >= rockX && KuddusCoordinateX + 119 <= rockX + 200) && (KuddusCoordinateY + KuddusCoordinateJump + 100 <= 395)){ /*&& (Start == true)*/
			//exit(0);
			//cout << "fahim" << endl;
			barikhawa = true;
			resetrock = true;
		}
		if (barikhawa){
			obstacleReset();
			exitButtonCliclHandler();
		}
	}
};

Obstacle rock2[13];
Obstacle rock1[10];
Obstacle rockdefault;





                    


void iDraw()
{
	iClear();
	if (homePage == 1){
		loadPage();
	}

	else if (Start){
		drawStartPage();
	}

	else if (storyPage){
		drawStoryPage();
	}

	else if (aboutpage){
		drawAboutPage();
	}
	else if (rulepage){
		drawRulePage();
	}
	else if (level1){
		cout << "fahim" << endl;
		drawlevel1();
	}
	else if (level2){

		drawlevel2();
	}
	else if (gameOver){
		drawgameOver();
	}
	else if (gamewin){
		drawyouwon();
	}
	

	
	
}

// isettimer(changecharimg, 0.2)
//changecharimg index++; isettimer(changecharimg, 0.2)


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
		if (indexLoad == 4){
			continueDone = true;
			indexLoad++;
		}
		printf("x = %d, y = %d\n", mx, my);
		// if (mx >= leftX && mx <= rightX && my <= topY && my >= bottomY)
		if (homePage == 1 && (mx >= 518 && mx <= 645) && (my >= 660 && my <= 715)){
			StartButtonClickHandler();
		}

		else if (homePage == 1 && (mx>=515 && mx<=640) && (my>=560 && my<=615)){
			StoryButtonClickHandler();
		}

		else if (homePage == 1 && (mx >= 516 && mx <= 642) && (my >= 258 && my <= 310)){
			AboutButtonClickHandler();
		}

		else if (homePage == 1 && (mx >= 516 && mx <= 642) && (my >= 465 && my <= 510)){
			RuleButtonClickHandler();
		}
		else if ((Start || storyPage || aboutpage || rulepage) && (mx >= 10 && mx <= 50) && (my >= 33 && my <= 60)){
			BackButtonClickHandler();
		}
		else if (Start == true && (mx >= 40 && mx <= 209) && (my >= 531 && my <= 768)){
			level1ButtonClickHandler();
		}
		else if (Start == true && (mx >= 440 && mx <= 650) && (my >= 320 && my <= 460)){
			level2ButtonClickHandler();
		}
		else if (gameOver == true && barikhawa == false && (mx >= 35 && mx <= 480) && (my >= 380 && my <= 730)){
			//cout << "ami" << endl;
			gameOver = false;
			level1ButtonClickHandler();
		}

		else if (gameOver == true && barikhawa == false && (mx >= 860 && mx <= 1150) && (my >= 187 && my <= 345)){
			StartButtonClickHandler();
		}
			
			
		

	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'a')
	{
		if (QuizFlag1){
			quizwronganswer();
		}
		else if (QuizFlag2){
			youwonButtonClickHandler();
		}
		
	}
	else if (key == 'b'){
		if (QuizFlag1){
			youwonButtonClickHandler();
		}
		else if (QuizFlag2){
			quizwronganswer2();
		}
	}
	else if (key == 'c'){
		if (QuizFlag1){
			quizwronganswer();
		}
		else if (QuizFlag2){
			quizwronganswer2();
		}
	}
	else if (key == 'd'){
		if (QuizFlag1){
			quizwronganswer();
		}
		else if (QuizFlag2){
			quizwronganswer2();
		}
	}
	else if (key == ' '){
		if (!jump){
			jump = true;
			jumpup = true;
		}
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
  function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		flag = true;
		if (QuizFlag1 == true){
			KuddusCoordinateX += 20;
		}
		Kuddusindex++;
		if (Kuddusindex >= 5){
			Kuddusindex = 0;
		}
		StandPosition = false;
	}
	if (key == GLUT_KEY_LEFT)
	{
		//KuddusCoordinateX -= 5;
		Kuddusindex--;
		if (Kuddusindex <= 0){
			Kuddusindex = 5;
		}
		StandPosition = false;
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}


	
}

void onKeyboardUp(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT || key == ' ')
	{
		StandPosition = true;
	}
}

void loading(){
	//cout << "Image loading";
	load[0] = iLoadImage(".\\LPage\\L1.png");
	load[1] = iLoadImage(".\\LPage\\L2.png");
	load[2] = iLoadImage(".\\LPage\\L3.png");
	load[3] = iLoadImage(".\\LPage\\L4.png");
	load[4] = iLoadImage(".\\LPage\\L5.png");
	load[5] = iLoadImage(".\\LPage\\L6.png"); 
	load[6] = iLoadImage(".\\LPage\\L7.png");
}
void button() {
	a = iLoadImage(".\\LPage\\Button\\L8.png");
	b = iLoadImage(".\\LPage\\Button\\L9.png");
	c = iLoadImage(".\\LPage\\Button\\L10.png");
	d = iLoadImage(".\\LPage\\Button\\L11.png");
	e = iLoadImage(".\\LPage\\Button\\L12.png");
	
	
}
void StartPageImage(){
	f = iLoadImage(".\\LPage\\L7.png");
	g = iLoadImage(".\\LPage\\4.png");
	h = iLoadImage(".\\LPage\\3.png");
	img = iLoadImage(".\\LPage\\back.png");
	j = iLoadImage(".\\LPage\\Rules.png");
	
}

void kuddusImage(){
	//these array is for run;
	kuddusRun[0] = iLoadImage(".\\LPage\\Kuddus\\Run\\R1.png");
	kuddusRun[1] = iLoadImage(".\\LPage\\Kuddus\\Run\\R2.png");
	kuddusRun[2] = iLoadImage(".\\LPage\\Kuddus\\Run\\R3.png");
	kuddusRun[3] = iLoadImage(".\\LPage\\Kuddus\\Run\\R4.png");
	kuddusRun[4] = iLoadImage(".\\LPage\\Kuddus\\Run\\R5.png");
	//cout << "Image loading";
	//this is for stand;
	kuddusRun[5] = iLoadImage(".\\LPage\\Kuddus\\Stand\\R1.png");
	//this images for jump;
	kuddusJump[0] = iLoadImage(".\\LPage\\Kuddus\\Jump\\R1.png");
	kuddusJump[1] = iLoadImage(".\\LPage\\Kuddus\\Jump\\R2.png");

}

void level1PageImage(){
	k = iLoadImage(".\\LPage\\Background\\bg1.png");
	m = iLoadImage(".\\Lpage\\Background\\gameOver.png");
	n = iLoadImage(".\\Lpage\\Background\\quiz.png");
	o = iLoadImage(".\\Lpage\\Obstacles\\rock-3.png");
	won = iLoadImage(".\\Lpage\\Background\\won.png");

}

void level2PageImage(){
	l = iLoadImage(".\\LPage\\Background\\bankbg.jpg");
	p = iLoadImage(".\\LPage\\Obstacles\\table-1.png");
}


void fuctionForLoad()
{
	loadTimer++;

	if (loadTimer >= 500)
	{
		indexLoad++;
		loadTimer = 0;
	}
}


void fuctionForLoad2()
{
	loadTimer++;

	if (loadTimer >= 500)
	{
		indexLoad++;
		loadTimer = 0;
	}
}



void loadPage(){
	if (indexLoad < 4)
		fuctionForLoad();

	//	iShowImage(0, 0, 600, 600, a);
	iShowImage(0, 0, 1200, 800, load[indexLoad]);

	/*if (continueDone){
	iFilledRectangle(500, 650, 200, 50);
	iFilledRectangle(500, 550, 200, 50);
	iFilledRectangle(500, 450, 200, 50);
	iFilledRectangle(500, 350, 200, 50);
	}*/

	if (continueDone){
		iShowImage(420, 550, 320, 250, a);
		iShowImage(420, 450, 320, 250, b);
		iShowImage(420, 350, 320, 250, c);
		iShowImage(420, 250, 320, 250, d);
		iShowImage(420, 150, 320, 250, e);

	}
}

void drawStartPage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, f);
	iShowImage(5, 5, 50, 80, img);
}

void StartButtonClickHandler(){
	homePage = 0;
	Start = true;
}

void drawStoryPage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, g);
	iShowImage(5, 5, 50, 80, img);
}

void StoryButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = true;
}

void drawAboutPage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, h);
	iShowImage(5, 5, 50, 80, img);
}

void AboutButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = true;
}

void drawRulePage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, j);
	iShowImage(5, 5, 50, 80, img);
}

void RuleButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = true;
}

void BackButtonClickHandler(){
	homePage = 1;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
}


void drawlevel1(){
	drawbackground1();
	
	if (jump){
		if (jumpup){
			iShowImage(KuddusCoordinateX, KuddusCoordinateY + KuddusCoordinateJump, 119, 200, kuddusJump[0]);
		}
		else{
			iShowImage(KuddusCoordinateX, KuddusCoordinateY + KuddusCoordinateJump, 119, 200, kuddusJump[1]);
		}
		
	}
	else{

		if (!StandPosition){
			iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[Kuddusindex]);

			/*if (standCounter >= 20){
			standCounter = 0;
			Kuddusindex = 0;
			StandPosition = true;
			flag = false;
			}*/
		}
		else {

			iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[5]);
		}
	}
	
	drawobstacles1();

	if (QuizFlag1 == true){
		iShowImage(0, 0, pageLength, weigth, n);

		if (!StandPosition){
			iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[Kuddusindex]);

			/*if (standCounter >= 20){
			standCounter = 0;
			Kuddusindex = 0;
			StandPosition = true;
			flag = false;
			}*/
		}
		else {

			iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[5]);
		}
	}
}
void drawlevel2(){
	drawbackground2();
	
	if (jump)
	{
		if (jumpup)
		{
			iShowImage(KuddusCoordinateX, KuddusCoordinateY + KuddusCoordinateJump+100, 119, 200, kuddusJump[0]);
		}
		else
		{
			iShowImage(KuddusCoordinateX, KuddusCoordinateY + KuddusCoordinateJump+100, 119, 200, kuddusJump[1]);
		}

	}
	else{
		if (!StandPosition)
		{
			iShowImage(KuddusCoordinateX, KuddusCoordinateY - 65, 119, 200, kuddusRun[Kuddusindex]);
			/*if (standCounter >= 20){
			standCounter = 0;
			Kuddusindex = 0;
			StandPosition = true;
			flag = false;
			}*/
		}
		else {
			iShowImage(KuddusCoordinateX, KuddusCoordinateY - 65, 119, 200, kuddusRun[5]);
		}
	}
	
	drawobstacles2();
	if (QuizFlag2 == true){
		iShowImage(0, 0, pageLength, weigth, n);

		if (!StandPosition){
			iShowImage(KuddusCoordinateX, KuddusCoordinateY - 65, 119, 200, kuddusRun[Kuddusindex]);
			/*if (standCounter >= 20){
			standCounter = 0;
			Kuddusindex = 0;
			StandPosition = true;
			flag = false;
			}*/
		}
		else {

			iShowImage(KuddusCoordinateX, KuddusCoordinateY - 65, 119, 200, kuddusRun[5]);
		}
	}
	
}

void drawbackground1(){
	//iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(backgroundimage, 0, pageLength, weigth, k);
	if (flag)
	{
		iShowImage(backgroundimage + 1200, 0, pageLength, weigth, k);
		if (!StandPosition){
			backgroundimage -= 0.9                  ;
		}
		
		//cout << backgroundimage << "\n";
		if (backgroundimage <-1200){
			backgroundimage = 0;
		}
	}
	
}

void drawobstacles1(){
	for (int i = 0; i < 10; i++){
		iShowImage(rock1[i].rockX, 125, 120, 100, o );
		if (flag){
			if (!StandPosition){
				rock1[i].rockX -= 0.9;
			}
			if (rock1[i].rockX < 10){
				//QuizFlag1 = true;
				 RockCount++;
				if (RockCount >= 10){
					cout << "you win" << endl;
					QuizFlag1 = true;
				}//quiz start;
				rock1[i].rockX = 120000;
			}
			//rock1[i].rockX = 120000;
		}
		rock1[i].collission();
	}
	
	
}

void   drawbackground2(){
	//iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(backgroundimage, 0, pageLength, weigth, l);
	if (flag)
	{
		iShowImage(backgroundimage + 1200, 0, pageLength, weigth, l);
		if (!StandPosition){
			backgroundimage -= 1;
		}
		//cout << backgroundimage << "\n";
		if (backgroundimage <-1200){
			backgroundimage = 0;
		}
	}

}

void drawobstacles2(){
	for (int i = 0; i < 10; i++){
		iShowImage(rock2[i].rockX, 60, 200, 180, p);
		if (flag){
			if (!StandPosition){
				rock2[i].rockX -= 1;
			}
			if (rock2[i].rockX < 10){
				RockCount++;
				if (RockCount >= 10){
					cout << "you win" << endl;
					QuizFlag2 = true;
				}//quiz start;
				rock1[i].rockX = 120000;
			
			}
		}
		rock2[i].collission2();
	}
	
}

void obstacleReset(){
	if (resetrock){
		/*if (level1){
			for (int i = 0; i < 10; i++){
				rock1[i].rockX = rockdefault.rockX;
			}
			RockCount = 0;
		}
		else if (level2){
			for (int i = 0; i < 13; i++){
				rock2[i].rockX = rockdefault.rockX;
			}*/
		GenerateRocks();
			RockCount = 0;
		
		KuddusCoordinateX = 10;
		KuddusCoordinateY = 125;
	}

	resetrock = false;
}

void drawgameOver(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, m);
	barikhawa = false;
	

}
void drawyouwon(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, won);
}


void level1ButtonClickHandler(){
	//cout << "dekhi" << endl;
	cout << barikhawa << endl;
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	gameOver = false;
	level1 = true;
	level2 = false;
	gamewin = false;
	barikhawa = false;
}

void level2ButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	level1 = false;
	level2 = true;
}
void quizwronganswer(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	gameOver = false;
	level1 = true;
	resetrock = true;
	obstacleReset();
	level2 = false;
	barikhawa = false;
	QuizFlag1 = false;
}
void quizwronganswer2(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	gameOver = false;
	level1 = false;
	level2 = true;
	resetrock = true;
	obstacleReset();
	barikhawa = false;
	QuizFlag1 = false;
	QuizFlag2 = false;

}

void exitButtonCliclHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	gameOver = true;
	level1 = false;
	level2 = false;
	barikhawa = false;
}

void youwonButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	gameOver = false;
	level1 = false;
	level2 = false;
	gamewin = true;
}


//korsi to commit
void change(){
	if (jump)
	{
		if (jumpup)
		{
			(KuddusCoordinateJump += 5);
			if (KuddusCoordinateJump >= JUMPLIMIT)
			{
				jumpup = false;
			}
		}
		else{
			KuddusCoordinateJump -= 5;
			if (KuddusCoordinateJump < 0){
				jump = false;
				KuddusCoordinateJump = 0;
			}
		}
	}
}


void GenerateRocks(){
	
		for (int i = 0; i < 10; i++){
			rock1[i] = Obstacle(1200 + i * 900);
		}
	
	
		for (int i = 0; i < 13; i++){
			rock2[i] = Obstacle(1200 + i * 900);
	}
	
}



int main()
{
	iSetTimer(15, change);
	///srand((unsigned)time(NULL));
	iInitialize(pageLength, weigth , "Project Title");
	glutSpecialUpFunc(onKeyboardUp);
	//a = iLoadImage("LPage\\L1.png");
	///updated see the documentations
	GenerateRocks();      
	loading();
	button();
	loadPage();
	StartPageImage();
	kuddusImage();
	level1PageImage();
	level2PageImage();
	iStart();
	return 0;
}