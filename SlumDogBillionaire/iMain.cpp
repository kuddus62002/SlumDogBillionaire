#include "iGraphics.h"
#include<iostream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int pageLength = 1200;
int weigth = 800;
int a, b, c, d, e, f, g, h, i, j, k, l;
int load[7];
int kuddusRun[6];

int Kuddusindex = 0;
int KuddusCoordinateX = 10;
int KuddusCoordinateY = 125;
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
bool flag = false;

bool StandPosition = true;
bool continueDone = false;

void fuctionForLoad();
void loadPage();
void StartPageImage();

void drawlevel1();
void drawStartPage();
void drawStoryPage();
void drawAboutPage();
void drawRulePage();
void drawbackground1();


void StartButtonClickHandler();
void StoryButtonClickHandler();
void AboutButtonClickHandler();
void RuleButtonClickHandler();
void BackButtonClickHandler();
void level1ButtonClickHandler();




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
		
		drawlevel1();
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
	if (key == '\r')
	{
		
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
		KuddusCoordinateX += 10;
		Kuddusindex++;
		if (Kuddusindex >= 5){
			Kuddusindex = 0;
		}
		StandPosition = false;
	}
	if (key == GLUT_KEY_LEFT)
	{
		KuddusCoordinateX -= 10;
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
void button(){
	a = iLoadImage(".\\LPage\\Button\\L8.png");
	b = iLoadImage(".\\LPage\\Button\\L9.png");
	c = iLoadImage(".\\LPage\\Button\\L10.png");
	d = iLoadImage(".\\LPage\\Button\\L11.png");
	e = iLoadImage(".\\LPage\\Button\\L12.png");
	k = iLoadImage(".\\LPage\\Background\\bg1.png");
}
void StartPageImage(){
	f = iLoadImage(".\\LPage\\L7.png");
	g = iLoadImage(".\\LPage\\4.png");
	h = iLoadImage(".\\LPage\\3.png");
	i = iLoadImage(".\\LPage\\back.png");
	j = iLoadImage(".\\LPage\\Rules.png");
	
}

void kuddusImage(){
	kuddusRun[0] = iLoadImage(".\\LPage\\Kuddus\\Run\\R1.png");
	kuddusRun[1] = iLoadImage(".\\LPage\\Kuddus\\Run\\R2.png");
	kuddusRun[2] = iLoadImage(".\\LPage\\Kuddus\\Run\\R3.png");
	kuddusRun[3] = iLoadImage(".\\LPage\\Kuddus\\Run\\R4.png");
	kuddusRun[4] = iLoadImage(".\\LPage\\Kuddus\\Run\\R5.png");
	cout << "Image loading";
	kuddusRun[5] = iLoadImage(".\\LPage\\Kuddus\\Stand\\R1.png");

}

void level1PageImage(){
	
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
	iShowImage(5, 5, 50, 80, i);
}

void StartButtonClickHandler(){
	homePage = 0;
	Start = true;
}

void drawStoryPage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, g);
	iShowImage(5, 5, 50, 80, i);
}

void StoryButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = true;
}

void drawAboutPage(){
	iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(0, 0, pageLength, weigth, h);
	iShowImage(5, 5, 50, 80, i);
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
	iShowImage(5, 5, 50, 80, i);
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
	if (!StandPosition){
		iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[Kuddusindex]);
		if (standCounter >= 20){
			standCounter = 0;
			Kuddusindex = 0;
			StandPosition = true;
			flag = false;
		}
	}
	else {
		iShowImage(KuddusCoordinateX, KuddusCoordinateY, 119, 200, kuddusRun[5]);
	}
}

void drawbackground1(){
	//iFilledRectangle(0, 0, pageLength, weigth);
	iShowImage(backgroundimage, 0, pageLength, weigth, k);
	if (flag)
	{
		iShowImage(backgroundimage + 1200, 0, pageLength, weigth, k);
		backgroundimage -= 0.05;
		//cout << backgroundimage << "\n";
		if (backgroundimage <-1200){
			backgroundimage = 0;
		}
	}
	
}

void level1ButtonClickHandler(){
	homePage = 0;
	Start = false;
	storyPage = false;
	aboutpage = false;
	rulepage = false;
	level1 = true;
}






int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(pageLength, weigth , "Project Title");
	//a = iLoadImage("LPage\\L1.png");
	///updated see the documentations
	loading();
	button();
	loadPage();
	StartPageImage();
	kuddusImage();
	level1PageImage();
	iStart();
	return 0;
}