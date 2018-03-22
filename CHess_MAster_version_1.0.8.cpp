#include<graphics.h>
#include<bits/stdc++.h>

const char BOard_SEt[8][8] = {{'R','N','B','Q','K','B','N','R'},  {'P','P','P','P','P','P','P','P'},
                              {'\0','\0','\0','\0','\0','\0','\0','\0'},  {'\0','\0','\0','\0','\0','\0','\0','\0'},
                              {'\0','\0','\0','\0','\0','\0','\0','\0'},  {'\0','\0','\0','\0','\0','\0','\0','\0'},
                              {'p','p','p','p','p','p','p','p'},  {'r','n','b','q','k','b','n','r'}};

char new_board[8][8], array[200],   EMPTY_array[8][8],FILL_array[8][8];

int S_KIng[2], B_KIng[2];

void PLay();

int  WElcome1();
int  WElcome2();
void LOading1();
void LOading2();

void NEw_GAme();
void BOard();
void NEw_GUti();
int  NEw_CHess_GAme();
void NEw_GAme_COlour();

int HInts_BOard();
int HInts_KIng_MOve();
int HInts_QUeen_MOve();
int HInts_ROok_MOve();
int HInts_BIshop_MOve();
int HInts_KNight_MOve();
int HInts_PAwn_MOve();

void MOve();
int  GAme_MOde();
int  GAme_INput_CHeak();
int  GAme_INput_CHeak_CLear();

int   TEarn_VAlidity(int,int, int);
void  CUrrent_POsition(int a[]);
int   FIrst_cordinate_Check(int, int);
int   MOve_VAlidity(int,int, int,int);
int   MOve_GUti(int,int, int,int);
int   CHeak_GUti_move(int,int, int,int);
char* COnvert_STring(int, int);

int  PAwn(int,int, int,int);
int  KNight(int,int, int,int);
int  ROok(int,int, int,int);
int  KIng(int,int, int,int);
int  BIshop(int,int, int,int);
int  QUeen(int,int, int,int);
void PAwn_8(int,int, int,int);

void TRarn_CLear();
int  POsition_free(int, int);
int  POsition_SMall(int,int);
int  POsition_BIg(int, int);

int KIng_CHeck();
int BIg_KIng_CHeck(int,int);
int SMall_KIng_CHeck(int,int);
int KIng_POsition(int[], int);
int MY_GUti_CHeck(int,int, int,int);

int  BOx(int,int, int,int, int);
void bcreate(int,int, int,int, int);
void Mbcreate(int,int, int,int, int);
void createwindo(int,int, int,int, int);


int main()
{
    initwindow(1365, 748);


    PLay();

    getch();
    return 0;
}

void PLay()
{
    WElcome1();
    NEw_GAme();
    GAme_MOde();
    GAme_INput_CHeak();
    NEw_GUti();
    MOve();
}

int NEw_CHess_GAme()
{
    NEw_GAme();             /// CReate [ NEw_BOard ] Dice
    GAme_MOde();            /// ENter GAme MOde [ Single Or Double ]
    GAme_INput_CHeak();     /// CReate [ NEw_GAme, MOve_VAlidity ] Dice
    NEw_GAme_COlour();      /// CHange NEw GAme TExt COlour
    NEw_GUti();             /// SEt GUti POsition INitialy
    MOve();                 /// MAintain MOve
}

int WElcome1()
{
    bcreate(0, 0, 1358, 735, 9);
    bcreate(150, 100, 1195, 630, 0);

    setcolor(10);       settextstyle(6,0,7);    sprintf(array, "WELCOME");      outtextxy(430,200, array);
                        settextstyle(6,0,5);    sprintf(array, "To The");       outtextxy(580,300, array);

    setcolor(13);       settextstyle(6, 0, 7);  sprintf(array, "SMart CHess");  outtextxy(420,380, array);
                                                sprintf(array, "...GAme...");   outtextxy(480,480, array);
    bcreate(1035,530, 1178, 600, 9);
    setcolor(11);       settextstyle(0, 0, 3);  sprintf(array, "NEXT");         outtextxy(1060,552, array);

    int x,y;

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(50);
        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1040 && x<1173 && y>535 && y<595)
        {
            cleardevice();
            WElcome2();
            break;
        }
    }
}

int WElcome2()
{
    bcreate(0, 0, 1358, 735, 9);
    bcreate(150, 100, 1195, 630, 0);

    setcolor(13);   settextstyle(6, 0, 4);      sprintf(array, "Created by,");      outtextxy(420,180, array);

    delay(250);

    setcolor(10);        settextstyle(6, 0, 3);
    sprintf(array, "Name      : Dipta Dhar");                       outtextxy(420,240, array);
    sprintf(array, "ID           : 20131101068");                   outtextxy(420,270, array);
    sprintf(array, "Phone N. : 01559135799");                       outtextxy(420,300, array);
    sprintf(array, "Email      : dipta.bsmrstu.cse@gmail.com");     outtextxy(420,330, array);
    sprintf(array, "B.Sc Engg. in Computer Science & Engineering"); outtextxy(420,390, array);
    sprintf(array, "Bangabandhu Sheikh Mujibur Rahman");            outtextxy(420,420, array);
    sprintf(array, "Science & Technology University,");             outtextxy(420,450, array);
    sprintf(array, "Gopalganj-8100.");                              outtextxy(420,480, array);

    bcreate(1035,530, 1178, 600, 9);
    setcolor(11);       settextstyle(0, 0, 3);      sprintf(array, "NEXT");      outtextxy(1060,552, array);
    bcreate(167,530,  310,600,  9);
    setcolor(11);       settextstyle(0, 0, 3);      sprintf(array, "BACK");      outtextxy(190,552, array);

    int x,y;

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(50);
        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1040 && x<1173 && y>535 && y<595)
        {
            cleardevice();
            LOading1();
            return 0;
        }
        else if(x>172 && x<305 && y>535 && y<595)
        {
            cleardevice();
            WElcome1();
            return 0;
        }
    }

}

