exe: c_main.o fortran_sub.o
	gfortran c_main.o fortran_sub.o -lstdc++ -o exe

fortran_sub.o: fortran_sub.f90
	gfortran -c fortran_sub.f90

c_main.o: c_main.cpp c_header.h
	g++ -c c_main.cpp
