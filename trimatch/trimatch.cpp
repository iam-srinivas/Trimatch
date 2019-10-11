#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
#include<stdio.h>
#define maxx 11
#define maxy 11
#define dx 50
#define dy 50
time_t starttime,endtime;//countdown
int ct=time(&starttime);
int elapsed=0;
int limit=20;
int hsw=0;
int trp=0;
int highscore;
int flag=1,start=0,score=0;
GLfloat color[7][3]={{0,0,1},{0,1,0},{1,0,0},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};
GLfloat x0=0,y0=0;
GLint i,j,stroke=0,pastx,pasty,nextx,nexty,swapthetwo=0;
typedef struct cell
		{
			GLfloat x0,y0,x1,y1;
			int color;
	
		}cellt;
cellt board[20][20];

void addscore(int hscore)
{
	FILE *scorefile=fopen("score.txt","a+");
	fprintf(scorefile,"%d\n",hscore);
	fclose(scorefile);
}

int readscore()
{  	int rc;
	FILE *scorefile=fopen("score.txt","r");	
	fscanf(scorefile,"%d",&rc);
	while(!feof(scorefile))
	{
		fscanf(scorefile,"%d",&rc);
		printf("file score is %d\n",rc);
		
	}
	
	fclose(scorefile);
	return rc;
}

void shape(int i,int j)
{
	
	
	int x=i*dx;
	int y=j*dy;
	

if(board[i][j].color==4)//magenta
{
		
glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();
glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+15,y+5);
	glVertex2f(x+35,y+5);
	glVertex2f(x+45,y+25);
	glVertex2f(x+35,y+45);
	glVertex2f(x+15,y+45);
	glVertex2f(x+5,y+25);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+15,y+5);
	glVertex2f(x+35,y+5);
	glVertex2f(x+45,y+25);
	glVertex2f(x+35,y+45);
	glVertex2f(x+15,y+45);
	glVertex2f(x+5,y+25);
glEnd();
glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(x+15,y+5);
	glVertex2f(x+35,y+45);
glEnd();
glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(x+35,y+5);
	glVertex2f(x+15,y+45);
glEnd();
glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(x+45,y+25);
	glVertex2f(x+5,y+25);
glEnd();
}
else if(board[i][j].color==2)//red
{		
glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();

glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+5,y+5);
	glVertex2f(x+45,y+5);
	glVertex2f(x+45,y+45);
	glVertex2f(x+5,y+45);
glEnd();

glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+5,y+5);
	glVertex2f(x+45,y+5);
	glVertex2f(x+45,y+45);
	glVertex2f(x+5,y+45);
glEnd();

glBegin(GL_LINE_LOOP); //small square 1
	glColor3f(0,0,0);
	glVertex2f(x+5,y+5);
	glVertex2f(x+15,y+5);
	glVertex2f(x+15,y+15);
	glVertex2f(x+5,y+15);
glEnd();
glBegin(GL_LINE_LOOP); //small square 2
	glColor3f(0,0,0);
	glVertex2f(x+35,y+5);
	glVertex2f(x+45,y+5);
	glVertex2f(x+45,y+15);
	glVertex2f(x+35,y+15);
glEnd();
glBegin(GL_LINE_LOOP); //small square 3
	glColor3f(0,0,0);
	glVertex2f(x+35,y+35);
	glVertex2f(x+45,y+35);
	glVertex2f(x+45,y+45);
	glVertex2f(x+35,y+45);
glEnd();
glBegin(GL_LINE_LOOP); //small square 4
	glColor3f(0,0,0);
	glVertex2f(x+5,y+35);
	glVertex2f(x+15,y+35);
	glVertex2f(x+15,y+45);
	glVertex2f(x+5,y+45);
glEnd();
glBegin(GL_LINE_LOOP); //rhombus 1
	glColor3f(0,0,0);
	glVertex2f(x+5,y+45);
	glVertex2f(x+15,y+15);
	glVertex2f(x+45,y+5);
	glVertex2f(x+35,y+35);
