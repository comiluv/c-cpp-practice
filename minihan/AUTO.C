/* ===================================================================
             한글 자소처리 함수들 ( 한글 오토메타 두벌식 )
                               f o r
                  한글 라이브러리 [미니한글라이브]
                 94, 1   조 성 용. Creative in Hitel
   =================================================================== 

      한글을 사용할 때 기본이 되는 처리루틴이 모여있는 것입니다.
      여기서 자음값,모음값 은 자판에 있는 글자를 순서대로 나열한
      숫자에 해당하는 것이고, 초성값,중성값,종성값 은 실제로
      글자에 사용되어지는 자소의 값을 말합니다. 
      복자음과 복모음이 있어서 자판보다 많아지고, 종성에는 다른것이
      쓰이기 때문에 이렇게 구별합니다.
   =================================================================== */
 
/*
   입력된 ch1 키가 기호,숫자키이면      code[1]=0,
                   한글 자음의 키이면   code[1]=1,
                   한글 모음의 키이면   code[1]=2  로 돌려주며
   입력된 키가 한글 자소일때 자음이면 초성값,
                             모음이면 중성값을 code[2] 에 돌려준다.
   입력된 키를 젤 처음 처리할때 쓰임.
*/

void keycode(char ch1, int *code) {
  code[1]= 0; code[2]=0;
  if (ch1=='r')                 { code[1]=1; code[2]= 1; }
  if (ch1=='R')                 { code[1]=1; code[2]= 2; }
  if ((ch1=='s') || (ch1=='S')) { code[1]=1; code[2]= 3; }
  if (ch1=='e')                 { code[1]=1; code[2]= 4; }
  if (ch1=='E')                 { code[1]=1; code[2]= 5; }
  if ((ch1=='f') || (ch1=='F')) { code[1]=1; code[2]= 6; }
  if ((ch1=='a') || (ch1=='A')) { code[1]=1; code[2]= 7; }
  if (ch1=='q')                 { code[1]=1; code[2]= 8; }
  if (ch1=='Q')                 { code[1]=1; code[2]= 9; }
  if (ch1=='t')                 { code[1]=1; code[2]=10; }
  if (ch1=='T')                 { code[1]=1; code[2]=11; }
  if ((ch1=='d') || (ch1=='D')) { code[1]=1; code[2]=12; }
  if (ch1=='w')                 { code[1]=1; code[2]=13; }
  if (ch1=='W')                 { code[1]=1; code[2]=14; }
  if ((ch1=='c') || (ch1=='C')) { code[1]=1; code[2]=15; }
  if ((ch1=='z') || (ch1=='Z')) { code[1]=1; code[2]=16; }
  if ((ch1=='x') || (ch1=='X')) { code[1]=1; code[2]=17; }
  if ((ch1=='v') || (ch1=='V')) { code[1]=1; code[2]=18; }
  if ((ch1=='g') || (ch1=='G')) { code[1]=1; code[2]=19; }
  if ((ch1=='k') || (ch1=='K')) { code[1]=2; code[2]= 1; }
  if (ch1=='o')                 { code[1]=2; code[2]= 2; }
  if ((ch1=='i') || (ch1=='I')) { code[1]=2; code[2]= 3; }
  if (ch1=='O')                 { code[1]=2; code[2]= 4; }
  if ((ch1=='j') || (ch1=='J')) { code[1]=2; code[2]= 5; }
  if (ch1=='p')                 { code[1]=2; code[2]= 6; }
  if ((ch1=='u') || (ch1=='U')) { code[1]=2; code[2]= 7; }
  if (ch1=='P')                 { code[1]=2; code[2]= 8; }
  if ((ch1=='h') || (ch1=='H')) { code[1]=2; code[2]= 9; }
  if ((ch1=='y') || (ch1=='Y')) { code[1]=2; code[2]=10; }
  if ((ch1=='n') || (ch1=='N')) { code[1]=2; code[2]=11; }
  if ((ch1=='b') || (ch1=='B')) { code[1]=2; code[2]=12; }
  if ((ch1=='m') || (ch1=='M')) { code[1]=2; code[2]=13; }
  if ((ch1=='l') || (ch1=='L')) { code[1]=2; code[2]=14; }
}


