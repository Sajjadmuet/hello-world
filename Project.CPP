	#include"graphics.h"
	#include"conio.h"
	#include"iostream.h"
	#include"process.h"
	#include"dos.h"
	#include"ctype.h"
	#include"string.h"
	#include"stdlib.h"
 //no changes
	////////////////// FUNCTION DECLARATIONS //////////////////
	void graphmode();
	void demo();
	void mainframe();
	void drawsepa(int,int,int,int);
	void blink(int,int,char*);
	void flapp(int,int);
	void word(char*,int);
	void drag(char[],int);
	//// EXTERNAL VARIABLES ////
	int arrowposi=350;
	char mon[16][12]={"0 RS","1000 RS","2000 RS","3000 RS","5000 RS","10000 RS","20000 RS","40000 RS","80000 RS",
	"160000 RS","320000 RS","640000 RS","1250000 RS","2500000 RS","5000000 RS","10000000 RS"};
	int total=0;
	char name[30];

	class ellipses     /// MAIN CLASS
	{
	public:
	void ellpse(int x,int y)
	{
	setcolor(WHITE);
	ellipse(x,y,0,360,7,9);
	setcolor(BLACK);
	ellipse(x,y,0,360,6,8);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x+1,y+1,BLACK);
	setcolor(WHITE);
	ellipse(x+1,y+1,0,360,6,8);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(x+1,y+1,WHITE);
	}
	void abcd()
	{
	setcolor(8);
	settextstyle(11,0,5);
	outtextxy(22,396,"A");
	outtextxy(262,396,"B");
	outtextxy(22,426,"C");
	outtextxy(262,426,"D");
	}
	};

	class windows 			// GRAPHICS MAIN CLASS
{
	protected:
	int x,y,xLength,yLength;

	public:

	windows()

	{ x=0; y=0; xLength=0; yLength=0;}

	windows(int xx,int yy,int x1,int y1)
	{
	x=xx;   y=yy;   xLength=x1;   yLength=y1;
	}

	void drawgraybox()
	{
		 setcolor(WHITE);
		 setcolor(DARKGRAY);
		 rectangle(x+1,y+1,x+xLength+1,y+yLength+1);
		 setfillstyle ( SOLID_FILL,LIGHTGRAY);
		 bar(x+1, y+1, x+xLength,y+yLength);
		 setfillstyle ( SOLID_FILL,1);
		 bar(x+3 ,y+3 ,x+xLength-3,y+20);
		 }


	void drawmoneybox()
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	setcolor(DARKGRAY);
	rectangle(x+1,y+1,x+xLength+1,y+yLength+1);
	setfillstyle ( SOLID_FILL,LIGHTGRAY);
	bar(x+1, y+1, x+xLength,y+yLength);
	setfillstyle ( SOLID_FILL,1);
}
	void listmoney();


};

	class textblocks:private windows   ///  DERIVED OF class windows
{
	public:

	textblocks(int a,int b,int c,int d): windows(a,b,c,d) {}