void LOading1()
{
    bcreate(0, 0, 1358, 735, 9);
    bcreate(130, 80, 1215, 650, 0);

    setcolor(9);        settextstyle(6, 0, 7);      sprintf(array, "SMart CHess");      outtextxy(420,120, array);
                                                    sprintf(array, "...GAme...");       outtextxy(480,220, array);
    bcreate(565, 347, 935, 390,  7);
    bcreate(400, 347, 570, 390,  0);
    setcolor(5);        settextstyle(9, 0, 3);      sprintf(array, "LOading...");       outtextxy(413, 355, array);

    for(int x=570; x<930; x++)
    {
        for(int y=352; y<385; y++)
        {
            putpixel(x, y, 12);
        }
        delay(10);
    }

    setcolor(9);        settextstyle(6, 0, 5);      sprintf(array, "LOading.. COmplete....!");      outtextxy(400,480, array);

    bcreate(1055,560, 1195,630, 9);
    setcolor(11);       settextstyle(0, 0, 3);      sprintf(array, "NEXT");                         outtextxy(1078,582, array);

    bcreate(150,560, 290,630, 9);
    setcolor(11);       settextstyle(0, 0, 3);      sprintf(array, "BACK");                         outtextxy(173,582, array);

    int x,y;

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(10);
        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1060 && x<1190 && y>565 && y<625)      /// Next....!
        {
            cleardevice();
            LOading2();
            break;
        }
        else if(x>155 && x<285 && y>565 && y<625)   /// BACK......!
        {
            cleardevice();
            WElcome2();
            break;
        }
    }
}

void LOading2()
{

    int a,b;

    while(1)
    {

        setlinestyle(0, 0, 0);

        bcreate(339,30, 961,127, 9);
        setcolor(9);        settextstyle(6, 0,  5);     sprintf(array, "!...........HInTS...........!");     outtextxy(368,55, array);

        bcreate(1190,650, 1340, 720, 9);
        setcolor(11);       settextstyle(0, 0,  3);     sprintf(array, "PLAY");     outtextxy(1218,672, array);

        bcreate(30,650, 170,720, 9);
        setcolor(11);       settextstyle(0, 0, 3);      sprintf(array, "BACK");     outtextxy(53,672, array);

        int x1,x2, y1,y2, x,y, xd, yd, Td, d;   /// xd = X axis Distance & yd = Y axis Distance & Td = Total Distance

        x=100, y=170, xd=500, yd=50, Td=450;    /// X & Y are Change, Then all are change

        x1=x+20, x2=x+xd-20, y1=y+20, y2=y+Td-20;

        d = Td/6-7;

        Mbcreate(x,y, x+xd, y+Td, 15);
        bcreate(x1,y1, x2, y2, 0);

        setlinestyle(0, 0, 5);
        for(int i=0; i<5; i++)
        {
            line(x1+5, y1+=d, x2-5, y1);
        }

        x1 = x+80, y1=y+20+(d/5);

        setcolor(9);    settextstyle(6, 0, 5);
        sprintf(array, "K = KING");     outtextxy(x1, y1, array);           sprintf(array, "Q = QUEEN");        outtextxy(x1,y1+=d, array);
        sprintf(array, "R = ROOK");     outtextxy(x1,y1+=d, array);         sprintf(array, "B = BISHOP");       outtextxy(x1,y1+=d, array);
        sprintf(array, "N = KNIGHT");   outtextxy(x1,y1+=d, array);         sprintf(array, "P = PAWN");         outtextxy(x1+2,y1+=d, array);

        setlinestyle(0, 0, 3);

        x1 = x+650,     y1 = y+28;
        x2 = x1+480,    y2 = y1+Td-20;

        d = (y2-y1)/6;

        bcreate(x1+20,y1-45, x2-20, y1+5, 13);
        setcolor(10);   settextstyle(6, 0, 3);      sprintf(array, "CLICK the below Boxes");     outtextxy(x1+65, y1-33, array);

        bcreate(x1,y1, x2,y2, 0);
        setlinestyle(0, 0, 5);

        //char *con[] = {"K [King]", "Q [Queen]", "R [Rook]", "B [Bishop]", "N [Knight]", "P [Pawn]" };

        settextstyle(6, 0, 5);

        setcolor(14);   sprintf(array, "K [King]");     outtextxy(x1+100, y1+10, array);   y1 += d;     setcolor(8);    line(x1+6, y1, x2-7, y1);
        setcolor(14);   sprintf(array, "Q [Queen]");    outtextxy(x1+100, y1+10, array);   y1 += d;     setcolor(8);    line(x1+6, y1, x2-7, y1);
        setcolor(14);   sprintf(array, "R [Rook]");     outtextxy(x1+100, y1+10, array);   y1 += d;     setcolor(8);    line(x1+6, y1, x2-7, y1);
        setcolor(14);   sprintf(array, "B [Bishop]");   outtextxy(x1+100, y1+10, array);   y1 += d;     setcolor(8);    line(x1+6, y1, x2-7, y1);
        setcolor(14);   sprintf(array, "N [Knight]");   outtextxy(x1+100, y1+10, array);   y1 += d;     setcolor(8);    line(x1+6, y1, x2-7, y1);
        setcolor(14);   sprintf(array, "P [Pawn]");     outtextxy(x1+100, y1+10, array);   y1 += d;

        /*for(int i=0; i<6; i++)
        {
            setcolor(14);    outtextxy(x1+100, y1+10, con[i]);   y1 += d;
            setcolor(8);    if(i!=5) line(x1+6, y1, x2-7, y1);
        }*/
        setlinestyle(0, 0, 0);

        x1 = (x+650)+5,     x2 = (x1+480)-(5+6);    /// [5=x1 plus side] && [6=x2 minus side]
        y1 = (y+26)+5,      y2 = y+Td+8;

        d = (y2-y1)/6-7;

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(50);
        }
        getmouseclick(WM_LBUTTONDOWN, a,b);


        if(a>1194 && a<1336 && b>654 && b<715)          /// PLAY....! [bcreate(1190,650, 1340, 720, 9);]
        {
            cleardevice();
            break;
        }
        else if(a>34 && a<166 && b>654 && b<715)       /// BACK.....! [bcreate(30,650, 170,720, 9);]
        {
            cleardevice();
            LOading1();
            break;
        }

        else if(a>x1 && a<x2 && b>y1 && b<y1+d)
        {
            cleardevice();
            HInts_KIng_MOve();
        }
        else if(a>x1 && a<x2 && b>(y1+(1*d)+(1*7)) && b<(y1+(2*d)+(1*7)))
        {
            cleardevice();
            HInts_QUeen_MOve();
        }
        else if(a>x1 && a<x2 && b>(y1+(2*d)+(2*7)) && b<(y1+(3*d)+(2*7)))
        {
            cleardevice();
            HInts_ROok_MOve();
        }
        else if(a>x1 && a<x2 && b>(y1+(3*d)+(3*7)) && b<(y1+(4*d)+(3*7)))
        {
            cleardevice();
            HInts_BIshop_MOve();
        }
        else if(a>x1 && a<x2 && b>(y1+(4*d)+(4*7)) && b<(y1+(5*d)+(4*7)))
        {
            cleardevice();
            HInts_KNight_MOve();
        }
        else if(a>x1 && a<x2 && b>(y1+(5*d)+(5*7)) && b<(y1+(6*d)+(5*7)))
        {
            cleardevice();
            HInts_PAwn_MOve();
        }

    }
}

