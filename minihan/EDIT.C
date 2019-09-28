/* ======================================================================
                       텍스트 편집함수 정의 부분
                                 f o r
                   한글 라이브러리 [미니 한글라이브]
                   94, 1. 조 성 용 (Creative in Hitel)
   ======================================================================

       본 한글 라이브러리에서 가장 강력하게 지원되는 함수입니다.
       간단한 에디터에 편집을 해서 입력을 받을 필요가 있을 때
       에디터의 구현은 본 텍스트편집함수가 알아서 하고 사용자는
       단슨히 edit_han_text() 라는 함수명만 쓰면 됩니다.
       edit_han_text() 만 실제로 쓰이는 함수이고 나머지는 
       그 함수가 사용하는 함수입니다.
       edit_han_text() 에서는 
          화살표,F2,Shift-Space,Ctr-Y 등의 키가 사용됩니다.
  ====================================================================== */

typedef unsigned char uchar;

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <string.h>
#include <bios.h>
#include <graphics.h>


/*
  텍스트 편집함수 전용 변수.
  수가 많아서 전역변수로 정해짐
*/

uchar *screen;                          /*  에디터의 실제 내용  */
uchar *sindex;                          /*  라인별 인덱스       */
int *index;                             /*  라인별 인덱스       */
int maxline;                            /*  최대 라인 수        */
int culine;                             /*  현재 라인 수        */
int fx,fy,wx,wy;                        /*  에디터의 위치,크기  */
int cx,cy,wiy;                          /*  커서의 위치         */
int color1, color2;                     /*  색                  */
int hmode;                              /*  한/영  모드         */
int jhnum,jjnum, chnum[4], ccnum[4];    /*  한글 자소           */
int gone;                               /*  변환되어 넘어가는지 */
int code[3];                            /*  키로 입력된 글자    */


/*
  인덱스와 실제 내용을 읽고 쓰는 부분
*/

int getin(int y,int n) {
  return(*(index+(y-1)*2+n));
}

void wriin(int y,int n,int soo) {
  *(index+(y-1)*2+n)=soo;
}

uchar getsc(int y,int x) {
  return(*(screen+(getin(y,1)-1)*wx+x-1));
}

void wrisc(int y,int x,int soo) {
  *(screen+(getin(y,1)-1)*wx+x-1)=soo;
}


/*
   한글이 만들어지고 있을 때 커서가 이동되면 한글 자소를 초기화
*/

void hanzero(void) {
  jjnum=0; jhnum=0;
  ccnum[1]=0; ccnum[2]=0; ccnum[3]=0;
  chnum[1]=0; chnum[2]=0; chnum[3]=0;
}


/*
   한 줄을 출력한다.
*/

void displine(int y) {
  uchar st[100];
  int i;
  for (i=1; i<=getin(wiy+y,0); i++) st[i-1]=getsc(wiy+y,i);
  st[i-1]='\x0';
  print_han(fx+1,fy+y,st,color1,color2);
}


/* 
   화면을 다시 그린다.
*/

void dispallline(void) {
  int i,j;
  uchar st[100];
  for (i=1; i<=wy; i++) {
    strcpy(st,""); for (j=1; j<=wx; j++) strcat(st," ");
    if (wiy+i<=culine)
      for (j=1; j<=getin(wiy+i,0); j++) st[j-1]=getsc(wiy+i,j);
    print_han(fx+1,fy+i,st,color1,color2);
  }
}


/*
   위, 아래로 스크롤 한다.
*/

void scrup(int y) {
  scroll_up(fx+1,(fy+y)*16,fx+wx,(fy+wy)*16+15,16,color2);
}

void scrdown(int y) {
  scroll_down(fx+1,(fy+y)*16,fx+wx,(fy+wy)*16+15,16,color2);
}


/*
   왼쪽 화살표가 눌렸을 시
*/