glEnd();
glBegin(GL_LINE_LOOP); //rhombus 2
	glColor3f(0,0,0);
	glVertex2f(x+5,y+5);
	glVertex2f(x+35,y+15);
	glVertex2f(x+45,y+45);
	glVertex2f(x+15,y+35);
glEnd();
}

else if(board[i][j].color==0)//blue
{
glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();
glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+25,y+5);
 	glVertex2f(x+45,y+25);
 	glVertex2f(x+38,y+35);
	glVertex2f(x+12,y+35);
	glVertex2f(x+5,y+25);
glEnd();
glBegin(GL_LINE_LOOP); //tri
	glColor3f(0,0,0);
	glVertex2f(x+25,y+5);
 	glVertex2f(x+45,y+25);
 	glVertex2f(x+5,y+25);
glEnd();
glBegin(GL_LINE_LOOP); //top
	glColor3f(0,0,0);
	glVertex2f(x+5,y+25);
	glVertex2f(x+45,y+25);
	glVertex2f(x+38,y+35);
	glVertex2f(x+12,y+35);
glEnd();
glBegin(GL_LINES); //l
	glColor3f(0,0,0);
	glVertex2f(x+25,y+5);
	glVertex2f(x+20,y+25);
glEnd();
glBegin(GL_LINES); //l
	glColor3f(0,0,0);
	glVertex2f(x+25,y+5);
	glVertex2f(x+30,y+25);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+15,y+15);
	glVertex2f(x+10,y+25);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+35,y+15);
	glVertex2f(x+40,y+25);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+10,y+25);
	glVertex2f(x+25,y+35);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+40,y+25);
	glVertex2f(x+25,y+35);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+20,y+25);
	glVertex2f(x+25,y+35);
glEnd();
glBegin(GL_LINES); //ls
	glColor3f(0,0,0);
	glVertex2f(x+30,y+25);
	glVertex2f(x+25,y+35);
glEnd();
	
}

else if(board[i][j].color==3)//yellow
{
glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();

glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+5,y+25);
	glVertex2f(x+20,y+20);
	glVertex2f(x+25,y+5);
 	glVertex2f(x+30,y+20);
 	glVertex2f(x+45,y+25);
 	glVertex2f(x+30,y+30);
 	glVertex2f(x+25,y+45);
	glVertex2f(x+20,y+30);
	
glEnd();

glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+25,y+5);
 	glVertex2f(x+30,y+20);
 	glVertex2f(x+45,y+25);
 	glVertex2f(x+30,y+30);
 	glVertex2f(x+25,y+45);
	glVertex2f(x+20,y+30);
	glVertex2f(x+5,y+25);
	glVertex2f(x+20,y+20);
glEnd();

glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(x+20,y+25);
 	glVertex2f(x+25,y+20);
 	glVertex2f(x+30,y+25);
 	glVertex2f(x+25,y+30);
glEnd();

	
}

else if(board[i][j].color==1)//green
{
	
glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();

glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+5,y+5);
 	glVertex2f(x+45,y+5);
 	glVertex2f(x+45,y+45);
 	glVertex2f(x+5,y+45);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+5,y+5);
 	glVertex2f(x+45,y+5);
 	glVertex2f(x+45,y+45);
 	glVertex2f(x+5,y+45);
glEnd();

glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+5,y+15);
 	glVertex2f(x+45,y+15);
 	glVertex2f(x+45,y+20);
	glVertex2f(x+5,y+20);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+5,y+15);
 	glVertex2f(x+45,y+15);
 	glVertex2f(x+45,y+20);
	glVertex2f(x+5,y+20);
glEnd();

glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+5,y+30);
 	glVertex2f(x+45,y+30);
 	glVertex2f(x+45,y+35);
	glVertex2f(x+5,y+35);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+5,y+30);
 	glVertex2f(x+45,y+30);
 	glVertex2f(x+45,y+35);
	glVertex2f(x+5,y+35);
glEnd();
	
}

else if(board[i][j].color==5)
{
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+0,y+0);
 	glVertex2f(x+50,y+0);
 	glVertex2f(x+50,y+50);
	glVertex2f(x+0,y+50);