int HInts_BOard()
{
    int i,j,x1,x2,y1,y2,c;
    int b_x1, b_x2, b_y1, b_y2;
    b_x1=300, b_x2=359, b_y1=150, b_y2=210;

    setlinestyle(0, 0, 0);

    Mbcreate(0,0, 1365,748, 9);        /// Outside Rectangle
    bcreate(45,35, 1325,720, 0);

    bcreate(905, 295, 1275, 455, 9);    /// GUTI Show Dice
    Mbcreate(915, 305, 1265, 445, 0);

    bcreate(235, 90, 845,693, 9);       /// Board Side Rectangle
    bcreate(295,145, 783,635, 0);

    bcreate(1150,610, 1295, 680, 9);
    setcolor(11);       settextstyle(6, 0,  3);     sprintf(array, "BACK");     outtextxy(1175,632, array);

    x1 = b_x1, y1 = b_y1, x2 = b_x2, y2 = b_y2;

    for(i=c=0; i<8; i++)
    {
        if(c%2 == 0)
            for(j=0; j<8; j++)
            {
                if(j%2==1)
                    bar(x1, y1,  x2,y2);

                x1 += 60,   x2 += 60;
            }
        else
            for(j=0; j<8; j++)
            {
                if(j%2 != 1)
                    bar(x1, y1,  x2,y2);

                x1 += 60,   x2 += 60;
            }
        y1 += 60,   y2 += 60,   x1 = b_x1,    x2 = b_x2;
        c++;
    }
}

int HInts_PAwn_MOve()
{
    HInts_BOard();
    setcolor(9);    settextstyle(6, 0,  5);     sprintf(array, "!...PAWN...!");     outtextxy(930, 330, array);
                    settextstyle(6, 0,  5);     sprintf(array, "...MOVE...");       outtextxy(950, 370, array);

    int x,y, a,b, fx,fy, r, x1,y1, col;

    a=314,  b=161;      x1=6;

    srand(time(NULL));          sprintf(array, "P");

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            if(x1==6)   r = rand()%8;

            fx=r, fy=x1;

            setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+3+(fx*60), b+(fy*60), array);
            delay(1000);
            col = fx+fy;
            col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
            circle((a+18+(fx*60)), (b+20+(fy*60)), 13);

            x1--;

            if(x1<0) x1=6;

        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }
}

int HInts_KNight_MOve()
{
    HInts_BOard();
    setcolor(9);    settextstyle(6, 0,  4);     sprintf(array, " !....KNIGHT....!");    outtextxy(930, 330, array);
                    settextstyle(6, 0,  5);     sprintf(array, " ...MOVE...");          outtextxy(950, 370, array);

    srand(time(NULL));      sprintf(array, "N");

    int x,y, a,b, fx,fy, rx,ry, r, col;     a=314,  b=161;

    fx = rand()%8,  fy = rand()%8;

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            rx=rand()%8,    ry=rand()%8;

            r = ((fx-rx)*(fx-rx)) + ((fy-ry)*(fy-ry));    if(r != 5)  continue;

            setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(rx*60), b+(ry*60), array);
            delay(1200);

            col = rx+ry;
            col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
            circle((a+18+(rx*60)), (b+20+(ry*60)), 13);

            fx=rx,  fy=ry;

        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }
}

int HInts_BIshop_MOve()
{
    HInts_BOard();
    setcolor(9);    settextstyle(6, 0,  4);     sprintf(array, " !....BISHOP....!");    outtextxy(930, 330, array);
                    settextstyle(6, 0,  5);     sprintf(array, "...MOVE...");    outtextxy(950, 370, array);

    int x,y, a,b, fx,fy, r, x1,y1, col;

    a=314,  b=161, fx=3, fy=4;

    srand(time(NULL));          sprintf(array, "B");

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(fy*60), array);
            delay(1000);
            col = fx+fy;
            col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
            circle((a+18+(fx*60)), (b+20+(fy*60)), 13);

            r = rand()%2;

            if(r==0)
            {
                x1 = rand()%7;

                if(x1==3)  x1=5;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+((x1+1)*60), array);
                delay(1000);
                col = x1+x1+1;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+((x1+1)*60)), 13);
            }
            else if(r==1)
            {
                x1 = rand()%8;

                if(x1==3) x1=5;

                y1=7-x1;
                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+(y1*60), array);
                delay(1000);
                col = x1+y1;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+(y1*60)), 13);
            }

        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }
}

int HInts_ROok_MOve()
{
    HInts_BOard();
    setcolor(9);    settextstyle(6, 0,  4);     sprintf(array, " !.....ROOK.....!");    outtextxy(930, 330, array);
                    settextstyle(6, 0,  5);     sprintf(array, "...MOVE...");           outtextxy(950, 370, array);

    int x,y, a,b, fx,fy, r, x1, col;

    a=314,  b=161, fx=3, fy=4;

    srand(time(NULL));          sprintf(array, "R");

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(fy*60), array);
            delay(1000);
            col = fx+fy;
            col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
            circle((a+18+(fx*60)), (b+20+(fy*60)), 13);

            r = rand()%2;

            if(r==0)
            {
                x1 = rand()%8;

                if(x1==4)   x1=2;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(x1*60), array);
                delay(1000);
                col = x1+fx;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(fx*60)), (b+20+(x1*60)), 13);
            }
            else if(r==1)
            {
                x1 = rand()%8;

                if(x1==3) x1=6;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+(fy*60), array);
                delay(1000);
                col = x1+fy;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+(fy*60)), 13);
            }
        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }
}

int HInts_QUeen_MOve()
{
    HInts_BOard();
    setcolor(9);    settextstyle(6, 0,  4);     sprintf(array, " !....QUEEN....!");     outtextxy(930, 330, array);
                    settextstyle(6, 0,  5);     sprintf(array, "...MOVE...");           outtextxy(950, 370, array);

    int x,y, a,b, fx,fy, r, x1,y1, col;

    a=312,  b=161, fx=3, fy=4;

    srand(time(NULL));          sprintf(array, "Q");

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(fy*60), array);
            delay(1000);
            col = fx+fy;
            col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
            circle((a+18+(fx*60)), (b+20+(fy*60)), 13);

            r = rand()%4;

            if(r==0)
            {
                x1 = rand()%7;

                if(x1==3)  x1=5;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+((x1+1)*60), array);
                delay(1000);
                col = x1+x1+1;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+((x1+1)*60)), 13);

            }
            else if(r==1)
            {
                x1 = rand()%8;

                if(x1==4)   x1=2;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(x1*60), array);
                delay(1000);
                col = x1+fx;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(fx*60)), (b+20+(x1*60)), 13);
            }
            else if(r==2)
            {
                x1 = rand()%8;

                if(x1==3) x1=5;

                y1=7-x1;
                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+(y1*60), array);
                delay(1000);
                col = x1+y1;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+(y1*60)), 13);
            }
            else if(r==3)
            {
                x1 = rand()%8;

                if(x1==3) x1=6;

                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(x1*60), b+(fy*60), array);
                delay(1000);
                col = x1+fy;
                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(x1*60)), (b+20+(fy*60)), 13);
            }

        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }
}

