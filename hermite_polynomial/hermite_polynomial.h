double h_integral ( int n );
double *h_polynomial_coefficients ( int n );
double *h_polynomial_value ( int m, int n, double x[] );
void h_polynomial_values ( int *n_data, int *n, double *x, double *fx );
double *h_polynomial_zeros ( int nt );
void h_quadrature_rule ( int nt, double t[], double wts[] );
double he_double_product_integral ( int i, int j );
double he_integral ( int n );
double *he_polynomial_coefficients ( int n );
double *he_polynomial_value ( int m, int n, double x[] );
void he_polynomial_values ( int *n_data, int *n, double *x, double *fx );
double *he_polynomial_zeros ( int nt );
void he_quadrature_rule ( int nt, double t[], double wts[] );
double he_triple_product_integral ( int i, int j, int k );
double *hen_exponential_product ( int p, double b );
double *hen_polynomial_value ( int m, int n, double x[] );
double *hen_power_product ( int p, int e );
double *hf_exponential_product ( int p, double b );
double *hf_function_value ( int m, int n, double x[] );
void hf_function_values ( int *n_data, int *n, double *x, double *fx );
double *hf_power_product ( int p, int e );
void hf_quadrature_rule ( int nt, double t[], double wts[] );
double *hn_exponential_product ( int p, double b );
double *hn_polynomial_value ( int m, int n, double x[] );
double *hn_power_product ( int p, int e );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
void imtqlx ( int n, double d[], double e[], double z[] );
double r8_epsilon ( );
double r8_factorial ( int n );
double r8_factorial2 ( int n );
double r8_sign ( double x );
void r8mat_print ( int m, int n, double a[], char *title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, char *title );
double r8vec_dot_product ( int n, double a1[], double a2[] );
void r8vec_print ( int n, double a[], char *title );
void r8vec2_print ( int n, double a1[], double a2[], char *title );
void timestamp ( );