/*
   a 로 종성값을 받아서 그것이 어떤 초성이 되는지를 
   b 에 돌려준다. 초성으로 쓰일 수 없는 종성이면 exist=0 으로
   돌려준다.
   종성이 초성으로 옮겨갈때 쓰임.
*/
  
void whatfirst( int a,int *b,int *exist) {
  *exist = 1;
  switch (a) {
    case  1 : *b= 1; break;
    case  2 : *b= 2; break;
    case  3 : *exist= 0; break;
    case  4 : *b= 3; break;
    case  5 : *exist= 0; break;
    case  6 : *exist= 0; break;
    case  7 : *b= 4; break;
    case  8 : *b= 6; break;
    case  9 : *exist= 0; break;
    case 10 : *exist= 0; break;
    case 11 : *exist= 0; break;
    case 12 : *exist= 0; break;
    case 13 : *exist= 0; break;
    case 14 : *exist= 0; break;
    case 15 : *exist= 0; break;
    case 16 : *b= 7; break;
    case 17 : *b= 8; break;
    case 18 : *exist= 0; break;
    case 19 : *b=10; break;
    case 20 : *b=11; break;
    case 21 : *b=12; break;
    case 22 : *b=13; break;
    case 23 : *b=15; break;
    case 24 : *b=16; break;
    case 25 : *b=17; break;
    case 26 : *b=18; break;
    case 27 : *b=19; break;
  }
}


/*
   받침이 입력되는 순간에 입력된 코드를 keycode() 에서 초성값으로 
   변환한 것을 a 로 받아서 종성값으로 변환해서 b 로 돌려준다.
   a가 종성에는 없는 자소일때는 exist=0 으로 돌려준다.
   받침이 입력될때 종성값을 구하는 것이지만,다음글자로 넘어가는지 
   판별하기 위해서도 쓰임.
*/

void whatlast(int a,int *b,int *exist) {
  *exist = 1;
  switch (a) {
    case  1 : *b= 1; break;
    case  2 : *b= 2; break;
    case  3 : *b= 4; break;
    case  4 : *b= 7; break;
    case  5 : *exist= 0; break;
    case  6 : *b= 8; break;
    case  7 : *b=16; break;
    case  8 : *b=17; break;
    case  9 : *exist= 0; break;
    case 10 : *b=19; break;
    case 11 : *b=20; break;
    case 12 : *b=21; break;
    case 13 : *b=22; break;
    case 14 : *exist= 0; break;
    case 15 : *b=23; break;
    case 16 : *b=24; break;
    case 17 : *b=25; break;
    case 18 : *b=26; break;
    case 19 : *b=27; break;
  }
}


/*
   자음을 a,b 두개를 각각 종성값,초성값으로 받아서 그 두 자음이 
   합해질 수 있는지 판별해서 합쳐진 종성값을 c 로 돌려준다.
   합해질 수 없으면 can=0 으로 돌려준다.
   받침에서 자음이 연속으로 두개 입력될때 복자음으로 되는지,
   다음글자로 넘어가는지를 판별할 때 쓰임.
*/

void canadd(int a,int b,int *c,int *can) {
   *can= 0;
   if (a== 1) if (b==10) { *can= 1; *c= 3; }
   if (a== 4) if (b==13) { *can= 1; *c= 5; }
   if (a== 4) if (b==19) { *can= 1; *c= 6; }
   if (a== 8) if (b== 1) { *can= 1; *c= 9; }
   if (a== 8) if (b== 7) { *can= 1; *c=10; }
   if (a== 8) if (b== 8) { *can= 1; *c=11; }
   if (a== 8) if (b==10) { *can= 1; *c=12; }
   if (a== 8) if (b==17) { *can= 1; *c=13; }
   if (a== 8) if (b==18) { *can= 1; *c=14; }
   if (a== 8) if (b==19) { *can= 1; *c=15; }
   if (a==17) if (b==10) { *can= 1; *c=18; }
}


/* 
   종성값 a 로 받은 것은 복자음 받침인데 이것을 두개의 자음으로 분리해서
   분리된 값을 b,c 에 각각 종성값과 초성값으로 전달한다.
   여기선 분리될 수 있는 것만 받게 된다.
   받침에 복자음이 있고 모음이 입력될때 종성이 분리되어 다음
   글자로 넘어갈 때 쓰임
*/

