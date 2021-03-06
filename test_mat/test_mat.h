double *aegerter ( int n );
double aegerter_condition ( int n );
double aegerter_determinant ( int n );
double *aegerter_eigenvalues ( int n );
double *aegerter_inverse ( int n );
double *anticirculant ( int m, int n, double x[] );
double anticirculant_determinant ( int n, double x[] );
double *antihadamard ( int n );
double antihadamard_determinant ( int n );
double *antisymm_random ( int n, int *seed );
double *archimedes ( void );
double *archimedes_null ( void );
double *bab ( int n, double alpha, double beta );
double bab_condition ( int n, double alpha, double beta );
double bab_determinant ( int n, double alpha, double beta );
double *bab_eigenvalues ( int n, double alpha, double beta );
double *bab_inverse ( int n, double alpha, double beta );
double *bernstein ( int n );
double *bernstein_inverse ( int n );
double *bimarkov_random ( int n, int *seed );
double *bis ( double alpha, double beta, int m, int n );
double bis_determinant ( double alpha, double beta, int n );
double *bis_eigenvalues ( double alpha, double beta, int n );
double *bis_inverse ( double alpha, double beta, int n );
double *bodewig ( void );
double bodewig_condition ( void );
double bodewig_determinant ( void );
double *bodewig_eigenvalues ( void );
double *bodewig_inverse ( void );
void bodewig_plu ( double p[], double l[], double u[] );;
double *bodewig_rhs ( void );
double *bodewig_right ( void );
double *bodewig_solution ( void );
double *boothroyd ( int n );
double boothroyd_determinant ( int n );
double *boothroyd_inverse ( int n );
double *borderband ( int n );
double borderband_determinant ( int n );
double *borderband_inverse ( int n );
void borderband_plu ( int n, double p[], double l[], double u[] );
double complex c8_zero ( );
double complex *c8mat_copy_new ( int m, int n, double complex a1[] );
double complex *c8mat_identity ( int n );
double complex *c8mat_mm_new ( int n1, int n2, int n3, double complex a[], 
  double complex b[] );
double c8mat_norm_fro ( int m, int n, double complex a[] );
void c8mat_print ( int m, int n, double complex a[], char *title );
void c8mat_print_some ( int m, int n, double complex a[], int ilo, int jlo, 
  int ihi, int jhi, char *title );
