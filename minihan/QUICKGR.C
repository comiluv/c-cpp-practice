/* ====================================================================
                          그래픽 출력 부분
                               f o r
                   한글 라이브러리 [미니한글 라이브]
                  94, 1. 조 성 용 (Creative in Hitel)
                         Thanks to Kim.J.W
   ====================================================================

     빠른 속도로 한글,영문을 출력하고, 상하 좌우로 스크롤 할 수
     있는 함수들이 있습니다.
     인라인 어셈블리가 있으므로 TC 2.0 에서는 외부에서 컴파일 합니다.
   ==================================================================== */

#include <dos.h>

typedef unsigned char uchar;


/*
   x,y 좌표에 전달받은 16*16 의 img 를 color1 색으로 덮어 쓴다.
   한글 한 글자 출력시 쓰임.
*/

void over_put_32(int x,int y,uchar *img,uchar color1) {
  asm  push ds;
  asm  mov ax,0a000h;
  asm  mov es,ax;
  _SI = y*80+x;
  _BX = FP_OFF(img);
  _DS = FP_SEG(img);
  asm  mov di,si;
  asm  mov dx,3ceh;
  asm  mov ax,205h;
  asm  out dx,ax;
  asm  mov ax,305h;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  mov dx,ax;
  asm  mov ax,0f01h;
  asm  out dx,ax;
  asm  mov dx,3ceh;
  asm  mov al,0;
  asm  mov ah,byte ptr color1;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov si,di;
  Put_han1:
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc si;
  asm  inc bx;
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc bx;
  asm  add si,79;
  asm  loop Put_han1;
  asm  mov ax,5;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  out dx,ax;
  asm  mov ax,1;
  asm  out dx,ax;
  asm  mov ax,0;
  asm  mov dx,ax;
  asm  pop ds;
}


/*
   x,y 좌표에 전달받은 16*16 의 img 를 color1 색과 color2 배경색으로 쓴다.
   한글 한 글자 출력시 쓰임.
*/

void ins_put_32(int x,int y,uchar *img,uchar color1,uchar color2) {
  asm  push ds;
  asm  mov ax,0a000h;
  asm  mov es,ax;
  _SI = y*80+x;
  _BX = FP_OFF(img);
  _DS = FP_SEG(img);
  asm  mov di,si;
  asm  mov dx,3ceh;
  asm  mov ax,205h;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov al,color2;
  Put_han:
  asm  mov byte ptr es:[si],al;
  asm  inc si;
  asm  mov byte ptr es:[si],al;
  asm  add si,79;
  asm  loop Put_han;
  asm  mov ax,305h;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  mov dx,ax;
  asm  mov ax,0f01h;
  asm  out dx,ax;
  asm  mov dx,3ceh;
  asm  mov al,0;
  asm  mov ah,byte ptr color1;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov si,di;
  Put_han1:
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc si;
  asm  inc bx;
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc bx;
  asm  add si,79;
  asm  loop Put_han1;
  asm  mov ax,5;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  out dx,ax;
  asm  mov ax,1;
  asm  out dx,ax;
  asm  mov ax,0;
  asm  mov dx,ax;
  asm  pop ds;
}


/*
   x,y 좌표에 전달받은 8*16 의 img 를 color1 색으로 쓴다.
   영자 한 글자 출력시 쓰임.
*/

void over_put_16(int x,int y,uchar *img,uchar color1) {
  asm  push ds;
  asm  mov ax,0a000h;
  asm  mov es,ax;
  _SI = y*80+x;
  _BX = FP_OFF(img);
  _DS = FP_SEG(img);
  asm  mov di,si;
  asm  mov dx,3ceh;
  asm  mov ax,205h;
  asm  out dx,ax;
  asm  mov ax,305h;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  mov dx,ax;
  asm  mov ax,0f01h;
  asm  out dx,ax;
  asm  mov dx,3ceh;
  asm  mov al,0;
  asm  mov ah,byte ptr color1;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov si,di;
  Put_eng1:
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc bx;
  asm  add si,80;
  asm  loop Put_eng1;
  asm  mov ax,5;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  out dx,ax;
  asm  mov ax,1;
  asm  out dx,ax;
  asm  mov ax,0;
  asm  mov dx,ax;
  asm  pop ds;
}