void devide(int a,int *b,int *c) {
  switch (a) {
    case  3 : *b=  1; *c= 10; break;
    case  5 : *b=  4; *c= 13; break;
    case  6 : *b=  4; *c= 19; break;
    case  9 : *b=  8; *c=  1; break;
    case 10 : *b=  8; *c=  7; break;
    case 11 : *b=  8; *c=  8; break;
    case 12 : *b=  8; *c= 10; break;
    case 13 : *b=  8; *c= 17; break;
    case 14 : *b=  8; *c= 18; break;
    case 15 : *b=  8; *c= 19; break;
    case 18 : *b= 17; *c= 10; break;
  }
}


/*
   a 로 받은 모음값이 복모음을 이룰 수 있는 것인
   (오,요,우,유,으,이) 이면 1, 아니면 0 을 돌려준다.   
   모음이 연속 두개 입력될때 복모음을 이루는지 검사할 때 쓰임.
*/

char midtype(int a) {
  char boo;
  boo= 0;
  if ((9<=a) && (a<=13)) boo= 1;
  return boo;
}


/* 
   a,b 두개의 모음값을 받아서 합쳐질 수 있으면 합쳐진 중성값을
   c 로 돌려준다. 합쳐질 수 없으면 can=0 으로 돌려준다.
   모음이 연속 두개 입력될때 쓰임.
*/

void addmiddle(int a,int b,int *c,int *can) {
  *can= 0;
  if (a==  9) if (b==  1) { *c= 10; *can= 1; }
  if (a==  9) if (b==  2) { *c= 11; *can= 1; }
  if (a==  9) if (b== 14) { *c= 12; *can= 1; }
  if (a== 14) if (b==  5) { *c= 15; *can= 1; }
  if (a== 14) if (b==  6) { *c= 16; *can= 1; }
  if (a== 14) if (b== 14) { *c= 17; *can= 1; }
  if (a== 19) if (b== 14) { *c= 20; *can= 1; }
}


/*
  모음값 a 를 받아서 중성값으로 변환해서 b 로 돌려준다.
  모음의 키가 입력될 때 처음에 사용한다.
*/

void transmother(int a,int *b) {
  if (a==  1) *b=  1;
  if (a==  2) *b=  2;
  if (a==  3) *b=  3;
  if (a==  4) *b=  4;
  if (a==  5) *b=  5;
  if (a==  6) *b=  6;
  if (a==  7) *b=  7;
  if (a==  8) *b=  8;
  if (a==  9) *b=  9;
  if (a== 10) *b= 13;
  if (a== 11) *b= 14;
  if (a== 12) *b= 18;
  if (a== 13) *b= 19;
  if (a== 14) *b= 21;
}


/*
  한글 오토메타의 핵심부분.
  code 로 하나의 자소를 받아서
  현재 진행중인 글자가 어떤 자소로 이루어져 있는지에 따라 
  키가 입력될시 어떻게 변환되는지를 판별한다.
  각 변수는
    code[1,2]    : 자음인지,모음인지와 자음값,모음값을 전달받은것.
    CHnum[1,2,3] : 현재 진행중인 글자의 초성값,중성값,종성값.  
    JHnum        : 현재 진행중인 글자의 조합형태에 해당하는 숫자.
    gone         : 처리한 후에 글자가 다음으로 넘어가면 1, 아니면 0.
    CCnum[1,2,3],JJnum : 글자가 넘어갈 시 종전 글자를 저장한는 것.
*/    

