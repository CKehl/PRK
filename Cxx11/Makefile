include ../common/Cxx11.defs
include ../common/PRKVERSION

CPPFLAGS  = -DPRKVERSION=$(PRKVERSION)

# debugging
ifdef VERBOSE
    CPPFLAGS += -DVERBOSE
endif

CXXFLAGS  = $(DEFAULT_OPT_FLAGS) $(CPPFLAGS)

ifeq ($(USE_PRK_TBB_PARTITIONER),static)
    PRK_TBB_PARTITIONER=1
endif
ifeq ($(USE_PRK_TBB_PARTITIONER),affinity)
    PRK_TBB_PARTITIONER=2
endif
ifeq ($(USE_PRK_TBB_PARTITIONER),simple)
    PRK_TBB_PARTITIONER=3
endif
ifndef PRK_TBB_PARTITIONER
    PRK_TBB_PARTITIONER=0
endif

# Valid choices are OpenMP, Threads, Serial, Cuda
ifdef USE_PRK_KOKKOS_BACKEND
    KOKKOS_BACKEND_FLAG = -DPRK_KOKKOS_BACKEND=$(USE_PRK_KOKKOS_BACKEND)
endif

#ASMFLAGS = -fsource-asm -fverbose-asm -fasm-blocks -fcode-asm
ASMFLAGS = -fverbose-asm

OMPFLAGS = $(OPENMPFLAG) -DUSE_OPENMP
TARGETFLAGS = $(OFFLOADFLAG)
OPENCLFLAGS = $(OPENCLFLAG) -DCL_HPP_MINIMUM_OPENCL_VERSION=120 -DCL_HPP_TARGET_OPENCL_VERSION=120
# We do not yet handle all possible exceptions...
#OPENCLFLAGS += -D__CL_ENABLE_EXCEPTIONS
ORNLACCFLAGS = $(ORNLACCFLAG)
TBBFLAGS = $(TBBFLAG) -DPRK_TBB_PARTITIONER=$(PRK_TBB_PARTITIONER)
CBLASFLAGS = $(CBLASFLAG) $(OPENMPFLAG)
BOOSTFLAGS = $(BOOSTFLAG)
RANGEFLAGS = $(RANGEFLAG) -DUSE_RANGES
# add Boost for transform + zip_iterator
STLFLAGS = $(STLFLAG) $(RANGEFLAGS) $(BOOSTFLAGS)
PSTLFLAGS = $(PSTLFLAG) $(RANGEFLAGS)
EXECUTORSFLAGS = $(EXECUTORSFLAG) $(PSTLFLAGS) #$(RANGEFLAGS)
RAJAFLAGS = $(RAJAFLAG)
THRUSTFLAGS = $(THRUSTFLAG) $(RANGEFLAGS)
KOKKOSFLAGS = $(KOKKOSFLAG) $(KOKKOS_BACKEND_FLAG)
SYCLFLAGS = $(SYCLFLAG)
ORNLACCFLAGS = $(ORNLACCFLAG)

ifdef OCCADIR
  include ${OCCADIR}/scripts/makefile
endif
OCCAFLAGS = -I${OCCADIR}/include -Wl,-rpath -Wl,${OCCADIR}/lib -L${OCCADIR}/lib -locca

.PHONY: all clean vector valarray openmp target opencl taskloop tbb stl pstl \
	rangefor kokkos raja cuda cublas sycl dpcpp \
	boost-compute thrust executor oneapi onemkl

EXTRA=
ifeq ($(shell uname -s),Darwin)
  ifneq ($(findstring icpc,$(CXX)),icpc)
    EXTRA += target
  endif
else
  EXTRA += target
endif
ifneq ($(findstring pgc++,$(CXX)),pgc++)
  EXTRA += pstl
endif

all: sequential vector valarray openmp taskloop stl rangefor opencl sycl $(EXTRA)

