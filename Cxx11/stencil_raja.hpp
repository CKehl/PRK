void star1(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(1,n-1);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i)*n+(j-1)] * -0.5
                          +in[(i-1)*n+(j)] * -0.5
                          +in[(i+1)*n+(j)] * 0.5
                          +in[(i)*n+(j+1)] * 0.5;
      });
    });
}

void star2(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(2,n-2);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i)*n+(j-2)] * -0.125
                          +in[(i)*n+(j-1)] * -0.25
                          +in[(i-2)*n+(j)] * -0.125
                          +in[(i-1)*n+(j)] * -0.25
                          +in[(i+1)*n+(j)] * 0.25
                          +in[(i+2)*n+(j)] * 0.125
                          +in[(i)*n+(j+1)] * 0.25
                          +in[(i)*n+(j+2)] * 0.125;
      });
    });
}

void star3(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(3,n-3);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i)*n+(j-3)] * -0.05555555555555555
                          +in[(i)*n+(j-2)] * -0.08333333333333333
                          +in[(i)*n+(j-1)] * -0.16666666666666666
                          +in[(i-3)*n+(j)] * -0.05555555555555555
                          +in[(i-2)*n+(j)] * -0.08333333333333333
                          +in[(i-1)*n+(j)] * -0.16666666666666666
                          +in[(i+1)*n+(j)] * 0.16666666666666666
                          +in[(i+2)*n+(j)] * 0.08333333333333333
                          +in[(i+3)*n+(j)] * 0.05555555555555555
                          +in[(i)*n+(j+1)] * 0.16666666666666666
                          +in[(i)*n+(j+2)] * 0.08333333333333333
                          +in[(i)*n+(j+3)] * 0.05555555555555555;
      });
    });
}

void star4(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(4,n-4);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i)*n+(j-4)] * -0.03125
                          +in[(i)*n+(j-3)] * -0.041666666666666664
                          +in[(i)*n+(j-2)] * -0.0625
                          +in[(i)*n+(j-1)] * -0.125
                          +in[(i-4)*n+(j)] * -0.03125
                          +in[(i-3)*n+(j)] * -0.041666666666666664
                          +in[(i-2)*n+(j)] * -0.0625
                          +in[(i-1)*n+(j)] * -0.125
                          +in[(i+1)*n+(j)] * 0.125
                          +in[(i+2)*n+(j)] * 0.0625
                          +in[(i+3)*n+(j)] * 0.041666666666666664
                          +in[(i+4)*n+(j)] * 0.03125
                          +in[(i)*n+(j+1)] * 0.125
                          +in[(i)*n+(j+2)] * 0.0625
                          +in[(i)*n+(j+3)] * 0.041666666666666664
                          +in[(i)*n+(j+4)] * 0.03125;
      });
    });
}

void star5(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(5,n-5);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i)*n+(j-5)] * -0.02
                          +in[(i)*n+(j-4)] * -0.025
                          +in[(i)*n+(j-3)] * -0.03333333333333333
                          +in[(i)*n+(j-2)] * -0.05
                          +in[(i)*n+(j-1)] * -0.1
                          +in[(i-5)*n+(j)] * -0.02
                          +in[(i-4)*n+(j)] * -0.025
                          +in[(i-3)*n+(j)] * -0.03333333333333333
                          +in[(i-2)*n+(j)] * -0.05
                          +in[(i-1)*n+(j)] * -0.1
                          +in[(i+1)*n+(j)] * 0.1
                          +in[(i+2)*n+(j)] * 0.05
                          +in[(i+3)*n+(j)] * 0.03333333333333333
                          +in[(i+4)*n+(j)] * 0.025
                          +in[(i+5)*n+(j)] * 0.02
                          +in[(i)*n+(j+1)] * 0.1
                          +in[(i)*n+(j+2)] * 0.05
                          +in[(i)*n+(j+3)] * 0.03333333333333333
                          +in[(i)*n+(j+4)] * 0.025
                          +in[(i)*n+(j+5)] * 0.02;
      });
    });
}

