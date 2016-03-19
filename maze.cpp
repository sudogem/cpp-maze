/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Project Name: Prototype Model MGv22304 : Sample Maze Game(2d array)  */
/* Coded by    : Arman and Da Super Friends                             */
/* SubjectCode : Project of CSC133 Compiler Design                      */
/* Project Consultant : Mr. Francis Baylon                              */
/* Note : This program is for educational purposes only.                */
/*        You can free to use and modify this code                      */
/*        but i hope that you can learn new ideas from this.            */
/*          							                                              */
/* Everybody wants to go to heaven, but nobody wants to die.            */

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>

#define BLOCK "Û"
#define fromUp 1
#define fromDown 2
#define fromLeft 3
#define fromRight 4
#define GOINGLEFT 1
#define GOINGDOWN 2
#define GOINGRIGHT 3
#define ARROWUP 72
#define ARROWDOWN 80
#define ESC 27

int matrix[30][30];
int startxloc = 30;
int startyloc = 10;

int starty=18;
int startx=29;
int choiceID;

void initgraphix(void);
void destroygraphix(void);
void typewriter_effects(char *contentmessage,int d);
void progname(void);
void display_atik_atik_Menu(void);
void highlightChoice1(int selectedChoice);
void viewGameDevelopers();
void playMaze();
int getChoice(void);
void map();
void zergslocation();
void burrowingzerglings();
void initWall();
void drawbox(int left,int top,int right,int bottom,int color);
void box1(int left,int top,int right,int bottom,
	int opendirection,int shadecolor,int mydelay);



/* ----------------- INIT AND DESTROY GRAPHICS MODE -----------------------*/
void initgraphix(){
int gd=DETECT;   /* request auto detection */
int gm;
int errcode;
  initgraph(&gd,&gm,"..\\bgi");
  errcode=graphresult();
  if (errcode!=grOk){
      printf("Graphics error : %s.\n",grapherrormsg(errcode));
      getch();
      exit(1);
  }
}
void destroygraphix(){
  closegraph();
}

/* ----------------------- DISPLAY PROGRAM NAME ---------------------------*/
void progname(){

//char p[8] = { 0xAA, 0x55, 0xAA, 0x34, 0xAA, 0x55, 0xAA, 0x55 };
//char p[8] =    { 0x33, 0x33, 0xCC, 0xCC, 0x33, 0x33, 0xCC, 0xCC };
//char p[8] =    { 0xF0, 0xF0, 0xF0, 0xF0, 0x0F, 0x0F, 0x0F, 0x0F };
//char p[8] =    { 0x00, 0x10, 0x28, 0x44, 0x28, 0x10, 0x00, 0x00 };
//char p[8] =    { 0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00 };
//char p[8] =    { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 };
//char p[8] =    { 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00 };
//char p[8] =    { 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00 };
//char p[8] =    { 0x00, 0x00, 0x22, 0x08, 0x00, 0x22, 0x1C, 0x00 };
//char p[8] =    { 0xFF, 0x7E, 0x3C, 0x18, 0x18, 0x3C, 0x7E, 0xFF };
//char p[8] =    { 0x00, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00 };
//char p[8] =    { 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00 };


  initgraphix();
  setbkcolor(BLACK);
  setfillstyle(SOLID_FILL,GREEN);
  //setfillpattern(p,BROWN);
  bar(193,170,462,240);

  setfillstyle(SOLID_FILL,BROWN);
  bar(193,223,462,240);

  setcolor(DARKGRAY);
  rectangle(193,223,462,240); // MIDDLE RECT

  setcolor(DARKGRAY);
  rectangle(191,168,464,242);   // TOP RECT


  setfillstyle(SOLID_FILL,RED);
  settextstyle(0,HORIZ_DIR,2);
  setcolor(BLACK);
  outtextxy(190,225,"in da Lost Temple");

  setcolor(WHITE);
  outtextxy(191,226,"in da Lost Temple");

  settextstyle(3,HORIZ_DIR,4);

  setcolor(LIGHTGREEN);
  outtextxy(215,177,"Mark & Dencie");

  settextstyle(0,HORIZ_DIR,1);
  //outtextxy(335,257,"TMNT");

  while(1){
	if (kbhit()){
	int c;
	   c = getch();
	   if (c == ESC ) exit(0);
	   else break;
	}
	settextstyle(2,HORIZ_DIR,4);
	setcolor(LIGHTBLUE);

	outtextxy(getmaxx()/2-66,410,"® press key to continue ¯");
	delay(90);

	setcolor(BLACK);
	outtextxy(getmaxx()/2-66,410,"® press key to continue ¯");
	delay(50);
  }
  //getch();
  destroygraphix();
  //exit(0);
  restorecrtmode();
  _setcursortype(_NOCURSOR);
  delay(400);
  box1(1,1,80,50,GOINGDOWN,RED,0);
  box1(2,2,79,49,GOINGDOWN,BROWN,0);
  box1(3,3,78,48,GOINGDOWN,BLACK,0);
}


