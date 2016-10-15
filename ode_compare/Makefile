exe: main.o fortran_sub.o
	g++ c_main.o fortran_sub.o -o exe

DLSODA.o: DLSODA.F
	gfortran -c DLSODA.F
	
fortran_sub.o: fortran_sub.f90
	gfortran -c fortran_sub.f90

main.o: main.cpp
	g++ -c c_main.cpp