int HInts_KIng_MOve()
{
    HInts_BOard();

    setcolor(9);    settextstyle(6, 0,  5);         sprintf(array, "!....KING....!");   outtextxy(930, 330, array);
                                                    sprintf(array, "...MOVE...");       outtextxy(950, 370, array);

    int x,y, a, b, fx,fy, r, cx,cy, col;    /// a=312, b=161;

    a=312,  b=161, fx=3, fy=4;

    cx=fx,  cy=fy;

    srand(time(NULL));          sprintf(array, "K");

    while(1)
    {

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            r = rand()%8;

                 if(r==0)   fx--, fy--;     else if(r==1)   fy--;       else if(r==2)   fx++, fy--;
            else if(r==3)   fx--;           /*      [X,Y]      */       else if(r==4)   fx++;
            else if(r==5)   fx--, fy++;     else if(r==6)   fy++;       else if(r==7)   fx++, fy++;

            if(fx>=0 && fx<8 && fy>=0 && fy<8)
            {
                setcolor(9);    settextstyle(6, 0, 4);      outtextxy(a+(fx*60), b+(fy*60), array);
                delay(1000);

                col = fx+fy;

                col%2==0 ? setcolor(BLACK) : setcolor(WHITE);     setlinestyle(0, 0, 30);
                circle((a+18+(fx*60)), (b+20+(fy*60)), 13);

                cx=fx, cy=fy;

            }
            else    fx = cx, fy=cy;

        }
        getmouseclick(WM_LBUTTONDOWN, x,y);

        if(x>1155 && x<1290 && y>615 && y<675)
        {
            cleardevice();
            break;
        }
    }

}

void NEw_GAme()
{
    int i,j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            new_board[i][j]=BOard_SEt[i][j];

    BOard();
}

void BOard()
{
    createwindo(0,0, 1365,748, 9);


    int i,j,x1,x2,y1,y2,c;
    int b_x1, b_x2, b_y1, b_y2;
    b_x1=250, b_x2=309, b_y1=150, b_y2=210;

    Mbcreate(186,  88, 792, 692, 8);
    Mbcreate(248+2, 148+2, 730-2, 632-2, 0);

    setcolor(7);    setlinestyle(0, 10, 4);     rectangle(248, 148, 730, 632);   /// Inside rectangle

    setlinestyle(0, 0, 0);

    x1 = b_x1, y1 = b_y1, x2 = b_x2, y2 = b_y2;

    for(i=c=0; i<8; i++)
    {
        if(c%2 == 0)
            for(j=0; j<8; j++)
            {
                if(j%2==1)      bar(x1, y1,  x2,y2);

                x1 += 60,   x2 += 60;
            }
        else
            for(j=0; j<8; j++)
            {
                if(j%2 != 1)    bar(x1, y1,  x2,y2);

                x1 += 60,   x2 += 60;
            }
        y1 += 60,   y2 += 60,   x1 = b_x1,    x2 = b_x2;
        c++;
    }

    setcolor(8);    settextstyle(9, 0, 4);      sprintf(array, "SMart CHess");  outtextxy(363, 90, array);

    //bcreate(1130,15+25, 1335, 80+25, 7);
    //setcolor(8);    settextstyle(6,0,3);    outtextxy(1148, 35+25, "NEw GAme");
    bcreate(1130+33,15+22+80, 1335, 80+80+3, 7);
    setcolor(7);    settextstyle(6,0,2);        sprintf(array, "EXit GAme");    outtextxy(1148+30, 35+80+13, array);

    int x,y, col;

    x=950, y=180, x1=1335, y1=330,y2=680, col=7;        /// CHange it TO NEw CReate WIndow

    bcreate(x,y, x1, y1, col);

    Mbcreate(x+5,y+5, x1-5, y+30, 8);
    setcolor(7);   settextstyle(6, 0, 2);       sprintf(array, "GAme MOde");    outtextxy(x+10+(x1-x)/4, y+4, array);

    bcreate(x+20, y+80, x+(x1-x)/2-50, y1-20,  13);
    setcolor(8);   settextstyle(6, 0, 3);       sprintf(array, "SIngle");       outtextxy(x+35, y1-59, array);

    bcreate(x+(x1-x)/2+35, y+80, x1-20, y1-20, 13);
    setcolor(8);   settextstyle(6, 0, 3);       sprintf(array, "DOuble");       outtextxy(x1-144, y1-59, array);

    /*bcreate(x,y1+20, x1,y2,  7);        /// MOVE VALIDITY DICE
    Mbcreate(x+5,y1+25, x1-5, y1+55, 8);                setcolor(7);   settextstyle(6, 0, 3);      outtextxy(x+(x1-x)/5+5, y1+24, "MOve VAlidity");


    bcreate(x1-100, y1+70, x1-20, y1+120, 11);          setcolor(13);    settextstyle(6, 0, 1);  outtextxy(x+20, y1+85, "MOve COunt [M.C.]:");
    Mbcreate(x1-100, y1+140, x1-20, y1+200, 9);         setcolor(13);    settextstyle(6, 0, 2);  outtextxy(x+20, y1+160, "ENter YOur MOve:");*/

    /*settextstyle(6, 0, 3);         outtextxy(x1-68, y1+82, "1");
    Mbcreate(x+30, y2-100, x1-35,y2-58, 4);     /// TErn CLear
    setcolor(4);    settextstyle(6,0,2);    outtextxy(x+63, y2-90, "!....INvalid  MOve....!");
    setcolor(4);    settextstyle(6,0,1);    outtextxy(x+50, y2-90, "!...NOT YOUR TURN...!");*/

}

int GAme_INput_CHeak_CLear()
{
    Mbcreate(1130,15+25, 1335, 80+25, 9);   /// NEw GAme
    Mbcreate(950,350, 1335,680,  9);           /// MOve VAlidity DIce
}