	void drawtextbox(char opt[])
	{
		setcolor(WHITE);
		rectangle(x,y,x+xLength,y+yLength);
		setcolor(BLACK);
		rectangle(x,y,x+xLength-1,y+yLength-1);
		setcolor(LIGHTGRAY);
		rectangle(x+1,y+1,x+xLength-1,y+yLength-1);
		setfillstyle(SOLID_FILL,WHITE);
		bar(x+1,y+1,x+xLength-2,y+yLength-2);
		setcolor(8);
		settextstyle(2,0,4);
		moveto(x+2,y+2);
		outtext(opt);
	}
};


	class options:public ellipses   // Derived of CLASS  ellipses
	{
	   private:

		char ques[100];
		char opt1[30];
		char opt2[30];
		char opt3[30];
		char opt4[30];
		char option;
		char take;

	void boxx();
	void boxxw();
	void congr();
	void lockin(int x,int y,int xle,int yle,int a,int b)
	{
	retextbox();
	rectangle(x+1,y+1,x+xle-1,y+yle-1);
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	bar(x+1,y+1,x+xle-2,y+yle-2);
	setcolor(LIGHTCYAN);
	ellipse(a,b,0,360,5,7);
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	floodfill(a+1,b+1,LIGHTCYAN);
	setcolor(8);
	settextstyle(2,0,4);
	outtextxy(40+2,390+2,opt1);
	outtextxy(280+2,390+2,opt2);
	outtextxy(40+2,420+2,opt3);
	outtextxy(280+2,420+2,opt4);
	abcd();
	settextstyle(7,0,1);
	outtextxy(80,450,"PRESS ENTER TO CONTINUE");
	}
	void textbox(int x,int y, int xLength, int yLength,char opt[])
	{
	setcolor(WHITE);
	rectangle(x,y,x+xLength,y+yLength);
	setcolor(BLACK);
	rectangle(x,y,x+xLength-1,y+yLength-1);
	setcolor(LIGHTGRAY);
	rectangle(x+1,y+1,x+xLength-1,y+yLength-1);
	setfillstyle(SOLID_FILL,WHITE);
	bar(x+1,y+1,x+xLength-2,y+yLength-2);
	setcolor(8);
	settextstyle(2,0,4);
	moveto(x+2,y+2);
	outtext(opt);
	}
	void retextbox()
	{
	textbox(40,390,130,15,opt1);
	textbox(280,390,130,15,opt2);
	textbox(40,420,130,15,opt3);
	textbox(280,420,130,15,opt4);
	ellpse(25,398);
	ellpse(265,398);
	ellpse(25,428);
	ellpse(265,428);
	abcd();
	}

	   public:


void getvalue(char qq[],char o1[],char o2[],char o3[], char o4[],char op)
{
strcpy(ques,qq); strcpy(opt1,o1); strcpy(opt2,o2); strcpy(opt3,o3);
strcpy(opt4,o4); option=op;
}


void sendopt()
{
setcolor(7);
settextstyle(2,0,4);
moveto(20,358);
outtext(ques);
textbox(40,390,130,15,opt1);
textbox(280,390,130,15,opt2);
textbox(40,420,130,15,opt3);
textbox(280,420,130,15,opt4);
ellipses ellipse1,ellipse2,ellipse3,ellipse4;
ellipse1.ellpse(25,398);
ellipse2.ellpse(265,398);
ellipse3.ellpse(25,428);
ellipse4.ellpse(265,428);
ellipse1.abcd();
}


	void lock();

	void retun()
	{

		if (option==take)
		{
		cleardevice();
		setbkcolor(BLACK);
		congr();
		delay(300);
		cleardevice();
		boxx();
		settextstyle(5,0,2);
		setcolor(3);
		moveto(250,180);
		outtext("You are right.");
		moveto(200,210);
		outtext("You won");
		moveto(300,210);
		outtext(mon[++total]);
		flapp(575,100);
		moveto(250,248);
		setcolor(3);
		outtext("WELL DONE BUDDY!");
		getch();
		}
		else
		{
		setbkcolor(BLACK);
		cleardevice();
		boxxw();
		settextstyle(5,0,2);
		setcolor(3);
		moveto(220,180);
		outtext("Sorry you are wrong.");
		moveto(180,210);
		outtext("you could win only ");
		moveto(380,210);
		outtext(mon[total]);
		flapp(575,90);
		setcolor(3);
		moveto(220,248);
		outtext("Want to play again (y/n):");
		gotoxy(60,17);
		char want;
		cin >> want;
		want=tolower(want);
			if (want=='n')
		       {
   setcolor(0);
   for(int i=0;i<=220;i++)
   {
   rectangle(0+i,0+i,640-i,480-i);
   delay(10);
   }
   for(i=0;i<=220;i++)
   {
   rectangle(100+i,100,540-i,380);
   delay(8);
   }
exit(1);               }
			else mainframe();
			closegraph();
		}

	}

};








//////////////       FUNCTION DEFINITION OF CLASS windows
void windows::listmoney()
{
	char money[16][9]={"0","1000","2000","3000","5000","10000","20000","40000","80000",
	"160000","320000","640000","1250000","2500000","5000000","10000000"};
	int a=70;
	setcolor(BLUE);
	settextstyle(3,0,2);
	outtextxy(530,30,"Rs");
	setcolor(BROWN);
	settextstyle(7,0,1);
	for(int c=15;c>0;c--)
	{
	outtextxy(480,a,money[c]);
	delay(150);
	a+=20;
	}
	char *arrow="<---";
	setcolor(BLUE);
	settextstyle(7,0,1);
	outtextxy(570,arrowposi,arrow);
	arrowposi-=20;
	}


