/*    ===========================================================
                   Header file for MINI HANHUL LIB
      ===========================================================  */

typedef unsigned char uchar;

void init_graph(void);

void print_eng(int x,int y,char *st,int color1,int color2);

void print_han(int x,int y,char *st,int color1,int color2);

void read_eng(int fx,int fy,int max,uchar *string, int *selected,
	      int color1,int color2);

void read_han(int fx,int fy, int max, uchar *string, int *selected,
	      int color1,int color2);

void edit_han_text(int fx_,int fy_,int wx_,int wy_,int max_,uchar *text,
	      int color1_,int color2_ );
