#include<stdlib.h>
#include<cairo.h>
#include<cairo-xlib.h>
#include<time.h>
#define RIGHT 4
#define LEFT 3
#define DOWN 2
#define UP 1
#define TILE 2
#define BORDER 30
#define IMG_DIMEN(x) (((x)*TILE)+(((x)-1)*BORDER))

static void render(int** grid,int w,int h){
  cairo_surface_t* surface=cairo_image_surface_create(CAIRO_FORMAT_ARGB32,IMG_DIMEN(w),IMG_DIMEN(h));
  cairo_t* cr=cairo_create(surface);
  cairo_set_source_surface(cr,surface,0,0);
  cairo_set_source_rgb(cr,0.1,0.1,0.1);
  cairo_paint(cr);
  cairo_set_source_rgb(cr,0,1,0);
  for(int a=0;a<w;a++){
    for(int b=0;b<h;b++){
      if(grid[a][b]){
        int top=b*(TILE+BORDER);
        int left=a*(TILE+BORDER);
        cairo_rectangle(cr,left,top,TILE,TILE);
        if(grid[a][b]==RIGHT && a<w-1) cairo_rectangle(cr,left+TILE,top,BORDER,TILE);
        if(grid[a][b]==DOWN && b<h-1) cairo_rectangle(cr,left,top+TILE,TILE,BORDER);
        if(grid[a][b]==LEFT && a>0) cairo_rectangle(cr,left-BORDER,top,BORDER,TILE);
        if(grid[a][b]==UP && b>0) cairo_rectangle(cr,left,top-BORDER,TILE,BORDER);
      }
    }
  }
  cairo_fill(cr);
  cairo_surface_flush(surface);
  cairo_surface_write_to_png(surface,"file.png");
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
}

int main(int argc,char** argv){
  int w=35;
  int h=20;
  srand(time(NULL));
  int** grid=(int**)malloc(sizeof(int*)*w);
  for(int a=0;a<w;a++) grid[a]=(int*)calloc(h,sizeof(int));
  for(int a=0;a<w;a++){
    for(int b=0;b<h;b++){
      grid[a][b]=(rand()%4)+1;
    }
  }
  render(grid,w,h);
  return 0;
}