double complex *c8mat_uniform_01 ( int m, int n, int *seed );
double complex *c8mat_zero_new ( int m, int n );
double complex *c8vec_copy_new ( int n, double complex a1[] );
double complex *c8vec_unity ( int n );
double *carry ( int alpha, int n );
double carry_determinant ( int alpha, int n );
double *carry_eigenvalues ( int alpha, int n );
double *carry_inverse ( int alpha, int n );
double *carry_left ( int n );
double *carry_right ( int n );
double *cauchy ( int n, double x[], double y[] );
double cauchy_determinant ( int n, double x[], double y[] );
double *cauchy_inverse ( int n, double x[], double y[] );
double *cheby_diff1 ( int n );
double *cheby_diff1_null ( int n );
double *cheby_t ( int n );
double cheby_t_determinant ( int n );
double *cheby_t_inverse ( int n );
double *cheby_u ( int n );
double cheby_u_determinant ( int n );
double *cheby_u_inverse ( int n );
double *cheby_u_polynomial ( int n, double x );
double *cheby_van1 ( int n, double x[] );
double *cheby_van2 ( int n );
double cheby_van2_determinant ( int n );
double *cheby_van2_inverse ( int n );
double *cheby_van3 ( int n );
double cheby_van3_determinant ( int n );
double *cheby_van3_inverse ( int n );
double *chow ( double alpha, double beta, int m, int n );
double chow_determinant ( double alpha, double beta, int n );
double *chow_eigenvalues ( double alpha, double beta, int n );
double *chow_inverse ( double alpha, double beta, int n );
double *chow_left ( double alpha, double beta, int n );
double *chow_right ( double alpha, double beta, int n );
double *circulant ( int m, int n, double x[] );
double circulant_determinant ( int n, double x[] );
double complex *circulant_eigenvalues ( int n, double x[] );
double *circulant_inverse ( int n, double x[] );
double *circulant2 ( int n );
double circulant2_determinant ( int n );
double complex *circulant2_eigenvalues ( int n );
double *circulant2_inverse ( int n );
double *clement1 ( int n );
double clement1_determinant ( int n );
double *clement1_eigenvalues ( int n );
double *clement1_inverse ( int n );
double *clement2 ( int n );
double clement2_determinant ( int n );
double *clement2_eigenvalues ( int n );
double *clement2_inverse ( int n );
double *clement3 ( int n, double x[], double y[] );
double clement3_determinant ( int n, double x[], double y[] );
double *clement3_inverse ( int n, double x[], double y[] );
double *combin ( double alpha, double beta, int n );
double combin_condition ( double alpha, double beta, int n );
double combin_determinant ( double alpha, double beta, int n );
double *combin_eigenvalues ( double alpha, double beta, int n );
double *combin_inverse ( double alpha, double beta, int n );
double *combin_right ( double alpha, double beta, int n );
double *companion ( int n, double x[] );
double companion_determinant ( int n, double x[] );
double *companion_inverse ( int n, double x[] );
double complex *complex3 ( void );
double complex *complex3_inverse ( void );
double *complex_i ( void );
double complex_i_determinant ( void );
double *complex_i_inverse ( void );
double *conex1 ( double alpha );
double conex1_determinant ( double alpha );
double *conex1_inverse ( double alpha );
double *conex2 ( double alpha );
double conex2_determinant ( double alpha );
double *conex2_inverse ( double alpha );
double *conex3 ( int n );
double conex3_condition ( int n );
double conex3_determinant ( int n );
double *conex3_inverse ( int n );
double *conex4 ( void );
double *conex4_inverse ( void );
double *conference ( int n );
double conference_determinant ( int n );
double *conference_inverse ( int n );
double *creation ( int m, int n );
double creation_determinant ( int n );
double *creation_null ( int n );
double *cycol_random ( int m, int n, int k, int *seed );
double *daub2 ( int n );
double daub2_determinant ( int n );
double *daub2_inverse ( int n );
double *daub4 ( int n );
double daub4_determinant ( int n );
double *daub4_inverse ( int n );
double *daub6 ( int n );
double daub6_determinant ( int n );
double *daub6_inverse ( int n );
double *daub8 ( int n );
double daub8_determinant ( int n );
double *daub8_inverse ( int n );
double *daub10 ( int n );
double daub10_determinant ( int n );
double *daub10_inverse ( int n );
double *daub12 ( int n );
double daub12_determinant ( int n );
double *daub12_inverse ( int n );
double *diagonal ( int m, int n, double x[] );
double diagonal_determinant ( int n, double x[] );
double *diagonal_eigenvalues ( int n, double x[] );
double *diagonal_inverse ( int n, double x[] );
double *dif1 ( int m, int n );
double dif1_determinant ( int n );
double complex *dif1_eigenvalues ( int n );
double *dif1_null ( int n );
double *dif1cyclic ( int n );
double dif1cyclic_determinant ( int n );
double *dif1cyclic_null ( int n );
double *dif2 ( int m, int n );
double *dif2_cholesky ( int n );
double dif2_determinant ( int n );
double *dif2_eigenvalues ( int n );
double *dif2_inverse ( int n );
void dif2_plu ( int n, double p[], double l[], double u[] );
double *dif2_rhs ( int m, int k );
double *dif2_right ( int n );
double *dif2_solution ( int n, int k );
double *dif2cyclic ( int n );
double dif2cyclic_determinant ( int n );
double *dif2cyclic_null ( int n );
double *dorr ( double alpha, int n );
double *downshift ( int n );
double downshift_determinant ( int n );
double complex *downshift_eigenvalues ( int n );
double *downshift_inverse ( int n );
double *eberlein ( double alpha, int n );
double eberlein_determinant ( double alpha, int n );
double *eberlein_eigenvalues ( double alpha, int n );
double *eberlein_null_left ( int n );
double *eulerian ( int m, int n );
double eulerian_determinant ( int n );
double *eulerian_inverse ( int n );
double *exchange ( int m, int n );
double exchange_determinant ( int n );
double *exchange_eigenvalues ( int n );
double *exchange_inverse ( int n );
double *exchange_right ( int n );
double *fibonacci1 ( int n, double f1, double f2 );
double fibonacci1_determinant ( int n, double f1, double f2 );
double *fibonacci1_null ( int n, double f1, double f2 );
double *fibonacci2 ( int n );
double fibonacci2_determinant ( int n );
double *fibonacci2_eigenvalues ( int n );
double *fibonacci2_inverse ( int n );
double *fibonacci3 ( int n );
double fibonacci3_determinant ( int n );
double complex *fibonacci3_eigenvalues ( int n );
double *fibonacci3_inverse ( int n );
double *fiedler ( int m, int n, double x[] );
double fiedler_determinant ( int n, double x[] );
double *fiedler_inverse ( int n, double x[] );
double *forsythe ( double alpha, double beta, int n );
double forsythe_determinant ( double alpha, double beta, int n );
double complex *forsythe_eigenvalues ( double alpha, double beta, int n );
double *forsythe_inverse ( double alpha, double beta, int n );
double complex *fourier ( int n );
double complex fourier_determinant ( int n );
double complex *fourier_eigenvalues ( int n );
double complex *fourier_inverse ( int n );
double *fourier_cosine ( int n );
double fourier_cosine_determinant ( int n );
double *fourier_cosine_inverse ( int n );
double *fourier_sine ( int n );
double fourier_sine_determinant ( int n );
double *fourier_sine_inverse ( int n );
double *frank ( int n );
double frank_determinant ( int n );
double *frank_inverse ( int n );
double *frank_rhs ( int m, int k );
double *frank_solution ( int n, int k );
double *gear ( int ii, int jj, int n );
double gear_determinant ( int ii, int jj, int n );
double *gear_eigenvalues ( int ii, int jj, int n );
double *gfpp ( int n, double alpha );
double gfpp_determinant ( int n, double alpha );
double *gfpp_inverse ( int n, double alpha );
void gfpp_plu ( int n, double alpha, double p[], double l[], double u[] );
double *givens ( int m, int n );
double givens_determinant ( int n );
double *givens_eigenvalues ( int n );
double *givens_inverse ( int n );
void givens_plu ( int n, double p[], double l[], double u[] );
double *gk316 ( int n );
double gk316_determinant ( int n );
double *gk316_eigenvalues ( int n );
double *gk316_inverse ( int n );
double *gk323 ( int m, int n );
double gk323_determinant ( int n );
double *gk323_inverse ( int n );
double *gk324 ( int m, int n, double x[] );
double gk324_determinant ( int n, double x[] );
double *gk324_inverse ( int n, double x[] );
double *grcar ( int m, int n, int k );
double *hadamard ( int m, int n );
double *hamming ( int m, int n );
double *hankel ( int n, double x[] );
double *hanowa ( double alpha, int n );
double hanowa_determinant ( double alpha, int n );
double complex *hanowa_eigenvalues ( double alpha, int n );
double *hanowa_inverse ( double alpha, int n );
double *harman ( void );
double harman_determinant ( void );
double *harman_eigenvalues ( void );
double *harman_inverse ( void );
double *hartley ( int n );
double hartley_determinant ( int n );
double *hartley_inverse ( int n );
double *helmert ( int n );
double helmert_determinant ( int n );
double *helmert_inverse ( int n );
double *helmert2 ( int n, double x[] );
double *helmert2_inverse ( int n, double x[] );
double *hermite ( int n );
double hermite_determinant ( int n );
double *hermite_inverse ( int n );
double *hermite_roots ( int order );
double *herndon ( int n );
double herndon_determinant ( int n );
double *herndon_eigenvalues ( int n );
double *herndon_inverse ( int n );
double *hilbert ( int m, int n );
double hilbert_determinant ( int n );
double *hilbert_inverse ( int n );
double *hoffman ( double omega );
double *hoffman_rhs ( void );
double *hoffman_optimum ( void );
double *householder ( int n, double x[] );
double householder_determinant ( int n, double x[] );
double *householder_eigenvalues ( int n, double x[] );
double *householder_inverse ( int n, double x[] );
int i4_even ( int i );
void i4_factor ( int n, int maxfactor, int *nfactor, int factor[], 
  int exponent[], int *nleft );
