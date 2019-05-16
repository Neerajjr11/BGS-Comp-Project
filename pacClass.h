#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>



//array that stores map positions, 0 for walls, 1 for pellets, 2 for power pellet, 3 for teleport places, 4 for empty space
int mapCo[32][28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		   0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
		   0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
		   0,2,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,2,0,
		   0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
		   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		   0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
		   0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
		   0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
		   0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
		   4,4,4,4,4,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,4,4,4,4,4,
		   4,4,4,4,4,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,4,4,4,4,4,
		   4,4,4,4,4,0,1,0,0,1,4,4,4,4,4,4,4,4,1,0,0,1,0,4,4,4,4,4,
		   0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
		   3,4,4,4,4,4,1,4,4,1,0,4,4,4,4,4,4,0,1,4,4,1,4,4,4,4,4,3,
		   3,4,4,4,4,4,1,4,4,1,0,4,4,4,4,4,4,0,1,4,4,1,4,4,4,4,4,3,
		   0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
		   4,4,4,4,4,0,1,0,0,1,4,4,4,4,4,4,4,4,1,0,0,1,0,4,4,4,4,4,
		   4,4,4,4,4,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,4,4,4,4,4,
		   4,4,4,4,4,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,4,4,4,4,4,
		   0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
		   0,1,1,1,1,1,1,4,4,1,1,1,1,0,0,1,1,1,1,4,4,1,1,1,1,1,1,0,
		   0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
		   0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
		   0,2,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,2,0,
		   0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
		   0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
		   0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
		   0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
		   0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
		   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Functions to convert xco and yco to array coordinates
int convertXCo(int xco){
	return (xco-175)/10;
}

int convertYCo(int yco){
	return (yco-90)/10;
}

//Function to draw the pacman map
void map()
{
   setcolor(BLUE);
   line(170,85,450,85);   line(170,405,450,405);//Aa to A2 and 6a to 62
   line(180,395,440,395);//5b to 51

   line(180,95,300,95);   line(320,95,440,95);  //Bb to Bm and Bp to B1
   line(300,95,300,135);  line(320,95,320,135);//Bm to Fm and Bp to Fp
   line(300,135,320,135);                      //Fm to Fp

   line(170,85,170,185);  line(450,85,450,185); //Aa to Ja and A2 to J2
   line(180,95,180,175);  line(440,95,440,175); //Bb to Ib and B1 to I1

   line(180,175,230,175); line(440,175,390,175);//Ib to Ig and I1 to Iv
   line(170,185,220,185); line(450,185,400,185);//Ja to Jf and J2 to Jw

   line(230,175,230,225); line(390,175,390,225);//Ig to Og and Iv to Ov
   line(220,185,220,215); line(400,185,400,215);//Jf to Nf and Jw to Nw

   line(230,225,170,225); line(390,225,450,225);//Ng to Na and Nv to N2
   line(220,215,170,215); line(400,215,450,215);//Mf to Ma and Mw to M2

   line(170,245,230,245); line(450,245,390,245);//Pa to Pg and P2 to Pv
   line(170,255,220,255); line(450,255,400,255);//Qa to Qf and Q2 to Qw

   line(230,245,230,295); line(390,245,390,295);//Pg to Ug and Pv to Uv
   line(220,255,220,285); line(400,255,400,285);//Qf to Tf and Qw to Tw

   line(170,285,220,285); line(450,285,400,285);//Tf to Ta and Tw to T2
   line(180,295,230,295); line(440,295,390,295);//Ug to Ub and Uv to U1

   line(180,295,180,335); line(440,295,440,335);
   line(180,335,200,335); line(440,335,420,335);
   line(200,335,200,355); line(420,335,420,355);
   line(180,355,200,355); line(440,355,420,355);
   line(180,355,180,395); line(440,355,440,395);

   line(170,285,170,405); line(450,285,450,405);//Ta to 6a and T2 to 62
   //Outer layers done
   //Inner objects(A is 85, a is 170):
   line(190,105,190,135); line(230,105,230,135);
   line(190,105,230,105); line(190,135,230,135);

   line(240,105,240,135); line(290,105,290,135);
   line(240,105,290,105); line(240,135,290,135);

   line(330,105,330,135); line(380,105,380,135);
   line(330,105,380,105); line(330,135,380,135);

   line(390,105,390,135); line(430,105,430,135);
   line(390,105,430,105); line(390,135,430,135);

   line(190,145,190,165); line(230,145,230,165);
   line(190,145,230,145); line(190,165,230,165);

   line(240,145,240,225); line(290,175,290,195);
   line(240,145,260,145); line(240,225,260,225);
   line(260,145,260,175); line(260,195,260,225);
   line(260,175,290,175); line(260,195,290,195);

   line(380,145,380,225); line(330,175,330,195);
   line(360,145,380,145); line(360,225,380,225);
   line(360,145,360,175); line(360,195,360,225);
   line(360,175,330,175); line(360,195,330,195);

   line(390,145,390,165); line(430,145,430,165);
   line(390,145,430,145); line(390,165,430,165);

   line(270,145,350,145); line(300,195,320,195);
   line(270,145,270,165); line(350,145,350,165);
   line(270,165,300,165); line(350,165,320,165);
   line(300,165,300,195); line(320,165,320,195);
   //Message at the start of the game
   setcolor(YELLOW);
   outtextxy(270,205,"Player One");
   outtextxy(290,260,"Ready!");
   //Enclosure of the ghosts
   setcolor(CYAN);
   line(270,215,350,215); line(270,255,350,255);
   line(270,215,270,255); line(350,215,350,255);
   setcolor(BLUE);
   line(240,245,240,295); line(260,245,260,295);
   line(240,245,260,245); line(240,295,260,295);

   line(360,245,360,295); line(380,245,380,295);
   line(380,245,360,245); line(380,295,360,295);

   line(270,275,350,275); line(300,325,320,325);
   line(270,275,270,295); line(350,275,350,295);
   line(270,295,300,295); line(350,295,320,295);
   line(300,295,300,325); line(320,295,320,325);

   line(190,305,230,305); line(230,305,230,355);
   line(190,305,190,325); line(190,325,210,325);
   line(210,325,210,355); line(210,355,230,355);

   line(390,305,430,305); line(390,305,390,355);
   line(430,305,430,325); line(430,325,410,325);
   line(410,325,410,355); line(410,355,390,355);

   line(240,305,290,305);line(240,325,290,325);
   line(240,305,240,325);line(290,305,290,325);

   line(330,305,380,305);line(330,325,380,325);
   line(330,305,330,325);line(380,305,380,325);

   line(270,335,350,335); line(300,385,320,385);
   line(270,335,270,355); line(350,335,350,355);
   line(270,355,300,355); line(350,355,320,355);
   line(300,355,300,385); line(320,355,320,385);

   line(240,335,260,335); line(190,385,290,385);
   line(190,385,190,365); line(290,385,290,365);
   line(190,365,240,365); line(290,365,260,365);
   line(240,365,240,335); line(260,365,260,335);

   line(360,335,380,335); line(330,385,430,385);
   line(330,385,330,365); line(430,385,430,365);
   line(330,365,360,365); line(430,365,380,365);
   line(360,365,360,335); line(380,365,380,335);
   //Removing start message
   delay(3000);
   setfillstyle(SOLID_FILL,0);
   setcolor(0);
   int poly[8],Poly[8];
   poly[0]=270;
   poly[1]=200;
   poly[2]=270;
   poly[3]=215;
   poly[4]=350;
   poly[5]=215;
   poly[6]=350;
   poly[7]=200;

   Poly[0]=270;
   Poly[1]=260;
   Poly[2]=270;
   Poly[3]=270;
   Poly[4]=350;
   Poly[5]=270;
   Poly[6]=350;
   Poly[7]=260;
   fillpoly(4, poly);
   fillpoly(4, Poly);
}


//Character class is super class for pacman class and ghost class
class character {
	protected:
	int xco;
	int yco;
	//When this value changes, it is reflected for all the ghosts and pacman
	static int powerPellet;
	public:
	int getXco(){
		return xco;
	}
	int getYco(){
		return yco;
	}
	int getPowerPellet(){
		return powerPellet;
	}
	int setXco(int newXco){
		xco = newXco;
	}
	int setYco(int newYco){
		yco = newYco;
	}
	int setPowerPellet(int newPellet){
		powerPellet = newPellet;
	}
};

//Class for pacman objects, derived class of Character
class Pacman: public Character{
	int score;
	int life;
	public:
	//Draws pacman with direction as parameter
	void pacDraw(char direction);
	//passes direction as parameter and updates Xco and Yco of pacman
	void pacMove(char direction);
};

void Pacman:: pacDraw(char direction)
{
	tolower(direction);
	if
}