/*
   x,y 좌표에 전달받은 8*16 의 img 를 color1 색과 color2 배경색으로 쓴다.
   영자 한 글자 출력시 쓰임.
*/

void ins_put_16(int x,int y,uchar *img,uchar color1,uchar color2) {
  asm  push ds;
  asm  mov ax,0a000h;
  asm  mov es,ax;
  _SI = y*80+x;
  _BX = FP_OFF(img);
  _DS = FP_SEG(img);
  asm  mov di,si;
  asm  mov dx,3ceh;
  asm  mov ax,205h;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov al,color2;
  Put_eng:
  asm  mov byte ptr es:[si],al;
  asm  add si,80;
  asm  loop Put_eng;
  asm  mov ax,305h;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  mov dx,ax;
  asm  mov ax,0f01h;
  asm  out dx,ax;
  asm  mov dx,3ceh;
  asm  mov al,0;
  asm  mov ah,byte ptr color1;
  asm  out dx,ax;
  asm  mov cx,16;
  asm  mov si,di;
  Put_eng1:
  asm  mov al,byte ptr es:[si];
  asm  mov al,byte ptr ds:[bx];
  asm  mov byte ptr es:[si],al;
  asm  inc bx;
  asm  add si,80;
  asm  loop Put_eng1;
  asm  mov ax,5;
  asm  out dx,ax;
  asm  mov ax,3;
  asm  out dx,ax;
  asm  mov ax,1;
  asm  out dx,ax;
  asm  mov ax,0;
  asm  mov dx,ax;
  asm  pop ds;
}


/*
   x1,y1 에서 x2,y2 부분까지를 위로 n 칸 민다. 
   공간에는 color2 색으로 채운다.
*/

void scroll_up(int x1,int y1,int x2,int y2,int n,uchar color2) {
  unsigned x_width = x2-x1+1;
  unsigned y_width;
  y_width = 80*n;
  asm push ds;
  asm push es;
  asm mov dx,3ceh;
  asm mov ax,5;
  asm out dx,ax;
  asm mov ax,0a000h;
  asm mov es,ax;
  asm mov ds,ax;
  _CX = y2-y1-n+1;
  asm mov ax,y1;
  asm mov dx,80;
  asm mul dx;
  asm mov bx,ax;
  asm mov dx,3c4h;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm mov dx,3ceh;
  asm mov ax,0008h;
  asm out dx,ax;
  uplp2:
  asm push cx;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x1;
  asm mov si,di;
  asm add si,y_width;
  asm cld;
  asm rep movsb;
  asm add bx,80;
  asm pop cx;
  asm loop uplp2
  asm mov ax,0ff08h;
  asm out dx,ax;
  asm mov dx,3c4h;
  _CX = n;
  uplp:
  asm push cx;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x1;
  uplp3:
  asm mov byte ptr es:[di],0;
  asm mov al,2;
  asm mov ah,color2;
  asm out dx,ax;
  asm mov byte ptr es:[di],0ffh;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm inc di;
  asm loop uplp3;
  asm pop cx;
  asm add bx,80;
  asm loop uplp;
  asm pop es;
  asm pop ds;
}


/*
   x1,y1 에서 x2,y2 부분까지를 아래로 n 칸 민다. 
   공간에는 color2 색으로 채운다.
*/

