#include <iostream>
#include <SDL2/SDL.h> // window and renderer and basic configure
#include <SDL2/SDL_image.h> // loading BitMap images on window
#include <SDL2/SDL_ttf.h> // font and text render
#include <SDL2/SDL2_gfx.h> // extra useful function
#include <string>
#include <math.h>
#include <fstream>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<windows.h>
#include<SDL2/SDL_mixer.h>
// grohi (Alireza Khaleghi && Vahid.Ansari)
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
using namespace std;
struct ajor {
    int strength,x,y;
    bool bom=false,pri=false;
};
int main( int argc, char * argv[] )
{
    int R,G,B;
    int W = 800;
    int L = 1200;
    int colorball=0;
    int damg;
    float vx,vy;
string name,s,history;
cin>>name;
ifstream in,in1,in2,in3,in4,in5;
bool newgamer=true;
bool firstsave=true;
int gamenumber=0;
int level1,score1,lives1;
int level2,score2,lives2;
int level3,score3,lives3;
int level4,score4,lives4;
int level5,score5,lives5;
string  file,filenam1,filenam2,filenam3,filenam4,filenam5;
filenam1=name+"1.txt";
filenam2=name+"2.txt";
filenam3=name+"3.txt";
filenam4=name+"4.txt";
filenam5=name+"5.txt";
in1.open(filenam1.c_str());
in2.open(filenam2.c_str());
in3.open(filenam3.c_str());
in4.open(filenam4.c_str());
in5.open(filenam5.c_str());
 if(in1.good())
{

    in1>>lives1>>score1>>level1;
    cout<<"game number 1 :: "<<"\t"<<"level : "<<level1<<" & Scores : "<<score1<<" & lives : "<<lives1<<endl;
    gamenumber=1;
    newgamer=false;
}
if(in2.good())
{

        in2>>lives2>>score2>>level2;
        cout<<"game number 2 :: "<<"\t"<<"level : "<<level2<<" & Scores : "<<score2<<" & lives : "<<lives2<<endl;
        newgamer=false;
        gamenumber=2;
}
 if(in3.good())
{

        in3>>lives3>>score3>>level3;
        cout<<"game number 3 :: "<<"\t"<<"level : "<<level3<<" & Scores : "<<score3<<" & lives : "<<lives3<<endl;
        newgamer=false;
        gamenumber=3;
}
 if(in4.good())
{
        in4>>lives4>>score4>>level4;
        cout<<"game number 4 :: "<<"\t"<<"level : "<<level4<<" & Scores : "<<score4<<" & lives : "<<lives4<<endl;
        newgamer=false;
        gamenumber=4;
}
if(in5.good())
{
        in5>>lives5>>score5>>level5;
        cout<<"game number 5 :: "<<"\t"<<"level : "<<level5<<" & Scores : "<<score5<<" & lives : "<<lives5<<endl;
        newgamer=false;
        gamenumber=5;
}
if(gamenumber==1)
{
        file=filenam1;
}
if(gamenumber==2)
{
        file=filenam2;
}
if(gamenumber==3)
{
        file=filenam3;
}
if(gamenumber==4)
{
        file=filenam4;
}
if(gamenumber==5)
{
        file=filenam5;
}
in1.close();
in2.close();
in3.close();
in4.close();
in5.close();
in.open(file.c_str());
int level,Score,lives;
int hardness=0;
ajor ajor [100][6];
SDL_Texture *img;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
srand(time(NULL));
SDL_Texture *img2,*img3,*img4,*img5,*img6,*exp1,*exp2,*exp3,*exp4,*exp5;
exp1=IMG_LoadTexture(m_renderer,"exp1.jpg");
exp2=IMG_LoadTexture(m_renderer,"exp2.jpg");
exp3=IMG_LoadTexture(m_renderer,"exp3.jpg");
exp4=IMG_LoadTexture(m_renderer,"exp4.jpg");
exp5=IMG_LoadTexture(m_renderer,"exp5.jpg");
img6=IMG_LoadTexture(m_renderer,"skull.png");
img2=IMG_LoadTexture(m_renderer,"back ground .png");
img3=IMG_LoadTexture(m_renderer,"wood.jpg");
img4=IMG_LoadTexture(m_renderer,"back ground 2.png");
img5=IMG_LoadTexture(m_renderer,"back ground 2.png");

int w,h;
SDL_QueryTexture(exp1,NULL,NULL,&w,&h);
SDL_QueryTexture(exp2,NULL,NULL,&w,&h);
SDL_QueryTexture(exp3,NULL,NULL,&w,&h);
SDL_QueryTexture(exp4,NULL,NULL,&w,&h);
SDL_QueryTexture(exp5,NULL,NULL,&w,&h);
SDL_QueryTexture(img5,NULL,NULL,&w,&h);
SDL_QueryTexture(img4,NULL,NULL,&w,&h);
SDL_QueryTexture(img2,NULL,NULL,&w,&h);
SDL_QueryTexture(img3,NULL,NULL,&w,&h);
SDL_QueryTexture(img6,NULL,NULL,&w,&h);
SDL_Rect texr,texr2,texr3,texr4,texr5,texr6,texrep;
SDL_Rect texrj;
texr6.x=5;
texr6.y=210;
texr6.h=300;
texr6.w=200;
texr.x=380;
texr.y=650;
texr.h=40;
texr.w=40;
texr2.x=0;
texr2.y=0;
texr2.h=800;
texr2.w=1200;
texr3.x=300;
texr3.y=690;
texr3.h=20;
texr3.w=200;
texr4.x=380;
texr4.y=650;
texr4.h=40;
texr4.w=40;
 SDL_Texture*jooon;
jooon=IMG_LoadTexture(m_renderer,"galb.png");
SDL_QueryTexture(jooon,NULL,NULL,&w,&h);
SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
SDL_Event event ;
int situation=1;
SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
rect(m_renderer,0,0,1200,700,22,170,176,1);
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
Mix_Music*backgroundsound =Mix_LoadMUS("ghoor.mp3");
Mix_Chunk*jump =Mix_LoadWAV("Jump.wav");
Mix_PlayMusic(backgroundsound,-1);
Mix_Music*gameover =Mix_LoadMUS("gameo.mp3");
Mix_Chunk*boombi =Mix_LoadWAV("Explosion.wav");
while (1)
        {
        //load or new
        label8:
             Mix_PlayMusic(backgroundsound,-1);
   while (situation==1)
  {
      texr.x=texr3.x+80;texr.y=texr3.y-40;
          int mousex=0;
          int mousey=0;
  string str="Hy "+name;
  const char *font =str.c_str();
  const char *font1 ="NEW GAME";
  const char *font2 ="RELOAD LAST GAME";
  textRGBA(m_renderer,10,10,font,5,40,255,255,0,255);
  textRGBA(m_renderer,100,100,font1,5,40,255,255,0,255);
  if(!newgamer)
  textRGBA(m_renderer,100,200,font2,5,40,255,255,0,255);
        if( SDL_PollEvent( &event ) )
                switch(event.type)
                {
          case SDL_MOUSEBUTTONDOWN:
              mousex=event.motion.x;
              mousey=event.motion.y;
                break;
                }
                //New Game
                if(mousex>=80&&mousex<=500&&mousey>=100&&mousey<=140)
                {
                   level=1;Score=0;lives=3;situation=2;
                   //cleaning window
                   SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                   rect(m_renderer,0,0,1200,700,22,170,176,1);
                }
                // REload
                else if(mousex>=80&&mousex<=500&&mousey>=200&&mousey<=240&&!newgamer)
                {
                 int b=0;level=0;Score=0;lives=0;
                 in>>lives>>Score>>level>>texr.x>>texr.y>>damg>>colorball>>texr3.x>>hardness>>vx>>vy;
                 for(int i=0;i<100;i++){
                        for(int j=0;j<6;j++){
                        int randombompriz;
                        randombompriz=rand()%10;
                        if(randombompriz==7)
                        {
                            ajor[i][j].bom=true;
                        }
                        else if(randombompriz==8)
                        {
                            ajor[i][j].pri=true;
                        }




                        ajor[i][j].strength=(rand()%5);
                        if(hardness==1)
                        {if(ajor[i][j].strength<2) ajor[i][j].strength =0;    }
                        else if(hardness==2)
                        {              continue;       }
                        else if(hardness==3)
                        {if(ajor[i][j].strength<2) ajor[i][j].strength =5;    }

                        }
                        }
                 if(level>=6)
                 {
                         for(int i=level-6;i<level;i++)
                         {
                                 for(int j=0;j<6;j++)
                                 {
                                         int priz,bomb;
                                         ajor[i][j].x=210*j;ajor[i][j].y=110*(level-i-1);
                                         in>>ajor[i][j].strength>>bomb>>priz;
                                         if(bomb==1)
                                         {
                                                 ajor[i][j].bom=true;
                                         }else { ajor[i][j].bom=false;}

                                         if(priz==1)
                                         {
                                                 ajor[i][j].pri=true;
                                         }else { ajor[i][j].pri=false;}

                                 }
                         }
                 }
                 else
                 {
                    for(int i=0;i<level;i++)
                         {
                                 for(int j=0;j<6;j++)
                                 {
                                         int priz,bomb;
                                         ajor[i][j].x=210*j;ajor[i][j].y=110*(level-i-1);
                                         in>>ajor[i][j].strength>>bomb>>priz;

                                         if(bomb==1)
                                         {
                                                 ajor[i][j].bom=true;
                                         }else { ajor[i][j].bom=false;}

                                         if(priz==1)
                                         {
                                                 ajor[i][j].pri=true;
                                         }else { ajor[i][j].pri=false;}

                                 }
                         }
                 }
if(colorball==1)
{
         img=IMG_LoadTexture(m_renderer,"red.png");
                       SDL_QueryTexture(img,NULL,NULL,&w,&h);
}
if(colorball==2)
{
         img=IMG_LoadTexture(m_renderer,"yellow.png");
                       SDL_QueryTexture(img,NULL,NULL,&w,&h);
}
if(colorball==3)
{
         img=IMG_LoadTexture(m_renderer,"grean.png");
                       SDL_QueryTexture(img,NULL,NULL,&w,&h);
}
if(colorball==4)
{
         img=IMG_LoadTexture(m_renderer,"blue.png");
                       SDL_QueryTexture(img,NULL,NULL,&w,&h);
}
                        in.close();
                        //cleaning window
                        SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
                        situation=5;
                        goto label00;
                }

  }
  // rang toop
 while (situation==2)
  {
          int mousex=0;
          int mousey=0;
        string str = name + " CHOOSE COLLOR OF BALL :";
  const char *font =str.c_str();
  const char *font1 ="1 : RED BALL";
  const char *font2 ="2 : YELLOW BALL";
  const char *font3 ="3 : GREEN BALL";
  const char *font4 ="4 : BLUE BALL";
  textRGBA(m_renderer,10,10,font,5,40,255,255,0,255);
  textRGBA(m_renderer,100,100,font1,5,40,255,0,0,255);
  textRGBA(m_renderer,100,200,font2,5,40,255,255,0,255);
  textRGBA(m_renderer,100,300,font3,5,40,0,255,0,255);
  textRGBA(m_renderer,100,400,font4,5,40,0,0,255,255);
        if( SDL_PollEvent( &event ) )
                switch(event.type)
                {
          case SDL_MOUSEBUTTONDOWN:
              mousex=event.motion.x;
              mousey=event.motion.y;
                break;
                }
                if(mousex>=80&&mousex<=500&&mousey>=100&&mousey<=140)
                {
                       img=IMG_LoadTexture(m_renderer,"red.png");
                       SDL_QueryTexture(img,NULL,NULL,&w,&h);
                   situation=3;
                   //cleaning window
                   texr.x=400;texr.y=100;
                   SDL_RenderCopy(m_renderer,img,NULL,&texr);
                   SDL_RenderPresent(m_renderer);
                   SDL_Delay(1000);
                   texr.x=380;
                   texr.y=650;
                   rect(m_renderer,0,0,1200,700,22,170,176,1);
                   colorball=1;
                   goto label1;
                }
                else if(mousex>=80&&mousex<=500&&mousey>=200&&mousey<=240)
                {
                        img=IMG_LoadTexture(m_renderer,"yellow.png");
                        SDL_QueryTexture(img,NULL,NULL,&w,&h);
                        situation=3;
                        //cleaning window
                        texr.x=450;texr.y=200;
                   SDL_RenderCopy(m_renderer,img,NULL,&texr);
                   SDL_RenderPresent(m_renderer);
                   SDL_Delay(1000);
                    texr.x=380;
                    texr.y=650;
                    colorball=2;
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
                        goto label1;
               }
               else if(mousex>=80&&mousex<=500&&mousey>=300&&mousey<=340)
                {
                        img=IMG_LoadTexture(m_renderer,"grean.png");
                        SDL_QueryTexture(img,NULL,NULL,&w,&h);
                        situation=3;
                        //cleaning window
                        texr.x=400;texr.y=300;
                   SDL_RenderCopy(m_renderer,img,NULL,&texr);
                   SDL_RenderPresent(m_renderer);
                   SDL_Delay(1000);
                    texr.x=380;
                    texr.y=650;
                    colorball=3;
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
                        goto label1;
                }
                else if(mousex>=80&&mousex<=500&&mousey>=400&&mousey<=440)
                {
                        img=IMG_LoadTexture(m_renderer,"blue.png");
                        SDL_QueryTexture(img,NULL,NULL,&w,&h);
                        situation=3;
                        //cleaning window
                        texr.x=400;texr.y=400;
                   SDL_RenderCopy(m_renderer,img,NULL,&texr);
                   SDL_RenderPresent(m_renderer);
                   SDL_Delay(1000);
                   texr.x=380;
                    texr.y=650;
                      colorball=4;
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
                        goto label1;

                }
                }
// choose hardness
label1:
while (situation==3)
  {
          int mousex=0;
          int mousey=0;
        string str = name + " CHOSE HARDNESS OF GAME :";
          const char *font =str.c_str();
          const char *font1 ="1 : EASY";
          const char *font2 ="2 : NORMAL";
          const char *font3 ="3 : HARD";
  textRGBA(m_renderer,10,10,font,5,40,255,255,0,255);
  rect(m_renderer,100,100,400,40,255,255,255,1);
  textRGBA(m_renderer,100,100,font1,5,40,255,0,0,255);
  textRGBA(m_renderer,100,200,font2,5,40,255,255,0,255);
  textRGBA(m_renderer,100,300,font3,5,40,0,255,0,255);
        if( SDL_PollEvent( &event ) )
                switch(event.type)
                {
          case SDL_MOUSEBUTTONDOWN:
              mousex=event.motion.x;
              mousey=event.motion.y;
                if(mousex>=80&&mousex<=500&&mousey>=100&&mousey<=140)
                {
                       hardness=1;
                   situation=4;
                   //cleaning window
                   //SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                   rect(m_renderer,0,0,1200,700,22,170,176,1);
                }
                else if(mousex>=80&&mousex<=500&&mousey>=200&&mousey<=240)
                {
                        hardness=2;
                        situation=4;
                        //cleaning window
                       // SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
               }
               else if(mousex>=80&&mousex<=500&&mousey>=300&&mousey<=340)
                {
                        hardness=3;
                        situation=4;
                        //cleaning window
                        //SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                        rect(m_renderer,0,0,1200,700,22,170,176,1);

                }
                        for(int i=0;i<100;i++){
                        for(int j=0;j<6;j++){
                                int randombompriz;
                        randombompriz=rand()%10;
                        if(randombompriz==7)
                        {
                            ajor[i][j].bom=true;
                        }
                        else if(randombompriz==8)
                        {
                            ajor[i][j].pri=true;
                        }
                        ajor[i][j].strength=(rand()%5);
                        if(hardness==1)
                        {if(ajor[i][j].strength<2) ajor[i][j].strength =0;    }
                        else if(hardness==2)
                        {              continue;       }
                        else if(hardness==3)
                        {if(ajor[i][j].strength<2) ajor[i][j].strength =5;    }

                        }
                        }
                           goto label2;
                            break;

                }
                }

// befor lunch
label2:
while(situation==4)
{
    texr3.y=690;
    if(level>=6)
    {
        for(int i=0;i<level-6;i++)
            for(int j=0;j<6;j++)
        {
            if(ajor[i][j].strength>0)
            {
                rect(m_renderer,0,0,1200,800,0,0,0,1);
                                        const char *font2 ="GAME OVER";
                                        textRGBA(m_renderer,220,330,font2,5,130,255,0,0,255);
                                        //texr6.y=210;
                                    SDL_RenderCopy(m_renderer,img6,NULL,&texr6);
                                     texr6.x=1000;texr6.y=210;
                                     SDL_RenderCopy(m_renderer,img6,NULL,&texr6);
                                     SDL_RenderPresent(m_renderer);
                                        newgamer=true;
                        texr.x=texr3.x+80;texr.y=texr3.y-40;
                                        situation=8;
                                        goto label9;
                                        break;
            }
        }
    }
        SDL_Delay(30);texr.x=texr3.x+80;texr.y=texr3.y-40;
   if(level<6)
    {
        for(int i=0;i<level;i++)
                         for(int j=0;j<6;j++)
                {
                    ajor[i][j].x=210*j;ajor[i][j].y=110*(level-i-1);

                    if(ajor[i][j].strength>0)
                    {
                        if(ajor[i][j].strength==5)
                        {
                            R=255;G=0;B=0;
                        }
                        else if(ajor[i][j].strength==4)
                        {
                            R=255;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==3)
                        {
                            R=0;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==2)
                        {
                            R=0;G=0;B=255;
                        }
                        else if(ajor[i][j].strength==1)
                        {
                            R=255;G=255;B=255;
                        }
                        rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,R,G,B,1);

                        if(ajor[i][j].bom==true)
                        ellipse(m_renderer,ajor[i][j].x+100,ajor[i][j].y+50,30,30,0,0,0,1);
                         if(ajor[i][j].pri==true)
                            {
                        texrj.x=ajor[i][j].x+10;texrj.y=ajor[i][j].y+10;texrj.w=180;texrj.h=80;
                                            rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,0,0,0,0);
                                                SDL_RenderCopy(m_renderer,jooon,NULL,&texrj);
                          }
                       // SDL_RenderPresent(m_renderer);
                    }
                    else if(ajor[i][j].strength<=0)
                                    {
                                      rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,22,170,176,1);
                                    }
                }
                }