void decide(int *JJnum,int *JHnum,int *code,int *CCnum,int *CHnum,int *gone) {
  int a,b,t1,t2,t3,t4, i,j, m;
  int can, ok, exist;
  *gone=0;
                                     /* 자음이 입력되었으면 */
  if (code[1]==1) {                    
    m=0;
    if (*JHnum==0) if (m==0) {
      m=1;
      *gone= 0;
      *JHnum= 1;
      CHnum[1]= code[2];
    }
    if (*JHnum==1) if (m==0) {
      m=1;
      *gone= 1;
      *JJnum= 1;
      *JHnum= 1;
      CCnum[1]= CHnum[1];
      CHnum[1]= code[2]; CHnum[2]=0; CHnum[3]=0;
    }
    if ((*JHnum==2) || (*JHnum==5) || (*JHnum==8)) if (m==0) {
      m=1;
      if (CHnum[1]==0) {
    m=2;
    *gone=1;
    *JJnum=2; *JHnum=1;
    CCnum[1]=0; CCnum[2]=CHnum[2]; CCnum[3]=0;
    CHnum[1]=code[2]; CHnum[2]=0; CHnum[3]=0;
      }
      if (m==1) {
    t1= code[2];
    whatlast( t1, &t2, &exist );
    if (exist) {
      *gone= 0;
      *JHnum= *JHnum+1;
      CHnum[3]= t2;
    }
    if (!(exist)) {
      *gone= 1;
      *JJnum= *JHnum;
      *JHnum= 1;
      for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
      CHnum[1]= code[2]; CHnum[2]=0; CHnum[3]=0;
    }
      }
    }
    if ((*JHnum==3) || (*JHnum==6) || (*JHnum==9)) if (m==0) {
      m=1;
      t1= CHnum[3]; t2= code[2];
      canadd( t1, t2, &t3, &can );
      if (can) {
    *gone= 0;
    *JHnum = *JHnum+1;
    CHnum[3]= t3;
      }
      if (!(can)) {
    *gone= 1;
    *JJnum= *JHnum;
    *JHnum= 1;
    for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
    CHnum[1]= code[2];  CHnum[2]=0; CHnum[3]= 0;
      }
    }
    if ((*JHnum==4) || (*JHnum==7) || (*JHnum==10)) if (m==0) {
      m=1;
      *gone= 1;
      *JJnum= *JHnum;
      *JHnum= 1;
      for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
      CHnum[1]= code[2];  CHnum[2]=0; CHnum[3]= 0;
    }
  }
                                         /* 모음이 입력되었으면 */
  if (code[1]==2) {
    m=0;
    if ((*JHnum==0) || (*JHnum==1)) if (m==0) {
      m=1;
      *gone= 0;
      *JHnum= 2; t1= code[2];
      if (midtype(t1)) *JHnum= 5;
      t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
    }
    if (*JHnum==2) if (m==0) {
      m=1;
      *gone= 1;
      *JJnum= 2;
      *JHnum= 2; t1= code[2];
      if (midtype(t1)) *JHnum= 5;
      for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
      CHnum[1]=0;
      t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
      CHnum[3]=0;
    }
    if ((*JHnum==3) || (*JHnum==6) || (*JHnum==9)) if (m==0) {
      m=1;
      *gone= 1;
      t2= CHnum[3];
      whatfirst( t2,&t3, &exist );
      if (exist) {
    *JJnum= *JHnum - 1;
    *JHnum= 2; t1= code[2];
    if (midtype(t1)) *JHnum= 5;
    CCnum[1]= CHnum[1]; CCnum[2]= CHnum[2]; CCnum[3]=0;
    CHnum[1]= t3;
    t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
    CHnum[3]=0;
      }
      if (!(exist)) {
    *JJnum= *JHnum;
    *JHnum= 2; t1= code[2];
    if (midtype(t1)) *JHnum= 5;
    for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
    CHnum[1]=0;
    t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
    CHnum[3]= 0;
      }
    }
    if ((*JHnum==4) || (*JHnum==7) || (*JHnum==10)) if (m==0) {
      m=1;
      *gone= 1;
      t2= CHnum[3];
      devide( t2,&t3,&t4 );
      *JJnum= *JHnum - 1;
      *JHnum= 2; t1= code[2];
      if (midtype(t1)) *JHnum= 5;
      CCnum[1]= CHnum[1]; CCnum[2]= CHnum[2]; CCnum[3]= t3;
      CHnum[1]= t4;
      t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
      CHnum[3]= 0;
    }
    if (*JHnum==5) if (m==0) {
      m=1;
      t1= CHnum[2];
      t2= code[2];
      addmiddle( t1,t2,&t3, &can );
      if (can) {
    *gone= 0;
    *JHnum= 8;
    CHnum[2]= t3;
      }
      if (!(can)) {
    *gone= 1;
    *JJnum= 5;
    *JHnum= 5;
    CCnum[1]= CHnum[1]; CCnum[2]= CHnum[2]; CCnum[3]= 0;
    CHnum[1]= 0;
    t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
    CHnum[3]= 0;
      }
    }
    if (*JHnum==8) if (m==0) {
      m=1;
      *gone= 1;
      *JJnum= 8;
      *JHnum= 2; t1= code[2];
      if (midtype(t1)) *JHnum= 5;
      for (i=1; i<=3; i++) CCnum[i]= CHnum[i];
      CHnum[1]=0;
      t1= code[2]; transmother(t1,&t2); CHnum[2]= t2;
      CHnum[3]= 0;
    }
  }
}


