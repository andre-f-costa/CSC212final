#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>

void s_triangle(std::vector<std::vector<int>> * grid, int row, int col , int levels);
void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col);

int main(int argc, char** argv){
    int size = atoi(argv[1]); //square grid of odd value, even does not result in triangle
    int levels = atoi(argv[2]);
    std::string out_file = argv[3];

    std::vector<std::vector<int>> grid(size, std::vector<int> (size, 0)); // make and empty 2d array size x size of all zeros

    set_base_triangle(&grid, (size/2), size); // fill in grid with the base level triangle

    std::ofstream outfile (out_file);        //output the file to a .ppm file
    outfile << "P3" << std::endl;
    outfile << size << " " << size << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j]){
                outfile << grid[i][j]*100 << " " << 0 << " " << 0 << " ";
            }
            else{
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
        }
        outfile << std::endl;
    }

    outfile.close();

    /*for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
}

void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col){
    int i = row - 1;
    int j = 0;
    while(i >= 0 && j <= col/2){    //create the left diagonal upward branch of the triangle
        (*grid)[i][j] = 1;
        //i -= 2;
        i--;
        j++;
    }
    //i += 4;
    i += 2;
    while(i < row){                //create the right diagonal downward branch of the triangle
        (*grid)[i][j] = 1;
        //i += 2;
        i++;
        j++;
    }
    i = row - 1;
    j = 1;
    while(!(*grid)[i][j]){              //create the base of the triangle
        (*grid)[i][j] = 1;
        j ++;
    }
}
