       program collatz

       implicit none

       integer :: u1, u0, length, max_length, umax

       umax = 0
       max_length = 0

       outerloop: do u0 = 1, 1000
       
       length = 0
       u1 = u0

       innerloop: do
          if (u1 == 1) then
             exit
          end if

          ! if even:
          if (mod(u1,2) == 0) then
             u1 = u1/2
          else 
          ! elseif odd:
             u1 = 3*u1 + 1
          end if
        
         length = length + 1
 
         !print *, "length = ", length
         !print *, "u1 = ", u1

       end do innerloop

       if (length > max_length) then
           max_length = length
           umax = u0
       end if

       end do outerloop

       print *, umax, max_length
       
       end program