/*
   내부에서 사용하는 아스키 숫자를 키에 맞게 변환한다.
*/

void asciicode(int ch1,int ch2,int *ACode) {
  *ACode= 0;
  if (32<=ch1) if (ch1<=126) if (ch2==0) *ACode=ch1+1;
}


/*
   받은 글자를 조합형 한글 코드로 변환한다.
   CHnum[1,2,3] 은 각각 초,중,종성값이고 c1,c2 는 만들어져서
   돌려주는 아스키코드값이다.
   한글의 진행되는 한글자만 자소별로 처리되고 다른 부분은 모두
   조합형 형태로 보관됨.
*/
      
void deci(int *CHnum,int *c1,int *c2) {
    int i,j,m;
    int b1,b2;
    if (CHnum[1]>=0) {
      b1=132+CHnum[1]*4;
      b2=65;
    }
    if (CHnum[2]>0) {
      if ( 1<=CHnum[2]) if (CHnum[2]<= 5) { b1=b1+0; b2=65+(CHnum[2]- 0)*32; }
      if ( 6<=CHnum[2]) if (CHnum[2]<=11) { b1=b1+1; b2=65+(CHnum[2]- 6)*32; }
      if (12<=CHnum[2]) if (CHnum[2]<=17) { b1=b1+2; b2=65+(CHnum[2]-12)*32; }
      if (18<=CHnum[2]) if (CHnum[2]<=21) { b1=b1+3; b2=65+(CHnum[2]-18)*32; }
    }
    if (CHnum[3]>0) {
      if ( 1<=CHnum[3]) if (CHnum[3]<=16) b2=b2+CHnum[3]+0;
      if (17<=CHnum[3]) if (CHnum[3]<=27) b2=b2+CHnum[3]+1;
    }
    *c1=b1; *c2=b2;
  }


/*
   글자가 진행중일때 Del 키가 눌렸을 시 현재 진행중인 글자가
   어떻게 자소별로 변환되는지 처리해서 돌려준다.
   JHnum 은 글자의 형태, CHnum 은 각 자소값.
   처리후에도 글자가 남아 있으면 process=1 소멸되었으면 0 으로 돌려준다.
*/

void backhan(int *JHnum,int *CHnum,int *process) {
  int i,j,n, m;
  m=0;
  if (*JHnum==1) if (m==0) {
    m=1;
    *process=0;
    (*JHnum)=0;
    CHnum[1]=0;
  }
  if ((*JHnum==2) || (*JHnum==5)) if (m==0) {
    m=1;
    (*JHnum)=1;
    CHnum[2]= 0;
  }
  if (*JHnum==8) if (m==0) {
    m=1;
    (*JHnum)= 5;
    if (10<=CHnum[2]) if (CHnum[2]<=12) CHnum[2]= 9;
    if (15<=CHnum[2]) if (CHnum[2]<=17) CHnum[2]=14;
    if (CHnum[2]==20) CHnum[2]=19;
  }
  if ((*JHnum==3) || (*JHnum==6) || (*JHnum==9)) if (m==0) {
    m=1;
    (*JHnum)--;
    CHnum[3]= 0;
  }
  if ((*JHnum==4) || (*JHnum==7) || (*JHnum==10)) if (m==0) {
    m=1;
    (*JHnum)--;
    if (CHnum[3]==3) CHnum[3]= 1;
    if ((CHnum[3]==5) || (CHnum[3]==6)) CHnum[3]= 4;
    if (9<=CHnum[3]) if (CHnum[3]<=15) CHnum[3]= 8;
    if (CHnum[3]==18) CHnum[3]=17;
  }
}