int GAme_INput_CHeak()
{
    int x,x1,x2, y,y1,y2;

    x=950, y=180, x1=1335, y1=330,y2=680;

    bcreate(1130,15+25, 1335, 80+25, 7);
    setcolor(8);    settextstyle(6,0,3);        sprintf(array, "NEw GAme");             outtextxy(1148, 35+25, array);

    bcreate(x,y1+20, x1,y2,  7);
    Mbcreate(x+5,y1+25, x1-5, y1+55, 8);
    setcolor(7);    settextstyle(6, 0, 3);      sprintf(array, "MOve VAlidity");        outtextxy(x+(x1-x)/5+5, y1+24, array);

    bcreate(x1-100, y1+70, x1-20, y1+120, 11);
    setcolor(13);   settextstyle(6, 0, 1);      sprintf(array, "MOve COunt [M.C.]:");   outtextxy(x+20, y1+85, array);

    Mbcreate(x1-100, y1+140, x1-20, y1+200, 9);
    setcolor(13);   settextstyle(6, 0, 2);      sprintf(array, "ENter YOur MOve:");     outtextxy(x+20, y1+160, array);
}

void NEw_GUti()
{
    int x1,y1,d, b_x1, b_y1, b, s;

    b_x1=247, b_y1=160, d=60, b=17, s=20;   /// b=Big, s=Small
    x1=b_x1, y1=b_y1;

    settextstyle(6, 0, 4);  setcolor(GREEN);
    sprintf(array, "R");    outtextxy(x1+=b,  y1, array);     sprintf(array, "N");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "B");    outtextxy(x1+=d,  y1, array);     sprintf(array, "Q");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "K");    outtextxy(x1+=d,  y1, array);     sprintf(array, "B");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "N");    outtextxy(x1+=d,  y1, array);     sprintf(array, "R");      outtextxy(x1+=d,  y1, array);

    x1=b_x1, y1=b_y1+d;             sprintf(array, "P");
    outtextxy(x1+=s,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);

    x1=b_x1, y1=(b_y1 + 6*d);       setcolor(9);
    outtextxy(x1+=s,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);
    outtextxy(x1+=d,  y1, array);     outtextxy(x1+=d,  y1, array);

    x1=b_x1, y1=(b_y1 + 7*d);
    sprintf(array, "R");    outtextxy(x1+=b,  y1, array);     sprintf(array, "N");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "B");    outtextxy(x1+=d,  y1, array);     sprintf(array, "Q");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "K");    outtextxy(x1+=d,  y1, array);     sprintf(array, "B");      outtextxy(x1+=d,  y1, array);
    sprintf(array, "N");    outtextxy(x1+=d,  y1, array);     sprintf(array, "R");      outtextxy(x1+=d,  y1, array);
}

void MOve()
{
    int c=0,fcc, x1,y1,x2,y2, valid, tv, kc, colour, BOX, MGC;

    int a,a1,a2, b,b1,b2;
    a=950, b=180, a1=1335, b1=330,b2=680;

    while(1)
    {
        c%2==0 ? colour=9 : colour=2;
        Mbcreate(a1-100,b1+140, a1-20,b1+200, colour);         /// TURN DICE [ E. Y. M. ]

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(10);
        }
        getmouseclick(WM_LBUTTONDOWN, x1, y1);

        if(x1>1167 && x1<1320 && y1>121 && y1<156)    exit(1);    /// Exit...  [ bcreate(1163,117, 1335, 163, 7); ]

        if(x1>1134 && x1<1320 && y1>44 && y1<98)                    /// NEw... [ bcreate(1130,40, 1335, 105, 7); ]
        {
            setlinestyle(0, 0, 0);
            GAme_INput_CHeak_CLear();
            NEw_CHess_GAme();
            return;
        }



        (x1>250 && x1<725 && y1>150 && y1<625)  ?  BOX=1 : BOX=0;   if(BOX==0)  {  Mbcreate(980,580, 1300,622, 7);  continue;  }

        tv = TEarn_VAlidity(x1,y1, c);                              if(tv==0)   continue;

        fcc = FIrst_cordinate_Check(x1, y1);                        if(fcc==0)  continue;





        c%2==0 ? setcolor(9) : setcolor(2);
        settextstyle(6, 0, 3);      sprintf(array, "1");  outtextxy(a1-68, b1+82, array);   /// bcreate(a1-100,a1+70, a1-20,a1+120, 11);

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(10);
        }
        getmouseclick(WM_LBUTTONDOWN, x2, y2);



        MGC = MY_GUti_CHeck(x1,y1, x2,y2);
        if(MGC==1)
        {
            Mbcreate(980,580, 1300,622, 4);
            setcolor(4);    settextstyle(6,0,2);    sprintf(array, "!..YOur KIng IS CHeck..!");    outtextxy(985, 590, array);
            continue;
        }



        ///TRarn_CLear();

        c%2==0 ? setcolor(2) : setcolor(9);
        settextstyle(6, 0, 3);  sprintf(array, "2");  outtextxy(a1-68, b1+82, array);

        valid = MOve_VAlidity(x1,y1, x2, y2);

        if(valid == 1)  {c++;   kc = KIng_CHeck();}
        if(c==10) c=0;

    }
}

int MY_GUti_CHeck(int x1,int y1, int x2,int y2)
{
    int a[4], x,y;
    a[0]=x1,a[1]=y1,  a[2]=x2,a[3]=y2;      CUrrent_POsition(a);

    x1 = ((a[0]-250)/60)-1;     y1 = ((a[1]-150)/60)-1;     x2 = ((a[2]-250)/60)-1;     y2 = ((a[3]-150)/60)-1;

    for(int i=0; i<8; i++) for(int j=0; j<8; j++) EMPTY_array[i][j] = new_board[i][j];
    EMPTY_array[x2][y2] = EMPTY_array[x1][y1];

///----------------------------------------------------------------------------|
    int GUTI[4], S;                                                         ///|
                                                                            ///|
    (EMPTY_array[x2][y2]>='a' && EMPTY_array[x2][y2]<='z')  ?  S=1 : S=0;   ///|    [S==1, GUTI is SMall], [S==1, GUTI is BIG]
                                                                            ///|
    if(S==1)    KIng_POsition(GUTI, 1);                                     ///|    [FIND_KING_POSITION]
    else        KIng_POsition(GUTI, 0);                                     ///|
                                                                            ///|
    x=GUTI[0], y=GUTI[1];                                                   ///|
///----------------------------------------------------------------------------|


    int SBK;
    if(S==1)
    {
        SBK = SMall_KIng_CHeck(x,y);
    }
    else
    {
        SBK = BIg_KIng_CHeck(x,y);
    }

    return SBK;
}

int SMall_KIng_CHeck(int x2, int y2)
{
    int val;

    for(int x1=0; x1<8; x1++)
    {
        for(int y1=0; y1<8; y1++)
        {
            if(EMPTY_array[x1][y1]>='A' && EMPTY_array[x1][y1]<='Z')
            {
                val = CHeak_GUti_move(x1,y1, x2,y2);
            }
        }

        if(val==1)  return 1;
    }

    return 0;
}