sequential: p2p stencil transpose nstream dgemm sparse

vector: p2p-vector p2p-hyperplane-vector stencil-vector transpose-vector nstream-vector sparse-vector dgemm-vector \
	transpose-async transpose-thread

valarray: transpose-valarray nstream-valarray

openmp: p2p-hyperplane-openmp p2p-tasks-openmp stencil-openmp transpose-openmp nstream-openmp

target: stencil-openmp-target transpose-openmp-target nstream-openmp-target

taskloop: stencil-taskloop transpose-taskloop nstream-taskloop

mpi: nstream-mpi stencil-mpi

opencl: p2p-innerloop-opencl stencil-opencl transpose-opencl nstream-opencl

sycl: nstream-sycl nstream-sycl-explicit p2p-hyperplane-sycl stencil-sycl transpose-sycl pic-sycl \
      stencil-2d-sycl transpose-2d-sycl pic-sycl \
      nstream-sycl-usm nstream-sycl-explicit-usm stencil-sycl-usm transpose-sycl-usm

dpcpp: sycl nstream-dpcpp nstream-multigpu-dpcpp transpose-dpcpp

tbb: p2p-innerloop-tbb p2p-tbb stencil-tbb transpose-tbb nstream-tbb \
     p2p-hyperplane-tbb p2p-tasks-tbb

stl: stencil-stl transpose-stl nstream-stl

pstl: stencil-pstl transpose-pstl nstream-pstl

rangefor: stencil-rangefor transpose-rangefor nstream-rangefor

executors: nstream-executors transpose-executors

kokkos: stencil-kokkos transpose-kokkos nstream-kokkos

raja: p2p-raja stencil-raja nstream-raja \
      p2p-raja transpose-raja nstream-raja stencil-raja # transpose-raja

cuda: stencil-cuda transpose-cuda nstream-cuda nstream-managed-cuda

hip: nstream-hip transpose-hip stencil-hip nstream-managed-hip

hipstl: nstream-hipstl

hipblas: nstream-hipblas dgemm-hipblas

thrust: nstream-host-thrust nstream-device-thrust \
        transpose-host-thrust transpose-device-thrust

cublas: transpose-cublas nstream-cublas dgemm-cublas dgemm-multigpu-cublas dgemm-mpi-cublas

cblas: transpose-cblas dgemm-cblas

onemkl: nstream-onemkl dgemm-onemkl dgemm-multigpu-onemkl

oneapi: onemkl dpcpp sycl

occa: transpose-occa nstream-occa

ornlacc: p2p-hyperplane-ornlacc

boost-compute: nstream-boost-compute
# busted
#nstream-valarray-boost-compute

p2p-hyperplane-vector: p2p-hyperplane-openmp.cc prk_util.h
	$(CXX) $(CXXFLAGS) $< -o $@

#transpose-opencl: transpose-opencl.cc transpose.cl prk_util.h prk_opencl.h
#	$(CXX) $(CXXFLAGS) $< $(OPENCLFLAGS) -o $@

#nstream-opencl: nstream-opencl.cc nstream.cl prk_util.h prk_opencl.h
#	$(CXX) $(CXXFLAGS) $< $(OPENCLFLAGS) -o $@

%-mpi: %-mpi.cc prk_util.h prk_mpi.h
	$(CXX) $(CXXFLAGS) $(MPIINC) $< $(MPILIB) -o $@

%-mpi: %-mpi.cc prk_util.h prk_mpi.h
	$(CXX) $(CXXFLAGS) $(MPIINC) $< $(MPILIB) -o $@

%-opencl: %-opencl.cc prk_util.h prk_opencl.h
	$(CXX) $(CXXFLAGS) $< $(OPENCLFLAGS) -o $@

%-celerity: %-celerity.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $(BOOSTFLAGS) $(CELERITYINC) $(MPIINC) $< $(CELERITYLIB) $(MPILIB) -o $@

