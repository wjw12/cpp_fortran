subroutine test_sub(fl, db, cp) bind(C)
    use iso_c_binding
    implicit none
    real (C_FLOAT) :: fl
    real (C_DOUBLE) :: db
    complex (C_DOUBLE_COMPLEX) :: cp
    
    fl = fl + 1.
    
    db = db + cos(dble(fl))
    
    cp = cp*2
    
    return
    
    
end subroutine
