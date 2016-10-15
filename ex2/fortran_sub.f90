
      subroutine matmulvec(A, M, N, B, C) bind(c)
        use iso_c_binding
        implicit none
        integer(c_int) :: M, N
        real(c_double) :: A(M,N), B(N,1), C(M,1)

        C = matmul(A, B)

      end subroutine 