void scroll_down(int x1,int y1,int x2,int y2,int n,uchar color2){
  unsigned x_width = x2-x1+1;
  unsigned y_width;
  y_width = 80*n;
  asm push ds;
  asm push es;
  asm mov dx,3ceh;
  asm mov ax,5;
  asm out dx,ax;
  asm mov ax,0a000h;
  asm mov es,ax;
  asm mov ds,ax;
  _CX = y2-y1-n+1;
  asm mov ax,y2;
  asm mov dx,80;
  asm mul dx;
  asm mov bx,ax;
  asm mov dx,3c4h;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm mov dx,3ceh;
  asm mov ax,0008h;
  asm out dx,ax;
  dnlp2:
  asm push cx;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x1;
  asm mov si,di;
  asm sub si,y_width;
  asm cld;
  asm rep movsb;
  asm sub bx,80;
  asm pop cx;
  asm loop dnlp2
  asm mov ax,0ff08h;
  asm out dx,ax;
  asm mov dx,3c4h;
  _CX = n;
  dnlp:
  asm push cx;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x1;
  dnlp3:
  asm mov byte ptr es:[di],0;
  asm mov al,2;
  asm mov ah,color2;
  asm out dx,ax;
  asm mov byte ptr es:[di],0ffh;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm inc di;
  asm loop dnlp3;
  asm pop cx;
  asm sub bx,80;
  asm loop dnlp;
  asm pop es;
  asm pop ds;
}


/*
   x1,y1 에서 x2,y2 부분까지를 좌로 n 칸 민다. 
   공간에는 color2 색으로 채운다.
*/

void scroll_left(int x1,int y1,int x2,int y2,int n,uchar color2) {
  unsigned x_width = x2-x1-n+1;
  asm push ds;
  asm push es;
  asm mov dx,3ceh;
  asm mov ax,5;
  asm out dx,ax;
  asm mov ax,0a000h;
  asm mov ds,ax;
  asm mov es,ax;
  _CX = y2-y1+1;
  asm mov ax,y1;
  asm mov dx,80;
  asm mul dx;
  asm mov bx,ax;
  asm mov dx,3c4h;
  asm mov ax,0f02h;
  asm out dx,ax;
  llp1:
  asm push cx;
  asm mov dx,3ceh;
  asm mov ax,0008h;
  asm out dx,ax;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x1;
  asm mov si,di;
  asm add si,n;
  asm cld;
  asm rep movsb;
  asm mov ax,0ff08h;
  asm out dx,ax;
  _CX = n;
  asm mov dx,3c4h;
  llp2:
  asm mov byte ptr es:[di],0;
  asm mov al,2;
  asm mov ah,color2;
  asm out dx,ax;
  asm mov byte ptr es:[di],0ffh;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm inc di;
  asm loop llp2;
  asm add bx,80;
  asm pop cx;
  asm loop llp1;
  asm mov dx,3ceh;
  asm mov ax,0ff08h;
  asm out dx,ax;
  asm pop es;
  asm pop ds;
}


/*
   x1,y1 에서 x2,y2 부분까지를 우로 n 칸 민다. 
   공간에는 color2 색으로 채운다.
*/

void scroll_right(int x1,int y1,int x2,int y2,int n,uchar color2) {
  unsigned x_width = x2-x1-n+1;
  asm push ds;
  asm push es;
  asm mov dx,3ceh;
  asm mov ax,5;
  asm out dx,ax;
  asm mov ax,0a000h;
  asm mov ds,ax;
  asm mov es,ax;
  _CX = y2-y1+1;
  asm mov ax,y1;
  asm mov dx,80;
  asm mul dx;
  asm mov bx,ax;
  asm mov dx,3c4h;
  asm mov ax,0f02h;
  asm out dx,ax;
  rlp1:
  asm push cx;
  asm mov dx,3ceh;
  asm mov ax,0008h;
  asm out dx,ax;
  _CX = x_width;
  asm mov di,bx;
  asm add di,x2;
  asm mov si,di;
  asm sub si,n;
  asm std;
  asm rep movsb;
  asm mov si,bx;
  asm add si,x1;
  asm mov ax,0ff08h;
  asm out dx,ax;
  _CX = n;
  asm mov dx,3c4h;
  rlp2:
  asm mov byte ptr es:[si],0;
  asm mov al,2;
  asm mov ah,color2;
  asm out dx,ax;
  asm mov byte ptr es:[si],0ffh;
  asm mov ax,0f02h;
  asm out dx,ax;
  asm inc si;
  asm loop rlp2;
  asm add bx,80;
  asm pop cx;
  asm loop rlp1;
  asm mov dx,3ceh;
  asm mov ax,0ff08h;
  asm out dx,ax;
  asm pop es;
  asm pop ds;
}
 