int BIg_KIng_CHeck(int x2, int y2)
{
    int val;

    for(int x1=0; x1<8; x1++)
    {
        for(int y1=0; y1<8; y1++)
        {
            if(EMPTY_array[x1][y1]>='a' && EMPTY_array[x1][y1]<='a')
            {
                val = CHeak_GUti_move(x1,y1, x2,y2);
            }
        }

        if(val==1)  return 1;
    }

    return 0;
}

int KIng_POsition(int a[], int guti)    /// [GUti==1 mean's SMall GUTI],  [GUti==0 mean's BIG GUTI]
{
    int c=0;

    if(guti==1)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(EMPTY_array[i][j]=='k')
                {
                    a[0]=i,   a[1]=j,   c=1;
                    break;
                }
            }

            if(c==1)    break;
        }
    }

    else
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(EMPTY_array[i][j]=='K')
                {
                    a[0]=i,   a[1]=j,   c=1;
                    break;
                }
            }

            if(c==1)    break;
        }
    }

}

int TEarn_VAlidity(int x,int y, int c)
{
    ///Mbcreate(a+30,b2-100, a1-35,b2-58, 4);      a=950, b=180, a1=1335, b1=330,b2=680;

    Mbcreate(980,580, 1300,622, 7); ///TURN CLEAR

    int a[4]; a[0]=x, a[1]=y;   CUrrent_POsition(a);
    x = ((a[0]-250)/60)-1;     y = ((a[1]-150)/60)-1;

    if(c%2==0 && new_board[y][x]>='A' && new_board[y][x]<='Z')
    {
        Mbcreate(980,580, 1300,622, 4);
        setcolor(4);    settextstyle(6,0,1);    sprintf(array, "!...NOT YOUR TURN...!");    outtextxy(1000, 590, array);  ///outtextxy(a+50, b2-90, "!...NOT YOUR TURN...!");
        return 0;
    }
    else if(c%2==1 && new_board[y][x]>='a' && new_board[y][x]<='z')
    {
        Mbcreate(980,580, 1300,622, 4);
        setcolor(4);    settextstyle(6,0,1);    sprintf(array, "!...NOT YOUR TURN...!");    outtextxy(1000, 590, array);
        return 0;
    }

    return 1;
}

void CUrrent_POsition(int a[])
{
    int x,y,d, x1, y1, x2, y2;
    x=250, y=150, d=60;

    x1=x2=x, y1=y2=y;

    while(1)
    {
        if(x1>=a[0] && y1>=a[1] && x2>=a[2] && y2>=a[3]) break;

        if(x1<a[0])   x1 += d;
        if(y1<a[1])   y1 += d;
        if(x2<a[2])   x2 += d;
        if(y2<a[3])   y2 += d;
    }

    a[0]=x1, a[1]=y1, a[2]=x2, a[3]=y2;
}

int FIrst_cordinate_Check(int x, int y)
{
    int a[4], i, j;
    a[0]=x, a[1]=y;

    CUrrent_POsition(a);

    i = ((a[0]-250)/60)-1;     j = ((a[1]-150)/60)-1;

    if(x>251 && x<729 && y>151 && y<629 && new_board[j][i] != '\0')     return 1;
    else return 0;
}

int MOve_VAlidity(int x1,int y1, int x2,int y2)
{

    if((x1>251 && x1<729 && y1>151 && y1<629) && (x2>251 && x2<729 && y2>151 && y2<629) && (x1!=x2 && y1!=y2))
    {
        Mbcreate(980,580, 1300,622, 7);         /// TURN CLEAR

        int a[5];
        a[0]=x1, a[1]=y1, a[2]=x2, a[3]=y2;

        CUrrent_POsition(a);

        int a1, b1, a2, b2, val;

        a1 = ((a[0]-250)/60)-1;     b1 = ((a[1]-150)/60)-1;
        a2 = ((a[2]-250)/60)-1;     b2 = ((a[3]-150)/60)-1;


        val = MOve_GUti(b1, a1, b2, a2); /// REAL POSITION

        if(val==0)
        {
            Mbcreate(980,580, 1300,622, 4);
            setcolor(4);    settextstyle(6,0,2);    sprintf(array, "!....INvalid  MOve....!");    outtextxy(1013, 590, array);
            return 0;
        }

        else
        {
            new_board[b2][a2]=new_board[b1][a1];  /// REplace Second PLace to First Place GUti

            if((a1+b1)%2==0)
            {
                setcolor(BLACK);
                setlinestyle(1, 1, 30);
                circle(a[0]-30, a[1]-30, 13);

                (a2+b2)%2==0 ? setcolor(BLACK) : setcolor(WHITE);
                circle(a[2]-30, a[3]-30, 13);
            }

            else
            {
                setcolor(WHITE);
                setlinestyle(1, 1, 30);
                circle(a[0]-30, a[1]-30, 13);

                (a2+b2)%2==0 ? setcolor(BLACK) : setcolor(WHITE);
                circle(a[2]-30, a[3]-30, 13);
            }

            if(new_board[b1][a1]>='a' && new_board[b1][a1]<='z')
            {
                setcolor(9);
            }
            else
            {
                setcolor(GREEN);
            }

            new_board[b1][a1]='\0';

            int x3, y3;
            x3 = a[2]-47; y3 = a[3]-48;
            if(new_board[b2][a2]=='P' || new_board[b2][a2]=='p')
                x3=a[2]-43;

            settextstyle(6,0,4);
            outtextxy(x3, y3, COnvert_STring(b2, a2));

            PAwn_8(b2,a2, (a[2]-47), (a[3]-48));

            return 1;
        }
    }

    else
    {
        Mbcreate(980,580, 1300,622, 4);
        setcolor(4);    settextstyle(6,0,2);    sprintf(array, "!....INvalid  MOve....!");    outtextxy(1013, 590, array);
        return 0;
    }
}

int MOve_GUti(int x1,int y1, int x2,int y2)
{
    if( ((new_board[x1][y1]>='a' && new_board[x1][y1]<='z') && (new_board[x2][y2]>='a' && new_board[x2][y2]<='z')) || ((new_board[x1][y1]>='A' && new_board[x1][y1]<='Z') && (new_board[x2][y2]>='A' && new_board[x2][y2]<='Z')) )
        return 0;
    else if(new_board[x1][y1]=='\0')    return 0;

    int val;
    val = CHeak_GUti_move(x1,y1, x2,y2);

    return val;
}