pic: pic.cc prk_util.h random_draw.o
	$(CXX) $(CXXFLAGS) $< random_draw.o -o $@

pic-sycl: pic-sycl.cc prk_util.h prk_sycl.h random_draw.o
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< random_draw.o -o $@

random_draw.o: random_draw.c random_draw.h
	$(CC) $(DEFAULT_OPT_FLAGS) $(CPPFLAGS) -c $< -o $@

%-dpcpp: %-dpcpp.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< -o $@

%-sycl: %-sycl.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< -o $@

%-sycl-explicit-usm: %-sycl-explicit-usm.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< -o $@

%-sycl-usm: %-sycl-usm.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< -o $@

%-sycl-explicit: %-sycl-explicit.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< -o $@

%-onemkl: %-onemkl.cc prk_util.h prk_sycl.h
	$(SYCLCXX) $(CPPFLAGS) $(SYCLFLAGS) $< $(ONEMKLFLAG) -o $@

%-target: %-target.cc prk_util.h prk_openmp.h
	$(CXX) $(CXXFLAGS) $< $(OMPFLAGS) $(TARGETFLAGS) -o $@

%-openmp: %-openmp.cc prk_util.h prk_openmp.h
	$(CXX) $(CXXFLAGS) $< $(OMPFLAGS) -o $@

%-taskloop: %-taskloop.cc prk_util.h prk_openmp.h
	$(CXX) $(CXXFLAGS) $< $(OMPFLAGS) -o $@

%-tbb: %-tbb.cc prk_util.h prk_tbb.h
	$(info PRK help: Consider setting USE_PRK_TBB_PARTITIONER={static,affinity,simple} when invoking make)
	$(CXX) $(CXXFLAGS) $< $(TBBFLAGS) -o $@

%-stl: %-stl.cc prk_util.h prk_pstl.h
	$(CXX) $(CXXFLAGS) $< $(STLFLAGS) -o $@

#%-stl: %-pstl.cc prk_util.h prk_pstl.h
#	$(CXX) $(CXXFLAGS) $< $(STLFLAGS) -o $@

%-pstl: %-pstl.cc prk_util.h prk_pstl.h
	$(CXX) $(CXXFLAGS) $< $(PSTLFLAGS) -o $@

%-rangefor: %-rangefor.cc prk_util.h prk_ranges.h
	$(CXX) $(CXXFLAGS) $< $(RANGEFLAGS) -o $@

%-executors: %-executors.cc prk_util.h prk_executors.h
	$(CXX) $(CXXFLAGS) $< $(EXECUTORSFLAGS) -o $@

%-boost-compute: %-boost-compute.cc prk_util.h prk_opencl.h
	$(CXX) $(CXXFLAGS) $< $(BOOSTFLAGS) $(OPENCLFLAGS) -o $@

%-raja: %-raja.cc prk_util.h prk_raja.h
	$(CXX) $(CXXFLAGS) $< $(RAJAFLAGS) -o $@

ifeq ($(PRK_KOKKOS_BACKEND),Cuda)
%-kokkos: %-kokkos.cc prk_util.h prk_kokkos.h
	${KOKKOSDIR}/bin/nvcc_wrapper $(CPPFLAGS) $(CUDAFLAGS) $< $(KOKKOSFLAG) -DPRK_KOKKOS_BACKEND=Cuda -o $@
else
%-kokkos: %-kokkos.cc prk_util.h prk_kokkos.h
	$(info PRK help: Set USE_PRK_KOKKOS_BACKEND={Threads,Serial,Cuda} when invoking make to not use OpenMP)
	$(CXX) $(CXXFLAGS) $< $(KOKKOSFLAGS) -o $@
endif

# for host execution
%-thrust: %-thrust.cc prk_util.h prk_thrust.h
	$(CXX) $(CXXFLAGS) $< $(THRUSTFLAGS) -o $@