//////////////       FUNCTION DEFINITIONS OF CLASS options     ////////////

void options::boxx()
{
	int k=320;
	for(int j=1;j<150;j++)
		{
		setcolor(0);
		rectangle(140-2,j-2,141+400,j-2+150);
		rectangle(120-2,k+2,121+400,k+2+150);
		delay(15);
		setcolor(5);
		rectangle(140,j,140+400,j+150);
		rectangle(120,k,120+400,k+150);
		k--;
		}
		line(140,150,120,174);
		line(540,150,520,174);
		line(140,300,120,324);
		line(540,300,520,324);
	}
void options::boxxw()
{
		int k=270;
		for(int j=3;j<150;j++)
		{
		setcolor(0);
		rectangle(j-2,140-2,j-2+400,141+150);
		rectangle(k+2,160-2,k+2+400,161+150);
		delay(15);
		setcolor(5);
		rectangle(j,140,j+400,140+150);
		rectangle(k,160,k+400,160+150);
		k--;
		}
		line(150,140,125,160);
		line(550,140,525,160);
		line(550,290,525,310);
		line(150,290,125,310);
	}

void options::congr()
{
		char cong1[]="Congrat";
		char cong2[]="ulations!";
		int j=480;
		settextstyle(4,0,6);

		for(int i=0;i<155;i++,j--)
		{
		delay(1);
		setcolor(0);
		outtextxy(i-2,200,cong1);
		outtextxy(j+2,200,cong2);
		setcolor(9);
		outtextxy(i,200,cong1);
		outtextxy(j,200,cong2);

		}
		}
void options::lock()
{
	char vari;
	settextstyle(7,0,2);
	setcolor(7);
	lockin(40,390,130,15,25,398);
	take='a';
	while((vari=getch())!='\r')
	{
		if (vari==80)
		{lockin(40,420,130,15,25,428);
		 take='c';}
		 else if (vari==72)
		{lockin(40,390,130,15,25,398);
		take='a';}
		else if (vari==77)
		{ lockin(280,420,130,15,265,428);
		take='d'; }
		if(vari==75)
		{lockin(280,390,130,15,265,398);
		 take='b';}
		else if(vari==27)
		exit(1);
	}

}

void main()     ///////////////// START OF THE MAIN FUNCTION
{
graphmode();
cleardevice();
demo();
cleardevice();
settextstyle(11,0,5);
windows graybox(180,170,300,150);
graybox.drawgraybox();
setbkcolor(CYAN);
setcolor(7);
outtextxy(185,178,"CONNECT");
setcolor(8);
outtextxy(210,224,"User'S name");
outtextxy(210,284,"PASSWORD");
textblocks textbox1(320,220,140,15);
textbox1.drawtextbox('\0');
settextstyle(11,0,5);
outtextxy(324,224,"Admin(46,36,32)");
textblocks textbox2(320,280,140,15);
textbox2.drawtextbox('\0');
settextstyle(11,0,5);
char pass[]="funtime";
char passwo[16];
char ch;
int j=0;
int i=324;
while((ch=getch())!='\r')
{
setcolor(8);
passwo[j]=ch;
outtextxy(i+=7,284,"*");
j++;
if(ch==8)
{
setcolor(WHITE);
outtextxy(i,284,"*");
outtextxy(i-7,284,"*");
i-=14;
j-=2;
}
}
passwo[j]='\0';
if (strcmpi(pass,passwo)==0)
mainframe();

else
{
cleardevice();
windows graybox(180,170,300,150);
graybox.drawgraybox();
setbkcolor(CYAN);
settextstyle(7,0,1);
outtextxy(206,240,"SORRY! WRONG PASSWORD");
getch();
setcolor(0);
   for(int i=0;i<=220;i++)
   {
   rectangle(0+i,0+i,640-i,480-i);
   delay(10);
   }
   for(i=0;i<=220;i++)
   {
   rectangle(100+i,100,540-i,380);
   delay(8);
   }
exit(1);
}
}
//*************************FUNCTION DEFINITIONS*************************

