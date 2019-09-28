/* ======================================================================
                     4 개의 기본 입출력 함수 정의
                                f o r
                   한글 라이브러리 [미니한글라이브]
                  94, 1. 조 성 용 (Creative in Hitel)
   ======================================================================

     다음의 4 개의 함수가 정의되어 있습니다.
         void print_eng()   :  영문 출력
         void print_han()   :  한글 출력
         void read_eng()    :  영문 입력
         void read_han()    :  한글 입력

     그외도 몇개 더 있는것은 직접적으로는 쓰일 필요는 없습니다.
   ====================================================================== */

typedef unsigned char uchar;

extern uchar HF[10*19*32];
extern uchar HM[4*21*32];
extern uchar HL[4*27*32];
extern uchar ENG[127*16];

#include <math.h>
#include <bios.h>


/*
   한글용과 영문용 커서
*/

uchar engcuser[32] = {
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255 };

uchar hancuser[16] = {
  255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255 };

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <graphics.h>


/*
   그래픽 초기화. 한글 초기화가 따로 있지 않다.
   VGA 가 아니거나 에러가 나면 실행을 중지한다.
*/

void init_graph(void) {
  int gd=DETECT, gm, re;
  initgraph(&gd,&gm,"");
  if (gd!=9) {
    cprintf("Sorry, this program works only in VGA  or you must have VGAEGA.BGI driver.");
    exit(1);
  }
  if (graphresult()!=grOk) {
    cprintf("Graphics error.");
    exit(1);
  }
}


/*
   x,y 의 텍스트 좌표에 아스키값이 c1 인 영자 하나를
   color1 색, color2 배경색으로 그린다.
   주로  print_eng() 함수에서 쓰인다.
*/

void put_eng(int x,int y,int c1,int color1,int color2) {
  uchar t1,t2,t3;
  if (c1> 0) ins_put_16(x,y*16,ENG+(c1)*16, color1,color2);
  if (c1==0) over_put_16(x,y*16,engcuser,color2);
}


/*
   x,y 의 텍스트 좌표에 초,중,종성값이 각각 c1 c2 c3 인 한글
   한 자를 color1 색, color2 배경색으로 그린다.
   주로  print_han() 함수에서 쓰인다.
*/

void put_han(int x,int y,int c1,int c2,int c3,int color1,int color2) {
  uchar t1,t2,t3;
  writetype(c1,c2,c3,&t1,&t2,&t3);
  if (c1>0)
    ins_put_32(x,y*16,HF+ (t1-1)*20*32+ (c1  )*32, color1,color2);
  if (c2>0) {
    if (c1==0)
      ins_put_32(x,y*16,HM+ (t2-1)*22*32+ (c2  )*32, color1,color2);
    if (c1>0)
      over_put_32(x,y*16,HM+ (t2-1)*22*32+ (c2  )*32, color1);
  }
  if (c3>0) {
    if (c1==0) if (c2==0)
      ins_put_32(x,y*16,HL+ (t3-1)*28*32+ (c3  )*32, color1,color2);
    if ((c1>0) || (c2>0))
      over_put_32(x,y*16,HL+ (t3-1)*28*32+ (c3  )*32, color1);
  }
  if (c1==0) if (c2==0) if (c3==0)
    over_put_32(x,y*16,hancuser,color2);
}


/*
   x,y 의 텍스트 좌표에 st 로 받은 영문 문자열을 화면에
   color1 색, color2 배경색으로 쓴다.
*/

void print_eng(int x,int y,char *st,int color1,int color2) {
  int i,a,len;
  len=strlen(st);
  for (i=1; i<=len; i++) put_eng(x+i-1,y,st[i-1],color1,color2);
}


/*
   x,y 의 텍스트 좌표에 st 로 받은 한글 조합형 문자열을 화면에
   color1 색, color2 배경색으로 쓴다.
*/

void print_han(int x,int y,char *st,int color1,int color2) {
  int i;
  uchar ch1,ch2,c1,c2,c3;
  for (i=1; i<=strlen(st); i++) {
    ch1= st[i-1];
    if (32<=ch1) if (ch1<=127) put_eng(x+i-1,y,ch1,color1,color2);
    if (132<=ch1) if (ch1<=211) {
      ch2= st[i];
      c1= floor((ch1-132)/4);
      c2= fmod((ch1-132),4) * 6;
      c2= c2 + floor((ch2-65)/32);
      c3= fmod((ch2-65),32);
      if (c3>=18) c3--;
      put_han(x+i-1,y,c1,c2,c3,color1,color2);
      i++;
    }
  }
}