void left(void) {
  int i, l1,l2;
  if (jhnum>0) hanzero();
  l1=1; l2=1;
  while (l1<cx) {
    l2=l1;
    l1++;
    if (l1<=getin(wiy+cy,0)) if (getsc(wiy+cy,l1-1)>=128) l1++;
  }
  cx=l2;
  end: i=0; i=i;
}


/*
   오른쪽 화살표가 눌렸을 시
*/

void right(void) {
  int i;
  if (jhnum>0) hanzero();
  if (cx==getin(wiy+cy,0)+1) goto end;
  cx++;
  if (cx<=getin(wiy+cy,0)) if (getsc(wiy+cy,cx-1)>=128) cx++;
  end: i=0; i=i;
}


/*
   위쪽 화살표가 눌렸을 시
*/

void up(void) {
  int i,l1,l2;
  if (jhnum>0) hanzero();
  if (wiy+cy==1) goto end;
  l1=1; l2=1;
  if (cx>getin(wiy+cy-1,0)) cx=getin(wiy+cy-1,0)+1;
  while (l1<=cx) {
    l2=l1;
    l1++;
    if (l1<=getin(wiy+cy-1,0)) if (getsc(wiy+cy-1,l1-1)>=128) l1++;
  }
  cx=l2;
  cy--;
  if (cy==0) {
    scrdown(1);
    wiy--; cy=1;
    displine(1);
  }
  end: i=0; i=i;
}


/*
   아래쪽 화살표가 눌렸을 시
*/

void down(void) {
  int i,l1,l2;
  if (jhnum>0) hanzero();
  if (wiy+cy==culine) goto end;
  l1=1; l2=1;
  if (cx>getin(wiy+cy+1,0)) cx=getin(wiy+cy+1,0)+1;
  while (l1<=cx) {
    l2=l1;
    l1++;
    if (l1<=getin(wiy+cy+1,0)) if (getsc(wiy+cy+1,l1-1)>=128) l1++;
  }
  cx=l2;
  cy++;
  if (cy>wy) {
    scrup(1);
    wiy++; cy=wy;
    displine(wy);
  }
  end: i=0; i=i;
}


/*
   Home 키가 눌렸을 시
*/

void home(void) {
  if (jhnum>0) hanzero();
  cx=1;
}


/*
   End 키가 눌렸을 시
*/

void end(void) {
  if (jhnum>0) hanzero();
  cx=getin(wiy+cy,0)+1;
}


/*
   PgUp 키가 입력 되얶을 때
*/

void pgup(void) {
  int past=wiy;
  if (wiy==0) cy=1;
  wiy-=wy;
  if (wiy<0) wiy=0;
  if (past!=wiy) dispallline();
  cx=1;
}


/*
   PgDn 키가 입력이 되었을 때
*/

void pgdown(void) {
  int past=wiy;
  if (wiy+wy>=culine) cy=culine-wiy;
  wiy+=wy;
  if (wiy+1>culine) wiy-=wy;
  if (wiy+cy>culine) cy=1;
  if (past!=wiy) dispallline();
  cx=1;
}


/*
   Ctr-PgUp 이 입력되었을 때
*/

void top(void) {
  int past=wiy;
  wiy=0; cy=1;
  if (past!=wiy) dispallline();
  cx=1;
}


/*
   Ctr-PgDn 이 입력되었을 때
*/

void bottom(void) {
  int past=wiy;
  wiy=culine-wy;
  if (wiy<0) wiy=0;
  cy=wy;
  if (wiy+cy>culine) cy=culine-wiy;
  if (past!=wiy) dispallline();
  cx=1;
}


/*
   라인이 추가될때 라인별 인덱스에 기록하기
*/

int find(void) {
  int i=1;
  while (i<=maxline) {
    if (*(sindex+i)==0) {
      *(sindex+i)=1;
      return(i);
    }
    i++;
  }
}


/*
   Enter 시 커서 밑의 내용이 밀려난다.
*/

