#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include <string>
#include <windows.h>
#include <MMSystem.h>
#include <glut.h>
#include <GL.h>
#include <GLU.h>
#include <GLAux.h>
#include <time.h>
///Game speed
int FPS=50;
///Game
int start=0, gameover=0, level=0, check=0, getZombie1, getZombie2, getZombie3, getZombie4, alive1=0, alive2=0, alive3=0, alive4=0, checkText=0, zombiePower=0;
int zombiepowerMore=0;
///Game score
int score=0, fileScore;
///For player's left/right
float moveHuman=0;
///Zombies coming
int movezombiePos1=0, movezombiePos2=0, movezombiePos3=0, movezombiePos4=0;
int zombiePos1=(rand() % (15-0+1) + 0), zombiePos2=(rand() % (33-21+1) + 21), zombiePos3=(rand() % (50-37+1) + 37), zombiePos4=(rand() % (70-63+1) + 63);

///For displaying text
const int font1 =(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 =(int)GLUT_BITMAP_HELVETICA_18;
const int font3 =(int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x,y);
    for(c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

///Zombie variation
void zombie01()
{
    ///Hand
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(27-2,100-6);
    glVertex2f(27-2,100-8.5);
    glVertex2f(24+2,100-8.5);
    glVertex2f(24+2,100-6);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(32-2,100-6);
    glVertex2f(32-2,100-8.5);
    glVertex2f(29+2,100-8.5);
    glVertex2f(29+2,100-6);
    glEnd();
    ///Body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(26,100-3.5);
    glVertex2f(26,100-7);
    glVertex2f(30,100-7);
    glVertex2f(30,100-3.5);
    glEnd();
    ///Head
    glColor3f(0.5411,0.2,0.1411);
    glBegin(GL_POLYGON);
    glVertex2f(26+1.5,100-5.5-1);
    glVertex2f(26+1.5,100-5);
    glVertex2f(30-1.5,100-5);
    glVertex2f(30-1.5,100-5.5-1);
    glEnd();
}

void zombie02()
{
    ///Hand
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(28-2,100-7);
    glVertex2f(26-2,100-9);
    glVertex2f(23+2,100-10);
    glVertex2f(25+2,100-7);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(32-2+3,100-7);
    glVertex2f(32-2+5,100-9);
    glVertex2f(29+2+3,100-10);
    glVertex2f(29+2+1,100-7);
    glEnd();
    ///Body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(26,100-3.5);
    glVertex2f(26,100-7);
    glVertex2f(30+3,100-7);
    glVertex2f(30+3,100-3.5);
    glEnd();
    ///Head
    glColor3f(0.5411,0.2,0.1411);
    glBegin(GL_POLYGON);
    glVertex2f(26+2,100-5.5-1);
    glVertex2f(26+2,100-5);
    glVertex2f(30-2+3,100-5);
    glVertex2f(30-2+3,100-5.5-1);
    glEnd();
}

void zombie03()
{
    ///Hand
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(27-2,100-6);
    glVertex2f(27-2,100-8.5);
    glVertex2f(24+2,100-8.5);
    glVertex2f(24+2,100-6);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(32-4,100-6);
    glVertex2f(32-4,100-8.5);
    glVertex2f(29+2-2,100-8.5);
    glVertex2f(29+2-2,100-6);
    glEnd();
    ///Body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(26,100-3.5);
    glVertex2f(26,100-7);
    glVertex2f(28,100-7);
    glVertex2f(28,100-3.5);
    glEnd();
    ///Head
    glColor3f(0.5411,0.2,0.1411);
    glBegin(GL_POLYGON);
    glVertex2f(26+.5,100-5.5-1);
    glVertex2f(26+.5,100-5);
    glVertex2f(30-2-.5,100-5);
    glVertex2f(30-2-.5,100-5.5-1);
    glEnd();
}

void startGame()
{
    ///road
    //glColor3f(0,0.501,0);
    if(((score/15)%140) <= 30)
    {
        glColor3f(0.3765, 0.8471, 0.1882);
    }
    else if(((score/15)%140) <= 60 && ((score/15)%140) >= 31)
    {
        glColor3f(0.5647, 0.9412, 0.5647);
    }
    else if(((score/15)%140) <= 90 && ((score/15)%140) >= 61)
    {
        glColor3f(0.094, 0.7529, 0.5647);
    }
    else if(((score/15)%140) <= 140 && ((score/15)%140) >= 91)
    {
        glColor3f(0.188, 0.282, 0.282);
    }
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();
    score++;

    ///print score
    char buffer[50];
    sprintf(buffer, "%d meter(s)",score/15);
    if(checkText == 0)
    {
        glColor3f(0,0,0);
    }
    else
    {
        glColor3f(1,1,1);
    }
    renderBitmapString(80.5,91, (void*)font3, buffer);

    ///print High Score
    char buffer2[50];
    sprintf(buffer2, "%d meter(s)",fileScore);
    renderBitmapString(80.5,95,(void*)font3,buffer2);

    ///level
    //increase speed with level
    if(score % 50 == 0)
    {
        int last = score / 50;
        if(last != level)
        {
            level = score / 50;
            FPS += 2;
        }
    }
    //printf("%d\n",moveHuman);

    ///Human body
    //glColor3f(0.678,1.0,0.184);
    glColor3f(0.8745, 0.63529, 0.43529);
    glBegin(GL_POLYGON);
    glVertex2f(moveHuman+26, 1);
    glVertex2f(moveHuman+26, 4);
    //glColor3f(0,0.545,0.545);
    glVertex2f(moveHuman+30, 4);
    glVertex2f(moveHuman+30, 1);
    glEnd();
    ///Human head
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(moveHuman+26+1.5, 1+1);
    glVertex2f(moveHuman+26+1.5, 4-1);
    glVertex2f(moveHuman+30-1.5, 4-1);
    glVertex2f(moveHuman+30-1.5, 1+1);
    glEnd();

    ///opposite zombie 1
//    glPushMatrix();
//    glTranslated(movezombiePos1,zombiePos1,0);
//    zombie03();
//    glPopMatrix();
//    zombiePos1--;
//    if(zombiePos1 < -100)
//    {
//        zombiePos1 = 0;
//        //zombiePos1 = (rand() % (15-0+1) + 0);
//        movezombiePos1 = moveHuman;
//    }
//    //kill check zombie 1
//    if((abs(moveHuman-movezombiePos1) < 5) && (zombiePos1 + 100 < 10))
//    {
//        start = 0;
//        gameover = 1;
//    }

    if(alive1 == 0)
    {
        getZombie1 = rand() % 3 + 1;
        alive1 = 1;
    }
    if(getZombie1 == 1)
    {
        //printf("1\n");
        alive1 = 1;
        glPushMatrix();
        glTranslated(movezombiePos1,zombiePos1,0);
        zombie01();
        glPopMatrix();
        zombiePos1--;
        if(zombiePos1 < -100)
        {
            zombiePos1 = 0;
            alive1 = 0;
            movezombiePos1 = moveHuman;
        }
        //collusion check zombie pos 1
        if((abs(moveHuman-movezombiePos1) < (5+zombiePower)) && (zombiePos1 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie1 == 2)
    {
        //printf("2\n");
        alive1 = 1;
        glPushMatrix();
        glTranslated(movezombiePos1,zombiePos1,0);
        zombie02();
        glPopMatrix();
        zombiePos1--;
        if(zombiePos1 < -100)
        {
            zombiePos1 = 0;
            alive1 = 0;
            movezombiePos1 = moveHuman;
        }
        //collusion check zombie pos 1
        if((abs(moveHuman-movezombiePos1) < (9+zombiePower)) && (zombiePos1 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie1 == 3)
    {
        //printf("3\n");
        alive1 = 1;
        glPushMatrix();
        glTranslated(movezombiePos1,zombiePos1,0);
        zombie03();
        glPopMatrix();
        zombiePos1--;
        if(zombiePos1 < -100)
        {
            zombiePos1 = 0;
            alive1 = 0;
            movezombiePos1 = moveHuman;
        }
        //collusion check zombie pos 1
        if((abs(moveHuman-movezombiePos1) < (2+zombiePower)) && (zombiePos1 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }


    ///opposite zombie 2
//    glPushMatrix();
//    glTranslated(movezombiePos2,zombiePos2,0);
//    zombie01();
//    glPopMatrix();
//    zombiePos2--;
//    if(zombiePos2 < -100)
//    {
//        zombiePos2 = 0;
//        //zombiePos2 = (rand() % (33-21+1) + 21);
//        movezombiePos2 = moveHuman;
//    }
//    //kill check zombie 2
//    if((abs(moveHuman-movezombiePos2) < 5) && (zombiePos2 + 100 < 10))
//    {
//        start = 0;
//        gameover = 1;
//    }

    if(alive2 == 0)
    {
        getZombie2 = rand() % 3 + 1;
        alive2 = 1;
    }
    if(getZombie2 == 1)
    {
        //printf("1\n");
        alive2 = 1;
        glPushMatrix();
        glTranslated(movezombiePos2,zombiePos2,0);
        zombie01();
        glPopMatrix();
        zombiePos2--;
        if(zombiePos2 < -100)
        {
            zombiePos2 = 0;
            alive2 = 0;
            movezombiePos2 = moveHuman;
        }
        //collusion check zombie pos 2
        if((abs(moveHuman-movezombiePos2) < (5+zombiePower)) && (zombiePos2 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie2 == 2)
    {
        //printf("2\n");
        alive2 = 1;
        glPushMatrix();
        glTranslated(movezombiePos2,zombiePos2,0);
        zombie02();
        glPopMatrix();
        zombiePos2--;
        if(zombiePos2 < -100)
        {
            zombiePos2 = 0;
            alive2 = 0;
            movezombiePos2 = moveHuman;
        }
        //collusion check zombie pos 2
        if((abs(moveHuman-movezombiePos2) < (9+zombiePower)) && (zombiePos2 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie2 == 3)
    {
        //printf("3\n");
        alive2 = 1;
        glPushMatrix();
        glTranslated(movezombiePos2,zombiePos2,0);
        zombie03();
        glPopMatrix();
        zombiePos2--;
        if(zombiePos2 < -100)
        {
            zombiePos2 = 0;
            alive2 = 0;
            movezombiePos2 = moveHuman;
        }
        //collusion check zombie pos 2
        if((abs(moveHuman-movezombiePos2) < (2+zombiePower)) && (zombiePos2 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }

    ///opposite zombie 3
//    glPushMatrix();
//    glTranslated(movezombiePos3,zombiePos3,0);
//    zombie01();
//    glPopMatrix();
//    zombiePos3--;
//    if(zombiePos3 < -100)
//    {
//        zombiePos3 = 0;
//        //zombiePos3 = (rand() % (50-37+1) + 37);
//        movezombiePos3 = moveHuman;
//    }
//    //kill check zombie 3
//    if((abs(moveHuman-movezombiePos3) < 5) && (zombiePos3 + 100 < 10))
//    {
//        start = 0;
//        gameover = 1;
//    }
    if(alive3 == 0)
    {
        getZombie3 = rand() % 3 + 1;
        alive3 = 1;
    }
    if(getZombie3 == 1)
    {
        //printf("1\n");
        alive3 = 1;
        glPushMatrix();
        glTranslated(movezombiePos3,zombiePos3,0);
        zombie01();
        glPopMatrix();
        zombiePos3--;
        if(zombiePos3 < -100)
        {
            zombiePos3 = 0;
            alive3 = 0;
            movezombiePos3 = moveHuman;
        }
        //collusion check zombie pos 3
        if((abs(moveHuman-movezombiePos3) < (5+zombiePower)) && (zombiePos3 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie3 == 2)
    {
        //printf("2\n");
        alive3 = 1;
        glPushMatrix();
        glTranslated(movezombiePos3,zombiePos3,0);
        zombie02();
        glPopMatrix();
        zombiePos3--;
        if(zombiePos3 < -100)
        {
            zombiePos3 = 0;
            alive3 = 0;
            movezombiePos3 = moveHuman;
        }
        //collusion check zombie pos 3
        if((abs(moveHuman-movezombiePos3) < (9+zombiePower)) && (zombiePos3 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie3 == 3)
    {
        //printf("3\n");
        alive3 = 1;
        glPushMatrix();
        glTranslated(movezombiePos3,zombiePos3,0);
        zombie03();
        glPopMatrix();
        zombiePos3--;
        if(zombiePos3 < -100)
        {
            zombiePos3 = 0;
            alive3 = 0;
            movezombiePos3 = moveHuman;
        }
        //collusion check zombie pos 3
        if((abs(moveHuman-movezombiePos3) < (2+zombiePower)) && (zombiePos3 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }

    ///opposite zombie 4
//    glPushMatrix();
//    glTranslated(movezombiePos4,zombiePos4,0);
//    zombie01();
//    glPopMatrix();
//    zombiePos4--;
//    if(zombiePos4 < -100)
//    {
//        zombiePos4 = 0;
//        //zombiePos4 = (rand() % (70-56+1) + 56);
//        movezombiePos4 = moveHuman;
//    }
//    //kill check zombie 4
//    if((abs(moveHuman-movezombiePos4) < 5) && (zombiePos4 + 100 < 10))
//    {
//        start = 0;
//        gameover = 1;
//    }

    if(alive4 == 0)
    {
        getZombie4 = rand() % 3 + 1;
        alive4 = 1;
    }
    if(getZombie4 == 1)
    {
        //printf("1\n");
        alive4 = 1;
        glPushMatrix();
        glTranslated(movezombiePos4,zombiePos4,0);
        zombie01();
        glPopMatrix();
        zombiePos4--;
        if(zombiePos4 < -100)
        {
            zombiePos4 = 0;
            alive4 = 0;
            movezombiePos4 = moveHuman;
        }
        //collusion check zombie pos 4
        if((abs(moveHuman-movezombiePos4) < (5+zombiePower)) && (zombiePos4 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie4 == 2)
    {
        //printf("2\n");
        alive4 = 1;
        glPushMatrix();
        glTranslated(movezombiePos4,zombiePos4,0);
        zombie02();
        glPopMatrix();
        zombiePos4--;
        if(zombiePos4 < -100)
        {
            zombiePos4 = 0;
            alive4 = 0;
            movezombiePos4 = moveHuman;
        }
        //collusion check zombie pos 4
        if((abs(moveHuman-movezombiePos4) < (9+zombiePower)) && (zombiePos4 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
    if(getZombie4 == 3)
    {
        //printf("3\n");
        alive4 = 1;
        glPushMatrix();
        glTranslated(movezombiePos4,zombiePos4,0);
        zombie03();
        glPopMatrix();
        zombiePos4--;
        if(zombiePos4 < -100)
        {
            zombiePos4 = 0;
            alive4 = 0;
            movezombiePos4 = moveHuman;
        }
        //collusion check zombie pos 4
        if((abs(moveHuman-movezombiePos4) < (2+zombiePower)) && (zombiePos4 + 100 < (10+zombiePower+zombiepowerMore)))
        {
            start = 0;
            gameover = 1;
        }
    }
}

void scratch()
{
        ///number 1
        glPushMatrix();
        glTranslatef(50-9,22,0);
        glScalef(1,1.5,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,1);
        glVertex2f(3,10);
        glVertex2f(2.1,6.5);
        glVertex2f(2.6,5.7);
        glVertex2f(-1.5,-10.5);
        glEnd();
        glPopMatrix();
        ///number 2
        glPushMatrix();
        glTranslatef(50-3,22,0);
        glScalef(1,1.5,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(3,6.5);
        glVertex2f(4,11);
        glVertex2f(1.5,5.5);
        glVertex2f(-1,4);
        glVertex2f(-1.4,-6);
        glVertex2f(-3,-11);
        glVertex2f(-.5,-6.2);
        glEnd();
        glPopMatrix();
        ///number 4
        glPushMatrix();
        glTranslatef(50+6,22,0);
        glScalef(1,1.5,1);
        glBegin(GL_POLYGON);
        glVertex2f(0,8);
        glVertex2f(1,3.5);
        glVertex2f(.5,0);
        glVertex2f(1,-4.5);
        glVertex2f(-2.5,-11);
        glVertex2f(0,-4.5);
        glVertex2f(0,0);
        glEnd();
        glPopMatrix();
        ///number 3
        glPushMatrix();
        glTranslatef(50,22,0);
        glScalef(1,1.5,1);
        glBegin(GL_POLYGON);
        glVertex2f(0.5,0);
        glVertex2f(0,3);
        glVertex2f(2,6.5);
        glVertex2f(1.7,8);
        glVertex2f(3,10);
        glVertex2f(2.5,6.3);
        glVertex2f(2.3,1);
        glVertex2f(1,0);
        glVertex2f(-2.5,-10);
        glEnd();
        glPopMatrix();
        glPopMatrix();
}

void firstdesign()
{
    if(gameover != 1)
    {
        ///scratch
        glColor3f(0.4,0,0);
        scratch();
        ///scratch 2
        glPushMatrix();
        glColor3f(0.4,0,0);
        glTranslatef(43,32,0);
        scratch();
        glPopMatrix();
        ///scratch 3
        glPushMatrix();
        glColor3f(0.4,0,0);
        glTranslatef(-35,62,0);
        scratch();
        glPopMatrix();
        ///scratch 4
        glPushMatrix();
        glColor3f(0.4,0,0);
        glTranslatef(25,68,0);
        scratch();
        glPopMatrix();
        ///scratch 5
        glPushMatrix();
        glColor3f(0.4,0,0);
        glTranslatef(-40,25,0);
        scratch();
        glPopMatrix();

        ///menu
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(32-14,50+5+16);
        glVertex2f(32+46+6,50+5+16);
        glVertex2f(32+46+6,50-15+4);
        glVertex2f(32-14,50-15+4);
        glEnd();

        glColor3f(0.259,0.259,0.259);
        glBegin(GL_POLYGON);
        glVertex2f(32-10,50+5+12);
        glVertex2f(32+48,50+5+12);
        glVertex2f(32+48,50-15+8);
        glVertex2f(32-10,50-15+8);
        glEnd();

        glColor3f(1,1,1);
        renderBitmapString(30-3,80,(void*)font1,"2D Escape From Zombie");

        glColor3f(1,1,1);
        renderBitmapString(30,50+10,(void*)font2,"Press SPACE to START");
        renderBitmapString(30+4,50+10-4,(void*)font2,"Press ESC to EXIT");

        renderBitmapString(30+1.5,50-11+10,(void*)font3,"Press LEFT to turn LEFT");
        renderBitmapString(30,50-14+10,(void*)font3,"Press RIGHT to turn RIGHT");

        ///creators
        renderBitmapString(30+10,50-34+10,(void*)font3,"Game Made By");
        renderBitmapString(30-1,50-38+10,(void*)font3,"Kazi Ferdous Mahin 011171009");
        renderBitmapString(30-1,50-41+10,(void*)font3,"Robiuddin Robi    011171023");
    }

    if(gameover == 1)
    {
        glPushMatrix();
        glColor3f(0.4,0,0);
        glTranslatef(0,-14,0);
        glScalef(1,3,1);
        scratch();
        glPopMatrix();

        glClearColor(0.501,0.501,0.501,1);
        check = 0;
        glColor3f(1,1,1);
        renderBitmapString(35+2,65+10,(void*)font1, "You are dead");
        glColor3f(1,1,1);
        char buffer2[50];
        sprintf(buffer2, "You have escaped %d meter(s)",score/15);
        renderBitmapString(20+2,60-4+10,(void*)font1,buffer2);
        renderBitmapString(24,60-12+10,(void*)font1, "Press 'space' for play again");

        if(score/15 > fileScore)
        {
            FILE *fptr;
            fptr = fopen("score.txt","w");
            fprintf(fptr,"%d",score/15);
            fclose(fptr);
        }
    }


}

void keyboardListener(unsigned char key, int xx,int yy){
	switch(key){
        case ' ':
            if(start == 0 && check == 0)
            {
                //printf("here\n");
                start = 1;
                gameover = 0;
                FPS = 50;
                moveHuman = 0;
                movezombiePos1 = 0;
                movezombiePos2 = 0;
                movezombiePos3 = 0;
                movezombiePos4 = 0;
                zombiePos1 = (rand() % (15-0+1) + 0);
                zombiePos2 = (rand() % (33-21+1) + 21);
                zombiePos3 = (rand() % (50-37+1) + 37);
                zombiePos4 = (rand() % (70-63+1) + 63);
                score = 0;
                level = 0;
                check = 1;
                FILE *fptr;
                fptr = fopen("score.txt","r");
                fscanf(fptr,"%d", &fileScore);
                fclose(fptr);
            }
            break;
        case 27:
            exit(0);
            break;
		default:
			break;
	}

}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT :
			if(moveHuman >= -4.5)
            {
                moveHuman = moveHuman - (FPS/10);
                if(moveHuman < -4.5)
                {
                    moveHuman = -5;
                }
            }
			break;
		case GLUT_KEY_RIGHT :
			if(moveHuman <= 48.5)
            {
                moveHuman = moveHuman + (FPS/10);
                if(moveHuman > 48.5)
                {
                    moveHuman = 49;
                }
            }
			break;

		case GLUT_KEY_PAGE_UP:
			break;

		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;

		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer, 0);
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/


	/****************************
	/ Add your objects from here
	****************************/
	//add objects
    if(start == 1)
    {
        //glClearColor(0,0.392,0, 1);
        //glClearColor(0.501,0.501,0.501,1);
        if(((score/15)%140) <= 15)
        {
            checkText = 0;
            zombiePower = 0;
            zombiepowerMore = 0;
            glClearColor(0.7098, 0.830, 0.8784, 1);
        }
        else if(((score/15)%140) <= 30 && ((score/15)%140) >= 16)
        {
            glClearColor(0.780, 0.882, 0.898, 1);
        }
        else if(((score/15)%140) <= 45 && ((score/15)%140) >= 31)
        {
            glClearColor(1, 0.937, 0.478, 1);
        }
        else if(((score/15)%140) <= 60 && ((score/15)%140) >= 46)
        {
            glClearColor(0.9686, 0.75686, 0.41569, 1);
        }
        else if(((score/15)%140) <= 75 && ((score/15)%140) >= 61)
        {
            glClearColor(0.95686, 0.41569, 0.333, 1);
        }
        else if(((score/15)%140) <= 90 && ((score/15)%140) >= 76)
        {
            glClearColor(1, 0.4196, 0.243, 1);
        }
        else if(((score/15)%140) <= 140 && ((score/15)%140) >= 90)
        {
            checkText = 1;
            zombiePower = 2;
            zombiepowerMore = 2;
            glClearColor(0.1529, 0.129, 0.30588, 1);
        }
        startGame();
    }
    else
    {
        firstdesign();
    }

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glFlush();
	glutSwapBuffers();
}


void init(){
	//codes for initialization
	//drawgrid=0;
	//drawaxes=1;
	//cameraHeight=150.0;
	//cameraAngle=1.0;
	//angle=0;

	//clear the screen
	//glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	//glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	//glLoadIdentity();

	//give PERSPECTIVE parameters
	//gluPerspective(80,	1,	1,	5000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 600);
	glutInitWindowPosition(200, 20);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);	//Depth, Double buffer, RGB color

	glutCreateWindow("2D Excape From Zombie");

	//init();

	//glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	//glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);

	glOrtho(0,100,0,100,-1,1);
	glClearColor(0.5215,0,0, 1);

	glutTimerFunc(1000, timer, 0);

    PlaySound("ggwp.wav",NULL, SND_ASYNC|SND_FILENAME);

	//sndPlaySound("opening.wav",SND_ASYNC);
	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