/*
  키입력 함수.
  정수대신 두개의 바이트에 전달한다.
*/

void inkey(uchar *ch1,uchar *ch2) {
  *ch1=0; *ch2=0;
  *ch1=getch();
  if (kbhit()) *ch2=getch();
}


/*
   x,y 의 텍스트 좌표에서 영문 한 줄을 입력받는다.
   max 는 줄의 최대칼럼수, string 은 전달받고 전달되는 문자열이다.
   string 은 반드시 정해진 다음에 이 함수가 사용되어야 한다.
   탈출키는 Enter,Esc 이고 그것에 따라 selected=1,0 으로 돌려진다.
   화살표와 각종 키를 쓸 수 있다.
*/

void read_eng(int fx,int fy,int max,uchar *string,
         int *selected, int color1,int color2) {
  uchar ch1,ch2;
  uchar st[100];
  int i,j,cx,len,started=1,cuser=0,loop=2000,pressed;
  strcpy(st,string);
  len=strlen(st);
  for (i=1; i<=max; i++) put_eng(fx+i-1,fy,0,color1,color2);
  for (i=1; i<=len; i++) put_eng(fx+i-1,fy,st[i-1],color2,color1);
  cx=len+1;
  if (cx>max) cx=max;
  do {
    pressed=0;
    for (i=1; i<=loop; i++) {
      ch1=0; ch2=0;
      if (kbhit()) inkey(&ch1,&ch2);
      if ((ch1>0) || (ch2>0)) {
    i=loop; pressed=1;
      }
    }
    if (pressed==0) {
      if (cuser==0) {
    cuser=1;
    if (cx<=len) put_eng(fx+cx-1,fy,st[cx-1],color2,color1);
    if (cx>len) put_eng(fx+cx-1,fy,0,color2,color1);
      }
      else {
    cuser=0;
    if (cx<=len) put_eng(fx+cx-1,fy,st[cx-1],color1,color2);
    if (cx>len) put_eng(fx+cx-1,fy,0,color1,color2);
      }
    }
    if (pressed) if (cuser==1) {
      if (cx<=len) put_eng(fx+cx-1,fy,st[cx-1],color1,color2);
      if (cx>len) put_eng(fx+cx-1,fy,0,color1,color2);
    }
    if (pressed) if (started) if ((ch1>0) || (ch2>0)) {
      started=0;
      if ((ch1==8) || (ch2==75) || (ch2==77) || (ch2==71) || (ch2==79)) {
    for (i=1; i<=len; i++) put_eng(fx+i-1,fy,st[i-1],color1,color2);
      }
      if ((ch1>=32) && (ch1<=127)) {
    for (i=1; i<=len; i++) put_eng(fx+i-1,fy,0,color1,color2);
    len=0;
    st[0]='\x0';
    cx=1;
      }
    }
    if (pressed) if ((ch1>0) || (ch2>0)) {
      if (ch2==75) {
    cx--;
    if (cx==0) cx++;
      }
      if (ch2==77) {
    cx++;
    if (cx>len+1) cx=len+1;
      }
      if (ch2==71) {
    cx=1;
      }
      if (ch2==79) {
    cx=len+1;
      }
      if (ch1>=32) if (ch1<=127) if (len<max-1) {
    if (cx<=len) {
      for (i=len+1; i>=cx; i--) st[i]=st[i-1];
      scroll_right(fx+cx-1,fy*16,fx+len,fy*16+15,1,color2);
    }
    st[cx-1]=ch1;
    put_eng(fx+cx-1,fy,ch1,color1,color2);
    len++;
    if (len==cx) st[cx]='\x0';
    cx++;
      }
      if (ch1==8) if (cx>1) {
    if (cx<=len) {
      for (i=cx; i<=len+1; i++) st[i-2]=st[i-1];
      scroll_left(fx+cx-1,fy*16,fx+len-1,fy*16+15,1,color2);
    }
    len--;
    if (len==cx-2) st[cx-1]='\x0';
    cx--;
      }
      cuser=1;
      if (cx<=len) put_eng(fx+cx-1,fy,st[cx-1],color2,color1);
      if (cx>len) put_eng(fx+cx-1,fy,0,color2,color1);
    }
  } while ((ch1!=27) && (ch1!=13));
  st[len]='\0';
  if (ch1==13) { *selected=1; strcpy(string,st); }
  if (ch1==27) *selected=0;
  if (cx<=len) put_eng(fx+cx-1,fy,st[cx-1],color1,color2);
  if (cx>len) put_eng(fx+cx-1,fy,0,color1,color2);
}


