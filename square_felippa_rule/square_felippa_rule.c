# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <string.h>
# include <math.h>

# include "square_felippa_rule.h"

/******************************************************************************/

void comp_next ( int n, int k, int a[], int *more, int *h,  int *t )

/******************************************************************************/
/*
  Purpose:

    COMP_NEXT computes the compositions of the integer N into K parts.

  Discussion:

    A composition of the integer N into K parts is an ordered sequence
    of K nonnegative integers which sum to N.  The compositions (1,2,1)
    and (1,1,2) are considered to be distinct.

    The routine computes one composition on each call until there are no more.
    For instance, one composition of 6 into 3 parts is
    3+2+1, another would be 6+0+0.

    On the first call to this routine, set MORE = FALSE.  The routine
    will compute the first element in the sequence of compositions, and
    return it, as well as setting MORE = TRUE.  If more compositions
    are desired, call again, and again.  Each time, the routine will
    return with a new composition.

    However, when the LAST composition in the sequence is computed 
    and returned, the routine will reset MORE to FALSE, signaling that
    the end of the sequence has been reached.

    This routine originally used a STATICE statement to maintain the
    variables H and T.  I have decided (based on an wasting an
    entire morning trying to track down a problem) that it is safer
    to pass these variables as arguments, even though the user should
    never alter them.  This allows this routine to safely shuffle
    between several ongoing calculations.


    There are 28 compositions of 6 into three parts.  This routine will
    produce those compositions in the following order:

     I         A
     -     ---------
     1     6   0   0
     2     5   1   0
     3     4   2   0
     4     3   3   0
     5     2   4   0
     6     1   5   0
     7     0   6   0
     8     5   0   1
     9     4   1   1
    10     3   2   1
    11     2   3   1
    12     1   4   1
    13     0   5   1
    14     4   0   2
    15     3   1   2
    16     2   2   2
    17     1   3   2
    18     0   4   2
    19     3   0   3
    20     2   1   3
    21     1   2   3
    22     0   3   3
    23     2   0   4
    24     1   1   4
    25     0   2   4
    26     1   0   5
    27     0   1   5
    28     0   0   6

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 July 2008

  Author:

    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
    C version by John Burkardt.

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms for Computers and Calculators,
    Second Edition,
    Academic Press, 1978,
    ISBN: 0-12-519260-6,
    LC: QA164.N54.

  Parameters:

    Input, int N, the integer whose compositions are desired.

    Input, int K, the number of parts in the composition.

    Input/output, int A[K], the parts of the composition.

    Input/output, int *MORE.
    Set MORE = FALSE on first call.  It will be reset to TRUE on return
    with a new composition.  Each new call returns another composition until
    MORE is set to FALSE when the last composition has been computed
    and returned.

    Input/output, int *H, *T, two internal parameters needed for the
    computation.  The user should allocate space for these in the calling
    program, include them in the calling sequence, but never alter them!
*/
{
  int i;

  if ( !( *more ) )
  {
    *t = n;
    *h = 0;
    a[0] = n;
    for ( i = 1; i < k; i++ )
    {
       a[i] = 0;
    }
  }
  else
  {
    if ( 1 < *t )
    {
      *h = 0;
    }
    *h = *h + 1;
    *t = a[*h-1];
    a[*h-1] = 0;
    a[0] = *t - 1;
    a[*h] = a[*h] + 1;
  }

  *more = ( a[k-1] != n );

  return;
}
/******************************************************************************/

void line_unit_o01 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O01 returns a 1 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[1], the weights.

    Output, double X[1], the abscissas.
