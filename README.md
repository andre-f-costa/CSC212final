# CSC 212 Final Project
## FALL 2021 URI
Recursive imaging.

## Graphical User Interface
### Note
The GUI is an executable, all it needs is that it is in the same folder as the object files for the 4 image types on your C drive. If creating anything besides the Koch
Triangle, you must give an output location for a .ppm file following the linux file format with "/mnt/" at the start.
>Example "/mnt/c/CSC/project/testimages/test.ppm"
>
The above would create a file called "test.ppm" inside of the testimages folder. 

## Hilbert curves
### Note
On when calling hilbert, call with output file name, size and number of iterations. Hilbert has a maximum output size of 10,000x10,000.
>Example: "./hilbert testoutput.ppm 1000 3"
>
The above call will create a file called testoutput.ppm, of size 1000x1000 with 3 iterations of the hilbert curve.

## Koch triangle
### Note 
When running, run with Clmg.h and Cturtle in the same folder. To run, use powershell and enter the following command:
>g++ koch.cpp -o koch -mwindows
>
That is all! 

## Sierpinski triangle
### Note
When calling s-triangle, the max number of levels run should be 9 and the size inputted should be between 2500x2500 and 4000x4000.
>Example: "./s-triangle 3000 3000 8 testfile.ppm"
>
The example above shows how to run the compiled code the parameters are, the file, rows, cols, levels of recursion, and output file.
>
When compiling just make sure to compile s-triangle.cpp and name the object file s-triangle.

## Sierpinski carpet
### Note
When calling s-carpet, keep the size below 5000x5000 and the levels of recursion at a max 7 levels
>Example: "./s-triangle 3000 5 testfile.ppm"
>
The example above shows how to run the compiled code the parameters are, the file, size, levels of recursion, and output file.
>
When compiling just make sure to compile s-carpet.cpp and name the object file s-carpet.