int i4_huge ( void );
int i4_is_prime ( int n );
int i4_log_10 ( int i );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
int i4_odd ( int i );
int i4_pochhammer ( int i, int j );
int i4_power ( int i, int j );
int i4_sign ( int i );
int i4_uniform ( int a, int b, int *seed );
int i4_wrap ( int ival, int ilo, int ihi );
void i4mat_print ( int m, int n, int a[], char *title );
void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi, 
  int jhi, char *title );
int i4vec_index ( int n, int a[], int aval );
int *i4vec_indicator_new ( int n );
void i4vec_print ( int n, int a[], char *title );
double *idem_random ( int n, int rank, int *seed );
double idem_random_determinant ( int n, int rank );
double *idem_random_eigenvalues ( int n, int rank );
double *idem_random_right ( int n, int rank, int *seed );
double *identity ( int m, int n );
double identity_determinant ( int n );
double *identity_eigenvalues ( int n );
double *identity_inverse ( int n );
double *identity_left ( int n );
double *identity_right ( int n );
double *ijfact1 ( int n );
double ijfact1_determinant ( int n );
double *ijfact2 ( int n );
double ijfact2_determinant ( int n );
double *ill3 ( void );
double ill3_determinant ( void );
double *ill3_eigenvalues ( void );
double *ill3_inverse ( void );
double *ill3_right ( void );
double *indicator ( int m, int n );
double *integration ( double alpha, int n );
double integration_determinant ( double alpha, int n );
double *integration_eigenvalues ( double alpha, int n );
double *integration_inverse ( double alpha, int n );
double *invol ( int n );
double invol_determinant ( int n );
double *invol_eigenvalues ( int n );
double *invol_inverse ( int n );
double *invol_random ( int n, int rank, int *seed );
double *jacobi ( int m, int n );
double jacobi_determinant ( int n );
double *jacobi_eigenvalues ( int n );
void jacobi_iterate ( int n, double a[], double lambda[], double x[] );
int jacobi_symbol ( int q, int p );
double *jordan ( double alpha, int m, int n );
double jordan_determinant ( double alpha, int n );
double *jordan_inverse ( double alpha, int n );
double *kahan ( double alpha, int m, int n );
double kahan_determinant ( double alpha, int n );
double *kahan_inverse ( double alpha, int n );
double *kershaw ( void );
double kershaw_determinant ( void );
double *kershaw_eigenvalues ( void );
double *kershaw_inverse ( void );
double *kershawtri ( int n, double x[] );
double kershawtri_determinant ( int n, double x[] );
double *kershawtri_inverse ( int n, double x[] );
double *kms ( double alpha, int m, int n );
double kms_determinant ( double alpha, int n );
double *kms_eigenvalues ( double alpha, int n );
double *kms_eigenvalues_theta ( double alpha, int n );
double kms_eigenvalues_theta_f ( double alpha, int n, double t );
double *kms_inverse ( double alpha, int n );
double *kms_right ( double alpha, int n );
void kms_ldl ( double alpha, int n, double **l, double **d );
void kms_plu ( double alpha, int n, double p[], double l[], double u[] );
double *krylov ( int n, double b[], double x[] );
void ksub_next ( int n, int k, int a[], int *more );
double *laguerre ( int n );
double laguerre_determinant ( int n );
double *laguerre_inverse ( int n );
double *lauchli ( double alpha, int m, int n );
double *lauchli_null_left ( double alpha, int m, int n );
double *legendre ( int n );
double *legendre_inverse ( int n );
int legendre_symbol ( int q, int p );
double *legendre_zeros ( int n );
double *lehmer ( int m, int n );
double *lehmer_inverse ( int n );
double *leslie ( double b, double di, double da );
double leslie_determinant ( double b, double di, double da );
double *lesp ( int m, int n );
double lesp_determinant ( int n );
double *lietzke ( int n );
double lietzke_determinant ( int n );
double *lietzke_inverse ( int n );
double *line_adj ( int n );
double line_adj_determinant ( int n );
double *line_adj_eigenvalues ( int n );
double *line_adj_null ( int n );
double *line_loop_adj ( int n );
double line_loop_adj_determinant ( int n );
double *line_loop_adj_eigenvalues ( int n );
double *loewner ( double w[], double x[], double y[], double z[], int n );
double *lotkin ( int m, int n );
double lotkin_determinant ( int n );
double *lotkin_inverse ( int n );
double *markov_random ( int n, int *seed );
double *maxij ( int m, int n );
double maxij_determinant ( int n );
double *maxij_inverse ( int n );
void maxij_plu ( int n, double p[], double l[], double u[] );
int mertens ( int n );
double *milnes ( int m, int n, double x[] );
double milnes_determinant ( int n, double x[] );
double *milnes_inverse ( int n, double x[] );
double *minij ( int m, int n );
double *minij_cholesky ( int n );
double minij_determinant ( int n );
double *minij_eigenvalues ( int n );
double *minij_inverse ( int n );
void minij_plu ( int n, double p[], double l[], double u[] );
int moebius ( int n );
double *moler1 ( double alpha, int m, int n );
double moler1_determinant ( double alpha, int n );
double *moler1_inverse ( double alpha, int n );
void moler1_plu ( double alpha, int n, double p[], double l[], double u[] );
double *moler2 ( void );
double moler2_determinant ( void );
double *moler2_eigenvalues ( void );
double *moler2_null ( void );
double *moler3 ( int m, int n );
double *moler3_cholesky ( int n );
double moler3_determinant ( int n );
double *moler3_inverse ( int n );
void moler3_plu ( int n, double p[], double l[], double u[] );
double *neumann ( int nrow, int ncol );
double neumann_determinant ( int n );
double *neumann_null ( int nrow, int ncol );
double *one ( int m, int n );
double one_determinant ( int n );
double *one_eigenvalues ( int n );
double *one_null ( int n );
double *one_right ( int n );
double *ortega ( int n, double u[], double v[], double d[] );
double ortega_determinant ( int n, double u[], double v[], double d[] );
double *ortega_eigenvalues ( int n, double u[], double v[], double d[] );
double *ortega_inverse ( int n, double u[], double v[], double d[] );
double *ortega_right ( int n, double u[], double v[], double d[] );
double *orth_random ( int n, int *seed );
double orth_random_determinant ( int n, int *seed );
double *orth_random_inverse ( int n, int *seed );
double *orth_symm ( int n );
double orth_symm_determinant ( int n );
double *orth_symm_eigenvalues ( int n );
double *orth_symm_inverse ( int n );
double *oto ( int m, int n );
double oto_determinant ( int n );
double *oto_eigenvalues ( int n );
double *oto_inverse ( int n );
void oto_plu ( int n, double p[], double l[], double u[] );
double *oto_right ( int n );
double *parlett ( void );
double *parlett_eigenvalues ( void );
double *parter ( int m, int n );
double parter_determinant ( int n );
double *parter_inverse ( int n );
double *pascal1 ( int n );
double pascal1_determinant ( int n );
double *pascal1_eigenvalues ( int n );
double *pascal1_inverse ( int n );
double *pascal2 ( int n );
double *pascal2_cholesky ( int n );
double pascal2_determinant ( int n );
double *pascal2_inverse ( int n );
void pascal2_plu ( int n, double p[], double l[], double u[] );
double *pascal3 ( int n, double alpha );
double pascal3_determinant ( int n, double alpha );
double *pascal3_inverse ( int n, double alpha );
double *pds_random ( int n, int *seed );
double pds_random_determinant ( int n, int *seed );
double *pds_random_eigenvalues ( int n, int *seed );
double *pds_random_inverse ( int n, int *seed );
double *pds_random_right ( int n, int *seed );
double *pei ( double alpha, int n );
double pei_determinant ( double alpha, int n );
double *pei_eigenvalues ( double alpha, int n );
double *pei_inverse ( double alpha, int n );
double *pei_right ( double alpha, int n );
int perm_check ( int n, int p[] );
void perm_inverse ( int n, int p[] );
int *perm_mat_to_vec ( int n, double a[] );
int perm_sign ( int n, int p[] );
double *perm_vec_to_mat ( int n, int p[] );
double permutation_determinant ( int n, double a[] );
double *permutation_inverse ( int n, double a[] );
double *permutation_random ( int n, int *seed );
double permutation_random_determinant ( int n, int *seed );
double *permutation_random_inverse ( int n, int *seed );
double complex *pick ( int n, double complex w[], double complex z[] );
double *plu ( int n, int pivot[], double p[], double l[], double u[] );
double plu_determinant ( int n, double p[], double l[], double u[] );
double *plu_inverse ( int n, double p[], double l[], double u[] );
double *poisson ( int nrow, int ncol, int n );
double poisson_determinant ( int nrow, int ncol, int n );
double *poisson_eigenvalues ( int nrow, int ncol, int n );
double *poisson_rhs ( int nrow, int ncol, int n );
double *poisson_solution ( int nrow, int ncol, int n );
int prime ( int n );
double *prolate ( double alpha, int n );
double *quaternion_i ( void );
double *quaternion_j ( void );
double *quaternion_k ( void );
float r4_abs ( float x );
int r4_nint ( float x );
double r8_abs ( double x );
double r8_choose ( int n, int k );
double r8_epsilon ( void );
double r8_factorial ( int n );
double r8_huge ( void );
double r8_max ( double x, double y );
double r8_mop ( int i );
int r8_nint ( double x );
double r8_normal_01 ( int *seed );
double r8_sign ( double x );
double r8_uniform ( double b, double c, int *seed );
double r8_uniform_01 ( int *seed );
void r8col_swap ( int m, int n, double a[], int j1, int j2 );
double *r8col_to_r8vec ( int m, int n, double a[] );
void r8mat_copy ( int m, int n, double a1[], double a2[] );
double *r8mat_copy_new ( int m, int n, double a1[] );
double r8mat_determinant ( int n, double a[] );
double *r8mat_diag_get_vector ( int n, double a[] );
double r8mat_gedet ( double a[], int n, int pivot[] );
int r8mat_gefa ( double a[], int n, int pivot[] );
void r8mat_geinverse ( double a[], int n, int pivot[] );
void r8mat_house_axh ( int n, double a[], double v[] );
double *r8mat_house_axh_new ( int n, double a[], double v[] );
double *r8mat_house_form ( int n, double v[] );
double *r8mat_identity ( int n );
double *r8mat_inverse ( int n, double a[] );
int r8mat_is_adjacency ( int m, int n, double a[] );
double r8mat_is_eigen_right ( int n, int k, double a[], double x[],
  double lambda[] );