void pushline(y1,y2,n) {
  int i;
  for (i=y2; i>=y1; i--) {
    wriin(i+n,0,getin(i,0));
    wriin(i+n,1,getin(i,1));
  }
  culine+=n;
  for (i=1; i<=n; i++) wriin(y1+i-1,1,find());
}


/*
   Enter 키가 입력이 될때
*/

void enter(void) {
  int i,j;
  uchar st[100]="";
  if (culine==maxline) goto end;
  if (cx<=getin(wiy+cy,0)) {
    for (i=1; i<=getin(wiy+cy,0)-cx+1; i++) st[i-1]=getsc(wiy+cy,cx+i-1);
    st[i-1]='\x0';
  }
  if (wiy+cy<culine)
    pushline(wiy+cy+1,culine,1);
  else {
    wriin(wiy+cy+1,1,find());
    culine++;
  }
  for (i=1; i<=strlen(st); i++) wrisc(wiy+cy+1,i,st[i-1]);
  wriin(wiy+cy,0,cx-1);
  wriin(wiy+cy+1,0,strlen(st));
  if (cy==wy) {
    for (i=1; i<=strlen(st); i++) put_eng(fx+cx+i-1,fy+cy,0,color1,color2);
    scrup(1);
    wiy++; cx=1;
    print_han(fx+1,fy+wy,st,color1,color2);
  }
  else {
    for (i=1; i<=strlen(st); i++) put_eng(fx+cx+i-1,fy+cy,0,color1,color2);
    if (cy<wy-1) scrdown(cy+1);
    for (i=1; i<=wx; i++) put_eng(fx+i,fy+cy+1,0,color1,color2);
    print_han(fx+1,fy+cy+1,st,color1,color2);
    cx=1; cy++;
  }
  end: i=0; i=i;
}


/*
   해당 라인을 오른쪽으로 밀기
*/

void push(int y,int x1,int x2,int n) {
  int i,p1,p2;
  for (i=x2; i>=x1; i--) wrisc(y,i+n,getsc(y,i));
  wriin(y,0,getin(y,0)+n);
  if (x1<=x2) scroll_right(fx+x1,(fy+cy)*16,fx+x2+2,(fy+cy)*16+15,n,color2);
}


/*
   영문 모드에서 한 글자가 입력이 될때
*/

void engone(char ch1) {
  int i,j;
  if (jhnum>0) cx+=2;
  if (jhnum>0) hanzero();
  if (cx<=getin(wiy+cy,0)) if (getin(wiy+cy,0)>=wx-1) goto end;
  if (cx>=wx) if (culine==maxline) goto end;
  if (cx>=wx) enter();
  if (cx<=getin(wiy+cy,0))
    push(wiy+cy,cx,getin(wiy+cy,0),1);
  else
    wriin(wiy+cy,0,getin(wiy+cy,0)+1);
  wrisc(wiy+cy,cx,ch1);
  put_eng(fx+cx,fy+cy,ch1,color1,color2);
  cx++;
  end: i=0; i=i;
}


/*
   한글 모드에서 한 글자가 입력이 될때
*/