void mainframe()
{
const int MAX=20;
int randomn[15];
randomize();
   int m=-1;
   while(m<14)
{
   ++m;
   randomn[m]=(rand()%MAX);
   for(int j=0; j<m; j++)
   {
   if (randomn[m]==randomn[j])
   m-=2;
   }
}
total=0;
arrowposi=350;
char pass[2];
char jj[2]={8};
windows graybox(150,170,330,150);
graybox.drawgraybox();
setbkcolor(CYAN);
settextstyle(7,0,1);
outtextxy(180,210,"WELCOME! TO OUR PROJECT");
settextstyle(11,0,5);
outtextxy(165,258,"Enter your name");
textblocks textbox(290,253,180,20);
textbox.drawtextbox('\0');
setcolor(8);
int j=0;
int i=290;
while((pass[0]=getch())!='\r')
{
pass[1]='\0';
setcolor(8);
settextstyle(11,0,5);
outtextxy(i+=8,260,pass);
name[j]=toupper(pass[0]);
j++;
if(pass[0]==8)
{
settextstyle(11,0,5);
setcolor(WHITE);
outtextxy(i,260,jj);
outtextxy(i-4,260,pass);
outtextxy(i-5,260,pass);
outtextxy(i-6,260,pass);
outtextxy(i-8,260,pass);
i-=16;
j-=2;
}
name[j]='\0';
}
options questions[MAX];
questions[0].getvalue("Who is the Information Minister of pakistan?","Raza Rabbani.","Nisar Memon.","Sartaj Aziz.","Shauquat Aziz.",'b');
questions[1].getvalue("Which computer bus is bi-directional?","Control bus.","Address bus.","Expansion bus.","Data bus.",'d');
questions[2].getvalue("What is the value of e(eita) in Mathematics?","2.72887","2.73828","2.71828","2.7818",'c');
questions[3].getvalue("Which one is the major constituent of Bones?","Calcium.","Magnesium.","Phosphorous.","Iron.",'a');
questions[4].getvalue("Which one of the following C++ does not support?","Constructors.","Byte code.","Pointers.","Destructors.",'b');
questions[5].getvalue("Which football team has three player's name with R?","ENGLAND","AUSTRALIA","BRAZIL","ARGENTINA",'c');
questions[6].getvalue("Choose the person who discoverd INDIA? ","VASCO-DE-GAMA","MARCOPOLO","COMUMBUS","ALEXANDER",'a');
questions[7].getvalue("When the man first reached the moon?","1955","1959","1965","1969",'d');
questions[8].getvalue("Ratio of change in 'V' and 'I' is which resistance?","Static","Dynamic","Average","Fixed",'b');
questions[9].getvalue("Which is the longest day of the Year? ","21st june","22nd june","21st july","22nd july",'a');
questions[10].getvalue("Which city is biggest Urban population in the World?","NewYork","Paris","Tokyo","Karachi",'c');
questions[11].getvalue("Who won the Cricket World cup of 1996? ","ENGLAND","SRILANKA","AUSTRALIA","PAKISTAN",'b');
questions[12].getvalue("When did Pakistan test the Nuclear Bomb? ","27th May 1998","27th May 1999","28th May 1998","28th May 1999",'c');
questions[13].getvalue("The word Delta    is a word of which language? ","Greek","Latin","English","French",'a');
questions[14].getvalue("How many girls are in our class? ","Eight","Nine","Ten","Eleven",'b');
questions[15].getvalue("How many people died in the recent bomb blast in Bali(Indonesia)?","Ten","Fifty","Hundred","Two hundred",'d');
questions[16].getvalue("Where will the 2003 Cricket World Cup held?","Australia","India","South Africa","Newzealand",'c');
questions[17].getvalue("The richest person of Asia A.R Rehman is on which rank?","second","fifth","ninth","tenth",'d');
questions[18].getvalue("Three famous Khans are in which film industry?","Software wood","Bolly wood","Lolly wood","Holly wood",'b');
questions[19].getvalue("When the Britishers opened the East India Company","1835","1840","1850","1860",'a');


for(int y=0;y<15;y++)
{
cleardevice();
windows moneybox(470,5,150,465);
moneybox.drawmoneybox();
moneybox.listmoney();
drawsepa(475,400,130,HORIZ_DIR);
blink(190,40,"WHO");
blink(140,100,"WILL BE");
blink(190,160,"THE");
blink(100,220,"MILLIONAIRE");
windows graybox2(10,350,450,120);
graybox2.drawgraybox();
questions[*(randomn+y)].sendopt();
questions[*(randomn+y)].lock();
questions[*(randomn+y)].retun();
}
}

