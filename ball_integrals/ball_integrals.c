# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "ball_integrals.h"

/******************************************************************************/

double ball01_monomial_integral ( int e[3] )

/******************************************************************************/
/*
  Purpose:

    BALL01_MONOMIAL_INTEGRAL returns monomial integrals in the unit ball.

  Discussion:

    The integration region is 

      X^2 + Y^2 + Z^2 <= 1.

    The monomial is F(X,Y,Z) = X^E(1) * Y^E(2) * Z^E(3).

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    10 May 2014

  Author:

    John Burkardt

  Reference:

    Philip Davis, Philip Rabinowitz,
    Methods of Numerical Integration,
    Second Edition,
    Academic Press, 1984, page 263.

  Parameters:

    Input, int E[3], the exponents of X, Y and Z in the 
    monomial.  Each exponent must be nonnegative.

    Output, double BALL01_MONOMIAL_INTEGRAL, the integral.
*/
{
  int i;
  double integral;
  const double r = 1.0;
  double s;

  if ( e[0] < 0 || e[1] < 0 || e[2] < 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "BALL01_MONOMIAL_INTEGRAL - Fatal error!\n" );
    fprintf ( stderr, "  All exponents must be nonnegative.\n" );
    fprintf ( stderr, "  E[0] = %d\n", e[0] );
    fprintf ( stderr, "  E[1] = %d\n", e[1] );
    fprintf ( stderr, "  E[2] = %d\n", e[2] );
    exit ( 1 );
  }

  if ( ( e[0] % 2 ) == 1 ||
       ( e[1] % 2 ) == 1 ||
       ( e[2] % 2 ) == 1 )
  {
    integral = 0.0;
  }
  else
  {
    integral = 2.0;

    for ( i = 0; i < 3; i++ )
    {
      integral = integral * r8_gamma ( 0.5 * ( double ) ( e[i] + 1 ) );
    }

    integral = integral 
      / r8_gamma ( 0.5 * ( double ) ( e[0] + e[1] + e[2] + 3 ) );
  }
/*
  The surface integral is now adjusted to give the volume integral.
*/
  s = e[0] + e[1] + e[2] + 3;

  integral = integral * pow ( r, s  ) / ( double ) ( s );

  return integral;
}
/******************************************************************************/

double *ball01_sample ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    BALL01_SAMPLE uniformly samples points from the unit ball.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2014

  Author:

    John Burkardt

  Reference:

    Russell Cheng,
    Random Variate Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998, pages 168.

    Reuven Rubinstein,
    Monte Carlo Optimization, Simulation, and Sensitivity 
    of Queueing Networks,
    Krieger, 1992,
    ISBN: 0894647644,
    LC: QA298.R79.

  Parameters:

    Input, int N, the number of points.

    Input/output, int *SEED, a seed for the random 
    number generator.

    Output, double X[3*N], the points.
*/
{
  const double exponent = 1.0 / 3.0;
  int i;
  int j;
  double norm;
  double r;
  double *x;

  x = r8mat_normal_01_new ( 3, n, seed );

  for ( j = 0; j < n; j++ )
  {
/*
  Compute the length of the vector.
*/
    norm = sqrt ( pow ( x[0+j*3], 2 ) 
                + pow ( x[1+j*3], 2 )
                + pow ( x[2+j*3], 2 ) );
/*
  Normalize the vector.
*/
    for ( i = 0; i < 3; i++ )
    {
      x[i+j*3] = x[i+j*3] / norm;
    }
/*
  Now compute a value to map the point ON the sphere INTO the sphere.
*/
    r = r8_uniform_01 ( seed );

    for ( i = 0; i < 3; i++ )
    {
      x[i+j*3] = pow ( r, exponent ) * x[i+j*3];
    }
  }
  return x;
}
/******************************************************************************/

double ball01_volume ( )

/******************************************************************************/
/*
  Purpose:

    BALL01_VOLUME returns the volume of the unit ball.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    02 January 2014

  Author:

    John Burkardt

  Parameters:

    Output, double BALL01_VOLUME, the volume of the unit ball.
*/
{
  const double r = 1.0;
  const double r8_pi = 3.141592653589793;
  double volume;

  volume = 4.0 * r8_pi * pow ( r, 3 ) / 3.0;

  return volume;
}
/******************************************************************************/

