subroutine ode_for(n, x, y) bind(C)
	use iso_c_binding
	implicit none
	integer(c_int) :: n
	real(c_double) :: x(n), y(n)
	
	! --------- declare parameters for subroutine DLSODA
    integer, dimension(1) :: NEQ
    real*8 :: T, TOUT
    real*8 :: Z(2)
    integer, parameter :: ITOL = 2
    real*8 :: RTOL(1:8), ATOL(1:8)
    integer :: ITASK, IOPT, LRW, LIW, JT, ISTATE
    real*8, dimension(:), allocatable :: RWORK
    integer, dimension(:), allocatable :: IWORK
	
	! -------- other
	integer :: i
    
! ------------- set parameters
    NEQ = 2
    ISTATE = 1
    T = 0.
    
    RTOL = 1.D-6
    ATOL = 1.D-6
    
    ! please refer to DLSODA.f
    ITASK = 1
    IOPT = 0
    LRW = 250 ! size of RWORK
    LIW = 40 ! size of IWORK
    JT = 2
    allocate(RWORK(1:LRW))
    allocate(IWORK(1:LIW))
    IWORK(5:10) = 0  
    RWORK(5:10) = 0. 
	
	do i=1,n
		Z(1) = x(i)
		Z(2) = y(i)
		T = 0.
		TOUT = 100.
		call DLSODA(FEX,NEQ,Z,T,TOUT,ITOL,RTOL,ATOL,ITASK,ISTATE,IOPT,RWORK,LRW,IWORK,LIW,FEX,JT)
		x(i) = Z(1)
		y(i) = Z(2)
	enddo
	
	contains
	
	subroutine FEX (NEQ, T, Y, YDOT)
		implicit none
		integer :: NEQ
		real*8 :: T, Y(NEQ), YDOT(NEQ)
		YDOT(1) = cos(Y(1))
		YDOT(2) = Y(1) + Y(2)*Y(2)
	end subroutine
	
end subroutine
	