*/
{
  int i;
  int order = 1;
  double w_save[1] = { 2.0 };
  double x_save[1] = { 0.0 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o02 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O02 returns a 2 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[2], the weights.

    Output, double X[2], the abscissas.
*/
{
  int i;
  int order = 2;
  double w_save[2] = {
    1.0000000000000000000,
    1.0000000000000000000 };
  double x_save[2] = {
    -0.57735026918962576451,
     0.57735026918962576451 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o03 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O03 returns a 3 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[3], the weights.

    Output, double X[3], the abscissas.
*/
{
  int i;
  int order = 3;
  double w_save[3] = {
    0.55555555555555555556,
    0.88888888888888888889,
    0.55555555555555555556 };
  double x_save[3] = {
    -0.77459666924148337704,
     0.00000000000000000000,
     0.77459666924148337704 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o04 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O04 returns a 4 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[4], the weights.

    Output, double X[4], the abscissas.
*/
{
  int i;
  int order = 4;
  double w_save[4] = {
    0.34785484513745385737,
    0.65214515486254614263,
    0.65214515486254614263,
    0.34785484513745385737 };
  double x_save[4] = {
    -0.86113631159405257522,
    -0.33998104358485626480,
     0.33998104358485626480,
     0.86113631159405257522 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

void line_unit_o05 ( double w[], double x[] )

/******************************************************************************/
/*
  Purpose:

    LINE_UNIT_O05 returns a 5 point quadrature rule for the unit line.

  Discussion:

    The integration region is:

    - 1.0 <= X <= 1.0

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 April 2009

  Author:

    John Burkardt

  Reference:

    Arthur Stroud,
    Approximate Calculation of Multiple Integrals,
    Prentice Hall, 1971,
    ISBN: 0130438936,
    LC: QA311.S85.

  Parameters:

    Output, double W[5], the weights.

    Output, double X[5], the abscissas.
*/
{
  int i;
  int order = 5;
  double w_save[5] = {
    0.23692688505618908751,
    0.47862867049936646804,
    0.56888888888888888889,
    0.47862867049936646804,
    0.23692688505618908751 };
  double x_save[5] = {
    -0.90617984593866399280,
    -0.53846931010568309104,
     0.00000000000000000000,
     0.53846931010568309104,
     0.90617984593866399280 };

  r8vec_copy ( order, w_save, w );
  r8vec_copy ( order, x_save, x );

  return;
}
/******************************************************************************/

double *monomial_value ( int m, int n, int e[], double x[] )

/******************************************************************************/
/*
  Purpose:

    MONOMIAL_VALUE evaluates a monomial.

  Discussion:

    This routine evaluates a monomial of the form

      product ( 1 <= i <= m ) x(i)^e(i)

    The combination 0.0^0 is encountered is treated as 1.0.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    17 August 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of evaluation points.

    Input, int E[M], the exponents.

    Input, double X[M*N], the point coordinates.

    Output, double MONOMIAL_VALUE[N], the monomial values.
*/
{
  int i;
  int j;
  double *v;

  v = ( double * ) malloc ( n * sizeof ( double ) );

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
  }

  for ( i = 0; i < m; i++ )
  {
    if ( 0 != e[i] )
    {
      for ( j = 0; j < n; j++ )
      {
        v[j] = v[j] * pow ( x[i+j*m], e[i] );
      }
    }
  }

  return v;
}
/******************************************************************************/

double square_monomial ( double a[], double b[], int expon[2] )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MONOMIAL integrates a monomial over a square in 2D.

  Discussion:

    This routine integrates a monomial of the form

      product ( 1 <= dim <= 2 ) x(dim)^expon(dim)

    where the exponents are nonnegative integers.  Note that
    if the combination 0^0 is encountered, it should be treated
    as 1.

    The integration region is:
      A(1) <= X <= B(1)
      A(2) <= Y <= B(2)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, double A[2], B[2], the lower and upper limits.

    Input, int EXPON[2], the exponents.

    Output, double SQUARE_MONOMIAL, the integral of the monomial.
*/
{
  int i;
  double value;

  for ( i = 0; i < 2; i++ )
  {
    if ( expon[i] == -1 )
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "SQUARE_MONOMIAL - Fatal error!\n" );
      fprintf ( stderr, "  Exponent of -1 encountered.\n" );
      exit ( 1 );
    }
  }

  value = 1.0;

  for ( i = 0; i < 2; i++ )
  {
    value = value 
      * ( pow ( b[i], expon[i] + 1 ) - pow ( a[i], expon[i] + 1 ) ) 
      / ( double ) ( expon[i] + 1 );
  }

  return value;
}
/******************************************************************************/

void square_monomial_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    SQUARE_MONOMIAL_TEST tests SQUARE_MONOMIAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
  double a[2] = { -1.0, -1.0 };
  int alpha;
  double b[2] = { +1.0, +1.0 };
  int beta;
  int expon[2];
  double value;

  printf ( "\n" );
  printf ( "SQUARE_MONOMIAL_TEST\n" );
  printf ( "  For a square in 2D,\n" );
  printf ( "  SQUARE_MONOMIAL returns the exact value of the\n" );
  printf ( "  integral of X^ALPHA Y^BETA\n" );
  printf ( "\n" );
  printf ( "  Volume = %g\n", square_volume ( a, b ) );
  printf ( "\n" );
  printf ( "     ALPHA      BETA      INTEGRAL\n" );
  printf ( "\n" );

  for ( alpha = 0; alpha <= degree_max; alpha++ )
  {
    expon[0] = alpha;
    for ( beta = 0; beta <= degree_max - alpha; beta++ )
    {
      expon[1] = beta;

      value = square_monomial ( a, b, expon );

      printf ( "  %8d  %8d  %14.6g\n",
        expon[0], expon[1], value );
    }
  }

  return;
}
/******************************************************************************/

void square_quad_test ( int degree_max )

/******************************************************************************/
/*
  Purpose:

    SQUARE_QUAD_TEST tests the rules for a square in 2D.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, int DEGREE_MAX, the maximum total degree of the
    monomials to check.
*/
{
  double a[2] = { -1.0, -1.0 };
  double b[2] = { +1.0, +1.0 };
  int dim;
  int expon[2];
  int h;
  int k;
  int more;
  int order;
  int order_1d[2];
  double quad;
  int t;
  double *v;
  double *w;
  double *xy;

  printf ( "\n" );
  printf ( "SQUARE_QUAD_TEST\n" );
  printf ( "  For a square in 2D,\n" );
  printf ( "  we approximate monomial integrals with:\n" );
  printf ( "  SQUARE_RULE, which returns M by N point rules..\n" );

  more = 0;

  for ( ; ; )
  {
    subcomp_next ( degree_max, 2, expon, &more, &h, &t );

    printf ( "\n" );
    printf ( "  Monomial exponents: " );
    for ( dim = 0; dim < 2; dim++ )
    {
      printf ( "  %2d", expon[dim] );
    }
    printf ( "\n" );
    printf ( "\n" );

    for ( k = 1; k <= 5; k++ )
    {
      for ( dim = 0; dim < 2; dim++ )
      {
        order_1d[dim] = k;
      }
      order = order_1d[0] * order_1d[1];
      w = ( double * ) malloc ( order * sizeof ( double ) );
      xy = ( double * ) malloc ( 2 * order * sizeof ( double ) );
      square_rule ( a, b, order_1d, w, xy );
      v = monomial_value ( 2, order, expon, xy );
      quad = r8vec_dot_product ( order, w, v );
      printf ( "  %6d  %6d  %14.6g\n", order_1d[0], order_1d[1], quad );
      free ( v );
      free ( w );
      free ( xy );
    }
/*
  Try a rule of mixed orders.
*/
    order_1d[0] = 3;
    order_1d[1] = 5;
    order = order_1d[0] * order_1d[1];
    w = ( double * ) malloc ( order * sizeof ( double ) );
    xy = ( double * ) malloc ( 2 * order * sizeof ( double ) );
    square_rule ( a, b, order_1d, w, xy );
    v = monomial_value ( 2, order, expon, xy );
    quad = r8vec_dot_product ( order, w, v );
    printf ( "  %6d  %6d  %14.6g\n", order_1d[0], order_1d[1], quad );
    free ( v );
    free ( w );
    free ( xy );

    printf ( "\n" );
    quad = square_monomial ( a, b, expon );
    printf ( "   Exact          %14.6g\n", quad );

    if ( !more )
    {
      break;
    }
  }

  return;
}
/******************************************************************************/

void square_rule ( double a[], double b[], int order_1d[], double w[], 
  double xy[] )

/******************************************************************************/
/*
  Purpose:

    SQUARE_RULE returns a quadrature rule for a square in 2D.

  Discussion:

    The integration region is:
      A(1) <= X <= B(1)
      A(2) <= Y <= B(2)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2014

  Author:

    John Burkardt

  Reference:

    Carlos Felippa,
    A compendium of FEM integration formulas for symbolic work,
    Engineering Computation,
    Volume 21, Number 8, 2004, pages 867-890.

  Parameters:

    Input, double A[2], B[2], the lower and upper limits.

    Input, int ORDER_1D[2], the order of the rule in
    each dimension.  1 <= ORDER_1D(I) <= 5.

    Output, double W[ORDER_1D[0]*ORDER_1D[1]], the weights.

    Output, double XY[2*ORDER_1D[0]*ORDER_1D[1]], the abscissas.
*/
{
  int i;
  int j;
  int o;
  int order;
  double *w_1d;
  double *x_1d;

  order = order_1d[0] * order_1d[1];

  for ( i = 0; i < 2; i++ )
  {
    o = order_1d[i];

    w_1d = ( double * ) malloc ( o * sizeof ( double ) );
    x_1d = ( double * ) malloc ( o * sizeof ( double ) );

    if ( o == 1 )
    {
      line_unit_o01 ( w_1d, x_1d );
    }
    else if ( o == 2 )
    {
      line_unit_o02 ( w_1d, x_1d );
    }
    else if ( o == 3 )
    {
      line_unit_o03 ( w_1d, x_1d );
    }
    else if ( o == 4 )
    {
      line_unit_o04 ( w_1d, x_1d );
    }
    else if ( o == 5 )
    {
      line_unit_o05 ( w_1d, x_1d );
    }
    else
    {
      fprintf ( stderr, "\n" );
      fprintf ( stderr, "SQUARE_RULE - Fatal error!\n" );
      fprintf ( stderr, "  Illegal value of ORDER_1D[*].\n" );
      exit ( 1 );
    }
/*
   Transform from [-1,+1] to [Ai,Bi]
*/
    for ( j = 0; j < o; j++ )
    {
      w_1d[j] = w_1d[j] * ( b[i] - a[i] ) / 2.0;
      x_1d[j] = ( ( 1.0 - x_1d[j] ) * a[i]   
                + ( 1.0 + x_1d[j] ) * b[i] ) 
                /   2.0;
    }
/*
  Add this information to the rule.
*/
    r8vec_direct_product ( i, o, x_1d, 2, order, xy );

    r8vec_direct_product2 ( i, o, w_1d, 2, order, w );

    free ( w_1d );
    free ( x_1d );
  }

  return;
}
/******************************************************************************/

double square_volume ( double a[], double b[] )

/******************************************************************************/
/*
  Purpose:

    SQUARE_VOLUME: volume of a unit quadrilateral.

  Discussion:

    The integration region is:
      A(1) <= X <= B(1)
      A(2) <= Y <= B(2)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 September 2014

  Author:

    John Burkardt

  Parameters:

    Input, double A[2], B[2], the lower and upper limits.

    Output, double SQUARE_VOLUME, the volume.
*/
{
  double value;

  value = ( b[0] - a[0] ) * ( b[1] - a[1] );

  return value;
}
/******************************************************************************/

void r8vec_copy ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_COPY copies an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 July 2005

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], the vector to be copied.

    Input, double A2[N], the copy of A1.
*/
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return;
}
/******************************************************************************/

void r8vec_direct_product ( int factor_index, int factor_order,
  double factor_value[], int factor_num, int point_num, double x[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_DIRECT_PRODUCT creates a direct product of R8VEC's.

  Discussion:

    An R8VEC is a vector of R8's.

    To explain what is going on here, suppose we had to construct
    a multidimensional quadrature rule as the product of K rules
    for 1D quadrature.

    The product rule will be represented as a list of points and weights.

    The J-th item in the product rule will be associated with
      item J1 of 1D rule 1,
      item J2 of 1D rule 2,
      ...,
      item JK of 1D rule K.

    In particular,
      X(J) = ( X(1,J1), X(2,J2), ..., X(K,JK))
    and
      W(J) = W(1,J1) * W(2,J2) * ... * W(K,JK)

    So we can construct the quadrature rule if we can properly
    distribute the information in the 1D quadrature rules.

    This routine carries out that task.

    Another way to do this would be to compute, one by one, the
    set of all possible indices (J1,J2,...,JK), and then index
    the appropriate information.  An advantage of the method shown
    here is that you can process the K-th set of information and
    then discard it.

  Example:

    Rule 1:
      Order = 4
      X(1:4) = ( 1, 2, 3, 4 )

    Rule 2:
      Order = 3
      X(1:3) = ( 10, 20, 30 )

    Rule 3:
      Order = 2
      X(1:2) = ( 100, 200 )

    Product Rule:
      Order = 24
      X(1:24) =
        ( 1, 10, 100 )
        ( 2, 10, 100 )
        ( 3, 10, 100 )
        ( 4, 10, 100 )
        ( 1, 20, 100 )
        ( 2, 20, 100 )
        ( 3, 20, 100 )
        ( 4, 20, 100 )
        ( 1, 30, 100 )
        ( 2, 30, 100 )
        ( 3, 30, 100 )
        ( 4, 30, 100 )
        ( 1, 10, 200 )
        ( 2, 10, 200 )
        ( 3, 10, 200 )
        ( 4, 10, 200 )
        ( 1, 20, 200 )
        ( 2, 20, 200 )
        ( 3, 20, 200 )
        ( 4, 20, 200 )
        ( 1, 30, 200 )
        ( 2, 30, 200 )
        ( 3, 30, 200 )
        ( 4, 30, 200 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int FACTOR_INDEX, the index of the factor being processed.
    The first factor processed must be factor 0.

    Input, int FACTOR_ORDER, the order of the factor.

    Input, double FACTOR_VALUE[FACTOR_ORDER], the factor values
    for factor FACTOR_INDEX.

    Input, int FACTOR_NUM, the number of factors.

    Input, int POINT_NUM, the number of elements in the direct product.

    Input/output, double X[FACTOR_NUM*POINT_NUM], the elements of the
    direct product, which are built up gradually.

  Local Parameters:

    Local, int START, the first location of a block of values to set.

    Local, int CONTIG, the number of consecutive values to set.

    Local, int SKIP, the distance from the current value of START
    to the next location of a block of values to set.

    Local, int REP, the number of blocks of values to set.
*/
{
  static int contig = 0;
  int i;
  int j;
  int k;
  static int rep = 0;
  static int skip = 0;
  int start;

  if ( factor_index == 0 )
  {
    contig = 1;
    skip = 1;
    rep = point_num;
    for ( j = 0; j < point_num; j++ )
    {
      for ( i = 0; i < factor_num; i++ )
      {
        x[i+j*factor_num] = 0.0;
      }
    }
  }

  rep = rep / factor_order;
  skip = skip * factor_order;

  for ( i = 0; i < factor_order; i++ )
  {
    start = 0 + i * contig;

    for ( k = 1; k <= rep; k++ )
    {
      for ( j = start; j < start + contig; j++ )
      {
        x[factor_index+j*factor_num] = factor_value[i];
      }
      start = start + skip;
    }
  }
  contig = contig * factor_order;

  return;
}
/******************************************************************************/

void r8vec_direct_product2 ( int factor_index, int factor_order,
  double factor_value[], int factor_num, int point_num, double w[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_DIRECT_PRODUCT2 creates a direct product of R8VEC's.

  Discussion:

    An R8VEC is a vector of R8's.

    To explain what is going on here, suppose we had to construct
    a multidimensional quadrature rule as the product of K rules
    for 1D quadrature.

    The product rule will be represented as a list of points and weights.

    The J-th item in the product rule will be associated with
      item J1 of 1D rule 1,
      item J2 of 1D rule 2,
      ...,
      item JK of 1D rule K.

    In particular,
      X(J) = ( X(1,J1), X(2,J2), ..., X(K,JK))
    and
      W(J) = W(1,J1) * W(2,J2) * ... * W(K,JK)

    So we can construct the quadrature rule if we can properly
    distribute the information in the 1D quadrature rules.

    This routine carries out that task for the weights W.

    Another way to do this would be to compute, one by one, the
    set of all possible indices (J1,J2,...,JK), and then index
    the appropriate information.  An advantage of the method shown
    here is that you can process the K-th set of information and
    then discard it.

  Example:

    Rule 1:
      Order = 4
      W(1:4) = ( 2, 3, 5, 7 )

    Rule 2:
      Order = 3
      W(1:3) = ( 11, 13, 17 )

    Rule 3:
      Order = 2
      W(1:2) = ( 19, 23 )

    Product Rule:
      Order = 24
      W(1:24) =
        ( 2 * 11 * 19 )
        ( 3 * 11 * 19 )
        ( 4 * 11 * 19 )
        ( 7 * 11 * 19 )
        ( 2 * 13 * 19 )
        ( 3 * 13 * 19 )
        ( 5 * 13 * 19 )
        ( 7 * 13 * 19 )
        ( 2 * 17 * 19 )
        ( 3 * 17 * 19 )
        ( 5 * 17 * 19 )
        ( 7 * 17 * 19 )
        ( 2 * 11 * 23 )
        ( 3 * 11 * 23 )
        ( 5 * 11 * 23 )
        ( 7 * 11 * 23 )
        ( 2 * 13 * 23 )
        ( 3 * 13 * 23 )
        ( 5 * 13 * 23 )
        ( 7 * 13 * 23 )
        ( 2 * 17 * 23 )
        ( 3 * 17 * 23 )
        ( 5 * 17 * 23 )
        ( 7 * 17 * 23 )

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    31 May 2009

  Author:

    John Burkardt

  Parameters:

    Input, int FACTOR_INDEX, the index of the factor being processed.
    The first factor processed must be factor 0.

    Input, int FACTOR_ORDER, the order of the factor.

    Input, double FACTOR_VALUE[FACTOR_ORDER], the factor values for
    factor FACTOR_INDEX.

    Input, int FACTOR_NUM, the number of factors.

    Input, int POINT_NUM, the number of elements in the direct product.

    Input/output, double W[POINT_NUM], the elements of the
    direct product, which are built up gradually.

  Local Parameters:

    Local, integer START, the first location of a block of values to set.

    Local, integer CONTIG, the number of consecutive values to set.

    Local, integer SKIP, the distance from the current value of START
    to the next location of a block of values to set.

    Local, integer REP, the number of blocks of values to set.
*/
{
  static int contig = 0;
  int i;
  int j;
  int k;
  static int rep = 0;
  static int skip = 0;
  int start;

  if ( factor_index == 0 )
  {
    contig = 1;
    skip = 1;
    rep = point_num;
    for ( i = 0; i < point_num; i++ )
    {
      w[i] = 1.0;
    }
  }

  rep = rep / factor_order;
  skip = skip * factor_order;

  for ( j = 0; j < factor_order; j++ )
  {
    start = 0 + j * contig;

    for ( k = 1; k <= rep; k++ )
    {
      for ( i = start; i < start + contig; i++ )
      {
        w[i] = w[i] * factor_value[j];
      }
      start = start + skip;
    }
  }

  contig = contig * factor_order;

  return;
}
/******************************************************************************/

double r8vec_dot_product ( int n, double a1[], double a2[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2007

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vectors.

    Input, double A1[N], A2[N], the two vectors to be considered.

    Output, double R8VEC_DOT_PRODUCT, the dot product of the vectors.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
  }
  return value;
}
/******************************************************************************/

void subcomp_next ( int n, int k, int a[], int *more, int *h, int *t )

/******************************************************************************/
/*
  Purpose:

    SUBCOMP_NEXT computes the next subcomposition of N into K parts.

  Discussion:

    A composition of the integer N into K parts is an ordered sequence
    of K nonnegative integers which sum to a value of N.

    A subcomposition of the integer N into K parts is a composition
    of M into K parts, where 0 <= M <= N.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    27 March 2009

  Author:

    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
    C version by John Burkardt.

  Reference:

    Albert Nijenhuis, Herbert Wilf,
    Combinatorial Algorithms for Computers and Calculators,
    Second Edition,
    Academic Press, 1978,
    ISBN: 0-12-519260-6,
    LC: QA164.N54.

  Parameters:

    Input, int N, the integer whose subcompositions are desired.

    Input, int K, the number of parts in the subcomposition.

    Input/output, int A[K], the parts of the subcomposition.

    Input/output, int *MORE, set by the user to start the computation,
    and by the routine to terminate it.

    Input/output, int *H, *T, two internal parameters needed for the
    computation.  The user should allocate space for these in the calling
    program, include them in the calling sequence, but never alter them!
*/
{
  int i;
  static int more2 = 0;
  static int n2 = 0;
/*
  The first computation.
*/
  if ( !( *more ) )
  {
    n2 = 0;

    for ( i = 0; i < k; i++ )
    {
      a[i] = 0;
    }
    more2 = 0;
    *h = 0;
    *t = 0;

    *more = 1;
  }
/*
  Do the next element at the current value of N.
*/
  else if ( more2 )
  {
    comp_next ( n2, k, a, &more2, h, t );
  }
  else
  {
    more2 = 0;
    n2 = n2 + 1;

    comp_next ( n2, k, a, &more2, h, t );
  }
/*
  Termination occurs if MORE2 = FALSE and N2 = N.
*/
  if ( !more2 && n2 == n )
  {
    *more = 0;
  }

  return;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  fprintf ( stdout, "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

