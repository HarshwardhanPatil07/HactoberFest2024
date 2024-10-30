#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

char ch, sc[10];
int maxx, maxy, gridx, gridy;
int gd=DETECT, gm;
int score, rep=0, death, dir, dark=0, t=300;
int map[20][19];
int x=9, y=14, x1=7, y1=8, x2=11, y2=8, x3= 7, y3=10, dir=0, st=120, end=60;
int tx2, ty2, tx3, ty3, r3;
float offset, octave[7]={130.81,146.83,164.81,174.61,196,220,246.94};

void kill();

void initialize()
{
	int i, j;
	int m[20][19]={
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0},
{0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0},
{0,0,0,0,1,0,0,0,2,0,2,0,0,0,1,0,0,0,0},
{0,1,1,1,1,0,2,2,2,2,2,2,2,0,1,1,1,1,0},
{0,1,0,0,1,0,2,0,0,2,0,0,2,0,1,0,0,1,0},
{0,1,1,1,1,0,2,2,2,2,2,2,2,0,1,1,1,1,0},
{0,1,0,0,1,0,2,0,2,0,2,0,2,0,1,0,0,1,0},
{0,1,1,1,1,0,2,2,2,2,2,2,2,0,1,1,1,1,0},
{0,0,0,0,1,0,2,0,0,0,0,0,2,0,1,0,0,0,0},
{0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
{0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0},
{0,1,1,0,1,1,1,1,1,2,1,1,1,1,1,0,1,1,0},
{0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0},
{0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0},
{0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
	for (i=0; i<20; i++)
		for (j=0; j<19; j++)
			map[i][j]= m[i][j];
	
	score= 0, death=0, dark=0;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	maxx=getmaxx();
	maxy=getmaxy();
	setviewport(0,0,maxx,maxy,1);
	gridx=ceil(maxx/19);
	gridy=ceil(maxy/20);
	offset=(maxx%19)/2;
}

void initpos()
{
	x=9, y=14, x1=7, y1=8, x2=11, y2=8, x3= 7, y3=10, dir=0, st=120, end=60;
	tx2=14, ty2=14, r3=0;
}

void start()
{
	int i, n;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	sector(maxx/2, maxy/2-50, 330, 30, 20, 20);
	outtextxy(maxx/2-25, maxy/2, "PacMan");
	outtextxy(maxx/2-84, maxy-50, "Press any key to start");
	for(i=0;i<30;i++)
	{
		n=random(6);
		sound(octave[n]*4);
		delay(50);
	}
	nosound();
	getch();
	sound(octave[6]*2);
	delay(15);
	nosound();
	cleardevice();
	outtextxy(maxx/2-42, 120, "INSTRUCTIONS");
	outtextxy(maxx/2-130, 180, "Your aim is to eat all the pellets");
	outtextxy(maxx/2-120, 220, "But be careful! You must avoid");
	outtextxy(maxx/2-123, 240, "the ghosts trying to catch you!");
	outtextxy(maxx/2-116, 300, "Use WASD to change directions");
	outtextxy(maxx/2-105, 185, "Modified by CM first batch boys");
	outtextxy(maxx/2-96, maxy-50, "Press any key to continue");
	getch();
	sound(octave[6]*2);
	delay(15);
	nosound();		
}

void dif()
{
	char c='M';
	while(c!=' ')
	{
	setcolor(YELLOW);
	cleardevice();
	outtextxy(maxx/2-42, 100, "LEVEL THE WAY YOU WANT");
	outtextxy(maxx/2-200, 130, "Choose the speed at which the game progresses");
	outtextxy(maxx/2-42, 170, "[S] Slow");
	outtextxy(maxx/2-42, 190, "[M] Medium");
	outtextxy(maxx/2-42, 210, "[F] Fast");
	outtextxy(maxx/2-42, 240, "[X] Xtreme");
	if(c=='s'||c=='S')
	{
		outtextxy(maxx/2-58, 280, "Current: Slow");
	}
	else if(c=='m'||c=='M')
	{
		outtextxy(maxx/2-64, 280, "Current: Medium");
	}
	else if(c=='f'||c=='F')
	{
		outtextxy(maxx/2-58, 280, "Current: Fast");
	}
	else if(c=='x'||c=='X')
	{
		outtextxy(maxx/2-64, 280, "The Xtreme Limited Edition");
	}
	outtextxy(maxx/2-96, maxy-50, "Press Spacebar to continue");
	c=getch();
	sound(octave[6]*2);
	delay(15);
	nosound();
	if(c=='s'||c=='S')
		t=400;
	else if(c=='m'||c=='M')
		t=300;
	else if(c=='f'||c=='F')
		t=200;
	else if(c=='x'||c=='X')
		dark=1;
	}
}

void slice(int p, int q, int sangle, int eangle, int rad)
	{
	int i,j;
	if(sangle>eangle){
	circle(p,q,rad);
	floodfill(p,q,YELLOW);
	setcolor(getbkcolor());
	setfillstyle(SOLID_FILL,getbkcolor());
	pieslice(p,q,eangle,sangle,rad);
	setcolor(YELLOW);
	}
	else{
	setfillstyle(SOLID_FILL, YELLOW);
	sector(p,q,sangle,eangle,rad,rad);
	}
	}
	
void show()
{
	int i,j;
	clrscr();
	cleardevice();
	for (i=0; i<20; i++)
	{	for (j=0; j<19; j++)
		{
		switch(map[i][j])
		{
		case 0:
		setfillstyle(SOLID_FILL, BLUE);
		bar(j*gridx+1+offset, i*gridy+1, (j+1)*gridx+offset, (i+1)*gridy);
		break;
		case 1:
		setcolor(WHITE);
		circle(j*gridx+gridx/2+offset, i*gridy+gridy/2, 2);
		break;
		case 2:
		setfillstyle(SOLID_FILL, BLACK);
		bar(j*gridx+1+offset, i*gridy+1, (j+1)*gridx+offset, (i+1)*gridy);
		break;
		}
	}
	}
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	slice(gridx*x+gridx/2+offset, gridy*y+gridy/2, st, end, gridy/2-2);
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	circle(gridx*x1+gridx/2+offset, gridy*y1+gridy/2, gridy/2-2);
	floodfill(gridx*x1+gridx/2+offset, gridy*y1+gridy/2, RED);
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	circle(gridx*x2+gridx/2+offset, gridy*y2+gridy/2, gridy/2-2);
	floodfill(gridx*x2+gridx/2+offset, gridy*y2+gridy/2, CYAN);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	circle(gridx*x3+gridx/2+offset, gridy*y3+gridy/2, gridy/2-2);
	floodfill(gridx*x3+gridx/2+offset, gridy*y3+gridy/2, GREEN);
	printf("\t\t\t\tPress Esc to Pause\t\tLives left: %2d", (3-death));
}

void update(int l, int m)
{
	int i,j,r=1;
	sprintf(sc,"%d", score);
	setcolor(WHITE);
	setviewport(offset,0,offset+120,gridy,1);
	clearviewport();
	outtextxy(offset,5,"Score: ");
	outtextxy(offset+60,5,sc);
	setviewport(0,0,maxx,maxy,1);
	if (dark==1)
	{
		cleardevice();
	    r=2;
	}
	for (i=(m-r); i<=(m+r); i++)
	{	for (j=(l-r); j<=(l+r); j++)
		{
		switch(map[i][j])
		{
		default:
		setfillstyle(SOLID_FILL, BLUE);
		bar(j*gridx+1+offset, i*gridy+1, (j+1)*gridx+offset, (i+1)*gridy);
		break;
		case 1:
		setfillstyle(SOLID_FILL, BLACK);
		bar(j*gridx+1+offset, i*gridy+1, (j+1)*gridx+offset, (i+1)*gridy);
		setcolor(WHITE);
		circle(j*gridx+gridx/2+offset, i*gridy+gridy/2, 2);
		break;
		case 2:
		setfillstyle(SOLID_FILL, BLACK);
		bar(j*gridx+1+offset, i*gridy+1, (j+1)*gridx+offset, (i+1)*gridy);
		break;
		}
	}
	}
		setfillstyle(SOLID_FILL, YELLOW);
		setcolor(YELLOW);
		slice(gridx*x+gridx/2+offset, gridy*y+gridy/2, st, end, gridy/2-2);
		
		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		circle(gridx*x1+gridx/2+offset, gridy*y1+gridy/2, gridy/2-2);
		floodfill(gridx*x1+gridx/2+offset, gridy*y1+gridy/2, RED);
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(gridx*x2+gridx/2+offset, gridy*y2+gridy/2, gridy/2-2);
		floodfill(gridx*x2+gridx/2+offset, gridy*y2+gridy/2, CYAN);
		setcolor(GREEN);
		setfillstyle(SOLID_FILL, GREEN);
		circle(gridx*x3+gridx/2+offset, gridy*y3+gridy/2, gridy/2-2);
		floodfill(gridx*x3+gridx/2+offset, gridy*y3+gridy/2, GREEN);
		
		setcolor(YELLOW);
}

void ghost1()
{
	int k, r=0;
	while(1)
	{
	if(r==2||(abs(y1-y)>=abs(x1-x)&&r==0))
	{
		if (r==2||y1>y)
		{
			if (map[y1-1][x1]!=0)
			{
				y1=y1-1;
				break;
			}
		}
		else if (r==2||y1<=y)
		{
			if (map[y1+1][x1]!=0)
			{
				y1=y1+1;
				break;
			}
		}
	}
	else 
	{
		if (r==2||x1>x)
		{
			if (map[y1][x1-1]!=0)
			{
				x1=x1-1;
				break;
			}
		}
		else if (r==2||x1<=x)
		{
			if (map[y1][x1+1]!=0)
			{
				x1=x1+1;
				break;
			}
		}
	}
	r++;
	if(r>3)
		break;
	}
		if(dark==0)
		update(x1,y1);
		if (x1==x&&y1==y)
		{
			death++;
			for(k=6;k>=0;k--)
			{
				sound(octave[k]);
				delay(50);
			}
			nosound();
			delay(750);
			if(death==3)
				kill();
			else
			{
				initpos();
				show();
			}
		}
}

void ghost2()
{
	int k, r=0;
	while(1)
	{
	if(r==2||(abs(y2-ty2)>=abs(x2-tx2)&&r==0))
	{
		if (r==2||y2>ty2)
		{
			if (map[y2-1][x2]!=0)
			{
				y2=y2-1;
				break;
			}
		}
		else if (r==2||y2<=ty2)
		{
			if (map[y2+1][x2]!=0)
			{
				y2=y2+1;
				break;
			}
		}
	}
	else 
	{
		if (r==2||x2>tx2)
		{
			if (map[y2][x2-1]!=0)
			{
				x2=x2-1;
				break;
			}
		}
		else if (r==2||x2<=tx2)
		{
			if (map[y2][x2+1]!=0)
			{
				x2=x2+1;
				break;
			}
		}
	}
	r++;
	if(r>3)
		break;
	}
		if(dark==0)
		update(x2,y2);
		if (x2==x&&y2==y)
		{
			death++;
			for(k=6;k>=0;k--)
			{
				sound(octave[k]);
				delay(50);
			}
			nosound();
			delay(750);
			if(death==3)
				kill();
			else
			{
				initpos();
				show();
			}
		}
		if (x2==tx2&&y2==ty2)
		{
			if(tx2==14&&ty2==14)
				tx2=4;
			else if(tx2==4&&ty2==14)
				ty2=2;
			else if(tx2==4&&ty2==2)
				tx2=14;
			else if(tx2==14&&ty2==2)
				ty2=14;
		}	
}

void ghost3()
{
	int k, r=0, f=0;
	if((abs(x3-x)<=8&&abs(y3-y)<=8)&&r3<=8&&f==0)
	{
		tx3=x;
		ty3=y;
		r3++;
		if(r3==8)
		f=1;
	}
	else
	{
		tx3=19-x;
		ty3=20-y;
		if(f==1)
			r3++;
	}
	if(r3==16)
	{
		r3=0;
		f=0;
	}
	while(1)
	{
	if(r==2||(abs(y3-ty3)>=abs(x3-tx3)&&r==0))
	{
		if (r==2||y3>ty3)
		{
			if (map[y3-1][x3]!=0)
			{
				y3=y3-1;
				break;
			}
		}
		else if (r==2||y3<=ty3)
		{
			if (map[y3+1][x3]!=0)
			{
				y3=y3+1;
				break;
			}
		}
	}
	else 
	{
		if (r==2||x3>tx3)
		{
			if (map[y3][x3-1]!=0)
			{
				x3=x3-1;
				break;
			}
		}
		else if (r==2||x3<=tx3)
		{
			if (map[y3][x3+1]!=0)
			{
				x3=x3+1;
				break;
			}
		}
	}
	r++;
	if(r>3)
		break;
	}
		if(dark==0)
		update(x3,y3);
		if (x3==x&&y3==y)
		{
			death++;
			for(k=6;k>=0;k--)
			{
				sound(octave[k]);
				delay(50);
			}
			nosound();
			delay(750);
			if(death==3)
				kill();
			else
			{
				initpos();
				show();
			}
		}	
}

void main()
{
	char c;
	int k;
	initialize();
	initpos();
	if (rep==0)
		start();
	dif();
	show();
	delay(500);
	while(1)
	{
	delay(t);
	while (kbhit())
	{	
		c= getch();
		if (c=='w'||c=='W')
		{
			dir=0;			
		}
		else if (c=='s'||c=='S')
		{
			dir=1;
		}
		else if (c=='a'||c=='A')
		{
			dir=2;
		}
		else if (c=='d'||c=='D')
		{
			dir=3;
		}
		else if (c==27)
		{
			sound(octave[6]*2);
			delay(15);
			nosound();
			kill();	
		}
		else if (c=='~')
			score=149;
	}
	if (dir==0)
		{
			if (map[y-1][x]==1)
			{
				y--;
				map[y][x]=2;
				sound(octave[6]*2);
				delay(50);
				nosound();
				score++;
			}
			else if (map[y-1][x]==2)
			{
				y--;
			}
			st=120, end=60;
		}
		else if (dir==1)
		{
			if (map[y+1][x]==1)
			{
				y++;
				map[y][x]=2;
				sound(octave[6]*2);
				delay(50);
				nosound();
				score++;
			}
			else if (map[y+1][x]==2)
			{
				y++;
			}
			st=300, end=240;
		}
		else if (dir==2)
		{
			if (map[y][x-1]==1)
			{
				x--;
				map[y][x]=2;
				sound(octave[6]*2);
				delay(50);
				nosound();
				score++;
			}
			else if (map[y][x-1]==2)
			{
				x--;
			}
			st=210, end=150;
		}
		else if (dir==3)
		{
			if (map[y][x+1]==1)
			{
				x++;
				map[y][x]=2;
				sound(octave[6]*2);
				delay(50);
				nosound();
				score++;
			}
			else if (map[y][x+1]==2)
			{
				x++;
			}
			st=30, end=330;
		}
		if((x==x1&&y==y1)||(x==x2&&y==y2)||(x==x3&&y==y3))
		{
			death++;
			for(k=6;k>=0;k--)
			{
				sound(octave[k]);
				delay(50);
			}
			nosound();
			delay(750);
			if(death==3)
				kill();
			else
			{
				initpos();
				show();
			}
		}	
		ghost1();
		ghost2();
		ghost3();
		update(x,y);
		if (score==150)
		{
			delay(500);
			kill();
		}
	}
}

void kill()
{
	clrscr();
	cleardevice();
	if (score==150)
	{
		outtextxy(maxx/2-40, maxy/2-50, "YOU WIN!");
		outtextxy(maxx/2-180, maxy-50, "(Press Spacebar to play again, Esc to exit)");
	}
	else if (death==3)
	{
		outtextxy(maxx/2-46, maxy/2-50, "GAME OVER!");
		outtextxy(maxx/2-190, maxy-50, "(Press Spacebar to start new game, Esc to exit)");
		sprintf(sc, "%d", score);
		outtextxy(maxx/2-40, maxy/2-20,"Score: ");
		outtextxy(maxx/2+15, maxy/2-20,sc);
	}
	else
	{
		outtextxy(maxx/2-46, maxy/2-50, "GAME PAUSED");
		outtextxy(maxx/2-240, maxy-50, "(Press P to resume, Spacebar to start new game, Esc to exit)");
		sprintf(sc, "%d", score);
		outtextxy(maxx/2-40, maxy/2-20,"Score: ");
		outtextxy(maxx/2+15, maxy/2-20,sc);
	}
	delay(750);
	while(1)
	{	ch=getch();
		if (ch==' ')
		{
			rep=1;
			main();
		}
		else if (ch==27)
		{
			clrscr();
			exit(0);
		}
		else if (ch=='p'||ch=='P')
		{
			show();
			break;
		}
	}
}
