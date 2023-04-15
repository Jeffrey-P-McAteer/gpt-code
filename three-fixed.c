#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define A(e,s) for(e=0;e<(sizeof(s)/sizeof(*s));++e)
#define B(s) #s
#define C(s) B(s)
#define D(e) jmp_buf e
#define E(e,s) if(setjmp(e))s

typedef void (*F)(void);

static jmp_buf g;
static F h[9],*i=h;

void _() { longjmp(g,1); }
void __(D(y)) { E(y,(*i)()); *i++=&_; longjmp(g,1); }
void ___(D(y)) { *i=&_; longjmp(y,1); }

void A1() { fputs("A", stdout); __(g); fputs("1", stdout); }
void A2() { fputs("B", stdout); __(g); fputs("2", stdout); }
void B1() { fputs("C", stdout); __(g); fputs("3", stdout); }
void B2() { fputs("D", stdout); __(g); fputs("4", stdout); }
void C1() { fputs("E", stdout); __(g); fputs("5", stdout); }
void C2() { fputs("F", stdout); __(g); fputs("6", stdout); }
void D1() { fputs("G", stdout); __(g); fputs("7", stdout); }
void D2() { fputs("H", stdout); __(g); fputs("8", stdout); }

int main(int c, char **v) {
  D(y); F w[] = {A1, A2, B1, B2, C1, C2, D1, D2};
  size_t e; A(e,w) { E(y,(*i++)=w[e]); E(y,___(y)); }
  E(y,__(y)); E(y,___(y)); return 0;
}