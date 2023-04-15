#include <stdio.h>
#include <setjmp.h>

#define A(e, s) for (e = 0; e < (sizeof(s) / sizeof(*s)); ++e)
#define D(e) jmp_buf e
#define E(e, s) if (!setjmp(e)) s

typedef void (*F)(void);

static jmp_buf g;
static F h[9], *i = h;

void _() { longjmp(g, 1); }
void __(D(y)) { E(y, (*i)()); *i++ = &_; longjmp(g, 1); }

void A1() { fputs("A", stdout); }
void A2() { fputs("2", stdout); }
void B1() { fputs("B", stdout); }
void B2() { fputs("3", stdout); }
void C1() { fputs("C", stdout); }
void C2() { fputs("4", stdout); }
void D1() { fputs("D", stdout); }
void D2() { fputs("5", stdout); }

int main(int c, char **v) {
  D(y);
  F w[] = {A1, A2, B1, B2, C1, C2, D1, D2};
  size_t e;
  i[8] = &_;
  A(e, w) {
    E(y, (*i) = w[e]);
    E(y, __(y));
  }
  return 0;
}