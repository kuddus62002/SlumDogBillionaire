#include "iGraphics.h"
#include<iostream>
using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int load[7];
int indexLoad = 0;
int a;
int loadTimer = 0;
bool continueDone = false;

void fuctionForLoad()
{
	loadTimer++;

	if (loadTimer >= 500)
	{
		indexLoad++;
		loadTimer = 0;
	}
}

void iDraw()
{
	iClear();
	if (indexLoad < 4)
		fuctionForLoad();

//	iShowImage(0, 0, 600, 600, a);
	iShowImage(0, 0, 1200, 800, load[indexLoad]);

	if (continueDone){
		iFilledRectangle(500, 650, 200, 50);
		iFilledRectangle(500, 550, 200, 50);
		iFilledRectangle(500, 450, 200, 50);
		iFilledRectangle(500, 350, 200, 50);
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
		

		// if (mx >= leftX && mx <= rightX && my <= topY && my >= bottomY)
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
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}
void loading(){
	cout << "Image loading";
	load[0] = iLoadImage(".\\LPage\\L1.png");
	load[1] = iLoadImage(".\\LPage\\L2.png");
	load[2] = iLoadImage(".\\LPage\\L3.png");
	load[3] = iLoadImage(".\\LPage\\L4.png");
	load[4] = iLoadImage(".\\LPage\\L5.png");
	load[5] = iLoadImage(".\\LPage\\L6.png");
}


int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(1200, 800, "Project Title");
	//a = iLoadImage("LPage\\L1.png");
	///updated see the documentations
	loading();
	iStart();
	return 0;
}