double r8mat_is_inverse ( int n, double a[], double b[] );
double r8mat_is_inverse_left ( int m, int n, double a[], double b[] );
double r8mat_is_inverse_right ( int m, int n, double a[], double b[] );
double r8mat_is_null_vector ( int m, int n, double a[], double x[] );
int r8mat_is_perm ( int n, double a[] );
double r8mat_is_plu ( int m, int n, double a[], double p[], double l[], 
  double u[] );
double r8mat_is_solution ( int m, int n, int k, double a[], double x[], 
  double b[] );
double r8mat_is_symmetric ( int m, int n, double a[] );
int r8mat_is_zero_one ( int m, int n, double a[] );
double *r8mat_mm_new ( int n1, int n2, int n3, double a[], double b[] );
double r8mat_norm_eis ( int m, int n, double a[] );
double r8mat_norm_fro ( int m, int n, double a[] );
double r8mat_norm_l1 ( int m, int n, double a[] );
double r8mat_norm_l2 ( int m, int n, double a[] );
double r8mat_norm_li ( int m, int n, double a[] );
void r8mat_plot ( int m, int n, double a[], char *title );
char r8mat_plot_symbol ( double r );
double *r8mat_poly_char ( int n, double a[] );
void r8mat_print ( int m, int n, double a[], char *title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, char *title );
void r8mat_symm_jacobi ( int n, double a[] );
double r8mat_trace ( int n, double a[] );
double *r8mat_transpose_new ( int m, int n, double a[] );
void r8mat_transpose_in_place ( int n, double a[] );
double *r8mat_uniform_new ( int m, int n, double b, double c, int *seed );
double *r8mat_uniform_01_new ( int m, int n, int *seed );
double *r8mat_zero_new ( int m, int n );
int r8poly_degree ( int na, double a[] );
void r8poly_print ( int n, double a[], char *title );
void r8row_swap ( int m, int n, double a[], int irow1, int irow2 );
double *r8row_to_r8vec ( int m, int n, double a[] );
void r8vec_copy ( int n, double a1[], double a2[] );
double *r8vec_copy_new ( int n, double a1[] );
double r8vec_dot_product ( int n, double a1[], double a2[] );
double *r8vec_house_column ( int n, double a[], int k );
double *r8vec_indicator_new ( int n );
double r8vec_max ( int n, double r8vec[] );
double r8vec_norm_l2 ( int n, double a[] );
void r8vec_print ( int n, double a[], char *title );
double r8vec_product ( int n, double a[] );
void r8vec_sort_bubble_a ( int n, double a[] );
double r8vec_sum ( int n, double a[] );
double *r8vec_uniform_new ( int n, double b, double c, int *seed );
double *r8vec_uniform_01_new ( int n, int *seed );
void r8vec_zero ( int n, double a[] );
double *r8vec_zero_new ( int n );
void r8vec2_print ( int n, double a1[], double a2[], char *title );
double rayleigh ( int n, double a[], double x[] );
double rayleigh2 ( int n, double a[], double x[], double y[] );
double *redheffer ( int n );
double redheffer_determinant ( int n );
double *ref_random ( int m, int n, double prob, int *seed );
double ref_random_determinant ( int n, double prob, int *seed );
double *riemann ( int m, int n );
double *ring_adj ( int n );
double ring_adj_determinant ( int n );
double *ring_adj_null ( int n );
double *ris ( int n );
double ris_determinant ( int n );
double *ris_inverse ( int n );
double *rodman ( double alpha, int m, int n );
double rodman_determinant ( double alpha, int n );
double *rodman_eigenvalues ( double alpha, int n );
double *rodman_inverse ( double alpha, int n );
double *rodman_right ( double alpha, int n );
double *rosser1 ( void );
double rosser1_determinant ( void );
double *rosser1_eigenvalues ( void );
double *rosser1_null ( void );
double *rosser1_right ( void );
double *routh ( int n, double x[] );
double routh_determinant ( int n, double x[] );
double *rowcolsum_matrix ( int row_num, int col_num, int *m, int *n );
double *rutis1 ( void );
double rutis1_determinant ( void );
double *rutis1_eigenvalues ( void );
double *rutis1_inverse ( void );
double *rutis1_right ( void );
double *rutis2 ( void );
double rutis2_determinant ( void );
double *rutis2_eigenvalues ( void );
double *rutis2_inverse ( void );
double *rutis2_right ( void );
double *rutis3 ( void );
double rutis3_determinant ( void );
double complex *rutis3_eigenvalues ( void );
double *rutis3_inverse ( void );
double complex *rutis3_left ( void );
double complex *rutis3_right ( void );
double *rutis4 ( int n );
double rutis4_determinant ( int n );
double *rutis4_eigenvalues ( int n );
double *rutis4_inverse ( int n );
double *rutis5 ( void );
double rutis5_condition ( void );
double rutis5_determinant ( void );
double *rutis5_eigenvalues ( void );
double *rutis5_inverse ( void );
double *rutis5_right ( void );
int s_len_trim ( char *s );
double *schur_block ( int n, double x[], double y[] );
double schur_block_determinant ( int n, double x[], double y[] );
double complex *schur_block_eigenvalues ( int n, double x[], double y[] );
double *schur_block_inverse ( int n, double x[], double y[] );
double *skew_circulant ( int m, int n, double x[] );
double skew_circulant_determinant ( int n, double x[] );
double complex *skew_circulant_eigenvalues ( int n, double x[] );
double complex *smoke1 ( int n );
double smoke1_determinant ( int n );
double complex *smoke1_eigenvalues ( int n );
double complex *smoke2 ( int n );
double smoke2_determinant ( int n );
double complex *smoke2_eigenvalues ( int n );
void sort_heap_external ( int n, int *indx, int *i, int *j, int isgn );
double *spline ( int n, double x[] );
double spline_determinant ( int n, double x[] );
double *spline_inverse ( int n, double x[] );
double *stirling ( int m, int n );
double stirling_determinant ( int n );
double *stirling_inverse ( int n );
double *stripe ( int n );
void subset_random ( int n, int *seed, int a[] );
void subset_by_size_next ( int n, int a[], int *size, int *more );
double *summation ( int m, int n );
double summation_condition ( int n );
double summation_determinant ( int n );
double *summation_eigenvalues ( int n );
double *summation_inverse ( int n );
double *sweet1 ( double perturb );
double *sweet2 ( double perturb );
double *sweet3 ( double perturb );
double *sweet4 ( double perturb );
double *sylvester ( int n, int nx, double x[], int ny, double y[] );
double *symm_random ( int n, double x[], int *seed );
double symm_random_determinant ( int n, double x[] );
double *symm_random_eigenvalues ( int n, double x[] );
double *symm_random_inverse ( int n, double x[], int *seed );
void timestamp ( void );
double *toeplitz ( int n, double x[] );
double *toeplitz_5diag ( int n, double d1, double d2, double d3, double d4, 
  double d5 );