int CHeak_GUti_move(int x1,int y1, int x2,int y2)
{
    int val=1;

    if(new_board[x1][y1]=='P' || new_board[x1][y1]=='p')
    {
        val = PAwn(x1,y1, x2,y2);
    }

    else if(new_board[x1][y1]=='N' || new_board[x1][y1]=='n')
    {
        val = KNight(x1,y1, x2,y2);
    }
    else if(new_board[x1][y1]=='R' || new_board[x1][y1]=='r')
    {
        val = ROok(x1,y1, x2,y2);
    }
    else if(new_board[x1][y1]=='K' || new_board[x1][y1]=='k')
    {
        val = KIng(x1,y1, x2,y2);
    }
    else if(new_board[x1][y1]=='B' || new_board[x1][y1]=='b')
    {
        val = BIshop(x1,y1, x2,y2);
    }
    else if(new_board[x1][y1]=='Q' || new_board[x1][y1]=='q')
    {
        val = QUeen(x1,y1, x2,y2);
    }
    return val;
}

int PAwn(int x1,int y1, int x2,int y2)
{
    int c,a,f = POsition_free(x2, y2);

    c=1;
    if(new_board[x1][y1]=='p')  /// SMall p
    {
        if(x1==6)
        {
            if(x1-x2==1)    c=0;

            a = POsition_free(x2+c, y2);

            if(a==1 && f==1 && (x2+1==x1 || x2+2==x1) && y1==y2)    return 1;
            else if(f==0 && x2+1==x1 && (y2+1==y1 || y1+1==y2))     return 1;
            return 0;
        }
        else
        {
            if(f==1 && x2+1==x1 && y1==y2)  return 1;
            else if(f==0 && x2+1==x1 && (y2+1==y1 || y1+1==y2)) return 1;
            return 0;
        }
    }

    else
    {
        if(x1==1)
        {
            if(x2-x1==1) c=0;
            a = POsition_free(x2-c, y2);

            if(a==1 && f==1 && (x1+1==x2 || x1+2==x2) && y1==y2)    return 1;
            else if(f==0 && x1+1==x2 && (y1+1==y2 || y2+1==y1))     return 1;
            return 0;
        }
        else
        {
            if(f==1 && x1+1==x2 && y1==y2)  return 1;
            else if(f==0 && x1+1==x2 && (y1+1==y2 || y2+1==y1)) return 1;
            return 0;
        }
    }
}

int KNight(int x1,int y1, int x2,int y2)
{
    int a,b, f, big, s;
    a=x1+y1;    b=x2+y2;

    f=POsition_free(x2, y2);
    big=POsition_BIg(x2, y2);
    s=POsition_SMall(x2, y2);

    if(a-b == 3)
    {
        if((x2+1==x1 || x2+2==x1) && (y2+1==y1 || y2+2==y1) && (s==0 || big==0 || f==1))    return 1;
        return 0;
    }
    else if(a-b == 1)
    {
        if((x1+1==x2 || x2+2==x1) && (y1+1==y2 || y2+2==y1) && (s==0 || big==0 || f==1))    return 1;
        return 0;
    }
    else if(b-a == 1)
    {
        if((x1+2==x2 || x2+1==x1) && (y2+1==y1 || y1+2==y2) && (s==0 || big==0 || f==1))  return 1;
        return 0;
    }
    else if(b-a == 3)
    {
        if((x1+1==x2 || x1+2==x2) && (y1+1==y2 || y1+2==y2) && (s==0 || big==0 || f==1))  return 1;
        return 0;
    }

    return 0;
}

int ROok(int x1,int y1, int x2,int y2)
{
    int f,big,sml,c=0;

    big = POsition_BIg(x2, y2);     sml = POsition_SMall(x2, y2);   f = POsition_free(x2, y2);

    if(f==1 || sml==0 || big==0) c++;

    if(x1==x2)
    {
        if(y1>y2)
        {
            c += y2;
            for(int i=y2+1; i<y1; i++)
            {
                if(new_board[x1][i] != '\0') break;
                c++;
            }

            if(c==y1)   return 1;
            return 0;
        }
        else
        {
            c += y1;
            for(int i=y1+1; i<y2; i++)
            {
                if(new_board[x1][i] != '\0') break;
                c++;
            }

            if(c==y2)   return 1;
            return 0;
        }
    }

    else if(y1==y2)
    {
        if(x1>x2)
        {
            c += x2;
            for(int i=x2+1; i<x1; i++)
            {
                if(new_board[i][y1] != '\0') break;
                c++;
            }

            if(c==x1)   return 1;
            return 0;
        }
        else
        {
             c += x1;
            for(int i=x1+1; i<x2; i++)
            {
                if(new_board[i][y1] != '\0') break;
                c++;
            }

            if(c==x2)   return 1;
            return 0;
        }
    }

    return 0;
}

int KIng(int x1,int y1, int x2,int y2)
{
    if(x1==x2)
    {
        if(y2+1==y1 || y1+1==y2)  return 1;
        return 0;
    }
    else if(y1==y2)
    {
        if(x2+1==x1 || x1+1==x2)    return 1;
        return 0;
    }
    else
    {
        if((x2+1==x1 && y2+1==y1) || (x2+1==x1 && y1+1==y2))    return 1;
        else if((x1+1==x2 && y2+1==y1) || (x1+1==x2 && y1+1==y2))   return 1;
        return 0;
    }
}

int BIshop(int x1,int y1, int x2,int y2)
{
    int i,j, m,n;

    m = (x1+y1)%2;  n = (x2+y2)%2;

    if(x1>x2 && y1>y2 && m==n)
    {
        for(i=x2+1,j=y2+1; i<x1 && j<y1; i++, j++)
        {
            if((i+j)%2 != m)    break;
            if(new_board[i][j] != '\0') break;
        }

        if(i==x1 && j==y1)   return 1;
        return 0;
    }
    else if(x1<x2 && y1<y2 && m==n)
    {
        for(i=x1+1,j=y1+1; i<x2 && j<y2; i++, j++)
        {
            if((i+j)%2 != m)    break;
            if(new_board[i][j] != '\0') break;
        }

        if(i==x2 && j==y2)   return 1;
        return 0;
    }
    else if(x1>x2 && y2>y1 && (x1+y1==x2+y2) && m==n)
    {
        for(i=x2+1,j=y2-1; i<x1; i++,j--)
        {
            if((i+j)%2 != m)    break;
            if(new_board[i][j] != '\0') break;
        }

        if(i==x1)   return 1;
        return 0;
    }
    else if(x2>x1 && y1>y2 && (x1+y1==x2+y2) && m==n)
    {
        for(i=x1+1,j=y1-1; i<x2; i++,j--)
        {
            if((i+j)%2 != m)    break;
            if(new_board[i][j] != '\0') break;
        }

        if(i==x2)   return 1;
        return 0;
    }

    return 0;
}