glEnd();

glBegin(GL_POLYGON);
	glColor3fv(color[board[i][j].color]);
	glVertex2f(x+5,y+5);
 	glVertex2f(x+45,y+5);
 	glVertex2f(x+45,y+45);
 	glVertex2f(x+5,y+45);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+5,y+5);
 	glVertex2f(x+45,y+5);
 	glVertex2f(x+45,y+45);
 	glVertex2f(x+5,y+45);
glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+15,y+5);
 	glVertex2f(x+15,y+45);
 	glVertex2f(x+20,y+45);
	glVertex2f(x+20,y+5);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+15,y+5);
 	glVertex2f(x+15,y+45);
 	glVertex2f(x+20,y+45);
	glVertex2f(x+20,y+5);
glEnd();

glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(x+30,y+5);
 	glVertex2f(x+30,y+45);
 	glVertex2f(x+35,y+45);
	glVertex2f(x+35,y+5);
glEnd();
glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex2f(x+30,y+5);
 	glVertex2f(x+30,y+45);
 	glVertex2f(x+35,y+45);
	glVertex2f(x+35,y+5);
glEnd();
}


}

void scorestring(float x,float y,float z,int cscore)
{
	char str[10]={'\0'};
	sprintf(str,"%d",cscore);
unsigned int c;
glRasterPos3f(x,y,z);
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[c]);
}




void drawstring(float x,float y,float z,const char *str)
{
unsigned int c;
glRasterPos3f(x,y,z);
for(c=0;c<strlen(str);c++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[c]);
}

void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 drawstring(70,400,0.0,"SRI SAIRAM COLLEGE OF ENGINEERING");
 glColor3f(1,0,0);
 drawstring(150,370,0.0,"DEPARTMENT OF ");
  drawstring(35,350,0.0,"COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(133,300,0.0,"MINI PROJECT ON ");
 glColor3f(1,0,1);
 drawstring(175,280,0.0,"TRIMATCH");
 glColor3f(1,0.5,0);
 drawstring(10,240,0.0,"BY:");
 glColor3f(0.0,0.0,1.0);
 drawstring(10.0,200.0,0.0,"SRINIVAS D (1SB16CS100)");
  glColor3f(0.0,0.0,1.0);
 drawstring(10.0,180.0,0.0,"KIRAN J (1SB16CS46)");
 glColor3f(1.0,0.0,0.0);
drawstring(10,150,0.0,"6th Semester,CSE");
 glColor3f(1,0.5,0);
 drawstring(282,240,0.0,"GUIDE:");
 glColor3f(0.5,0.2,0.2);
 drawstring(282,200,0.0,"MRS ROJI PRIYA");
 drawstring(282,180,0.0,"Assistant Professor,CSE");
  drawstring(120,90,0.0,"PRESS ENTER TO START");
glFlush();
}

void instruction(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 drawstring(200,400,0.0,"TRIMATCH");
 glColor3f(1,0,0);
 drawstring(60,300,0.0,"INSTRUCTIONS ");
 glColor3f(1,0.5,0);
drawstring(60,250,0.0,"->USE YOUR MOUSE OR POINTING DEVICE");
drawstring(60,220,0.0,"   TO SHIFT THE POSITION OF OBJECT ");
drawstring(60,190,0.0,"   BY DRAG AND DROP THE OBJECT");
 glColor3f(1,0,1);
drawstring(100,90,0.0,"PRESS ENTER TO START THE GAME");
glFlush();
}

void scoreboard(void)
{
	
	if(trp==0)
	{
		highscore=readscore();
		trp=1;
	}
	
	if(hsw==0)
	{
		
		if(score>highscore)
		{
		
			addscore(score);
			hsw=1;
		}
	}
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,0,0);
 drawstring(200,400,0.0,"GAME OVER");
 glColor3f(0,0,1);
 drawstring(150,300,0.0,"YOUR SCORE IS:");
 glColor3f(1,0,0);
 scorestring(350,300,0.0,score);
 drawstring(150,200,0.0,"HIGHSCORE IS:");
 glColor3f(1,0,0);
 scorestring(350,200,0.0,highscore);
 
 if(score>highscore)
 {
 		
 	 drawstring(100,150,0.0,"YOUR NEW HIGHSCORE IS:");
 	glColor3f(1,0,0);
 	scorestring(380,150,0.0,score);
 }
 
 glFlush();
}



