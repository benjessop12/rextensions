#define BASE 1
#define HALF_POINT 0.5

static VALUE rb_bignum_in_fib( VALUE self )
{
  unsigned long n = FIX2LONG(self);
  double root5 = sqrt(5);
  double phi = (BASE + root5) / 2;
  unsigned long flr = floor(log(n * root5) / log(phi) + HALF_POINT);
  unsigned long u = floor(pow(phi, flr) / root5 + HALF_POINT);

  if (u == n) { return Qtrue; }

  return Qfalse;
}
