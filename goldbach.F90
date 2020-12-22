        module PrimeNumbers
        implicit none
        
        integer :: num, n, possible_divisor, root
        
        contains
        
        logical function IsPrime(n)
                integer :: n, possible_divisor, root
                
                root = sqrt(real(n)) + 1
                
                if ((n == 1) .or. (mod(n, 2) == 0)) then
                        IsPrime = .false.
                else
                        IsPrime = .true.
                        do possible_divisor = 3, root                
                                if (mod(n, possible_divisor) == 0) then
                                        IsPrime = .false.
                                        exit
                                end if
                        end do
                end if

        end function IsPrime

        
        integer function NextPrime(num)
                integer :: n, num
                n = num

                infiniteloop: do
                        n = n + 1
                        if (IsPrime(n) == .True.) then
                                NextPrime = n
                                exit
                        end if
                end do infiniteloop

        end function NextPrime

        end module PrimeNumbers

 

        program goldbach_triple
        use PrimeNumbers
        implicit none
        integer :: p, q, r, diff, i
        
        ! print *, "r = q + (q-p)"
        i = 1
        p = 5
        print *, 'i,', 'p,','q,','r,','q-p'

        outerloop: do while (i <= 10000)
                q = NextPrime(p)

                innerloop: do 
                        diff = q - p 
                        r = q + diff
                
                        if (IsPrime(r) == .True.) then
                                print *, i ,',' ,p,',',q,',', r,',', diff
                                exit innerloop
                        else
                                q = NextPrime(q)
                        end if
                end do innerloop
        
                p = NextPrime(p)
                i = i + 1

        end do outerloop

        end program 