void Sleep(int s){
	clock_t endwait;
	endwait=clock()+s*CLOCKS_PER_SEC;
	while(clock()<endwait)
	{
	}
}



void addgravityr(GLint nx,GLint ny){
	printf("\n inside gravity rigtht ");
    
     for(int j=ny;j<9;j++)
	 {
		board[nx][j].color=board[nx][j+1].color;
	
	 }
	  board[nx][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx+1][j].color=board[nx+1][j+1].color;
	
	 }
	  board[nx+1][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx+2][j].color=board[nx+2][j+1].color;
	
	 }
	  board[nx+2][9].color=6;
    

}

void addgravityl(GLint nx,GLint ny){
	printf("\n inside gravity left ");
    
     for(int j=ny;j<9;j++)
	 {
		board[nx][j].color=board[nx][j+1].color;
	
	 }
	  board[nx][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx-1][j].color=board[nx-1][j+1].color;
	
	 }
	  board[nx-1][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx-2][j].color=board[nx-2][j+1].color;
	
	 }
	  board[nx-2][9].color=6;
	
}

void addgravityt(GLint nx,GLint ny){
	printf("\n inside gravity top ");
    for(int i=ny+2;i<9;i++){
    	board[nx][i].color=board[nx][i+1].color;
    }
    board[nx][9].color=6;
    
    for(int i=ny+1;i<9;i++){
    	board[nx][i].color=board[nx][i+1].color;
    }
    board[nx][9].color=6;
    
    for(int i=ny;i<9;i++){
    	board[nx][i].color=board[nx][i+1].color;
    }
    board[nx][9].color=6;
}

void addgravityb(GLint nx,GLint ny){
		printf("\n inside gravity bottom ");
    for(int i=ny;i<9;i++){
     board[nx][i].color=board[nx][i+1].color;	
    }
    board[nx][9].color=6;
    
    for(int i=ny-1;i<9;i++){
     board[nx][i].color=board[nx][i+1].color;	
    }
    board[nx][9].color=6;
    
    for(int i=ny-2;i<9;i++){
     board[nx][i].color=board[nx][i+1].color;	
    }
    board[nx][9].color=6;
}

void addgravityv(GLint nx,GLint ny){
	printf("\n inside gravity vertical ");
	  for(int i=ny;i<9;i++){
     board[nx][i+1].color=board[nx][i+2].color;	
    }
    board[nx][9].color=6;
    
    for(int i=ny;i<9;i++){
     board[nx][i].color=board[nx][i+1].color;	
    }
    board[nx][9].color=6;
    
    for(int i=ny;i<9;i++){
     board[nx][i-1].color=board[nx][i].color;	
    }
    board[nx][9].color=6;
}

void addgravityh(GLint nx,GLint ny){
	printf("\n inside gravity Horizontal ");
	 for(int j=ny;j<9;j++)
	 {
		board[nx][j].color=board[nx][j+1].color;
	
	 }
	  board[nx][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx+1][j].color=board[nx+1][j+1].color;
	
	 }
	  board[nx+1][9].color=6;
	  
	  for(int j=ny;j<9;j++)
	 {
		board[nx-1][j].color=board[nx-1][j+1].color;
	
	 }
	  board[nx-1][9].color=6;
}

void vanishr(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx+1][ny].color=6;
	board[nx+2][ny].color=6;
	addgravityr(nx,ny);
	score+=3;
	printf("\ncurrent score is %d\n",score);
	          
}

void vanishl(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx-1][ny].color=6;
	board[nx-2][ny].color=6;
	addgravityl(nx,ny);
	score+=3;
	printf("\ncurrent score is %d\n",score);
	          
}