int QUeen(int x1,int y1, int x2,int y2)
{
    if(x1==x2 || y1==y2)    ROok(x1,y1, x2,y2);
    else                    BIshop(x1,y1, x2,y2);
}

int POsition_free(int x, int y)
{
    if(new_board[x][y] == '\0')     return 1;
    return 0;
}

int POsition_SMall(int x, int y)
{
    if(new_board[x][y]>='a' && new_board[x][y]<='z')    return 1;
    return 0;
}

int POsition_BIg(int x, int y)
{
    if(new_board[x][y]>='A' && new_board[x][y]<='Z')    return 1;
    return 0;
}

void PAwn_8(int x,int y,    int x2,int y2)
{
    int a, b, c, d;
    a=60, c=130, b=200, d=480;

    if(x==0 || x==7)
    {
        Mbcreate(a,b, c,d, 8);

        setcolor(5);
        setlinestyle(0,0, 10);

        rectangle(a,b, c,d);
        b += 70;
        line(a, b, c, b);        b += 70;
        line(a, b, c, b);        b += 70;
        line(a, b, c, b);

        x==0 ? setcolor(9) : setcolor(GREEN);

        a = ((a+c)/2 - 15);     b = 200+18;

        sprintf(array, "Q");       outtextxy(a,b, array);    b += 70;
        sprintf(array, "R");       outtextxy(a,b, array);    b += 70;
        sprintf(array, "B");       outtextxy(a,b, array);    b += 70;
        sprintf(array, "N");       outtextxy(a,b, array);
    }

    if(new_board[x][y]=='p' && x==0)
    {
        int x1, y1;

        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(50);
            }
            getmouseclick(WM_LBUTTONDOWN, x1,y1);


            if(x1>=42 && x1<=138 && y1>=201 && y1<=269)
            {
                new_board[x][y] = 'q';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=271 && y1<=339)
            {
                new_board[x][y] = 'r';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=341 && y1<=409)
            {
                new_board[x][y] = 'b';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=411 && y1<=479)
            {
                new_board[x][y] = 'n';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
        }
    }

    else if(new_board[x][y]=='P' && x==7)
    {
        int x1, y1;

        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(50);
            }
            getmouseclick(WM_LBUTTONDOWN, x1,y1);


            if(x1>=42 && x1<=138 && y1>=201 && y1<=269)
            {
                new_board[x][y] = 'Q';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=271 && y1<=339)
            {
                new_board[x][y] = 'R';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=341 && y1<=409)
            {
                new_board[x][y] = 'B';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
            else if(x1>=42 && x1<=138 && y1>=411 && y1<=479)
            {
                new_board[x][y] = 'N';
                outtextxy(x2, y2, COnvert_STring(x,y));
                break;
            }
        }
    }

    if(x==0 || x==7)
    {
        a=60, c=130, b=200, d=480;
        Mbcreate(a-5,b-5, c+5,d+5, 9);
    }

    (x+y)%2==0 ? setcolor(GREEN) : setcolor(9);

}

char* COnvert_STring(int x, int y)
{
    char *a;

    a = (char *)malloc(200);

    a[0] = new_board[x][y];
    if(a[0]>='a' && a[0]<='z')  a[0] -=32;
    a[1] = '\0';
    return a;
}

int GAme_MOde()
{
    int i=0,a[] = {1, 2, 3, 5, 9, 10, 11};

    int x,x1,x2, y,y1,y2, m,n;
    x=950, y=180, x1=1335, y1=330,y2=680;

    while(1)
    {
        setcolor(a[i++]);   settextstyle(6, 0, 2);  sprintf(array, "...ENter GAme MOde...");      outtextxy(x+52, y+40, array);

        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(50);
        }
        getmouseclick(WM_LBUTTONDOWN, m,n);

        if(m>1167 && m<1320 && n>121 && n<156)    exit(1);

        if(m>(x+(x1-x)/2+39) && m<(x1-35) && n>(y+84) && n<(y1-27))
        {
            setcolor(15);   settextstyle(6, 0, 3);      sprintf(array, "DOuble");      outtextxy(x1-144, y1-59, array);
            Mbcreate(x+50,y+38, x+350, y+65, 7);
            //setcolor(7);    settextstyle(6, 0, 2);      outtextxy(x+52, y+40, "...ENter GAme MOde...");
            return 0;
        }

        if(i>7) i=0;

        ///bcreate(x+(x1-x)/2+35, y+80, x1-20, y1-20, 13);
    }
}

void NEw_GAme_COlour()
{
    setcolor(15);    settextstyle(6,0,3);   sprintf(array, "NEw GAme");     outtextxy(1148, 35+25, array);
}

void TRarn_CLear()
{
    //Mbcreate(995, 520, 1300, 570, 0);
    Mbcreate(980,580, 1300,622, 7);
}

int KIng_CHeck()
{

}

void Mbcreate(int x1,int y1,int x2,int y2,int col)
{
    setfillstyle(SOLID_FILL,col);
    bar(x1,y1, x2,y2);

    setfillstyle(SOLID_FILL, WHITE);
}

void bcreate(int x1,int y1,int x2,int y2,int col)
{
    setcolor(7);
    rectangle(x1,y1, x2,y2);
    setcolor(8);
    setfillstyle(SOLID_FILL,8);
    rectangle(x1+1,y1+1, x2,y2);
    floodfill(x1+5,y1+5,8);
    setfillstyle(SOLID_FILL,col);
    bar(x1+5,y1+5, x2-5,y2-5);

    setfillstyle(SOLID_FILL, WHITE);
}

void createwindo(int x,int y,int w,int z,int col)
{
    setcolor(8);    rectangle(x,y,w,z);
    setcolor(7);    setfillstyle(SOLID_FILL,8);     rectangle(x+1,x+1,w-1,z-1);         floodfill(x+3,y+3, 7);
    setcolor(7);    setfillstyle(SOLID_FILL,col);   rectangle(x+30,y+30,w-20,z-20);     floodfill(x+32,y+32,7);
    setcolor(0);    setlinestyle(0, 0, 3);          line(x+29, y+30, w-21, y+30);
                                                    line(x+29, y+30, x+29, z-20);
    setfillstyle(SOLID_FILL, WHITE);
}

int BOx(int x1,int y1, int x2,int y2, int col)
{
    Mbcreate(x1-10,y1-10, x2-10,y2-10, 0);      Mbcreate(x1,y1, x2+1,y2+1, 0);

    Mbcreate(x1-15,y1-15, x2-15,y2-15, 11);     bcreate(x1-5,y1-5, x2-5,y2-5, col);     delay(200);

    Mbcreate(x1-15,y1-15, x2-15,y2-15, 0);      Mbcreate(x1-5,y1-5, x2-4,y2-4, 0);
}