/* ----------------- DISPLAY MENU wid TYPEWRITER EFFECTS --------------------*/
void display_atik_atik_Menu(void){
  _setcursortype(_NOCURSOR);
  delay(400);
  box1(6,5,75,7,GOINGDOWN,YELLOW,16);
  drawbox(6,5,75,7,YELLOW);
  textcolor(LIGHTGREEN|BLINK);
  gotoxy(17,6); cprintf(" ®®®®®®®® Mark & Dencie in da Lost Temple  ¯¯¯¯¯¯¯¯¯");delay(30);

  box1(6,8,75,16,GOINGDOWN,YELLOW,16);
  drawbox(6,8,75,16,YELLOW);
  textcolor(WHITE);
  gotoxy(8,9); cprintf("Dencie was lost in the big forest of Lost Temple - a popular ");delay(50);
  gotoxy(8,10); cprintf("WCG map (World Cyber Games) played by gamers of Starcraft:Broodwar");delay(50);
  gotoxy(8,11); cprintf("from different parts of the world.");delay(50);
  gotoxy(8,12); cprintf("Let's help Mark to find Dencie. Be aware there maybe lots");delay(10);
  gotoxy(8,13); cprintf("of zerglings burrowing or maybe a Lurker. Dont forget to bring a");delay(10);
  gotoxy(8,14); cprintf("detector or observer. Or scan it with your COMSAT.");delay(10);
  gotoxy(8,15); cprintf("Press s to begin scanning of the burrowing zerglings or lurkers.");delay(10);


  box1(26,19,56,21,GOINGDOWN,YELLOW,16); /* container */
  drawbox(26,19,56,21,YELLOW);
  textcolor(WHITE); gotoxy(29,20); cprintf(".: What do you want ? :.");

  box1(26,22,56,23+3,GOINGDOWN,YELLOW,40); /* menu container */
  drawbox(26,22,56,23+3,YELLOW);
  textcolor(LIGHTCYAN);
  gotoxy(startx,starty+5);typewriter_effects("þ Play the game          þ",5);
  gotoxy(startx,starty+6);typewriter_effects("þ Know the developers    þ",5);
  gotoxy(startx,starty+7);typewriter_effects("þ Exit                   þ",5);
  textbackground(BLACK);
  textcolor(YELLOW);gotoxy(37,47);typewriter_effects("Use arrow keys to move the selection...",10);

}

/* ------------------------- DISPLAY THE MENU ------------------------------*/
void displaymenu(void){
   textcolor(LIGHTCYAN);
   textbackground(BROWN);
   gotoxy(startx,starty+5);cprintf("þ Play the game          þ");
   gotoxy(startx,starty+6);cprintf("þ Know the developers    þ");
   gotoxy(startx,starty+7);cprintf("þ Exit                   þ");
}