void grid1(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(1,n-1);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i-1)*n+(j-1)] * -0.25
                          +in[(i)*n+(j-1)] * -0.25
                          +in[(i-1)*n+(j)] * -0.25
                          +in[(i+1)*n+(j)] * 0.25
                          +in[(i)*n+(j+1)] * 0.25
                          +in[(i+1)*n+(j+1)] * 0.25
                          ;
      });
    });
}

void grid2(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(2,n-2);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i-2)*n+(j-2)] * -0.0625
                          +in[(i-1)*n+(j-2)] * -0.020833333333333332
                          +in[(i)*n+(j-2)] * -0.020833333333333332
                          +in[(i+1)*n+(j-2)] * -0.020833333333333332
                          +in[(i-2)*n+(j-1)] * -0.020833333333333332
                          +in[(i-1)*n+(j-1)] * -0.125
                          +in[(i)*n+(j-1)] * -0.125
                          +in[(i+2)*n+(j-1)] * 0.020833333333333332
                          +in[(i-2)*n+(j)] * -0.020833333333333332
                          +in[(i-1)*n+(j)] * -0.125
                          +in[(i+1)*n+(j)] * 0.125
                          +in[(i+2)*n+(j)] * 0.020833333333333332
                          +in[(i-2)*n+(j+1)] * -0.020833333333333332
                          +in[(i)*n+(j+1)] * 0.125
                          +in[(i+1)*n+(j+1)] * 0.125
                          +in[(i+2)*n+(j+1)] * 0.020833333333333332
                          +in[(i-1)*n+(j+2)] * 0.020833333333333332
                          +in[(i)*n+(j+2)] * 0.020833333333333332
                          +in[(i+1)*n+(j+2)] * 0.020833333333333332
                          +in[(i+2)*n+(j+2)] * 0.0625
                          ;
      });
    });
}

void grid3(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(3,n-3);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i-3)*n+(j-3)] * -0.027777777777777776
                          +in[(i-2)*n+(j-3)] * -0.005555555555555556
                          +in[(i-1)*n+(j-3)] * -0.005555555555555556
                          +in[(i)*n+(j-3)] * -0.005555555555555556
                          +in[(i+1)*n+(j-3)] * -0.005555555555555556
                          +in[(i+2)*n+(j-3)] * -0.005555555555555556
                          +in[(i-3)*n+(j-2)] * -0.005555555555555556
                          +in[(i-2)*n+(j-2)] * -0.041666666666666664
                          +in[(i-1)*n+(j-2)] * -0.013888888888888888
                          +in[(i)*n+(j-2)] * -0.013888888888888888
                          +in[(i+1)*n+(j-2)] * -0.013888888888888888
                          +in[(i+3)*n+(j-2)] * 0.005555555555555556
                          +in[(i-3)*n+(j-1)] * -0.005555555555555556
                          +in[(i-2)*n+(j-1)] * -0.013888888888888888
                          +in[(i-1)*n+(j-1)] * -0.08333333333333333
                          +in[(i)*n+(j-1)] * -0.08333333333333333
                          +in[(i+2)*n+(j-1)] * 0.013888888888888888
                          +in[(i+3)*n+(j-1)] * 0.005555555555555556
                          +in[(i-3)*n+(j)] * -0.005555555555555556
                          +in[(i-2)*n+(j)] * -0.013888888888888888
                          +in[(i-1)*n+(j)] * -0.08333333333333333
                          +in[(i+1)*n+(j)] * 0.08333333333333333
                          +in[(i+2)*n+(j)] * 0.013888888888888888
                          +in[(i+3)*n+(j)] * 0.005555555555555556
                          +in[(i-3)*n+(j+1)] * -0.005555555555555556
                          +in[(i-2)*n+(j+1)] * -0.013888888888888888
                          +in[(i)*n+(j+1)] * 0.08333333333333333
                          +in[(i+1)*n+(j+1)] * 0.08333333333333333
                          +in[(i+2)*n+(j+1)] * 0.013888888888888888
                          +in[(i+3)*n+(j+1)] * 0.005555555555555556
                          +in[(i-3)*n+(j+2)] * -0.005555555555555556
                          +in[(i-1)*n+(j+2)] * 0.013888888888888888
                          +in[(i)*n+(j+2)] * 0.013888888888888888
                          +in[(i+1)*n+(j+2)] * 0.013888888888888888
                          +in[(i+2)*n+(j+2)] * 0.041666666666666664
                          +in[(i+3)*n+(j+2)] * 0.005555555555555556
                          +in[(i-2)*n+(j+3)] * 0.005555555555555556
                          +in[(i-1)*n+(j+3)] * 0.005555555555555556
                          +in[(i)*n+(j+3)] * 0.005555555555555556
                          +in[(i+1)*n+(j+3)] * 0.005555555555555556
                          +in[(i+2)*n+(j+3)] * 0.005555555555555556
                          +in[(i+3)*n+(j+3)] * 0.027777777777777776
                          ;
      });
    });
}

