#define FALSE 0
#define FLOAT_POINT 2.0

static VALUE rb_find_median( VALUE self )
{
  VALUE result = rb_ary_sort_bang(self);
  const long int count = RARRAY_LEN(result);
  const long int last_index = count - 1;
  const long int mid = last_index / FLOAT_POINT;
  double r;

  switch(count) {
    case 0:
      return Qnil;
      break;
    case 1:
      return rb_ary_entry(self, 0);
      break;
  }

  if (count % 2) {
    VALUE max = rb_ary_entry(result, last_index / 2);
    VALUE med = rb_ary_entry(result, count / 2);
    r = (max + med) / FLOAT_POINT;
  } else {
    r = rb_ary_entry(self, mid);
  }

  return r;
}

static VALUE rb_find_consec( VALUE self )
{
  VALUE rb_ary = rb_ary_new();
  VALUE c_ary = rb_ary_new();

  long int max = RARRAY_LEN(self);
  double c, n;
  int i;
  for ( i = 0; i < max; i++ ) {
    VALUE ca = rb_ary_entry(self, i);
    VALUE na = rb_ary_entry(self, i + 1);

    c = TYPE(ca) == T_FLOAT ? NUM2DBL(ca) : FIX2INT(ca);

    if ( TYPE(na) == T_FLOAT ) {
      n = NUM2DBL(na);
    } else if ( TYPE(na) == T_FIXNUM ) {
      n = FIX2INT(na);
    }

    if ( RARRAY_LEN(c_ary) == 0 ) {
      VALUE c_ary_e = TYPE(ca) == T_FLOAT ? rb_float_new(c) : INT2FIX(c); 
      rb_ary_push(c_ary, c_ary_e);
    }

    if ( c + 1 == n ) {
      VALUE c_ary_e = TYPE(na) == T_FLOAT ? rb_float_new(n) : INT2FIX(n);
      rb_ary_push(c_ary, c_ary_e);
    } else {
      if ( RARRAY_LEN(c_ary) > 1 ) {
        rb_ary_push(rb_ary, c_ary);
        c_ary = rb_ary_new();
      }
    }
  }

  return rb_ary;
}

static VALUE rb_ary_square_m( VALUE self )
{
  long int len = RARRAY_LEN(self);
  VALUE c_ary = rb_ary_new();

  int i, val;
  long v;
  long long y;
  for ( i = 0; i < len; i++ ) {
    VALUE value = rb_ary_entry(self, i);
    int type = TYPE(value);

    switch (type) {
      case T_FIXNUM:
        v = FIX2INT(value);
        value = INT2FIX(v * v);
        break;
      case T_STRING:
        y = rb_str_to_inum(value, 10, FALSE);
        val = FIX2INT(y);
        value = INT2FIX(val * val);
        break;
      case T_TRUE:
      case T_FALSE:
        break;
    }
    rb_ary_push(c_ary, value);
  }

  return c_ary;
}

static VALUE rb_ary_lazy_sort_reverse_m( VALUE self )
{
  VALUE result = rb_ary_sort_bang(self);
  VALUE rev = rb_ary_reverse(result);

  return rev;
}