/* ----------------------- INIT MAZE WALL ---------------------------------*/
void initWall(){
int cols1,rows;


  for(cols1=1;cols1<=25;cols1++){
     for(rows=1;rows<=25;rows++){
	matrix[cols1][rows] = 0;
     }
  }


  for(rows=2;rows<=10;rows++){
     matrix[2][rows] = 1;
  }
  for(rows=17;rows<=18;rows++){
     matrix[2][rows] = 1;
  }


  for(rows=10;rows<=16;rows++){
     matrix[3][rows] = 1;
  }


  for(rows=2;rows<=8;rows++){
     matrix[4][rows] = 1;
  }
  for(rows=16;rows<=18;rows++){
     matrix[4][rows] = 1;
  }


  for(rows=13;rows<=16;rows++){
     matrix[5][rows] = 1;
  }


  for(rows=4;rows<=6;rows++){
     matrix[6][rows] = 1;
  }
  for(rows=17;rows<=19;rows++){
     matrix[6][rows] = 1;
  }



  for(rows=8;rows<=10;rows++){
     matrix[7][rows] = 1;
  }
  for(rows=12;rows<=13;rows++){
     matrix[7][rows] = 1;
  }


  for(rows=6;rows<=8;rows++){
     matrix[8][rows] = 1;
  }


  for(rows=9;rows<=13;rows++){
     matrix[9][rows] = 1;
  }

  for(rows=15;rows<=17;rows++){
     matrix[9][rows] = 1;
  }


  for(rows=2;rows<=7;rows++){
     matrix[10][rows] = 1;
  }
  for(rows=19;rows<=20;rows++){
     matrix[10][rows] = 1;
  }



  for(rows=7;rows<=9;rows++){
     matrix[11][rows] = 1;
  }

  for(rows=13;rows<=15;rows++){
     matrix[12][rows] = 1;
  }
  for(rows=17;rows<=19;rows++){
     matrix[12][rows] = 1;
  }
  for(rows=1;rows<=5;rows++){
     matrix[12][rows] = 1;
  }

  matrix[12][1] = -1; // MAZE ENDING POINT

  for(rows=7;rows<=9;rows++){
     matrix[13][rows] = 1;
  }


  for(rows=9;rows<=13;rows++){
     matrix[14][rows] = 1;
  }


  for(rows=5;rows<=7;rows++){
     matrix[15][rows] = 1;
  }
  for(rows=15;rows<=17;rows++){
     matrix[15][rows] = 1;
  }


  for(rows=9;rows<=11;rows++){
     matrix[16][rows] = 1;
  }
  for(rows=13;rows<=14;rows++){
     matrix[16][rows] = 1;
  }


  for(rows=4;rows<=5;rows++){
     matrix[17][rows] = 1;
  }
  for(rows=7;rows<=9;rows++){
     matrix[17][rows] = 1;
  }
  for(rows=11;rows<=13;rows++){
     matrix[17][rows] = 1;
  }
  for(rows=15;rows<=17;rows++){
     matrix[17][rows] = 1;
  }


  for(rows=13;rows<=15;rows++){
     matrix[18][rows] = 1;
  }

  for(rows=2;rows<=7;rows++){
     matrix[19][rows] = 1;
  }

 // ROW


  for(cols1=2;cols1<=10;cols1++){
     matrix[cols1][2] = 1;
  }
  for(cols1=12;cols1<=19;cols1++){
     matrix[cols1][2] = 1;
  }


  for(cols1=6;cols1<=10;cols1++){
     matrix[cols1][4] = 1;
  }


  for(cols1=2;cols1<=4;cols1++){
     matrix[cols1][5] = 1;
  }
  for(cols1=12;cols1<=17;cols1++){
     matrix[cols1][5] = 1;
  }


  for(cols1=6;cols1<=8;cols1++){
     matrix[cols1][6] = 1;
  }


  for(cols1=10;cols1<=15;cols1++){
     matrix[cols1][7] = 1;
  }
  for(cols1=15;cols1<=19;cols1++){
     matrix[cols1][7] = 1;
  }


  for(cols1=4;cols1<=7;cols1++){
     matrix[cols1][8] = 1;
  }


  for(cols1=9;cols1<=11;cols1++){
     matrix[cols1][9] = 1;
  }
  for(cols1=13;cols1<=16;cols1++){
     matrix[cols1][9] = 1;
  }

  for(cols1=16;cols1<=19;cols1++){
     matrix[cols1][9] = 1;
  }

//  matrix[13][9] = -2;      // ZERGLINGS...


  for(cols1=2;cols1<=7;cols1++){
     matrix[cols1][10] = 1;
  }


  for(cols1=9;cols1<=16;cols1++){
     matrix[cols1][11] = 1;
  }
 // matrix[10][11] = -2;    // ZERGLINGS...
 // matrix[16][11] = -2;    // ZERGLINGS...


  for(cols1=3;cols1<=9;cols1++){
     matrix[cols1][13] = 1;
  }
  for(cols1=11;cols1<=14;cols1++){
     matrix[cols1][13] = 1;
  }
  for(cols1=16;cols1<=19;cols1++){
     matrix[cols1][13] = 1;
  }



  for(cols1=5;cols1<=9;cols1++){
     matrix[cols1][15] = 1;
  }
  for(cols1=11;cols1<=15;cols1++){
     matrix[cols1][15] = 1;
  }
  for(cols1=17;cols1<=18;cols1++){
     matrix[cols1][15] = 1;
  }


  for(cols1=3;cols1<=5;cols1++){
     matrix[cols1][16] = 1;
  }


  for(cols1=6;cols1<=9;cols1++){
     matrix[cols1][17] = 1;
  }
  for(cols1=12;cols1<=17;cols1++){
     matrix[cols1][17] = 1;
  }



  for(cols1=2;cols1<=4;cols1++){
     matrix[cols1][18] = 1;
  }

  for(cols1=6;cols1<=18;cols1++){
     matrix[cols1][19] = 1;
  }

  burrowingzerglings();          // NOTE: UNCOMMENT THIS TO GENERATE
  for(cols1=6;cols1<=18;cols1++){  //       BURROWING ZERGLINGS
     matrix[cols1][19] = 1;
  }

int blockx,blocky;
gotoxy(1,1);
window(30,10,50,30);
  textbackground(1);
  for(cols1=1;cols1<=20;cols1++){
    for(rows=1;rows<=20;rows++){
	if(matrix[cols1][rows] == 1 || matrix[cols1][rows] == -1
	   || matrix[cols1][rows] == -2 ){
	    gotoxy(cols1,rows);
	    textcolor(1);
	    cprintf(BLOCK);
	    delay(10);
	    //cprintf("%d",matrix[cols1][rows]);
	}
	else {
	    gotoxy(cols1,rows);
	    textcolor(0);
	    cprintf(BLOCK);
	    delay(10);
	    //cprintf("%d",matrix[cols1][rows]);
	}
	blocky++;
    }
    blockx++;
  }

}
/* ------ BURROWING ZERGLINGS/LURKERS IN RANDOM LOCATION... --------------*/
void burrowingzerglings(){
int nzergs=0;
int totalzergs = 10;
int xloc,yloc;

  randomize();
  while(nzergs!=totalzergs){

     xloc = random(30)+1;
     yloc = random(30)+1;
     if (matrix[xloc][yloc] == 1) {
	   matrix[xloc][yloc] = -2;
	   nzergs++;
     }

  }
}
/* ---------------------- ZERGS LOCATION  --------------------------------*/
void zergslocation(){
int cols1,rows;
int blockx,blocky;

gotoxy(1,1);
window(10,10,30,30);
  for(cols1=1;cols1<=20;cols1++){
    for(rows=1;rows<=20;rows++){
	if (matrix[cols1][rows] == -2 ){
	    gotoxy(cols1,rows);
	    textcolor(5);
	    cprintf("*");
	}
	blocky++;
    }
    blockx++;
  }
}
/* ----------------------------- MAZE MAP --------------------------------*/
void map(){
int cols1,rows;
int blockx,blocky;

gotoxy(1,1);
window(30,10,50,30);
  for(cols1=1;cols1<=20;cols1++){
    for(rows=1;rows<=20;rows++){
	if(matrix[cols1][rows] == 1 || matrix[cols1][rows] == -1 ||
	    matrix[cols1][rows] == -2 ){
	    gotoxy(cols1,rows);
	    textcolor(1);
	    cprintf(BLOCK);
	    //cprintf("%d",matrix[cols1][rows]);
	}
	else {
	    gotoxy(cols1,rows);
	    textcolor(0);
	    cprintf(BLOCK);
	    //cprintf("%d",matrix[cols1][rows]);
	}
	blocky++;
    }
    blockx++;
  }
}