# for device execution (must compiler as .cu)
%-thrust: %-thrust.cu prk_util.h prk_thrust.h
	$(NVCC) $(CUDAFLAGS) $(CPPFLAGS) $< $(THRUSTFLAGS) -o $@

%-cuda: %-cuda.cu prk_util.h prk_cuda.h
	$(NVCC) $(CUDAFLAGS) $(CPPFLAGS) $< -o $@

%-mpi-cublas: %-mpi-cublas.cu prk_util.h prk_cuda.h prk_mpi.h
	$(NVCC) $(CUDAFLAGS) $(CPPFLAGS) $(MPIINC) -DPRK_USE_CUBLAS $< -lcublas $(MPILIB) -o $@

%-cublas: %-cublas.cu prk_util.h prk_cuda.h
	$(NVCC) $(CUDAFLAGS) $(CPPFLAGS) -DPRK_USE_CUBLAS $< -lcublas -o $@

%-hip: %-hip.cc prk_util.h prk_hip.h
	$(HIPCC) $(HIPFLAGS) $(CPPFLAGS) $< -o $@

%-hipstl: %-hipstl.cc prk_util.h prk_hip.h
	$(HIPCC) $(HIPFLAGS) $(RANGEFLAGS) $(CPPFLAGS) -DHIP_THRUST $< -o $@

%-hipblas: %-hipblas.cc prk_util.h prk_hip.h
	$(HIPCC) $(HIPFLAGS) $(CPPFLAGS) $< -o $@

%-cblas: %-cblas.cc prk_util.h
	$(CXX) $(CXXFLAGS) $< $(CBLASFLAGS) -o $@

%-occa: %-occa.cc prk_util.h
	$(info PRK help: Set OCCA_CXX=$(firstword $(CXX)) to use that compiler for OKL files.)
	$(CXX) $(CXXFLAGS) $< $(OCCAFLAGS) -o $@

%-ornlacc: %-ornlacc.cc prk_util.h
	$(CXX) $(CXXFLAGS) $< $(ORNLACCFLAGS) -o $@

%: %.cc prk_util.h
	$(CXX) $(CXXFLAGS) $< -o $@

%-raja.s: %-raja.cc prk_util.h
	$(CXX) $(CXXFLAGS) $(ASMFLAGS) -S $< $(RAJAFLAGS) -o $@

%.s: %.cc prk_util.h
	$(CXX) $(CXXFLAGS) $(ASMFLAGS) -S $< -o $@

clean:
	-rm -f *.o
	-rm -f *.s
	-rm -f *.ll # Coriander
	-rm -f pgipar* # PGI?
	-rm -f *.optrpt
	-rm -f *.dwarf
	-rm -rf *.dSYM # Mac
	-rm -f nstream transpose stencil p2p sparse dgemm
	-rm -f *-vector
	-rm -f *-valarray
	-rm -f *-openmp
	-rm -f *-target
	-rm -f *-taskloop
	-rm -f *-mpi
	-rm -f *-opencl
	-rm -f *-sycl
	-rm -f *-sycl-usm
	-rm -f *-sycl-explicit
	-rm -f *-sycl-explicit-usm
	-rm -f *-dpct
	-rm -f *-dpcpp
	-rm -f *-celerity
	-rm -f *-tbb
	-rm -f *-stl
	-rm -f *-pstl
	-rm -f *-rangefor
	-rm -f *-raja
	-rm -f *-kokkos
	-rm -f *-thrust
	-rm -f *-cuda
	-rm -f *-cublas
	-rm -f *-hip
	-rm -f *-hipblas
	-rm -f *-cblas
	-rm -f *-onemkl
	-rm -f *-occa
	-rm -f *-boost-compute
	-rm -f *-ornlacc
	-rm -f transpose-async transpose-thread

cleancl:
	-rm -f star[123456789].cl
	-rm -f grid[123456789].cl
