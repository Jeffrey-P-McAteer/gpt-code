#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define F(e,s) for(e=0;e<(sizeof(s)/sizeof(*s));++e)
#define S(s) #s
#define X(s) S(s)
#define J(e) jmp_buf e
#define T(e,s) if(setjmp(e))s

typedef void (*Y)(void);

static jmp_buf z;
static Y a[9],*b=a;

void _() { longjmp(z,1); }
void __(J(y)) { T(y,(*b)()); *b++=&_; longjmp(z,1); }
void ___(J(y)) { *b=&_; longjmp(y,1); }

void A() { fputs("A", stdout); } void B() { fputs("B", stdout); }
void C() { fputs("C", stdout); } void D() { fputs("D", stdout); }
void E() { fputs("E", stdout); } void F() { fputs("F", stdout); }
void G() { fputs("G", stdout); } void H() { fputs("H", stdout); }

int main(int c, char **v) {
  J(y); Y w[] = {A, B, C, D, E, F, G, H};
  size_t e; F(e,w) { T(y,(*b++)=w[e]); T(y,___(y)); }
  T(y,__(y)); T(y,___(y)); return 0;
}