void hanone(char ch1) {
  int i,j, c1,c2;
  int gone;
  keycode(ch1,code);
  if (code[1]==0) {
    engone(ch1);
    goto end;
  }
  if (jhnum==0) {
    if (getin(wiy+cy,0)>=wx-2) if (cx<=wx-2) goto end;
    if (cx>=wx-1) if (culine==maxline) goto end;
    if (cx>=wx-1) enter();
    if (cx<=getin(wiy+cy,0)) push(wiy+cy,cx,getin(wiy+cy,0),2);
  }
  decide(&jjnum,&jhnum,code,ccnum,chnum,&gone);
  if (gone) if ((getin(wiy+cy,0)<=wx-2) || (cx>=wx-2)) {
    if (getin(wiy+cy,0)>=cx+2) push(wiy+cy,cx+2,getin(wiy+cy,0),2);
    deci(ccnum,&c1,&c2);
    wrisc(wiy+cy,cx,c1); wrisc(wiy+cy,cx+1,c2);
    put_han(fx+cx,fy+cy,ccnum[1],ccnum[2],ccnum[3],color1,color2);
    for (i=1; i<=3; i++) ccnum[i]=0;
    cx+=2;
    if (cx>=wx-1) if (culine==maxline) {
      jhnum=0; goto end;
    }
    if (cx>=wx-1) enter();
  }
  deci(chnum,&c1,&c2);
  wrisc(wiy+cy,cx,c1); wrisc(wiy+cy,cx+1,c2);
  put_han(fx+cx,fy+cy,chnum[1],chnum[2],chnum[3],color1,color2);
  if (getin(wiy+cy,0)<cx) wriin(wiy+cy,0,cx+1);
  end: i=0; i=i;
}


/*
   해당 라인에서 왼쪽으로 당기기
*/

void pull(int y,int x1,int x2,int n) {
  int i,p1,p2;
  for (i=x1; i<=x2; i++) wrisc(y,i-n,getsc(y,i));
  wriin(y,0,getin(y,0)-n);
  if (x1<=x2) scroll_left(fx+x1-1,(fy+cy)*16,fx+x2+1,(fy+cy)*16+15,n,color2);
}


/*
   Del 등이 입력될때 커서 밑의 내용을 위로 끌어 올리기
*/

void pullline(y1,y2,n) {
  int i;
  if (y1>y2) exit(1);
  if (y1>culine) exit(1);
  if (y2>culine) exit(1);
  for (i=1; i<=n; i++) {
    *(sindex+getin(y1-i,1))=0;
    wriin(y1-i,0,0); wriin(y1-i,1,0);
  }
  for (i=y1; i<=y2; i++) {
    wriin(i-n,0,getin(i,0));
    wriin(i-n,1,getin(i,1));
  }
  for (i=1; i<=n; i++) {
    wriin(culine-n+i,0,0); wriin(culine-n+i,1,0);
  }
  culine-=n;
}


/*
   Del 키가 입력되었을 때
*/

void del(void) {
  int i,j,process=1,c1,c2,l1,l2,n;
  uchar st[100]="";
  if (wiy+cy==1) if (cx==1) if (jhnum==0) goto end;
  if (jhnum>0) {
    backhan(&jhnum,chnum,&process);
    if (process==0) {
      print_han(fx+cx,fy+cy,"  ",color1,color2);
      pull(wiy+cy,cx+2,getin(wiy+cy,0),2);
    }
    if (process==1) {
      deci(chnum,&c1,&c2);
      wrisc(wiy+cy,cx,c1); wrisc(wiy+cy,cx+1,c2);
      put_han(fx+cx,fy+cy,chnum[1],chnum[2],chnum[3],color1,color2);
    }
    goto end;
  }
  if (cx==1) {
    for (i=1; i<=getin(wiy+cy,0); i++) st[i-1]=getsc(wiy+cy,i);
    st[i-1]='\x0';
    if (getin(wiy+cy-1,0)+strlen(st)>=wx) goto end;
    if (wiy+cy<culine)
      pullline(wiy+cy+1,culine,1);
    else {
      *(sindex+getin(culine,1))=0;
      wriin(culine,0,0); wriin(culine,1,0);
      culine--;
    }
    cx=getin(wiy+cy-1,0)+1;
    if (cy==1) {
      wiy--;
      for (i=1; i<=strlen(st); i++) wrisc(wiy+cy,getin(wiy+cy,0)+i,st[i-1]);
      wriin(wiy+cy,0,getin(wiy+cy,0)+strlen(st));
      displine(1);
    }
    else {
      if (cy<wy)
    scrup(cy);
      if (cy==wy)
    for (i=1; i<=wx; i++) print_han(fx+i,fy+cy," ",color1,color2);
      cy--;
      for (i=1; i<=strlen(st); i++) wrisc(wiy+cy,getin(wiy+cy,0)+i,st[i-1]);
      wriin(wiy+cy,0,getin(wiy+cy,0)+strlen(st));
      displine(cy);
      if (wiy+wy<=culine) displine(wy);
    }
    goto end;
  }
  l1=1; l2=1;
  while (l1<cx) {
    l2=l1;
    l1++;
    if (l1<=getin(wiy+cy,0)) if (getsc(wiy+cy,l1-1)>=128) l1++;
  }
  n=cx-l2;
  if (getsc(wiy+cy,cx-n)<=127)
    print_han(fx+cx-1,fy+cy," ",color1,color2);
  else
    print_han(fx+cx-1,fy+cy,"  ",color1,color2);
  pull(wiy+cy,cx,getin(wiy+cy,0),n);
  cx-=n;
  end: i=0; i=i;
}


