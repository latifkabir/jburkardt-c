# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "asa053.h"

int main ( );
void test01 ( );
void test02 ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for ASA053_PRB.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2014

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ASA053_PRB:\n" );
  printf ( "  C version\n" );
  printf ( "  Test the ASA053 library.\n" );

  test01 ( );
  test02 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ASA053_PRB:\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( )

/******************************************************************************/
/*
  Purpose:

    TEST01 generates a random Wishart variate.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2014

  Author:

    John Burkardt
*/
{
# define NP 3

  double d[(NP*(NP+1))/2] = {
    3.0, 
    2.0, 4.0, 
    1.0, 2.0, 5.0 };
  int i;
  int n;
  int np = NP;
  double *sa;
  int seed;

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Generate a single Wishart deviate.\n" );

  n = 1;
  seed = 123456789;

  printf ( "\n" );
  printf ( "  The number of variables is %d\n", np );
  printf ( "  The number of degrees of freedom is %d\n", n );

  r8utp_print ( np, d, "  The upper Cholesky factor:" );

  sa = wshrt ( d, n, np, &seed );

  r8pp_print ( np, sa, "  The sample matrix:" );

  free ( sa );

  return;
# undef NP
}
/******************************************************************************/

void test02 ( )

/******************************************************************************/
/*
  Purpose:

    TEST02 averages many Wishart samples.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    16 April 2014

  Author:

    John Burkardt
*/
{
# define NP 3

  double d[(NP*(NP+1))/2] = {
    3.0, 
    2.0, 4.0, 
    1.0, 2.0, 5.0 };
  int i;
  int j;
  int k;
  int ki;
  int kj;
  int n;
  int np = NP;
  int npp;
  double *sa;
  double *s_average;
  double *sigma;
  int seed;
  int test_num = 100000;

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  Generate many Wishart deviates.\n" );
  printf ( "  Compare to D' * D * np / n\n" );
  n = 2;
  npp = ( np * ( np + 1 ) ) / 2;
  seed = 123456789;

  printf ( "\n" );
  printf ( "  The number of variables is %d\n", np );
  printf ( "  The number of degrees of freedom is %d\n", n );

  r8utp_print ( np, d, "  The upper Cholesky factor:" );

  s_average = ( double * ) malloc ( npp * sizeof ( double ) );

  for ( j = 0; j < npp; j++ )
  {
    s_average[j] = 0.0;
  }

  for ( i = 1; i <= test_num; i++ )
  {
    sa = wshrt ( d, n, np, &seed );
    for ( j = 0; j < npp; j++ )
    {
      s_average[j] = s_average[j] + sa[j];
    }
    free ( sa );
  }

  for ( j = 0; j < npp; j++ )
  {
    s_average[j] = s_average[j] / ( double ) ( test_num );
  }

  r8pp_print ( np, s_average, "  The averaged matrix:" );
/*
  Compare the result to ( D' * D ) * np / n.
*/
  sigma = ( double * ) malloc ( np * np * sizeof ( double ) );

  for ( i = 0; i < np; i++ )
  {
    for ( j = 0; j < np; j++ )
    {
      for ( k = 0; k <= i4_min ( i, j ); k++ )
      {
        ki = k + ( i * ( i + 1 ) ) / 2;
        kj = k + ( j * ( j + 1 ) ) / 2;
        sigma[i+j*np] = sigma[i+j*np] + d[ki] * d[kj];
      }
      sigma[i+j*np] = sigma[i+j*np] * ( double ) np / ( double ) n;
    }
  }

  r8mat_print ( np, np, sigma, "  Expected result:" );

  free ( s_average );
  free ( sigma );

  return;
# undef NP
}