else {
        for(int i=level-6;i<level;i++)
                         for(int j=0;j<6;j++)
                {
                    if(ajor[i][j].strength==5)
                        {
                            R=255;G=0;B=0;
                        }
                        else if(ajor[i][j].strength==4)
                        {
                            R=255;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==3)
                        {
                            R=0;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==2)
                        {
                            R=0;G=0;B=255;
                        }
                        else if(ajor[i][j].strength==1)
                        {
                            R=255;G=255;B=255;
                        }
                    ajor[i][j].x=210*j;ajor[i][j].y=110*(level-i-1);


                    if(ajor[i][j].strength>0)
                    {
                        rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,R,G,B,1);
                        if(ajor[i][j].bom==true)
                        ellipse(m_renderer,ajor[i][j].x+100,ajor[i][j].y+50,30,30,0,0,0,1);
                            if(ajor[i][j].pri==true)
                            {
                        texrj.x=ajor[i][j].x+10;texrj.y=ajor[i][j].y+10;texrj.w=180;texrj.h=80;
                                            rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,0,0,0,0);
                                                SDL_RenderCopy(m_renderer,jooon,NULL,&texrj);
                          }
                       // SDL_RenderPresent(m_renderer);
                    }
                    else if(ajor[i][j].strength<=0)
                                    {
                                      rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,22,170,176,1);
                                    }


                }
}
        if( SDL_PollEvent( &event ) )
        {

                     texr4.x=texr.x;
                     texr4.y=texr.y;
                     texr4.h=texr.h;
                     texr4.w=texr.w;
                     texr5.x=texr3.x;
                     texr5.y=texr3.y;
                     texr5.h=texr3.h;
                     texr5.w=texr3.w;
                switch( event.type){
                        texr4.x=texr.x;
                        texr4.y=texr.y;
                        texr4.h=texr.h;
                        texr4.w=texr.w;
                    case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                            case SDLK_a:
                                SDL_RenderCopy(m_renderer,img4,NULL,&texr4);
                                texr.x-=25;texr3.x-=25;break;
                            case SDLK_d:SDL_RenderCopy(m_renderer,img4,NULL,&texr4);
                                 texr.x+=25;texr3.x+=25;break;
                            case SDLK_SPACE:
                                 situation=5;
                                 break;
                                 SDL_RenderCopy(m_renderer,img4,NULL,&texr4);
                        }
                }
            }
                string sco="level : "+to_string(level)+"\t Scores : "+to_string(Score)+"\t lives : "+to_string(lives);
                rect(m_renderer,000,720,800,50,255,255,0,1);
                const char *font10=sco.c_str();
                textRGBA(m_renderer,100,720,font10,5,50,255,0,255,255);
                SDL_RenderCopy(m_renderer,img5,NULL,&texr5);
            SDL_RenderCopy(m_renderer,img3,NULL,&texr3);
            SDL_RenderCopy(m_renderer,img,NULL,&texr);
            SDL_RenderPresent(m_renderer);
            damg=level;
 vx=0,vy=5;
        }