void grid4(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(4,n-4);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i-4)*n+(j-4)] * -0.015625
                          +in[(i-3)*n+(j-4)] * -0.002232142857142857
                          +in[(i-2)*n+(j-4)] * -0.002232142857142857
                          +in[(i-1)*n+(j-4)] * -0.002232142857142857
                          +in[(i)*n+(j-4)] * -0.002232142857142857
                          +in[(i+1)*n+(j-4)] * -0.002232142857142857
                          +in[(i+2)*n+(j-4)] * -0.002232142857142857
                          +in[(i+3)*n+(j-4)] * -0.002232142857142857
                          +in[(i-4)*n+(j-3)] * -0.002232142857142857
                          +in[(i-3)*n+(j-3)] * -0.020833333333333332
                          +in[(i-2)*n+(j-3)] * -0.004166666666666667
                          +in[(i-1)*n+(j-3)] * -0.004166666666666667
                          +in[(i)*n+(j-3)] * -0.004166666666666667
                          +in[(i+1)*n+(j-3)] * -0.004166666666666667
                          +in[(i+2)*n+(j-3)] * -0.004166666666666667
                          +in[(i+4)*n+(j-3)] * 0.002232142857142857
                          +in[(i-4)*n+(j-2)] * -0.002232142857142857
                          +in[(i-3)*n+(j-2)] * -0.004166666666666667
                          +in[(i-2)*n+(j-2)] * -0.03125
                          +in[(i-1)*n+(j-2)] * -0.010416666666666666
                          +in[(i)*n+(j-2)] * -0.010416666666666666
                          +in[(i+1)*n+(j-2)] * -0.010416666666666666
                          +in[(i+3)*n+(j-2)] * 0.004166666666666667
                          +in[(i+4)*n+(j-2)] * 0.002232142857142857
                          +in[(i-4)*n+(j-1)] * -0.002232142857142857
                          +in[(i-3)*n+(j-1)] * -0.004166666666666667
                          +in[(i-2)*n+(j-1)] * -0.010416666666666666
                          +in[(i-1)*n+(j-1)] * -0.0625
                          +in[(i)*n+(j-1)] * -0.0625
                          +in[(i+2)*n+(j-1)] * 0.010416666666666666
                          +in[(i+3)*n+(j-1)] * 0.004166666666666667
                          +in[(i+4)*n+(j-1)] * 0.002232142857142857
                          +in[(i-4)*n+(j)] * -0.002232142857142857
                          +in[(i-3)*n+(j)] * -0.004166666666666667
                          +in[(i-2)*n+(j)] * -0.010416666666666666
                          +in[(i-1)*n+(j)] * -0.0625
                          +in[(i+1)*n+(j)] * 0.0625
                          +in[(i+2)*n+(j)] * 0.010416666666666666
                          +in[(i+3)*n+(j)] * 0.004166666666666667
                          +in[(i+4)*n+(j)] * 0.002232142857142857
                          +in[(i-4)*n+(j+1)] * -0.002232142857142857
                          +in[(i-3)*n+(j+1)] * -0.004166666666666667
                          +in[(i-2)*n+(j+1)] * -0.010416666666666666
                          +in[(i)*n+(j+1)] * 0.0625
                          +in[(i+1)*n+(j+1)] * 0.0625
                          +in[(i+2)*n+(j+1)] * 0.010416666666666666
                          +in[(i+3)*n+(j+1)] * 0.004166666666666667
                          +in[(i+4)*n+(j+1)] * 0.002232142857142857
                          +in[(i-4)*n+(j+2)] * -0.002232142857142857
                          +in[(i-3)*n+(j+2)] * -0.004166666666666667
                          +in[(i-1)*n+(j+2)] * 0.010416666666666666
                          +in[(i)*n+(j+2)] * 0.010416666666666666
                          +in[(i+1)*n+(j+2)] * 0.010416666666666666
                          +in[(i+2)*n+(j+2)] * 0.03125
                          +in[(i+3)*n+(j+2)] * 0.004166666666666667
                          +in[(i+4)*n+(j+2)] * 0.002232142857142857
                          +in[(i-4)*n+(j+3)] * -0.002232142857142857
                          +in[(i-2)*n+(j+3)] * 0.004166666666666667
                          +in[(i-1)*n+(j+3)] * 0.004166666666666667
                          +in[(i)*n+(j+3)] * 0.004166666666666667
                          +in[(i+1)*n+(j+3)] * 0.004166666666666667
                          +in[(i+2)*n+(j+3)] * 0.004166666666666667
                          +in[(i+3)*n+(j+3)] * 0.020833333333333332
                          +in[(i+4)*n+(j+3)] * 0.002232142857142857
                          +in[(i-3)*n+(j+4)] * 0.002232142857142857
                          +in[(i-2)*n+(j+4)] * 0.002232142857142857
                          +in[(i-1)*n+(j+4)] * 0.002232142857142857
                          +in[(i)*n+(j+4)] * 0.002232142857142857
                          +in[(i+1)*n+(j+4)] * 0.002232142857142857
                          +in[(i+2)*n+(j+4)] * 0.002232142857142857
                          +in[(i+3)*n+(j+4)] * 0.002232142857142857
                          +in[(i+4)*n+(j+4)] * 0.015625
                          ;
      });
    });
}