/*
   x,y 의 텍스트 좌표에서 한글 한 줄을 입력받는다.
   max 는 줄의 최대칼럼수, string 은 전달받고 전달되는 문자열이다.
   string 은 반드시 정해진 다음에 이 함수가 사용되어야 한다.
   탈출키는 Enter,Esc 이고 그것에 따라 selected=1,0 으로 돌려진다.
   한/영 전환은 Shift-Space, F2 로 한다.
   화살표와 각종 키를 쓸 수 있다.
*/

void read_han(int fx,int fy, int max,
           uchar *string, int *selected,
           int color1,int color2)  {
  int code[3];
  int jhnum=0, jjnum=0;
  int chnum[4]={0,0,0,0}, ccnum[4]={0,0,0,0};
  int gone=0,process=0,hmode=1;
  int i,j,n,cx,l,c1,c2,len,l1,l2;
  int pressed=0,loop=2000,cuser=0,started=1;
  uchar str[100],st[100],stcuser[3];
  uchar ch1,ch2;

  strcpy(str,string);
  len=strlen(str);
  for (i=1; i<=max; i++) put_eng(fx+i-1,fy,0,color1,color2);
  print_han(fx,fy,str,color2,color1);
  cx=len+1;
  if (cx>max) cx=max;

  do {
    if (len<cx) strcpy(stcuser," ");
    if (len>=cx) {
      if (str[cx-1]<=127) {
    stcuser[0]=str[cx-1]; stcuser[1]='\x0';
      }
      if (str[cx-1]>=128) {
    stcuser[0]=str[cx-1];
    stcuser[1]=str[cx  ];
    stcuser[2]='\x0';
      }
    }
    if (pressed==0) {
      if (cuser==0) {
    cuser=1;
    print_han(fx+cx-1,fy,stcuser,color2,color1);
      }
      else {
    cuser=0;
    print_han(fx+cx-1,fy,stcuser,color1,color2);
      }
    }
    for (i=1; i<=loop; i++) {
      ch1=0; ch2=0;
      if (kbhit()) inkey(&ch1,&ch2);
      if ((ch1>0) || (ch2>0)) {
    i=loop; pressed=1;
      }
    }
    if (pressed==1) {
      print_han(fx+cx-1,fy,stcuser,color1,color2);
    }

    if (pressed) if (started) if ((ch1>0) || (ch2>0)) {
      started=0;
      if ((ch1==8) || (ch2==75) || (ch2==77) || (ch2==71) || (ch2==79) || (ch1==13)) {
	print_han(fx,fy,str,color1,color2);
      }
      else {
    for (i=1; i<=len; i++) put_eng(fx+i-1,fy,0,color1,color2);
    len=0;
    str[0]='\x0';
    cx=1;
      }
    }

    if (pressed) if ((ch1>0) || (ch2>0)) {

      if ((bioskey(2)==1) || (bioskey(2)==2)) if (ch1==' ') {
	sound(300); delay(10); nosound();
	hmode=1-hmode;
	goto end;
      }

      if (32<=ch1) if (ch1<=127) if (hmode==1) {
     keycode(ch1,code);
     if (code[1]==0) {
       if (process==1) {
         for (i=1; i<=3; i++) { ccnum[i]=0; chnum[i]=0; }
         jjnum=0; jhnum=0; process=0;
         if (cx<max-1) cx=cx+2;
       }
       if (len<max-1) {
         if (len>=cx) for (i=len+1; i>=cx; i--) str[i]=str[i-1];
         str[cx-1]=ch1;
         scroll_right(fx+cx-1,fy*16,fx+len,fy*16+15,1,color2);
         put_eng(fx+cx-1,fy,ch1,color1,color2);
         len++;
         cx++;
       }
     }
     if (code[1]>0) {
       if (process==1) {
          keycode(ch1,code);
          decide( &jjnum, &jhnum, code, ccnum, chnum, &gone );
          if (gone==0) {
        deci(chnum,&c1,&c2);
        str[cx-1]=c1; str[cx]=c2;
        st[0]=c1; st[1]=c2; st[2]='\x0';
        print_han(fx+cx-1,fy,st,color1,color2);
          }
          if (gone==1) if (len<max-2) {
        if (len<(max-1)) {
          deci(ccnum,&c1,&c2);
          for (i=1; i<=3; i++) { ccnum[i]=0; jjnum=0; }
          str[cx-1]=c1; str[cx]=c2;
          st[0]=c1; st[1]=c2; st[2]='\x0';
          print_han(fx+cx-1,fy,st,color1,color2);
          cx=cx+2;
          if (len>=cx) for (i=len+1; i>=cx; i--) str[i+1]=str[i-1];
          deci(chnum,&c1,&c2);
          str[cx-1]=c1; str[cx]=c2;
          scroll_right(fx+cx-1,fy*16,fx+len+1,fy*16+15,2,color2);
          len=len+2;
          deci(chnum,&c1,&c2);
          str[cx-1]=c1; str[cx]=c2;
          st[0]=c1; st[1]=c2; st[2]='\x0';
          print_han(fx+cx-1,fy,st,color1,color2);
        }
          }
       }
       if (process==0) if (len<max-2) {
         if (len<(max-1)) {
           if (len>=cx) for (i=len+1; i>=cx; i--) str[i+1]=str[i-1];
           scroll_right(fx+cx-1,fy*16,fx+len+1,fy*16+15,2,color2);
           keycode(ch1,code);
           decide( &jjnum, &jhnum, code, ccnum, chnum, &gone );
           deci(chnum,&c1,&c2);
           str[cx-1]=c1; str[cx]=c2;
           st[0]=c1; st[1]=c2; st[2]='\x0';
           print_han(fx+cx-1,fy,st,color1,color2);
               len=len+2;
           process=1;
         }
       }
     }
      }
      if (32<=ch1) if (ch1<=127) if (hmode==0) {
    if (len<max-1) {
      if (len>=cx) for (i=len+1; i>=cx; i--) str[i]=str[i-1];
      str[cx-1]=ch1;
      scroll_right(fx+cx-1,fy*16,fx+len,fy*16+15,1,color2);
      put_eng(fx+cx-1,fy,ch1,color1,color2);
      len++; cx++;
    }
      }
      if (ch2==75) {
    if (jhnum>0) {
      for (i=1; i<=3; i++) { ccnum[i]=0; chnum[i]=0; }
      jhnum=0; jjnum=0;
    }
    l1=1; l2=1;
    while (l1<cx) {
      l2=l1;
      l1++;
      if (l1<=len) if (str[l1-2]>=128) l1++;
    }
    cx=l2;
      }
      if (ch2==77) {
    cx++;
    if (cx>len+1) cx=len+1;
    if (str[cx-2]>=128) cx++;
    if (process) {
      for (i=1; i<=3; i++) { ccnum[i]=0; chnum[i]=0; }
      jjnum=0; jhnum=0; process=0;
    }
      }
      if (ch2==71) {
    cx=1;
    if (process) {
      for (i=1; i<=3; i++) { ccnum[i]=0; chnum[i]=0; }
      jjnum=0; jhnum=0; process=0;
    }
      }
      if (ch2==79) {
    cx= len+1;
    if (process) {
      for (i=1; i<=3; i++) { ccnum[i]=0; chnum[i]=0; }
      jjnum=0; jhnum=0; process=0;
    }
      }
      if (ch1==8) {
    if (process==0) if (cx>1) {
      l1=1; l2=1;
      while (l1<cx) {
        l2=l1;
        l1++;
        if (l1<=len) if (str[l1-2]>=128) l1++;
      }
      n=cx-l2;
      for (i=cx; i<=len+1; i++) str[i-n-1]=str[i-1];
      scroll_left(fx+cx-2,fy*16,fx+len,fy*16+15,n,color2);
      cx=l2;
      len-=n;
    }
    if (process==1) {
      backhan(&jhnum,chnum,&process);
      if (process==1) {
        deci(chnum,&c1,&c2);
        str[cx-1]=c1; str[cx]=c2;
        st[0]=c1; st[1]=c2; st[2]='\x0';
        print_han(fx+cx-1,fy,st,color1,color2);
      }
      if (process==0) {
        if (cx+1<len) {
          for (i=cx+2; i<=len+1; i++) str[i-3]=str[i-1];
          scroll_left(fx+cx-1,fy*16,fx+len,fy*16+15,2,color2);
          len-=2;
        }
        else {
          len=cx-1;
          str[cx-1]='\x0';
          print_han(fx+cx-1,fy,"  ",color1,color2);
        }
      }
    }
      }
      if (ch2==60) {
	hmode= 1-hmode;
	sound(300); delay(10); nosound();
      }
      cuser=0;
      end: pressed=0;
    }
  } while ((ch1!=13) && (ch1!=27));
  str[len]='\0';
  if (ch1==13) { *selected=1; strcpy(string,str); }
  if (ch1==27) *selected=0;
}
 