/*
   Ctr-Y 가 입력되었을 때 해당 라인을 삭제하기
*/

void delline(void) {
  int i;
  uchar st[100]="";
  if (wiy+cy==culine) {
    for (i=1; i<=getin(wiy+cy,0); i++) strcat(st," ");
    print_han(fx+1,fy+cy,st,color1,color2);
    wriin(wiy+cy,0,0);
    cx=1;
    goto end;
  }
  pullline(wiy+cy+1,culine,1);
  scrup(cy);
  if (wiy+wy<=culine) displine(wy);
  end: i=0; i=i;
}


/*
   read_han_text() 함수에 전달되어진 text 문자열이 있으면, 즉
   길이가 0 보다 크면 text 문자열의 내용을 순서대로 에디터에
   써 준다. 그것을 기본으로 해서 편집을 할 수 있다.
*/

void readtext(uchar *text) {
  int x,y;
  long l,li;
  l=strlen(text);
  li=0; x=1; y=1;
  if (l>0) do {
    if (text[li]!='\r') if (text[li]!='\n') if (x<=wx-2) {
      wrisc(y,x,text[li]);
      if (text[li]>=128) {
    x++; li++; wrisc(y,x,text[li]);
      }
      x++;
    }
    if (text[li]=='\n') {
      wriin(y,0,x-1);
      y++; x=1; culine++;
      if (y<=maxline) wriin(y,1,find());
      if (y>maxline) { li=l; culine--; }
    }
    li++;
  } while (li<=l);
  wriin(y,0,x-2);
}


/*
   edit_han_text() 함수를 종료할 때 에디터에 있는 내용을
   text 변수에 순서대로 담는다. 향후 디스크에 저장하거나
   하는 프로그램을 작성시는 이것을 그대로 저장하면 된다.
*/

void writetext(uchar *text) {
  int i,j;
  long l;
  l=0;
  for (i=1; i<=culine; i++) {
    for (j=1; j<=getin(i,0); j++) {
      text[l]=getsc(i,j);
      l++;
    }
    text[l]='\r'; l++; text[l]='\n'; l++;
  }
  text[l]='\x0';
}


/*
   한글 텍스트 편집함수.
   임의의 위치에 임의의 크기의 창을 열어서 그 안에서 한글 텍스트
   편집을 하고 그 결과를 전달한다. 시작시 내용을 전달받을 수도 
   있다.
   fx_,fy_ : 창이 시작되는 텍스트 x,y 좌표 
   wx_,wy_ : 창의 폭과 높이
   max_    : 편집할 수 있는 최대 라인 수.
   text    : 전달받고 전달해주는 에디터의 내용.
   color1,color2 : 글자의 색과 배경색.
*/

