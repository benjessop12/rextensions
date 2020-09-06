#include "ruby_extensions.h"
#include "array.c"
#include "bignum.c"

void Init_ruby_extensions( void )
{
  /* -- Start of array methods --*/
  rb_define_method(rb_cArray, "consec", rb_find_consec, 0);
  rb_define_method(rb_cArray, "median_p", rb_find_median, 0);
  rb_define_method(rb_cArray, "square", rb_ary_square_m, 0);
  rb_define_method(rb_cArray, "sort_r!", rb_ary_lazy_sort_reverse_m, 0);
  /* -- End of array methods --*/
  /* -- Start of bignum methods --*/
  rb_define_method(rb_cInteger, "fib?", rb_bignum_in_fib, 0);
  /* -- End of bignum methods --*/
}
