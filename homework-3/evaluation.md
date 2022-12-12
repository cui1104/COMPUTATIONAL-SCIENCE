# Did they follow the guidelines?
1. Are .c files in the “src” directory and .h files in the “include”?
    ```
    Yes=+10
    Total 10/10
    ```
2. There should be appropriately defined header guards in the .h files
     ```
    Yes diag=+5
    Yes trid=+5
    Yes upp=+5
    Total 15/15
    ```
   
3. Memory for each matrix is as specified (e.g., upper triangular is in a continuous chunk)
    ```
    Yes diag=+5
    Yes trid=+5
    Yes upp=+5
    Total 15/15
    ```
   
4. Free all the allocated memory at the end of their driver. This can use direct calls to “free(matrix_type->storage)” or can call a “free_matrixType” function.
     ```
    visually Yes diag=+5
    visuallyYes trid=+5
    visually Yes upp=+5
    valgrind checking shows issues. -=10. See logfile.out line 132-137
    ==30255== LEAK SUMMARY:
    ==30255==    definitely lost: 80 bytes in 4 blocks
    ==30255==    indirectly lost: 0 bytes in 0 blocks
    ==30255==      possibly lost: 0 bytes in 0 blocks
    ==30255==    still reachable: 0 bytes in 0 blocks
    ==30255==         suppressed: 0 bytes in 0 blocks

    Total +=5
      ```
5. Deduct 1-2 points if the student does unnecessary things (like allocate unnecessary memory in the matrix-vector multiplication routines)
    ```

    Total = 15/15
    ```
## Total Section

```
Total=60/70
```   
# Does it work?
 1. Does “make” build correctly?
     ```
    yes+=4
    ```
 2. Do the drivers run?
    ```
    yes main =+2/4  
    yes verify=+2/4 
    Total = 4/4
    ```
 3. Do they initialize the copy correctly
    ```

    Yes=+4/4
    ```
 4. For main.c, does the printout look correct for the matrix and matrix-vector product?
    ```
   yes =+4/4
    ```
 5. For verify_and_time.c (this is also in the writeup) do they test the correct things (100 samples of matvec runtime) and get reasonable results for Diagonal and Tridiagonal Matrix types (e.g., faster than marvel the dense Matrix type)
    ```
    yes but matrix type time is different. Do you run it 3 times?-1 =+3/4
    ```
 ## Total Section

```
Total=19/20
```   

# PDF and github
1. PDF
 ```
    yes=+5/5
```
2. Github (tag, etc...)
 ```
 yes=+5/5, 

 ```
  ## Total Section

```
Total=10/10
```   

# Total Section
```
Total=89/100