int *i4vec_uniform_ab_new ( int n, int a, int b, int *seed )

/******************************************************************************/
/*
  Purpose:

    I4VEC_UNIFORM_AB_NEW returns a scaled pseudorandom I4VEC.

  Discussion:

    The pseudorandom numbers should be uniformly distributed
    between A and B.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    06 January 2014

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, integer N, the dimension of the vector.

    Input, int A, B, the limits of the interval.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, int I4VEC_UNIFORM_AB_NEW[N], a vector of random values 
    between A and B.
*/
{
  int c;
  int i;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;
  int *x;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "I4VEC_UNIFORM_AB_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }
/*
  Guaranteee A <= B.
*/
  if ( b < a )
  {
    c = a;
    a = b;
    b = c;
  }

  x = ( int * ) malloc ( n * sizeof ( int ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r = ( float ) ( *seed ) * 4.656612875E-10;
/*
  Scale R to lie between A-0.5 and B+0.5.
*/
    r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 
      +         r   * ( ( float ) b + 0.5 );
/*
  Use rounding to convert R to an integer between A and B.
*/
    value = round ( r );
/*
  Guarantee A <= VALUE <= B.
*/
    if ( value < a )
    {
      value = a;
    }
    if ( b < value )
    {
      value = b;
    }

    x[i] = value;
  }

  return x;
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

    where the exponents are nonnegative integers.  Note that
    if the combination 0^0 is encountered, it should be treated
    as 1.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    08 May 2014

  Author:

    John Burkardt

  Parameters:

    Input, int M, the spatial dimension.

    Input, int N, the number of points at which the
    monomial is to be evaluated.

    Input, int E[M], the exponents.

    Input, double X[M*N], the point coordinates.

    Output, double MONOMIAL_VALUE[N], the value of the monomial.
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

double r8_gamma ( double x )

/******************************************************************************/
/*
  Purpose:

    R8_GAMMA evaluates Gamma(X) for a real argument.

  Discussion:

    The C math library includes the GAMMA ( X ) function which should generally
    be used instead of this function.

    This routine calculates the gamma function for a real argument X.

    Computation is based on an algorithm outlined in reference 1.
    The program uses rational functions that approximate the gamma
    function to at least 20 significant decimal digits.  Coefficients
    for the approximation over the interval (1,2) are unpublished.
    Those for the approximation for 12 <= X are from reference 2.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    11 January 2010

  Author:

    Original FORTRAN77 version by William Cody, Laura Stoltz.
    C version by John Burkardt.

  Reference:

    William Cody,
    An Overview of Software Development for Special Functions,
    in Numerical Analysis Dundee, 1975,
    edited by GA Watson,
    Lecture Notes in Mathematics 506,
    Springer, 1976.

    John Hart, Ward Cheney, Charles Lawson, Hans Maehly,
    Charles Mesztenyi, John Rice, Henry Thatcher,
    Christoph Witzgall,
    Computer Approximations,
    Wiley, 1968,
    LC: QA297.C64.

  Parameters:

    Input, double X, the argument of the function.

    Output, double R8_GAMMA, the value of the function.
*/
{
  double c[7] = {
   -1.910444077728E-03, 
    8.4171387781295E-04, 
   -5.952379913043012E-04, 
    7.93650793500350248E-04, 
   -2.777777777777681622553E-03, 
    8.333333333333333331554247E-02, 
    5.7083835261E-03 };
  double eps = 2.22E-16;
  double fact;
  int i;
  int n;
  double p[8] = {
  -1.71618513886549492533811E+00,
   2.47656508055759199108314E+01, 
  -3.79804256470945635097577E+02,
   6.29331155312818442661052E+02, 
   8.66966202790413211295064E+02,
  -3.14512729688483675254357E+04, 
  -3.61444134186911729807069E+04,
   6.64561438202405440627855E+04 };
  int parity;
  const double pi = 3.1415926535897932384626434;
  double q[8] = {
  -3.08402300119738975254353E+01,
   3.15350626979604161529144E+02, 
  -1.01515636749021914166146E+03,
  -3.10777167157231109440444E+03, 
   2.25381184209801510330112E+04,
   4.75584627752788110767815E+03, 
  -1.34659959864969306392456E+05,
  -1.15132259675553483497211E+05 };
  double res;
  const double sqrtpi = 0.9189385332046727417803297;
  double sum;
  double value;
  double xbig = 171.624;
  double xden;
  double xinf = 1.79E+308;
  double xminin = 2.23E-308;
  double xnum;
  double y;
  double y1;
  double ysq;
  double z;

  parity = 0;
  fact = 1.0;
  n = 0;
  y = x;
/*
  Argument is negative.
*/
  if ( y <= 0.0 )
  {
    y = - x;
    y1 = ( double ) ( int ) ( y );
    res = y - y1;

    if ( res != 0.0 )
    {
      if ( y1 != ( double ) ( int ) ( y1 * 0.5 ) * 2.0 )
      {
        parity = 1;
      }

      fact = - pi / sin ( pi * res );
      y = y + 1.0;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
/*
  Argument is positive.
*/
  if ( y < eps )
  {
/*
  Argument < EPS.
*/
    if ( xminin <= y )
    {
      res = 1.0 / y;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
  else if ( y < 12.0 )
  {
    y1 = y;
/*
  0.0 < argument < 1.0.
*/
    if ( y < 1.0 )
    {
      z = y;
      y = y + 1.0;
    }
/*
  1.0 < argument < 12.0.
  Reduce argument if necessary.
*/
    else
    {
      n = ( int ) ( y ) - 1;
      y = y - ( double ) ( n );
      z = y - 1.0;
    }
/*
  Evaluate approximation for 1.0 < argument < 2.0.
*/
    xnum = 0.0;
    xden = 1.0;
    for ( i = 0; i < 8; i++ )
    {
      xnum = ( xnum + p[i] ) * z;
      xden = xden * z + q[i];
    }
    res = xnum / xden + 1.0;
/*
  Adjust result for case  0.0 < argument < 1.0.
*/
    if ( y1 < y )
    {
      res = res / y1;
    }
/*
  Adjust result for case 2.0 < argument < 12.0.
*/
    else if ( y < y1 )
    {
      for ( i = 1; i <= n; i++ )
      {
        res = res * y;
        y = y + 1.0;
      }
    }
  }
  else
  {
/*
  Evaluate for 12.0 <= argument.
*/
    if ( y <= xbig )
    {
      ysq = y * y;
      sum = c[6];
      for ( i = 0; i < 6; i++ )
      {
        sum = sum / ysq + c[i];
      }
      sum = sum / y - y + sqrtpi;
      sum = sum + ( y - 0.5 ) * log ( y );
      res = exp ( sum );
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
/*
  Final adjustments and return.
*/
  if ( parity )
  {
    res = - res;
  }

  if ( fact != 1.0 )
  {
    res = fact / res;
  }

  value = res;

  return value;
}
/******************************************************************************/

double r8_uniform_01 ( int *seed )

/******************************************************************************/
/*
  Purpose:

    R8_UNIFORM_01 returns a pseudorandom R8 scaled to [0,1].

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      r8_uniform_01 = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

    If the initial seed is 12345, then the first three computations are

      Input     Output      R8_UNIFORM_01
      SEED      SEED

         12345   207482415  0.096616
     207482415  1790989824  0.833995
    1790989824  2035175616  0.947702

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    11 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation
    edited by Jerry Banks,
    Wiley Interscience, page 95, 1998.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    P A Lewis, A S Goodman, J M Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has been updated.

    Output, double R8_UNIFORM_01, a new pseudorandom variate, strictly between
    0 and 1.
*/
{
  int i4_huge = 2147483647;
  int k;
  double r;

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }

  r = ( ( double ) ( *seed ) ) * 4.656612875E-10;

  return r;
}
/******************************************************************************/

double *r8mat_normal_01_new ( int m, int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8MAT_NORMAL_01_NEW returns a unit pseudonormal R8MAT.

  Licensing:

    This code is distributed under the GNU LGPL license. 

  Modified:

    03 October 2005

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Springer Verlag, pages 201-202, 1983.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, pages 362-376, 1986.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, pages 136-143, 1969.

  Parameters:

    Input, int M, N, the number of rows and columns in the array.

    Input/output, int *SEED, the "seed" value, which should NOT be 0.
    On output, SEED has been updated.

    Output, double R8MAT_NORMAL_01_NEW[M*N], the array of pseudonormal values.
*/
{
  double *r;

  r = r8vec_normal_01_new ( m * n, seed );

  return r;
}
/******************************************************************************/

double *r8vec_normal_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_NORMAL_01_NEW returns a unit pseudonormal R8VEC.

  Discussion:

    The standard normal probability distribution function (PDF) has
    mean 0 and standard deviation 1.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 August 2013

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of values desired.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_NORMAL_01_NEW[N], a sample of the standard normal PDF.

  Local parameters:

    Local, double R[N+1], is used to store some uniform random values.
    Its dimension is N+1, but really it is only needed to be the
    smallest even number greater than or equal to N.

    Local, int X_LO, X_HI, records the range of entries of
    X that we need to compute.
*/
{
  int i;
  int m;
  const double pi = 3.141592653589793;
  double *r;
  double *x;
  int x_hi;
  int x_lo;

  x = ( double * ) malloc ( n * sizeof ( double ) );
/*
  Record the range of X we need to fill in.
*/
  x_lo = 1;
  x_hi = n;
/*
  If we need just one new value, do that here to avoid null arrays.
*/
  if ( x_hi - x_lo + 1 == 1 )
  {
    r = r8vec_uniform_01_new ( 2, seed );

    x[x_hi-1] = sqrt ( - 2.0 * log ( r[0] ) ) * cos ( 2.0 * pi * r[1] );

    free ( r );
  }
/*
  If we require an even number of values, that's easy.
*/
  else if ( ( x_hi - x_lo + 1 ) % 2 == 0 )
  {
    m = ( x_hi - x_lo + 1 ) / 2;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2*m-2; i = i + 2 )
    {
      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );
      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * pi * r[i+1] );
    }
    free ( r );
  }
/*
  If we require an odd number of values, we generate an even number,
  and handle the last pair specially, storing one in X(N).
*/
  else
  {
    x_hi = x_hi - 1;

    m = ( x_hi - x_lo + 1 ) / 2 + 1;

    r = r8vec_uniform_01_new ( 2*m, seed );

    for ( i = 0; i <= 2*m-4; i = i + 2 )
    {
      x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );
      x[x_lo+i  ] = sqrt ( - 2.0 * log ( r[i] ) ) * sin ( 2.0 * pi * r[i+1] );
    }

    i = 2*m - 2;

    x[x_lo+i-1] = sqrt ( - 2.0 * log ( r[i] ) ) * cos ( 2.0 * pi * r[i+1] );

    free ( r );
  }

  return x;
}
/******************************************************************************/

double r8vec_sum ( int n, double a[] )

/******************************************************************************/
/*
  Purpose:

    R8VEC_SUM returns the sum of an R8VEC.

  Discussion:

    An R8VEC is a vector of R8's.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 August 2008

  Author:

    John Burkardt

  Parameters:

    Input, int N, the number of entries in the vector.

    Input, double A[N], the vector.

    Output, double R8VEC_SUM, the sum of the vector.
*/
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
  }

  return value;
}
/******************************************************************************/

double *r8vec_uniform_01_new ( int n, int *seed )

/******************************************************************************/
/*
  Purpose:

    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2^31 - 1 )
      unif = seed / ( 2^31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    19 August 2004

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int N, the number of entries in the vector.

    Input/output, int *SEED, a seed for the random number generator.

    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "R8VEC_UNIFORM_01_NEW - Fatal error!\n" );
    fprintf ( stderr, "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  r = ( double * ) malloc ( n * sizeof ( double ) );

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
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