/* ---------------------- DRAW OUTLINE BOX --------------------------------*/
void drawbox(int left,int top,int right,int bottom,int color){
register int ctr,ctr2;
char topLeftChar    = 'Ú';
char topRightChar   = '¿';
char bottomLeftChar = 'À';
char bottomRightChar= 'Ù';
char horizontalChar = 'Ä';
char verticalChar   = '³';

 textcolor(color);
 gotoxy(left,top);putch(topLeftChar);
 gotoxy(right,top);putch(topRightChar);
 gotoxy(left,bottom);putch(bottomLeftChar);
 gotoxy(right,bottom);putch(bottomRightChar);

 for(ctr=left+1;ctr < right;ctr++){
    gotoxy(ctr,top);putch(horizontalChar);
    gotoxy(ctr,bottom);putch(horizontalChar);
 }

 for(ctr=top+1;ctr<bottom;ctr++){
    gotoxy(left,ctr);putch(verticalChar);
    gotoxy(right,ctr);putch(verticalChar);
 }

}
/* -------------------------- DRAW SHADED BOX ------------------------------*/
void box1(int left,int top,int right,int bottom,int opendirection,int shadecolor,int mydelay){
register int i;
register int ctr,ctr2;
 textbackground(shadecolor);
 switch(opendirection){
   case GOINGDOWN: /* open downward */
	   for(ctr=top+1;ctr < bottom;ctr++) {
	      for(ctr2=left+1;ctr2<right;ctr2++){
	      gotoxy(ctr2,ctr); cprintf(" ");
	      }
	   delay(mydelay);
	   }
	   break;
   case GOINGLEFT: /* open to left*/
	  for(ctr=left+1;ctr < right;ctr++){
	      for(ctr2=top+1;ctr2<bottom;ctr2++){
		 gotoxy(ctr,ctr2);cprintf(" ");
	      }
	  delay(mydelay);
	  }
	  break;
   case GOINGRIGHT:
	 for(ctr=right+1;ctr > left;ctr--){
	    for(ctr2=top+1;ctr2<bottom;ctr2++){
	       gotoxy(ctr,ctr2);cprintf(" ");
	    }
	 delay(mydelay);
	 }

  }
}