void vanisht(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx][ny+1].color=6;
	board[nx][ny+2].color=6;
	addgravityt(nx,ny);
	score+=3;
	printf("\n current  score is %d \n",score);
	          
}
void vanishb(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx][ny-1].color=6;
	board[nx][ny-2].color=6;
	addgravityb(nx,ny);
	score+=3;
	printf("\n current score is %d \n",score);
	        
}
void vanishv(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx][ny-1].color=6;
	board[nx][ny+1].color=6;
	addgravityv(nx,ny);
	score+=3;
	printf("\n current score is %d\n ",score);
	          
}
void vanishh(GLint nx,GLint ny)
{
	printf("\n inside vanisher");
	board[nx][ny].color=6;
	board[nx-1][ny].color=6;
	board[nx+1][ny].color=6;
	addgravityh(nx,ny);
	score+=3;
	printf("\n current  score is %d\n",score);
	          
}
void scanpos(){
		for(i=0;i<maxx;i++)
	{
		
	
		for(j=0;j<maxy;j++)
		{
			
			
			
			if(board[i][j].color==board[i+1][j].color&board[i][j].color!=6)
			{
				if(board[i][j].color==board[i+2][j].color)
				{
					vanishr(i,j);
					printf("inside scanner");
				}
				
			}
		
		}
	}
	
		for(i=0;i<maxx;i++)
	{
		
	
		for(j=0;j<maxy;j++)
		{
			
			
			
			if(board[i][j].color==board[i][j+1].color&board[i][j].color!=6)
			{
				if(board[i][j].color==board[i][j+2].color)
				{
					vanisht(i,j);
					printf("inside scanner");
				}
				
			}
		
		}
	}
}

void checksamecolor(GLint nx,GLint ny)
{     
  	
    
		/*check for right*/
		if(board[nx][ny].color==board[nx+1][ny].color&board[nx][ny].color==board[nx+2][ny].color)
		{
			if((nextx/dx)+1>9||(nextx/dx)+2>9){
				printf("buffer colours reached the end right point");	
			}
			else{
			
	 			printf("\n same  right color found");
	 			vanishr(nx,ny);
			}
		}
	
	 	/*check for left*/
		if(board[nx][ny].color==board[nx-1][ny].color&board[nx][ny].color==board[nx-2][ny].color)
		{
			if((nextx/dx)-1<0||(nextx/dx)-2<0)
			{
				printf("buffer colours reached the end left point");
			}
			else
			{
			
	 			printf("\n same  left color found");
				vanishl(nx,ny);
			}
		}
	
	 	/*check for top*/
		if(board[nx][ny].color==board[nx][ny+1].color&board[nx][ny].color==board[nx][ny+2].color)
		{
			if((nexty/dy)+1>9||(nexty/dy)+2>9){
				printf("buffer colours reached the end right point");	
			}
			else
			{
				printf("\n same  top color found");
				vanisht(nx,ny);
			}
	 	
		}
	
	 	/*check for bottom*/
		if(board[nx][ny].color==board[nx][ny-1].color&board[nx][ny].color==board[nx][ny-2].color)
		{
				if((nexty/dy)-1<0||(nexty/dy)-2<0)
			{
				printf("buffer colours reached the end left point");
			}
	 		else
	 		{
	 			printf("\n same  bottom color found");
				vanishb(nx,ny);
	 		}
		}
	
		/*check for middle vertical*/
		if(board[nx][ny].color==board[nx][ny-1].color&board[nx][ny].color==board[nx][ny+1].color)
		{
	 	printf("\n same  vertical middle color found");
	  	vanishv(nx,ny);
		}
	
		/*check for middle horizntal*/
		if(board[nx][ny].color==board[nx-1][ny].color&board[nx][ny].color==board[nx+1][ny].color)
		{
	 	printf("\n same  horizontal middle color found");
	 	vanishh(nx,ny);
	
		}

	
}