void graphmode()
{
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode,"c:\\tc\\bgi");
}

void drawsepa(int x, int y, int length,int diraction)
{
	setcolor(DARKGRAY);
	if(diraction==HORIZ_DIR)
	     {	line(x,y,x+length,y);
		line(x,y+30,x+length,y+30);
		line(x,y+60,x+length,y+60);}
	else
		line(x,y,x,y+length);

	setcolor(WHITE);
	if(diraction==HORIZ_DIR)
	     {  line(x,y+1,x+length,y+1);
		line(x,y+31,x+length,y+31);
		line(x,y+61,x+length,y+61);}
	else
		line(x+1,y,x+1,y+length);
	settextstyle(11,0,5);
	setcolor(BLUE);
	outtextxy(x+5,y+15,name);
	outtextxy(x+5,y+45,mon[total]);
}



void blink(int x,int y,char*word)
{
settextstyle(1,0,6);
setcolor(WHITE);
outtextxy(x,y,word);
delay(600);
setcolor(11);
outtextxy(x,y,word);
}
void flapp(int x,int y)
	{
	settextstyle(3,0,1);
	for (int  j=5;j<46;j+=5)
		{
		sound(150*j);
		delay(100);
		nosound();
		}
	for (j=0;j<50;j++)
		{
		setcolor(14);
		moveto(x-25,y-10);
		outtext("1000");
		ellipse(x,y,0,360,50,j);
		ellipse(x,y,0,180,50,j+5);
		delay(15);
		setcolor(0);
		ellipse(x,y,0,360,50,j);
		ellipse(x,y,0,180,50,j+5);
		}
		setcolor(14);
		moveto(x-25,y-10);
		outtext("1000");
		for (j=50;j>0;j--)
		{
		setcolor(14);
		moveto(x-25,y-10);
		outtext("1000");
		ellipse(x,y,0,360,50,j);
		ellipse(x,y,180,360,50,j+5);
		delay(15);
		setcolor(0);
		ellipse(x,y,0,360,50,j);
		ellipse(x,y,180,360,50,j+5);
		}
	setcolor(14);
	ellipse(x,y,0,360,50,25);
	ellipse(x,y,0,180,50,30);
	moveto(x-25,y-10);
	outtext("1000");
	}