/* -------------------- TYPEWRITER TEXT EFFECTS ----------------------------*/
void typewriter_effects(char *contentmessage,int d){
char *p;
  p = contentmessage;/*POINTER p POINTS TO STARTING ADRESS OF d contentmessage*/
  while(*p) {
    cprintf("%c",*p);delay(d);*p++;
  }
}
/* ---------------------HIGHLIGHT THE SELECTED CHOICE----------------------*/
void highlightChoice1(int selectedChoice){
      textcolor(LIGHTGREEN);
      switch(selectedChoice){
	 case 1:  gotoxy(startx,starty+5);cprintf("þ Play the game          þ");
		  break;
	 case 2:  gotoxy(startx,starty+6);cprintf("þ Know the developers    þ");
		  break;
	 case 3:  gotoxy(startx,starty+7);cprintf("þ Exit                   þ");
		  break;
      }
}

/* --------------------- RETURN THE SELECTED CHOICE -----------------------*/
int getChoice(void){
int ch,i;

   displaymenu();
   highlightChoice1(choiceID);
   while(ch!=13){
     ch=getch();
     /*    printf("%d",ch); */
      switch(ch){
	case ARROWUP :                  /* arrow up */
		      choiceID--;
		      if (choiceID<1) {
				choiceID=3;
		      }
		       break;
	case ARROWDOWN :                /* arrow down */
		       choiceID++;
		       if (choiceID>3) {
			 choiceID=1;
		       }
		       break;
     }
     displaymenu();
     highlightChoice1(choiceID);
  }
  return choiceID;
}

/* ---------------------- MAZE MAIN PROGRAM --------------------------------*/
void main() {
int x1;
int y1;
int r,cl;
int isX;
int choice;

  progname();
  _setcursortype(_NOCURSOR);
  textmode(64);
  textbackground(BLUE);
  for(;;){
       choiceID = 1;
       display_atik_atik_Menu();
       choice = getChoice();
       switch(choice){
	  case 1:
		playMaze();
		break;
	  case 2:
		viewGameDevelopers();
		break;
	  case 3:
		exit(0);
		break;

       }
  }

}