void init()
{int i=0,j=0;
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
	glutPostRedisplay();
	
	srand(time(NULL));//to generate random numbers
	for(i=0;i<maxx;i++)
	{
		
	
		for(j=0;j<maxy;j++)
		{
			
			board[i][j].x0=x0+i*dx+1;
			board[i][j].x1=x0+(i+1)*dx-1;
			board[i][j].y0=y0+j*dy+1;
			board[i][j].y1=y0+(j+1)*dy-1;
			
			board[i][j].color=rand()%6;
		
		}
	}
	
	for(i=0;i<maxx;i++)
	{
		
	
		for(j=0;j<maxy;j++)
		{
			
			
			
			if(board[i][j].color==board[i+1][j].color)
			{
				if(board[i][j].color==board[i+2][j].color)
				{
					board[i][j].color=rand()%6;
				}
				
			}
		
		}
	}
	
		for(i=0;i<maxx;i++)
	{
		
	
		for(j=0;j<maxy;j++)
		{
			
		
						
			if(board[i][j].color==board[i][j+1].color)
			{
				if(board[i][j].color==board[i][j+2].color)
				{
					board[i][j].color=rand()%6;
				}
				
			}
		
		}
	}
	
};
void display(void)
{
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	if(start==0){
		frontscreen();
	}
	else if(start==1)
	{
		instruction();
	}
	else if(start==2&&elapsed<limit){
		
		time(&endtime);
	 	elapsed=difftime(endtime,ct);
	 	printf("elapsed time is %d\n",elapsed);
		if(elapsed==limit)
		{
			start=3;
		}
			for(i=0;i<maxx-1;i++)
		{
			for(j=0;j<maxy-1;j++)
			{

        		 glColor3fv(color[board[i][j].color]);

         	glBegin(GL_POLYGON);
         				     glVertex2f(board[i][j].x0,board[i][j].y0);
         				     glVertex2f(board[i][j].x0,board[i][j].y1);
         				     glVertex2f(board[i][j].x1,board[i][j].y1);
         			    	 glVertex2f(board[i][j].x1,board[i][j].y0);
         			     	glEnd();
         			    
						shape(i,j);
					glColor3f(0,0,0);
					drawstring(10,470,0.0,"TIME LEFT:");
					glColor3f(0,0,0);
 					scorestring(115,470,0.0,(limit+1)-elapsed);

	    	}
		}
	}
	else if(start==3)
	{
		scoreboard();
	}

	
	glFlush();
	glutSwapBuffers();
}
void mouse(int btn,int status,int x,int y)
{y=500-y;
	if(stroke==0&&btn==GLUT_LEFT_BUTTON&&status==GLUT_DOWN&&start==2)
{
	stroke=1;
	pastx=x;
	pasty=y;
	printf(" \n pastx=%d,%d\n",pastx/dx,pasty/dy);
}
	if(stroke==1&&btn==GLUT_LEFT_BUTTON&&status==GLUT_UP&&start==2)
	{
stroke=0;
nextx=x;
nexty=y;
printf("nextx=%d,%d\n",nextx/dx,nexty/dy);
if(abs(pastx/dx-nextx/dx)==1&&pasty/dy==nexty/dy)
swapthetwo=1;
if(abs(pasty/dy-nexty/dy)==1&&pastx/dx==nextx/dx)
swapthetwo=1;
	}
	
}

void idle(void)
{int temp;
if(swapthetwo)
{	
	if(board[nextx/dx][nexty/dy].color==6||board[pastx/dx][pasty/dy].color==6){
	 	swapthetwo=0;
	 	printf(" \n cannot swap with empty block");
	}
	

		else{
		
			swapthetwo=0;
			temp=board[pastx/dx][pasty/dy].color;
			board[pastx/dx][pasty/dy].color=board[nextx/dx][nexty/dy].color;
			board[nextx/dx][nexty/dy].color=temp;
			printf("swapped \n ");
        	
			checksamecolor(nextx/dx,nexty/dy);
		}	
		flag=0;
}
glutPostRedisplay();
if(!flag){
scanpos();
}
}

void Keyboard( unsigned char key, int x, int y )
{
 
 if(start==0 && key==13) //Ascii of 'enter' key is 13
    start=1;
 else if(start==1 && key==13) //Ascii of 'enter' key is 13
    start=2;
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("TRIMATCH");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutKeyboardFunc(Keyboard);
	init();
	glutMainLoop();
	return(0);
}