void demo()
{
setcolor(13);
		int dist=8;
		int dela=5;
		rectangle(20,160,620,220);
		setcolor(9);
		rectangle(40,130,620,220);
		int a,p;
		a=getpixel(21,160);
		p=getpixel(41,130);
		cleardevice();
		delay(1500);

char who[28][2]={"W","h","o"," ","W","i","l","l"," ","B","e"," ","T","h","e"
," ","M","i","l","l","i","o","n","A","i","r","e"};

	int b=80;
	for(int i=0;i<28;i++)
	{
	for(int j=10;j>3;j--)
	{
	settextstyle(7,0,j);
	setcolor(LIGHTCYAN);
	moveto(b,210);
	outtext(who[i]);
	delay(100);
	settextstyle(7,0,j);
	setcolor(0);
	moveto(b,210);
	outtext(who[i]);
	}
	settextstyle(7,0,j);
	setcolor(LIGHTCYAN);
	moveto(b,210);
	outtext(who[i]);
	if(who[i][0]=='i' || who[i][0]=='l' || who[i][0]=='r')
	b+=15;
	else
	b+=18;
	}
	for(int  j=40;j<=593;j++)
		{
		delay(5);
		putpixel(j,190,a);
		}
		for(j=190;j<=270;j++)
		{
		delay(5);
		putpixel(593,j,a);
		}
		for(j=593;j>=40;j--)
		{
		delay(5);
		putpixel(j,270,a);
		}
		for(j=270;j>=190;j--)
		{
		delay(6);
		putpixel(40,j,a);
		}

	       b=320;
	       int l=320;
	       for(int c=320;c<=440;c++,b++)
	       {
	       delay(dela);
	       putpixel(b,c,p);
	       putpixel(l,c,p);
	       putpixel(b+1,c-dist,p);
	       putpixel(l-1,c-dist,p);
	       l--;
	       }
	       c=440;
	       for(int x=200, y=440;x>=5;x--,y++)
	       {
	       delay(dela);
	       putpixel(x,c,p);
	       putpixel(y,c,p);
	       putpixel(x,c-dist,p);
	       putpixel(y,c-dist,p);
	       }
	       c=635;
	       b=5;
	       for( x=440;x>=20;x--)
	       {
	       delay(dela);
	       putpixel(c,x,p);
	       putpixel(b,x,p);
	       putpixel(c-dist,x,p);
	       putpixel(b+dist,x,p);
	       }
	       c=20;
	       for( x=5, y=635;x<=200;x++,y--)
	       {
	       delay(dela);
	       putpixel(x,c,p);
	       putpixel(y,c,p);
	       putpixel(x,c+dist,p);
	       putpixel(y,c+dist,p);
	       }
	       b=200,l=440;
	       for( c=20;c<=140;c++,b++)
	       {
	       delay(dela);
	       putpixel(b-1,c+dist,p);
	       putpixel(l+1,c+dist,p);
	       putpixel(b,c,p);
	       putpixel(l,c,p);
	       l--;
	       }
	       delay(3000);
	       settextstyle(7,1,2);
		cleardevice();
		for (int m=-240;m<100;m++)
		{
		moveto(2,m);
		setcolor(11);
		outtext("WHO WILL BE THE MILLIONAIRE?");
		moveto(2,m-1);
		setcolor(0);
		outtext("WHO WILL BE THE MILLIONAIRE?");
		}
		for (int n=102;n>19;n--)
		{
		moveto(2,n);
		setcolor(11);
		outtext("WHO WILL BE THE MILLIONAIRE?");
		moveto(2,n);
		setcolor(0);
		outtext("WHO WILL BE THE MILLIONAIRE?");
		}
		moveto(2,20);
		setcolor(11);
		outtext("WHO WILL BE THE MILLIONAIRE?");
		delay(1000);
		word("made by",120);
		delay(1000);
		word("02SW46",240);
		delay(1000);
		word("02SW36",300);
		delay(1000);
		word("02SW32",360);
		settextstyle(3,0,1);
		flapp(550,80);
		delay(2000);
		cleardevice();
		flapp(320,200);
		flapp(440,200);
		flapp(200,200);
		flapp(560,200);
		flapp(80,200);
		int column=5;
		settextstyle(8,0,5);
			drag("You",column);
			column+=105;
			drag("Can be",column);
			column+=175;
			drag("The",column);
			column+=100;
			drag("Million",column);
			column+=160;
			drag("Aire",column);
			for (int r=0;r<100;r++)
			{
			setcolor(11);
			moveto(160,r+2);
			outtext("BEST OF LUCK!");
			delay(10);
			moveto(160,r);
			setcolor(0);
			outtext("BEST OF LUCK!");
			}
			moveto(160,r+2);
			setcolor(11);
			outtext("BEST OF LUCK!");
			delay(2000);
	       }


void word(char*my ,int posi)
{
settextstyle(7,0,4);
setcolor(DARKGRAY);
moveto(200,posi);
outtext(my);
settextstyle(7,0,5);
setcolor(13);
moveto(200,posi);
outtext(my);
}


void drag(char str[],int column)
		{
		for(int k=550;k>column;k--)
			{
			delay(2);
			setcolor(11);
			moveto(k,300);
			outtext(str);
			setcolor(0);
			moveto(k+4,300);
			outtext(str);
			}
		}