/*
   c0 이 다음것들중에 있는지 판별하는 함수. 계산용.
*/

char in(char c0,char c1,char c2,char c3,char c4,char c5,
   char c6,char c7,char c8,char c9,char c10,
   char c11,char c12,char c13,char c14,char c15,
   char c16,char c17,char c18,char c19,char c20 ) {
   char re;
   re=0;
   if (c0==c1) re=1;
   if (c0==c2) re=1;
   if (c0==c3) re=1;
   if (c0==c4) re=1;
   if (c0==c5) re=1;
   if (c0==c6) re=1;
   if (c0==c7) re=1;
   if (c0==c8) re=1;
   if (c0==c9) re=1;
   if (c0==c10) re=1;
   if (c0==c11) re=1;
   if (c0==c12) re=1;
   if (c0==c13) re=1;
   if (c0==c14) re=1;
   if (c0==c15) re=1;
   if (c0==c16) re=1;
   if (c0==c17) re=1;
   if (c0==c18) re=1;
   if (c0==c19) re=1;
   if (c0==c20) re=1;
   return re;
}


/*
   초,중,종성의 존재와 종류에 따라서 직접 써지는 폰트가 무엇인지
   종류를 돌려준다. 
   b1,b2,b3 로 받아서 c1,c2,c3 로 돌려준다.
   화면에 글자를 쓸때 쓰임.
*/

void writetype(int b1,int b2,int b3,char *t1,char *t2,char *t3) {
  int i,j,k;
  int JH;
  char c1,c2;
  unsigned char num[3+1][2+1];
  c1=0; c2=0;
  num[1][2]=b1; num[2][2]=b2; num[3][2]=b3;
  for (i=1; i<=3; i++) num[i][1]= 1;
  if (in( num[1][2], 3,4,5,6,7,8,9,12,17,18,19,  0,0,0,0,0,0,0,0,0))  c1=1;
  if (in( num[2][2], 9,10,11,12,13,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0))  c2=1;
  JH= 0;
  if (num[1][2]>0) JH=1;
  if (num[2][2]>0) {
    if (in( num[2][2] ,1,2,3,4,5,6,7,8,21,  0,0,0,0,0,0,0,0,0,0,0)) JH=2;
    if (in( num[2][2] ,9,13,14,18,19,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) JH=5;
    if (in( num[2][2] ,10,11,12,15,16,17,20,  0,0,0,0,0,0,0,0,0,0,0,0,0)) JH=8;
  }
  if (num[3][2]>0) if (JH>=2) {
    if (in( num[3][2] ,1,2,4,7,8,16,17,19,20,21,22,23,24,25,26,27, 0,0,0,0))
      JH=JH+1;
    if (in( num[3][2] , 3,5,6,9,10,11,12,13,14,15,18, 0,0,0,0,0,0,0,0,0))
      JH=JH+2;
  }
  if (num[3][2]>0) if (JH<2) JH=3;
  if (JH==0) JH=1;
  switch (JH) {
    case 3: num[1][1]=6;   num[2][1]=3;    num[3][1]=1;
        if (in(num[2][2], 2,4,6,7,8, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[3][1]=2;
        break;
    case 4: num[1][1]=6;   num[2][1]=3;    num[3][1]=1;
        if (in(num[2][2], 2,4,6,7,8, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[3][1]=2;
        break;
    case 5: num[1][1]=2;   num[2][1]=2;
        if (in(num[2][2], 14,18, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[1][1]=3;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=1;
        break;
    case 6: num[1][1]=7;   num[2][1]=4;  num[3][1]=4;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=3;
        break;
    case 7: num[1][1]=7;   num[2][1]=4;  num[3][1]=4;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=3;
        break;
    case 8: num[1][1]=4;   num[2][1]=2;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=1;
        if (in(num[2][2], 15,16,17, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[1][1]=5;
        break;
    case 9: num[1][1]=8;   num[2][1]=4;    num[3][1]=1;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=3;
        break;
    case 10:num[1][1]=8;   num[2][1]=4;    num[3][1]=1;
        if (in(num[1][2], 1,16, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)) num[2][1]=3;
        break;
  }
  *t1=num[1][1]; *t2=num[2][1]; *t3=num[3][1];
  c1++; c2++;
}
 
