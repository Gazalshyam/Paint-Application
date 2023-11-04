#include<graphics.h>
#include<windows.h>
#include<direct.h>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>


using namespace std;
DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight =GetSystemMetrics(SM_CYSCREEN);
int radii,colr,shape;
class Paint{
public:

void scribble_screen(){
    loading();
    cleardevice();
    toolbar();
    setcolor(7);
    rectangle(0,20,screenWidth,21);
    displaybar();
    setcolor(7);
    rectangle(0,58,screenWidth,59);
    canvas();
}
void loading(){//loading the bar
    readimagefile("Logowt.jpg",385,250,585,450);//to display image 
 	setcolor(BLUE);
 	outtextxy(screenWidth/2-40,screenHeight/2,(char*)"Developed by Gazal And Harsha");
 	setcolor(BLUE);
 	rectangle(screenWidth/2-150,screenHeight/2,screenWidth/2+260,screenHeight/2);
	for(int i=0;i<260;i++)//loading bar at begining
	{
		setcolor(13);
		rectangle(screenWidth/2-150,screenHeight/2,screenWidth/2+i,screenHeight/2);
		delay(0);
	}
}
void toolbar(){
    setcolor(WHITE);
rectangle(0,0,screenWidth,20%screenHeight);
setcolor(BLACK);
// outtextxy(10,2,"File");
// button=CreateWindow("Button","File",WS_VISIBLE|WS_CHILD|WS_BORDER,20,50,200,20,hwnd,NULL,NULL,NULL);
// outtextxy(50,2,"Home");
outtextxy(100,2,"Save");
// outtextxy(150,2,"Undo");
// outtextxy(200,2,"Redo");
// Save
// UNDO
// REDO
}

void displaybar(){
    setcolor(WHITE);
rectangle(0,20,screenWidth,50);
//font declaration for displaybar
// eraser creation
for(int i=15;i<=35;i++){
    for(int j=25;j<=40;j++){
        putpixel(i,j,13);
    }
}
setcolor(BLACK);
outtextxy(0,40,"Eraser");
//eraser-brushes partition
setcolor(7);
for(int i=48;i<=50;i++)
rectangle(48,22,i,58);
//brushes circle
setcolor(BLACK);
for(int i=0;i<=3;i++)
circle(78,33,3+i);
outtextxy(53,40,"Brushes");
brushes();
//brushes-color partition
setcolor(7);
for(int i=110;i<=112;i++)
rectangle(110,22,i,58);
//creating a button;
//creating a dropdown menu-bar for brushes containing its pixel sizes 
//color pallete
rectangle(120,25,440,37.5);
setcolor(BLACK);
outtextxy(245,40,"Color Pallete");
for(int i=0;i<15;i++)
colorpallete(i);
//color pallete and shapes boundary
setcolor(7);
for(int i=447;i<=450;i++)
rectangle(447,22,i,58);
//Generating Shapes
setcolor(BLACK);
shapes();
outtextxy(460,40,"Shapes");
//border between shapes and text
setcolor(7);
for(int i=520;i<=523;i++)
rectangle(520,22,i,58);
//text style
setcolor(0);
settextstyle(1,0,4);
outtextxy(522,25,"T");
}

void brushes(){//after the size column
    outtextxy(685,37.5,"<-size");
    setfillstyle(HATCH_FILL,BLUE);
    circle(569,31,2);
    outtextxy(559,40,"2px"); 
    circle(593,31,3);
    outtextxy(587,40,"4px");
    circle(622,31,4);
    outtextxy(615,40,"8px");
    circle(658,31,8);
    outtextxy(645,40,"16px");
}
void colorpallete(int k){
  for(int i=120+20*k;i<=140+20*k;i++){
     for(int j=25;j<=37.5;j++){
           putpixel(i,j,k);
        }

} 
}
void shapes(){
rectangle(453,25,461,37.5);
line(463,25,470,37.5);
circle(480,31,8);
arc(495,45,10,90,18);
}

void canvas(){
POINT cursorposition;

setcolor(BLACK);
settextstyle(1,0,1);
outtextxy(0,70,"canvas");
shape=1;
while(1){
    setcolor(0);
        GetCursorPos(&cursorposition);
        ScreenToClient(GetForegroundWindow(), &cursorposition);//convert screen to window coordinate
        //using canva
        
        if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) &&shape==1&& cursorposition.x > 50 && cursorposition.x <screenHeight  && cursorposition.y > 0 && cursorposition.y < screenWidth) // getkeystate detects the mouse left button press
        {
            setcolor(colr);
                setfillstyle(SOLID_FILL,colr);
                circle(cursorposition.x,cursorposition.y,radii);
        }
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) &&shape==2&& cursorposition.x > 50 && cursorposition.x <screenHeight  && cursorposition.y > 0 && cursorposition.y < screenWidth) // getkeystate detects the mouse left button press
        {
            setcolor(colr);
                setfillstyle(SOLID_FILL,colr);
                rectangle(cursorposition.x,cursorposition.y,cursorposition.x+10,cursorposition.y+15);
        }
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) &&shape==3&& cursorposition.x > 50 && cursorposition.x <screenHeight  && cursorposition.y > 0 && cursorposition.y < screenWidth) // getkeystate detects the mouse left button press
        {
            setcolor(colr);
                setfillstyle(SOLID_FILL,colr);
                   line(cursorposition.x,cursorposition.y,cursorposition.x+10,cursorposition.y+15);
                
        }
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) &&shape==4&& cursorposition.x > 50 && cursorposition.x <screenHeight  && cursorposition.y > 0 && cursorposition.y < screenWidth) // getkeystate detects the mouse left button press
        {
            setcolor(colr);
                setfillstyle(SOLID_FILL,colr);
                arc(cursorposition.x,cursorposition.y,10,90,18);
        }
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) &&shape==5&& cursorposition.x > 50 && cursorposition.x <screenHeight  && cursorposition.y > 0 && cursorposition.y < screenWidth) // getkeystate detects the mouse left button press
        {
            setcolor(colr);
                setfillstyle(SOLID_FILL,colr);
                getch();
        }
                                  
        //save
        if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 100 && cursorposition.x < 140 && cursorposition.y > 2 && cursorposition.y < 20) // getkeystate detects the mouse left button press
        {
            writeimagefile("Screenshot.jpg",0,60,screenWidth,0,screenHeight);
            outtextxy(screenHeight,0,"Screenshot taken      ");
        }
        //eraser
        if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 10 && cursorposition.x < 35 && cursorposition.y > 20 && cursorposition.y < 40) // getkeystate detects the mouse left button press
        {
            
                setcolor(BLACK);
                colr=15;
                radii=3;
                shape=1;            
            outtextxy(screenHeight, 0, (char *)"Eraser In use       ");
            
        }
        //brushes
        if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 53 && cursorposition.x < 89 && cursorposition.y > 20 && cursorposition.y < 40) // getkeystate detects the mouse left button press
        {
            
                setcolor(BLACK);
                colr=0;
                radii=3;
                shape=1;            
            outtextxy(screenHeight, 0, (char *)"Brushes in Use      ");
            
        }
        //colorpallete/*------------------------------------*/
        //Color0
        if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 120 && cursorposition.x < 140 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(BLACK);
                colr=15;
                radii=3;           
            outtextxy(screenHeight, 0, (char *)"Color Black         ");
            
        }
        //color1
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 140 && cursorposition.x < 160 && cursorposition.y > 25&& cursorposition.y <37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(1);
                colr=1;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Blue      ");
            
        }
        //Color2
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 160 && cursorposition.x < 180 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(2);
                colr=2;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Green      ");
            
        }
        //Color3
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 180 && cursorposition.x < 200 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(3);
                colr=3;
                radii=3;            
            outtextxy(screenHeight, 0, (char *)"Color Cyan          ");
            
        }
        //Color4        
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 200 && cursorposition.x < 220 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(4);
                colr=4;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Red           ");
            
        }
        //Color5
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 220 && cursorposition.x < 240 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(5);
                colr=5;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Magenta           ");
            
        }
        //Color6
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 240 && cursorposition.x <260  && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(6);
                colr=6;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Brown             ");
            
        }
        //color7
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 260 && cursorposition.x < 280 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(7);
                colr=7;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Light Gray            ");
            
        }
        //color8
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 280 && cursorposition.x < 300 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(8);
                colr=8;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Dark Gray             ");
            
        }
        //Color9
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 300 && cursorposition.x < 320 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(9);
                colr=9;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Light Blue            ");
            
        }
        //color10
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 320 && cursorposition.x < 340 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(10);
                colr=10;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Light Green           ");
            
        }
        //color11
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 340 && cursorposition.x < 360 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(11);
                colr=11;
                radii=3;     
            outtextxy(screenHeight, 0, (char *)"Color Light Cyan            ");
            
        }
        //color12
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 360 && cursorposition.x < 380 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(12);
                colr=12;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Light Red             ");
            
        }
        //color13
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 380 && cursorposition.x < 400 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(13);
                colr=13;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Light Magenta             ");
            
        }
        //color14
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 400 && cursorposition.x < 420 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(14);
                colr=14;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color Yellow         ");
            
        }
        //color15
        else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 420 && cursorposition.x < 440 && cursorposition.y > 25 && cursorposition.y < 37.5) // getkeystate detects the mouse left button press
        {
            
                setcolor(15);
                colr=15;
                radii=3;
            outtextxy(screenHeight, 0, (char *)"Color White      ");

        }
        /**-----------------------------------*/
        //Shapes
        //rectangle
        if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 453 && cursorposition.x < 461 && cursorposition.y > 25 && cursorposition.y < 37.5)
        {
            colr = 0;
            shape=2;
            outtextxy(screenHeight, 0, (char *)"Rectangle       ");
        }
          //line
        if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 463 && cursorposition.x < 470 && cursorposition.y > 25 && cursorposition.y < 37.5)
        {
            colr = 0;
            shape=3;
            outtextxy(screenHeight, 0, (char *)"Line            ");
        }
        //circle
         if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 472 && cursorposition.x < 488 && cursorposition.y > 25 && cursorposition.y < 37.5)
        {
            colr = 0;
            shape=1;
            outtextxy(screenHeight, 0, (char *)"Circle          ");
        }
        // arc
         if (((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 495 && cursorposition.x < 520 && cursorposition.y > 25 && cursorposition.y < 37.5)
        {
            colr = 0;
            shape=4;
            outtextxy(screenHeight, 0, (char *)"Arc              ");
        }   
        /**--------------------------*/
        //text
        if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 522 && cursorposition.x <550  && cursorposition.y > 25 && cursorposition.y < 37.5)
        {
               colr=0;
               shape=5;
               outtextxy(screenHeight, 0, (char *)"Text              "); 
        }

        //Brush size/**-------------------------------------------*/
         if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 559 && cursorposition.x < 571 && cursorposition.y > 25 && cursorposition.y < 37.5)
            {
               colr=0;
               radii=2;
               outtextxy(screenHeight, 0, (char *)" 2px              "); 
            }
             if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 575 && cursorposition.x < 596 && cursorposition.y > 25 && cursorposition.y < 37.5)
            {
               colr=0;
               radii=4;
               outtextxy(screenHeight, 0, (char *)"4px                "); 
            } if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 600 && cursorposition.x < 630 && cursorposition.y > 25 && cursorposition.y < 37.5)
            {
               colr=0;
               radii=8;
               outtextxy(screenHeight, 0, (char *)"8px                "); 
            } if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorposition.x > 635 && cursorposition.x < 666 && cursorposition.y > 25 && cursorposition.y < 37.5)
            {
               colr=0;
               radii=16;
               outtextxy(screenHeight, 0, (char *)"16px              "); 
            }
    }
        
}    };
// };

int main(){
    //creating the workspace
    int gd=DETECT,gm;
    initgraph(&gd, &gm, (char*)"C:\\MinGW\\lib\\libbgi.a");
    //DWORD is a type of 32 bit unsigned integer using this because format windows depends on this
    //  DWORD screenWidth =GetSystemMetrics(SM_CXSCREEN);//get screen width that is the x coordinates
    //  DWORD screenHeight =GetSystemMetrics(SM_CYSCREEN);//get screen height that is the y coordinates
    // https://www.youtube.com/watch?v=SLudnS7nzaI&list=PL5UFsTza4wWSNhe0xuO6ELw7ORU-UHNDO&index=36
    initwindow(screenWidth,screenHeight,(char*)"Paint Application",-2,0,false,true);//https://www.youtube.com/watch?v=puX16SFgS9I
    /**width,height,title->is important otherwise can't access the main functions like minimize ,maximie and close buttons, 
    * space from left most corner, righmost corner, double buffering-> used ot show no flicker or any other artifacts, use of close button-> true to use it */
   setbkcolor(WHITE);
   cleardevice();
    Paint p;
    p.scribble_screen();
    getch();
    closegraph();
    return 0;
}