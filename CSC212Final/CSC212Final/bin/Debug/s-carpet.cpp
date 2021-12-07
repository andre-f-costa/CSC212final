#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>

void s_carpet(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_size, int level_count, std::vector<std::vector<int>> * level);

int main(int argc, char** argv){
    int size = atoi(argv[1]);
    int levels = atoi(argv[2]);
    std::string out_file = argv[3];

    std::vector<std::vector<int>> grid(size, std::vector<int> (size, 0)); // make and empty 2d array size x size of all zeros

    std::vector<std::vector<int>> level(size, std::vector<int> (size, 1));    //array to have a different color for each level

    int count_size = size/3;    //finds the size of the first square on the carpet

    int level_count = 1;

    int row_start = size/2;     //gives midpoint of first square
    int col_start = size/2;
    //s_triangle divides count_base and count_diagonal to keep the length of the next recursive triangle which will be half the size of the previous one.
    //s_triangle(&grid, (row - (row/2)) - 1, (row/4) - 1, levels, (count_base/2), count_diagonal/2, level_count, &level);        //start recursion pass in the mid point of the left diagonal of the triangle
    s_carpet(&grid, row_start, col_start, levels, count_size, level_count, &level);        //start recursion pass in the mid point of the left diagonal of the triangle
    std::ofstream outfile (out_file);        //output the file to a .ppm file
    outfile << "P3" << std::endl;
    outfile << size << " " << size << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j]){
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
            else{
                outfile << 0 << " " << 0 << " " << 0 << " ";
            }
        }
        outfile << std::endl;
    }

    outfile.close();

}

void s_carpet(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_size, int level_count, std::vector<std::vector<int>> * level){

    if(level_count == levels){
        return;
    }

    level_count ++;

    //recursivley go to all the next carpet spots
    s_carpet(grid,row_start, col_start - count_size, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start - count_size, col_start, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start, col_start + count_size, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start + count_size, col_start, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start - count_size, col_start - count_size, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start + count_size, col_start - count_size, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start - count_size, col_start + count_size, levels, count_size/3, level_count, level);
    s_carpet(grid,row_start + count_size, col_start + count_size, levels, count_size/3, level_count, level);


    row_start -= (count_size/2);     //start at the beginning of the block of carpet
    col_start -= (count_size/2);
    int col_start_hold = col_start; //allows me to reset col_start to the correct spot each loop

    for(int i = 0; i < count_size; i++){
        col_start = col_start_hold;
        for(int j = 0; j < count_size; j++){
            (*grid)[row_start][col_start] = 1;
            (*level)[row_start][col_start] = level_count;
            col_start++;
        }
        row_start++;
    }
}