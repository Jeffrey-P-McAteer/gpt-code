#include <stdio.h>

#define A (a[y][x]&1)
#define B (a[y][x]&2)
#define C (a[y][x]&4)
#define D (a[y][x]&8)
#define E (a[y][x]&16)
#define F (a[y][x]&32)
#define G(x) ((x)<<1)
#define H(x) ((x)>>1)

typedef unsigned char u;
u a[][7] = {
  {34, 0, 0, 0, 0, 0, 36},
  {17, 4, 4, 4, 2, 1, 20},
  {16, 9, 0, 0, 8, 4, 20},
  {16, 6, 1, 20, 32, 4, 4},
  {16, 8, 8, 6, 33, 0, 0},
  {16, 0, 0, 8, 6, 1, 21}
};

void S(u y, u x) {
  if (F) return;
  a[y][x] |= 32;
  if (y > 0 && !A) S(y - 1, x);
  if (x > 0 && !B) S(y, x - 1);
  if (y < 5 && !C) S(y + 1, x);
  if (x < 6 && !D) S(y, x + 1);
  if (E) printf("(%u, %u)\n", y, x);
  a[y][x] &= ~32;
}

int main() {
  S(0, 1);
  return 0;
}