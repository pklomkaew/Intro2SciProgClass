        program primenums ! Find all prime numbers < 100

        implicit none

        integer :: num, possible_divisor, divisor

        outsideloop: do num = 2, 100

                possible_divisor = 1
                divisor = 0

                insideloop: do
                        
                        if (mod(num, possible_divisor) == 0) then
                                divisor = divisor + 1                
                        end if

                        if (possible_divisor == num) then
                                exit
                        end if

                        possible_divisor = possible_divisor + 1

                end do insideloop

                if (divisor == 2) then
                        print *, num, " is prime"
                else
                        print *, num, " is not prime: it is divisible &
                                by ", possible_divisor
                end if
        
        end do outsideloop

        end program 