/* ---------------------- MAZE MAIN CONTROLLER -----------------------------*/
void playMaze(){
int c;
int x = 10;
int y = 21;
int readytomove = 0;
int startmove = 1;
int direction;
  box1(3,3,78,48,GOINGDOWN,BLACK,5);

  textcolor(WHITE);
  gotoxy(41,9); cprintf(" this is Dencie");
  gotoxy(39,30); cprintf(" this is Mark");
  gotoxy(30,45); textcolor(RED); cprintf("Press ESC to back to Main...");
  initWall();
  char s;

 // zergslocation();

  gotoxy(12,1); textcolor(YELLOW|BLINK); cprintf("");
  gotoxy(x,y-1); textcolor(WHITE); cprintf("");

  while((c=getch())!=27 && startmove!=0) {
  map();

     gotoxy(12,1); textcolor(YELLOW|BLINK); cprintf("");
     switch(c){
	  case 80:  // down
		y++;
		direction = fromDown;
		break;
	  case 75:  // left
		x--;
		direction = fromLeft;
		break;
	  case 72:  // up
		y--;
		direction = fromUp;
		break;
	  case 77:  // right
		x++;
		direction = fromRight;
		break;
	  case 115:
		zergslocation();
		break;
     }
     if ((matrix[x][y])==1 || (matrix[x][y])== -1 ||
	   (matrix[x][y]) == -2 ){
	  gotoxy(x,y); textcolor(15); cprintf("");
	  readytomove = 1;
	  if ((matrix[x][y])== -1) { // REACH ITS MAZE ENDING PT.
	      window(1,1,80,50);
	      box1(30,18,49,22,GOINGLEFT,BROWN,10);
	      drawbox(30,18,49,22,YELLOW);
	      gotoxy(32,19); textcolor(WHITE|BLINK); cprintf("CONGRATULATIONS!");
	      gotoxy(33,20); textcolor(YELLOW); cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	      gotoxy(34,21); textcolor(GREEN); cprintf("Youve made it!");
	      startmove = 0;
	  }
	  if ((matrix[x][y])== -2) { // ZERGLINGS ATTACKED
	      window(1,1,80,50);
	      box1(30,18,49,22,GOINGLEFT,BROWN,10);
	      drawbox(30,18,49,22,YELLOW);
	      gotoxy(32,19); textcolor(WHITE|BLINK); cprintf("ZERGLINGS ATTACK");
	      gotoxy(33,20); textcolor(YELLOW); cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	      gotoxy(34,21); textcolor(GREEN); cprintf("You failed!");
	      startmove = 0;
	  }

     }
     else {
       if(readytomove){
	 switch(direction){
	    case fromDown:
			y--;
			break;
	    case fromUp  :
			y++;
			break;
	    case fromLeft :
			x++;
			break;
	    case fromRight :
			x--;
			break;
	 }
	 gotoxy(x,y); textcolor(RED); cprintf("");
       }
     }


     //gotoxy(20,22); printf("x:%d, y:%d  ",x,y);
     //gotoxy(20,23); printf("px:%d, py:%d  ",prevx,prevy);
     //gotoxy(20,24); printf("matrix[%d][%d] : %d  ",x,y,matrix[x][y]);

   }//endwhile
   while(1){
     c=getch();
     if (c==ESC) break;
   }
   window(1,1,80,50);
   box1(3,3,78,48,GOINGDOWN,BLACK,5);
}
/* ----------------  DISPLAY THE SOFTWARE DEVELOPERS -----------------------*/
void viewGameDevelopers(void) {
char str[9];

   box1(3,3,78,48,GOINGDOWN,BLACK,5);
   delay(300);
   box1(25,13,57,35,GOINGDOWN,YELLOW,8); /* container */
   box1(25,13,59,37,GOINGDOWN,BLACK,0);  /* dropshadow */
   box1(25,13,57,35,GOINGLEFT,YELLOW,0); /* container */
   drawbox(25,13,57,35,YELLOW);

   gotoxy(startx+7,starty-5); textcolor(YELLOW);typewriter_effects(".: About :.",5);delay(100);
   textcolor(WHITE);
   gotoxy(startx+4,starty-3); typewriter_effects(" .: Maze Game :. ",2);delay(50);
   gotoxy(startx+3,starty-1); typewriter_effects(" Version 2.25.2004",2);delay(50);
   gotoxy(startx,starty+1); textcolor(LIGHTRED); typewriter_effects("   Copyright(c) 2005",5);delay(50);
   gotoxy(startx,starty+2);typewriter_effects(" (Year of the Chicken)",2);delay(50);
   gotoxy(startx-3,starty+4); textcolor(WHITE);typewriter_effects(" .:Jastis Legs(Pinoy version):.",2);delay(50);
   gotoxy(startx,starty+5); textcolor(LIGHTGREEN); typewriter_effects(".:arman as Lipstik-Man:. ",2);delay(50);
   gotoxy(startx,starty+6); typewriter_effects("   .:Mark as Mulawin:.",2);delay(50);
   gotoxy(startx,starty+7); typewriter_effects("  .:Eunice as KrysTala:.",2);delay(50);
   gotoxy(startx,starty+8); cprintf(" .:Yulin as Wonder Boy:.");delay(50);
   gotoxy(startx+1,starty+9); cprintf(" .:Dyncie as Bintong:. ");delay(50);
   gotoxy(startx-3,starty+10); cprintf(" .:Janus as Boboy Salongga:. ");delay(50);
   gotoxy(startx-3,starty+12);textcolor(YELLOW);cprintf("You know the speed of light,");delay(50);
   gotoxy(startx-3,starty+13);textcolor(YELLOW);cprintf("   so whats the speed of dark?");delay(50);
   getch();
  //exit(0);
   box1(24,12,60,40,GOINGDOWN,BLACK,5); /* container */
}