double *toeplitz_5s ( int row_num, int col_num, double alpha, double beta, 
  double gamma, int n );
double *toeplitz_5s_eigenvalues ( int row_num, int col_num, double alpha, 
  double beta, double gamma );
double *toeplitz_pds ( int m, int n, double x[], double y[] );
double *tournament_random ( int n, int *seed );
double tournament_random_determinant ( int n, int *seed );
double *transition_random ( int n, int *seed );
double *trench ( double alpha, int m, int n );
double *tri_l1_inverse ( int n, double a[] );
double *tri_u_inverse ( int n, double a[] );
double *tri_upper ( double alpha, int n );
double tri_upper_condition ( double alpha, int n );
double tri_upper_determinant ( double alpha, int n );
double *tri_upper_eigenvalues ( int n );
double *tri_upper_inverse ( double alpha, int n );
double tridiagonal_determinant ( int n, double a[] );
double *tris ( int m, int n, double x, double y, double z );
double tris_determinant ( int n, double x, double y, double z );
double complex *tris_eigenvalues ( int n, double x, double y, double z );
double *tris_inverse ( int n, double alpha, double beta, double gamma );
double *triv ( int n, double x[], double y[], double z[]  );
double triv_determinant ( int n, double x[], double y[], double z[]  );
double *triv_inverse ( int n, double x[], double y[], double z[] );
double *triw ( double alpha, int k, int n );
double triw_determinant ( double alpha, int k, int n );
double *triw_eigenvalues ( int n );
double *triw_inverse ( double alpha, int k, int n );
double *upshift ( int n );
double upshift_determinant ( int n );
double complex *upshift_eigenvalues ( int n );
double *upshift_inverse ( int n );
double *vand1 ( int n, double x[] );
double vand1_determinant ( int n, double x[] );
double *vand1_inverse ( int n, double x[] );
double *vand2 ( int n, double x[] );
double vand2_determinant ( int n, double x[] );
double *vand2_inverse ( int n, double x[] );
double *wathen ( int nx, int ny, int n );
int wathen_order ( int nx, int ny );
double *wilk03 ( void );
double wilk03_condition ( );
double wilk03_determinant ( void );
double *wilk03_eigenvalues ( void );
double *wilk03_inverse ( void );
double *wilk03_rhs ( void );
double *wilk03_solution ( void );
double *wilk04 ( void );
double wilk04_determinant ( void );
double *wilk04_eigenvalues ( void );
double *wilk04_inverse ( void );
double *wilk04_rhs ( void );
double *wilk04_solution ( void );
double *wilk05 ( void );
double wilk05_determinant ( void );
double *wilk05_inverse ( void );
double *wilk12 ( void );
double wilk12_determinant ( void );
double *wilk12_eigenvalues ( void );
double *wilk12_right ( void );
double *wilk20 ( double alpha );
double *wilk21 ( int n );
double wilk21_determinant ( int n );
double *wilk21_inverse ( int n );
double *wilson ( void );
double wilson_condition ( void );
double wilson_determinant ( void );
double *wilson_eigenvalues ( void );
double *wilson_inverse ( void );
void wilson_plu ( double p[], double l[], double u[] );
double *wilson_rhs ( void );
double *wilson_right ( void );
double *wilson_solution ( void );
double *zero ( int m, int n );
double zero_determinant ( int n );
double *zero_eigenvalues ( int n );
double *zero_null ( int n );
double *zero_right ( int n );
double *zielke ( int n, double x, double y, double z );