label4:
              while(situation==5)
        {
                label00:
            SDL_Delay(20);texr3.y=690;
                    texr4.x=texr.x;
                     texr4.y=texr.y;
                     texr4.h=texr.h;
                     texr4.w=texr.w;
                     texr5.x=texr3.x;
                     texr5.y=texr3.y;
                     texr5.h=texr3.h;
                     texr5.w=texr3.w;
                     texr.x+=vx;texr.y-=vy;
                     for(int i =0;i<level;i++)
                        for(int j=0;j<6;j++)
                     {
                         if(texr.x>=ajor[i][j].x-40&&texr.x<=ajor[i][j].x+200&&texr.y>=ajor[i][j].y-40&&texr.y<=ajor[i][j].y+100)
                        {
                                 if(ajor[i][j].strength>0)
                                {
                                   int karkas =ajor[i][j].strength;
                                   if(karkas-damg>0)
                                       ajor[i][j].strength-=damg;
                                       else
                                        ajor[i][j].strength=0;
                                    if(karkas>0)
                                    damg-=karkas;
                                    if(ajor[i][j].strength<=0)
                                    {
                                        Score+=level;
                                           rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,22,170,176,1);
                                           if(ajor[i][j].bom==true)
                                           {
                                               for(int s=i-1;s<=i+1;s++)
                                                for(int mmd=j-1;mmd<=j+1;mmd++)
                                               {
                                                   if(ajor[s][mmd].strength>0&&ajor[s][mmd].strength<=5)
                                                    Score+=level;
                                               }
                                               Score-=level;
                                               texrep.x=ajor[i][j].x-210;texrep.y=ajor[i][j].y-110;texrep.w=620;texrep.h=320;
                                               ajor[i][j-1].strength=0;
                                               ajor[i][j+1].strength=0;
                                               ajor[i-1][j].strength=0;
                                               ajor[i-1][j+1].strength=0;
                                               ajor[i-1][j-1].strength=0;
                                               ajor[i+1][j].strength=0;
                                               ajor[i+1][j+1].strength=0;
                                               ajor[i+1][j-1].strength=0;
                                                Mix_PlayChannel(-1,boombi,0);
                                                    SDL_RenderCopy(m_renderer,exp1,NULL,&texrep);
                                                    SDL_RenderPresent(m_renderer);
                                                    SDL_Delay(100);
                                                    SDL_RenderCopy(m_renderer,exp2,NULL,&texrep);
                                                    SDL_RenderPresent(m_renderer);
                                                    SDL_Delay(100);
                                                    SDL_RenderCopy(m_renderer,exp3,NULL,&texrep);
                                                    SDL_RenderPresent(m_renderer);
                                                    SDL_Delay(100);
                                                    SDL_RenderCopy(m_renderer,exp4,NULL,&texrep);
                                                    SDL_RenderPresent(m_renderer);
                                                    SDL_Delay(100);
                                                    SDL_RenderCopy(m_renderer,exp5,NULL,&texrep);
                                                    SDL_RenderPresent(m_renderer);
                                                    SDL_Delay(50);
                                                    rect(m_renderer,texrep.x,texrep.y,620,320,22,170,176,1);
                                                    SDL_RenderPresent(m_renderer);
                                           }
                                            if(ajor[i][j].pri==true)
                                            {
                                                texrj.x=ajor[i][j].x+10;texrj.y=ajor[i][j].y+10;texrj.w=180;texrj.h=80;
                                            rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,0,0,0,0);
                                                SDL_RenderCopy(m_renderer,jooon,NULL,&texrj);

                                                //rectangleRGBA(m_renderer,)
                                                SDL_Delay(10);

                                                lives++;
                                            }
                                             rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,22,170,176,1);
                                    }
                                    if(damg<=0)
                                    {
                                        level++;
                                        situation=4;
                                        texr.x=texr3.x+100;
                                        texr.y=texr3.y-40;
                                        Mix_PlayChannel(-1,jump,0);
                                        SDL_RenderCopy(m_renderer,img4,NULL,&texr4);
                                        goto label2;
                                    }
                                    //barkhord ba ajor
                                 if(texr.x>=ajor[i][j].x-40&&texr.x<=ajor[i][j].x+5&&texr.y>=ajor[i][j].y-40&&texr.y<ajor[i][j].y+5)
                                 {
                                     //left up
                                     Mix_PlayChannel(-1,jump,0);
                                    vx=5;
                                    if(texr.y==ajor[i][j].y-40)
                                    {
                                        vy=-vy;
                                    }
                                    else
                                    {
                                        vx=-vx;
                                    }

                                 }
                                 else if(texr.x>=ajor[i][j].x+155&&texr.x<=ajor[i][j].x+200&&texr.y>=ajor[i][j].y-40&&texr.y<ajor[i][j].y+5)
                                 {
                                     //right up
                                      Mix_PlayChannel(-1,jump,0);
                                        vx=5;
                                    if(texr.y==ajor[i][j].y-40)
                                    {
                                        vy=-vy;
                                    }
                                    else
                                    {
                                        vx=-vx;
                                    }
                                 }
                                 else if(texr.x>=ajor[i][j].x-40&&texr.x<=ajor[i][j].x+5&&texr.y>=ajor[i][j].y+55&&texr.y<=ajor[i][j].y+100)
                                 {
                                     //left down
                                      Mix_PlayChannel(-1,jump,0);
                                        vx=5;
                                    if(texr.x==ajor[i][j].x-40)
                                    {
                                        vx=-vx;
                                    }
                                    else
                                    {
                                        vy=-vy;
                                    }
                                 }
                                 else if(texr.x>=ajor[i][j].x+155&&texr.x<=ajor[i][j].x+200&&texr.y>=ajor[i][j].y+55&&texr.y<=ajor[i][j].y+100)
                                 {
                                     //right down
                                      Mix_PlayChannel(-1,jump,0);
                                    vx=5;
                                    if(texr.x==ajor[i][j].x+200)
                                    {
                                        vx=-vx;
                                    }
                                    else
                                    {
                                        vy=-vy;
                                    }
                                 }
                                 else if(texr.y>=ajor[i][j].y-40&&texr.y<=ajor[i][j].y-35&&texr.x>ajor[i][j].x+5&&texr.x<ajor[i][j].x+155)
                                 {
                                     //up
                                      Mix_PlayChannel(-1,jump,0);
                                    vy=-vy;
                                 }
                                 else if(texr.y<=ajor[i][j].y+105&&texr.y>=ajor[i][j].y+100&&texr.x>ajor[i][j].x+5&&texr.x<ajor[i][j].x+155)
                                 {
                                     //down
                                      Mix_PlayChannel(-1,jump,0);
                                    vy=-vy;
                                 }
                                 else if(texr.x>=ajor[i][j].x-40&&texr.x<=ajor[i][j].x-35&&texr.y>ajor[i][j].y+5&&texr.y<ajor[i][j].y+55)
                                 {
                                     //left
                                      Mix_PlayChannel(-1,jump,0);
                                    vx=-vx;
                                 }
                                 else if(texr.x<=ajor[i][j].x+200&&texr.x>=ajor[i][j].x+195&&texr.y>ajor[i][j].y+5&&texr.y<ajor[i][j].y+55)
                                 {
                                     //right
                                      Mix_PlayChannel(-1,jump,0);
                                    vx=-vx;
                                 }
                             }

                     }}
                     //barkhoord ba takhteh
                                if(texr.x>=texr3.x-40&&texr.x<=texr3.x+5&&texr.y>=texr3.y-40&&texr.y<=texr3.y-20)
                                  {
                                      //left  up
                                       Mix_PlayChannel(-1,jump,0);
                                       vy=-vy;
                                        vx=-5;

                                  }
                                  else if(texr.x>=texr3.x+155&&texr.x<=texr3.x+200&&texr.y>=texr3.y-40&&texr.y<=texr3.y-20)
                                  {
                                      //right up
                                       Mix_PlayChannel(-1,jump,0);
                                        vy=-vy;
                                        vx=5;
                                  }
                                 else if(texr.y>=texr3.y-40&&texr.y<=texr3.y-20&&texr.x>texr3.x+5&&texr.x<texr3.x+155)
                                  {
                                     vy=-vy;
                                      Mix_PlayChannel(-1,jump,0);
                                      //up
                                  }
                                  if(texr.y>=670)
                                  {
                                      //lose
                                    situation=4;
                                    lives--;
                                    if(lives==0)
                                    {
                                        rect(m_renderer,0,0,1200,800,0,0,0,1);



                                        const char *font2 =" GAME OVER ";
                                        textRGBA(m_renderer,240,330,font2,5,120,255,0,0,255);
                                        texr6.y=210;
                                    SDL_RenderCopy(m_renderer,img6,NULL,&texr6);
                                     texr6.x=1000;texr6.y=210;
                                     SDL_RenderCopy(m_renderer,img6,NULL,&texr6);
                                     SDL_RenderPresent(m_renderer);
                                        newgamer=true;
                                        texr.x=texr3.x+80;texr.y=texr3.y-40;
                                        situation=8;
                                        goto label9;
                                        break;
                                    }
                                    rect(m_renderer,texr.x-vx,texr.y+vy,40,40,22,170,176,1);
                                    texr.x=texr3.x+100;texr.y=texr3.y-40;
                                    SDL_RenderPresent(m_renderer);
                                    goto label2;
                                  }
                                   else if(texr.x>=1200)
                                   {
                                    vx=-vx; Mix_PlayChannel(-1,jump,0);
                                   }
                                   else if (texr.x<=0)
                                   {
                                    vx=-vx; Mix_PlayChannel(-1,jump,0);
                                   }
                                   else if(texr.y<=0)
                                   {
                                    vy=-vy; Mix_PlayChannel(-1,jump,0);
                                   }

        if( SDL_PollEvent( &event ) )
        {

                switch( event.type){
                        case SDL_KEYDOWN:
                           switch(event.key.keysym.sym)
                        {
                           case SDLK_a:
                        texr3.x=texr3.x -20;break;
                    case SDLK_d:
                        texr3.x  =texr3.x+ 20;break;
                    case SDLK_p:
                        situation=6;
                        goto label3;break;
                    case SDLK_c:
                        situation=7;
                        goto label6;
                        break;



                        }break;

                }
            }
            label5:
            if(level<6)
             for(int i=0;i<level;i++)
            {
                for(int j=0;j<6;j++)
                {
                    if(ajor[i][j].strength==5)
                        {
                            R=255;G=0;B=0;
                        }
                        else if(ajor[i][j].strength==4)
                        {
                            R=255;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==3)
                        {
                            R=0;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==2)
                        {
                            R=0;G=0;B=255;
                        }
                        else if(ajor[i][j].strength==1)
                        {
                            R=255;G=255;B=255;
                        }
                    if(ajor[i][j].strength>0)
                    {
                        rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,R,G,B,1);
                        if(ajor[i][j].bom==true)
                        ellipse(m_renderer,ajor[i][j].x+100,ajor[i][j].y+50,30,30,0,0,0,1);
                        if(ajor[i][j].pri==true)
                            {
                        texrj.x=ajor[i][j].x+10;texrj.y=ajor[i][j].y+10;texrj.w=180;texrj.h=80;
                                            rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,0,0,0,0);
                                                SDL_RenderCopy(m_renderer,jooon,NULL,&texrj);
                          }
                        SDL_RenderPresent(m_renderer);
                    }
                }
            }

            else {
                for(int i=level-6;i<level;i++)
            {

                for(int j=0;j<6;j++)
                {
                    if(ajor[i][j].strength==5)
                        {
                            R=255;G=0;B=0;
                        }
                        else if(ajor[i][j].strength==4)
                        {
                            R=255;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==3)
                        {
                            R=0;G=255;B=0;
                        }
                        else if(ajor[i][j].strength==2)
                        {
                            R=0;G=0;B=255;
                        }
                        else if(ajor[i][j].strength==1)
                        {
                            R=255;G=255;B=255;
                        }
                    if(ajor[i][j].strength>0)
                    {
                        rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,R,G,B,1);
                        if(ajor[i][j].bom==true)
                        ellipse(m_renderer,ajor[i][j].x+100,ajor[i][j].y+50,30,30,0,0,0,1);
                         if(ajor[i][j].pri==true)
                            {
                        texrj.x=ajor[i][j].x+10;texrj.y=ajor[i][j].y+10;texrj.w=180;texrj.h=80;
                                            rect(m_renderer,ajor[i][j].x,ajor[i][j].y,200,100,0,0,0,0);
                                                SDL_RenderCopy(m_renderer,jooon,NULL,&texrj);
                          }
                        SDL_RenderPresent(m_renderer);
                    }
                }
            }

            }
            string sco="level : "+to_string(level)+"\t Scores : "+to_string(Score)+"\t lives : "+to_string(lives);
            rect(m_renderer,000,720,800,50,255,255,0,1);
            const char *font10=sco.c_str();
            textRGBA(m_renderer,100,720,font10,5,50,255,0,255,255);
                rect(m_renderer,texr.x-vx,texr.y+vy,40,40,22,170,176,1);
            SDL_RenderCopy(m_renderer,img5,NULL,&texr5);
            SDL_RenderCopy(m_renderer,img3,NULL,&texr3);
            SDL_RenderCopy(m_renderer,img,NULL,&texr);
            SDL_RenderPresent(m_renderer);
                     }
        label3:
     while(situation==6)
     {
              if( SDL_PollEvent( &event ) )
              {
                      switch(event.type)

                      {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_p:
                    rect(m_renderer,texr.x-vx,texr.y+vy,40,40,22,170,176,1);
                        situation=5;
                        goto label5;
                        break;
                case SDLK_s:
                    if(gamenumber==0)
                    {
                        ofstream out1;
                        out1.open(filenam1.c_str());
                            out1<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                            if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {


                                             out1<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out1<<"1"<<endl;
                                             }
                                             else {
                                                out1<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out1<<"1"<<endl;
                                             }
                                             else {
                                                out1<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out1<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out1<<"1"<<endl;
                                             }
                                             else {
                                                out1<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out1<<"1"<<endl;
                                             }
                                             else {
                                                out1<<"0"<<endl;
                                             }
                                     }
                                }
                                }


                        out1.close();

                    }
                    if(gamenumber==1)
                    {
                        ofstream out2;
                        out2.open(filenam2.c_str());
                            out2<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                                if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out2<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out2<<"1"<<endl;
                                             }
                                             else {
                                                out2<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out2<<"1"<<endl;
                                             }
                                             else {
                                                out2<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out2<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out2<<"1"<<endl;
                                             }
                                             else {
                                                out2<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out2<<"1"<<endl;
                                             }
                                             else {
                                                out2<<"0"<<endl;
                                             }
                                     }
                                }
                                }
                        out2.close();

                    }
                    if(gamenumber==2)
                    {
                        ofstream out3;
                        out3.open(filenam3.c_str());
                            out3<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                                if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out3<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out3<<"1"<<endl;
                                             }
                                             else {
                                                out3<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out3<<"1"<<endl;
                                             }
                                             else {
                                                out3<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out3<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out3<<"1"<<endl;
                                             }
                                             else {
                                                out3<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out3<<"1"<<endl;
                                             }
                                             else {
                                                out3<<"0"<<endl;
                                             }
                                     }
                                }
                                }
                        out3.close();

                    }
                    if(gamenumber==3)
                    {
                        ofstream out4;
                        out4.open(filenam4.c_str());
                            out4<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                        if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out4<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out4<<"1"<<endl;
                                             }
                                             else {
                                                out4<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out4<<"1"<<endl;
                                             }
                                             else {
                                                out4<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out4<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out4<<"1"<<endl;
                                             }
                                             else {
                                                out4<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out4<<"1"<<endl;
                                             }
                                             else {
                                                out4<<"0"<<endl;
                                             }
                                     }
                                }
                                }
                        out4.close();
                    }
                    if(gamenumber==4)
                    {
                        ofstream out5;
                        out5.open(filenam5.c_str());
                    out5<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                        if(level>=6)
                        {
                        for(int i=level-6;i<level;i++)
                        {
                             for(int j=0;j<6;j++)
                             {
                                     out5<<ajor[i][j].strength<<endl;
                                     if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                             }
                        }

                        }
                        else
                        {
                          for(int i=0;i<level;i++)
                        {
                             for(int j=0;j<6;j++)
                             {
                                     out5<<ajor[i][j].strength<<endl;
                                     if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                             }
                        }
                        }
                        out5.close();

                    }
                    if(gamenumber==5&&firstsave)
                    {
                            firstsave=false;
                        ofstream out1,out2,out3,out4,out5;
                        out5.open(filenam5.c_str());
                        cout<<lives5<<"\t"<<score5<<"\t"<<level5;
                        out5<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<"\n"<<vx<<"\n"<<vy<<endl;
                         if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out5<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out5<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                     }
                                }
                                }
                                out5.close();
                                out4.open(filenam4.c_str());
                        out4<<lives5<<"\n"<<score5<<"\n"<<level5<<endl;
                        out4.close();
                        out3.open(filenam3.c_str());
                        out3<<lives4<<"\n"<<score4<<"\n"<<level4<<endl;
                        out3.close();
                        out2.open(filenam2.c_str());
                        out2<<lives3<<"\n"<<score3<<"\n"<<level3<<endl;
                        out2.close();
                        out1.open(filenam1.c_str());
                        out1<<lives2<<"\n"<<score2<<"\n"<<level2<<endl;
                        out1.close();

                    }
                    else if(gamenumber==5&&!firstsave)
                    {
                      ofstream out5;
                        out5.open(filenam5.c_str());
                        out5<<lives<<"\n"<<Score<<"\n"<<level<<"\n"<<texr.x<<"\n"<<texr.y<<"\n"<<damg<<"\n"<<colorball<<"\n"<<texr3.x<<"\n"<<hardness<<endl;
                         if(level>=6)
                                {
                                for(int i=level-6;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out5<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                     }
                                }

                                }
                                else
                                {
                                  for(int i=0;i<level;i++)
                                {
                                     for(int j=0;j<6;j++)
                                     {
                                             out5<<ajor[i][j].strength<<endl;
                                             if(ajor[i][j].bom==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                             if(ajor[i][j].pri==true)
                                             {
                                                     out5<<"1"<<endl;
                                             }
                                             else {
                                                out5<<"0"<<endl;
                                             }
                                     }
                                }
                                }
                                out5.close();
                    }

                }
                      }
              }
     }
     //cheeeeeeeet coooooooooooooooooood
     label6:
     while (situation==7)
     {
         if( SDL_PollEvent( &event ) )
              {
                      switch(event.type)
                      {
                      case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                         case SDLK_1:
                            if(level>6)
                            {

                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-6][i].strength=0;
                                    rect(m_renderer,ajor[level-6][i].x,ajor[level-6][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[0][i].strength=0;
                                    rect(m_renderer,ajor[0][i].x,ajor[0][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;
                         case SDLK_2:
                              if(level>6)
                            {

                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-5][i].strength=0;
                                    rect(m_renderer,ajor[level-5][i].x,ajor[level-5][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[1][i].strength=0;
                                    rect(m_renderer,ajor[1][i].x,ajor[1][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;
                         case SDLK_3:
                              if(level>6)
                            {

                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-4][i].strength=0;
                                    rect(m_renderer,ajor[level-4][i].x,ajor[level-4][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[2][i].strength=0;
                                    rect(m_renderer,ajor[2][i].x,ajor[2][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;

                         case SDLK_4:
                              if(level>6)
                            {

                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-3][i].strength=0;
                                    rect(m_renderer,ajor[level-3][i].x,ajor[level-3][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[3][i].strength=0;
                                    rect(m_renderer,ajor[3][i].x,ajor[3][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;
                         case SDLK_5:
                              if(level>6)
                            {

                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-2][i].strength=0;
                                    rect(m_renderer,ajor[level-2][i].x,ajor[level-2][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[4][i].strength=0;
                                    rect(m_renderer,ajor[4][i].x,ajor[4][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;
                        case SDLK_6:
                             if(level>6)
                            {
                                for(int i=0;i<6;i++)
                                {
                                    ajor[level-1][i].strength=0;
                                    rect(m_renderer,ajor[level-1][i].x,ajor[level-1][i].y,200,100,22,170,176,1);

                                }SDL_RenderPresent(m_renderer);
                            }
                            else
                            {
                               for(int i=0;i<6;i++)
                                {
                                    ajor[5][i].strength=0;
                                    rect(m_renderer,ajor[5][i].x,ajor[5][i].y,200,100,22,170,176,1);
                                }SDL_RenderPresent(m_renderer);
                            }
                            situation=6;
                            SDL_RenderCopy(m_renderer,img,NULL,&texr);
                            SDL_RenderPresent(m_renderer);
                            goto label3;
                            break;
                        }
                      }
              }
     }
     label9:
         Mix_PlayMusic(gameover,1);
        while(situation==8)
        {
          int mousex=0;
          int mousey=0;
          const char *font1 ="RETRY";
          const char *font2 ="QUIT THE GAME";
  textRGBA(m_renderer,50,50,font1,5,20,255,255,0,255);
  textRGBA(m_renderer,50,100,font2,5,20,255,255,0,255);

        if( SDL_PollEvent( &event ) )
                switch(event.type)
                {
          case SDL_MOUSEBUTTONDOWN:
              mousex=event.motion.x;
              mousey=event.motion.y;break;
                }
        if(mousex>=50&&mousex<=170&&mousey>=50&&mousey<=80)
                {
                       situation=1;
                       SDL_RenderCopy(m_renderer,img2,NULL,&texr2);
                        rect(m_renderer,0,0,1200,700,22,170,176,1);
                texr.x=texr3.x+80;texr.y=texr3.y-40;
                   Mix_FreeMusic(gameover);
                   goto label8;
                }
                else if(mousex>=50&&mousex<=200&&mousey>=100&&mousey<=130)
                {
                        Mix_FreeMusic(gameover);
                        goto label01;
               }
        }
        }
        label01:
                SDL_DestroyRenderer(m_renderer);
                SDL_DestroyTexture(img);
                SDL_DestroyTexture(img2);
                Mix_FreeMusic(backgroundsound);
                Mix_FreeChunk(jump);
        Mix_CloseAudio();
        SDL_DestroyTexture(img3);
        SDL_DestroyTexture(img4);
        SDL_DestroyTexture(img5);
        SDL_DestroyTexture(img6);
        SDL_DestroyWindow(m_window);
        }

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{
    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0)
        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    //SDL_RenderPresent(Renderer);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );
    // Show the window
    SDL_RenderPresent( Renderer );
}