void grid5(const int n, const int t, std::vector<double> & in, std::vector<double> & out) {
    RAJA::RangeSegment inside(5,n-5);
    RAJA::forall<thread_exec>(inside, [&](RAJA::Index_type i) {
      RAJA::forall<RAJA::simd_exec>(inside, [&](RAJA::Index_type j) {
            out[i*n+j] += +in[(i-5)*n+(j-5)] * -0.01
                          +in[(i-4)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-3)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-2)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-1)*n+(j-5)] * -0.0011111111111111111
                          +in[(i)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+1)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+2)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+3)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+4)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-5)*n+(j-4)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-4)] * -0.0125
                          +in[(i-3)*n+(j-4)] * -0.0017857142857142857
                          +in[(i-2)*n+(j-4)] * -0.0017857142857142857
                          +in[(i-1)*n+(j-4)] * -0.0017857142857142857
                          +in[(i)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+1)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+2)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+3)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+5)*n+(j-4)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-3)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-3)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-3)] * -0.016666666666666666
                          +in[(i-2)*n+(j-3)] * -0.0033333333333333335
                          +in[(i-1)*n+(j-3)] * -0.0033333333333333335
                          +in[(i)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+1)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+2)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+4)*n+(j-3)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-3)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-2)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-2)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-2)] * -0.0033333333333333335
                          +in[(i-2)*n+(j-2)] * -0.025
                          +in[(i-1)*n+(j-2)] * -0.008333333333333333
                          +in[(i)*n+(j-2)] * -0.008333333333333333
                          +in[(i+1)*n+(j-2)] * -0.008333333333333333
                          +in[(i+3)*n+(j-2)] * 0.0033333333333333335
                          +in[(i+4)*n+(j-2)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-2)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-1)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-1)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-1)] * -0.0033333333333333335
                          +in[(i-2)*n+(j-1)] * -0.008333333333333333
                          +in[(i-1)*n+(j-1)] * -0.05
                          +in[(i)*n+(j-1)] * -0.05
                          +in[(i+2)*n+(j-1)] * 0.008333333333333333
                          +in[(i+3)*n+(j-1)] * 0.0033333333333333335
                          +in[(i+4)*n+(j-1)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-1)] * 0.0011111111111111111
                          +in[(i-5)*n+(j)] * -0.0011111111111111111
                          +in[(i-4)*n+(j)] * -0.0017857142857142857
                          +in[(i-3)*n+(j)] * -0.0033333333333333335
                          +in[(i-2)*n+(j)] * -0.008333333333333333
                          +in[(i-1)*n+(j)] * -0.05
                          +in[(i+1)*n+(j)] * 0.05
                          +in[(i+2)*n+(j)] * 0.008333333333333333
                          +in[(i+3)*n+(j)] * 0.0033333333333333335
                          +in[(i+4)*n+(j)] * 0.0017857142857142857
                          +in[(i+5)*n+(j)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+1)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+1)] * -0.0017857142857142857
                          +in[(i-3)*n+(j+1)] * -0.0033333333333333335
                          +in[(i-2)*n+(j+1)] * -0.008333333333333333
                          +in[(i)*n+(j+1)] * 0.05
                          +in[(i+1)*n+(j+1)] * 0.05
                          +in[(i+2)*n+(j+1)] * 0.008333333333333333
                          +in[(i+3)*n+(j+1)] * 0.0033333333333333335
                          +in[(i+4)*n+(j+1)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+1)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+2)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+2)] * -0.0017857142857142857
                          +in[(i-3)*n+(j+2)] * -0.0033333333333333335
                          +in[(i-1)*n+(j+2)] * 0.008333333333333333
                          +in[(i)*n+(j+2)] * 0.008333333333333333
                          +in[(i+1)*n+(j+2)] * 0.008333333333333333
                          +in[(i+2)*n+(j+2)] * 0.025
                          +in[(i+3)*n+(j+2)] * 0.0033333333333333335
                          +in[(i+4)*n+(j+2)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+2)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+3)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+3)] * -0.0017857142857142857
                          +in[(i-2)*n+(j+3)] * 0.0033333333333333335
                          +in[(i-1)*n+(j+3)] * 0.0033333333333333335
                          +in[(i)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+1)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+2)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+3)*n+(j+3)] * 0.016666666666666666
                          +in[(i+4)*n+(j+3)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+3)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+4)] * -0.0011111111111111111
                          +in[(i-3)*n+(j+4)] * 0.0017857142857142857
                          +in[(i-2)*n+(j+4)] * 0.0017857142857142857
                          +in[(i-1)*n+(j+4)] * 0.0017857142857142857
                          +in[(i)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+1)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+2)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+3)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+4)*n+(j+4)] * 0.0125
                          +in[(i+5)*n+(j+4)] * 0.0011111111111111111
                          +in[(i-4)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-3)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-2)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-1)*n+(j+5)] * 0.0011111111111111111
                          +in[(i)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+1)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+2)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+3)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+4)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+5)*n+(j+5)] * 0.01
                          ;
      });
    });
}