void edit_han_text(int fx_,int fy_,int wx_,int wy_,int max_,
           uchar *text, int color1_,int color2_ ) {
  int hmode=1;
  int i,j, x,y;
  long l,li;
  uchar ch1,ch2;
  int cuser=0,loop=1000,pressed;
  uchar stcuser[3];
  uchar st[100];
  fx=fx_; fy=fy_; wx=wx_; wy=wy_,maxline=max_; culine=1;
  cx=1; cy=1; wiy=0;
  color1=color1_, color2=color2_;
  jhnum=0; jjnum=0;
  chnum[1]=0; chnum[2]=0; chnum[3]=0;
  ccnum[1]=0; ccnum[2]=0; ccnum[3]=0;
  l=farcoreleft();
  if (maxline<wy) maxline=wy;
  if (maxline>1000) maxline=1000;
  if (l<maxline*(wx+1+4)) {
    restorecrtmode();
    cprintf("not enough memory.. program halted..");
    exit(1);
  }
  screen=farmalloc(maxline*wx);
  sindex=farmalloc(maxline+1);
  for (i=1; i<=maxline; i++) *(sindex+i)=0;
  index=farmalloc(maxline*2*2);
  for (i=1; i<=maxline; i++) { wriin(i,0,0); wriin(i,1,0); }
  wriin(1,1,find());
  readtext(text);
  dispallline();
  do {
    pressed=0;
    if (cx>getin(wiy+cy,0)) strcpy(stcuser," ");
    if (cx<=getin(wiy+cy,0)) {
      if (32<=getsc(wiy+cy,cx)) if (getsc(wiy+cy,cx)<=127) {
    stcuser[0]=getsc(wiy+cy,cx);
    stcuser[1]='\x0';
      }
      if (128<=getsc(wiy+cy,cx)) {
    stcuser[0]=getsc(wiy+cy,cx);
    stcuser[1]=getsc(wiy+cy,cx+1);
    stcuser[2]='\x0';
      }
    }
    if (pressed==0) {
      if (cuser==0) {
    cuser=1;
    if (cx<=getin(wiy+cy,0))
      print_han(fx+cx,fy+cy,stcuser,color2,color1);
    if (cx> getin(wiy+cy,0))
      print_han(fx+cx,fy+cy,stcuser,color2,color1);
      }
      else {
    cuser=0;
    if (cx<=getin(wiy+cy,0))
      print_han(fx+cx,fy+cy,stcuser,color1,color2);
    if (cx> getin(wiy+cy,0))
      print_han(fx+cx,fy+cy,stcuser,color1,color2);
      }
    }
    for (i=1; i<=loop; i++) {
      ch1=0; ch2=0;
      if (kbhit()) inkey(&ch1,&ch2);
    if ((ch1>0) || (ch2>0)) {
    i=loop; pressed=1;
      }
    }
    if (pressed) {
      print_han(fx+cx,fy+cy,stcuser,color1,color2);
      if ((bioskey(2)==1) || (bioskey(2)==2)) if (ch1==' ') {
	sound(300); delay(10); nosound();
	hmode=1-hmode;
	goto end;
      }
      if (32<=ch1) if (ch1<=127) if (hmode==1) hanone(ch1);
      if (32<=ch1) if (ch1<=127) if (hmode==0) engone(ch1);
      if (ch1==13) {
    if (jhnum>0) { hanzero(); cx+=2; }
    enter();
      }
      if (ch1==8) del();
      if (ch1==25) delline();
      if (ch2==75) left();
      if (ch2==77) right();
      if (ch2==72) up();
      if (ch2==71) home();
      if (ch2==79) end();
      if (ch2==80) down();
      if (ch2==132) top();
      if (ch2==118) bottom();
      if (ch2==73) pgup();
      if (ch2==81) pgdown();
      if (ch2==60) {
	sound(300); delay(10); nosound();
	hmode=1-hmode;
      }
      end: cuser=0;
    }
  } while (ch1!=27);
  writetext(text);
  farfree(screen);
  farfree(sindex);
  farfree(index);
}
 
