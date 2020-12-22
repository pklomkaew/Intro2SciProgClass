          module righttriangle
          implicit none
          type myRightTriangle
                real :: sideA, sideB, hypotenuse
          end type myRightTriangle


          contains

          subroutine calculateHypotenuse(myTriangle)
                implicit none
                type(myRightTriangle) :: myTriangle

                myTriangle%hypotenuse = sqrt(myTriangle%sideA**2 + &
                        myTriangle%sideB**2)
          end subroutine


          subroutine printTriangle(myTriangle)
                type(myRightTriangle), intent(IN) :: myTriangle

                print *, "mytriangle:", myTriangle%sideA, &
                        myTriangle%sideB, myTriangle%hypotenuse
          end subroutine

          end module righttriangle



          program righttriangleDemo
          use righttriangle

          type(myRightTriangle) :: t
          t%sideA = 3
          t%sideB = 4

          call calculateHypotenuse(t)
          call printTriangle(t)

          end program
