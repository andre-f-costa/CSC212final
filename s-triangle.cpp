#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>

void s_triangle(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_base, int count_diagonal);
void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col, int &count_base, int &count_diagonal);

int main(int argc, char** argv){
    int row = atoi(argv[1]); //square grid of odd value, even does not result in triangle
    int col = atoi(argv[2]);    // input 2n x n but make it so that the program acts n x n
    int levels = atoi(argv[3]);
    std::string out_file = argv[4];

    std::vector<std::vector<int>> grid(row, std::vector<int> (col, 0)); // make and empty 2d array size x size of all zeros

    int count_base = 0;      //this will hold the length of the base of the equalateral triangle
    int count_diagonal = 0; //this will hold the length of the diagonals of the equalateral triangle

    set_base_triangle(&grid, row, col, count_base,count_diagonal); // fill in grid with the base level triangle

    std::cout << count_base << " " << count_diagonal << std::endl;

    /*for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

    s_triangle(&grid, (row - (row/2)) - 1, (row/4) - 1, levels, (count_base/2), count_diagonal/2);        //start recursion pass in the mid point of the left diagonal of the tiangle

    std::ofstream outfile (out_file);        //output the file to a .ppm file
    outfile << "P3" << std::endl;
    outfile << row << " " << col << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j]){
                outfile << 0 << " " << grid[i][j]*100 << " " << 0 << " ";
            }
            else{
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
        }
        outfile << std::endl;
    }

    outfile.close();

}

void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col, int &count_base, int &count_diagonal){
    int i = row - 1;
    int j = 0;
    while(i >= 0 && j <= col/2){    //create the left diagonal upward branch of the triangle
        (*grid)[i][j] = 1;
        count_diagonal++;
        if(i > 0){
            (*grid)[i - 1][j] = 1;  //fill out triangle more
        }
        if(j > 0){
            (*grid)[i][j - 1] = 1;
        }
        if(i > 0 && j > 0) {
            (*grid)[i - 1][j - 1] = 1;
        }
        if(j > 1){
            (*grid)[i][j - 2] = 1;
        }
        i -= 2;
        //i--;
        j++;
    }
    i += 4;
    //i += 2;
    while(i < row){                //create the right diagonal downward branch of the triangle
        (*grid)[i][j] = 1;
         if(i > 0){
            (*grid)[i - 1][j] = 1;  //fill out triangle more
        }
        if(j < col - 1){
            (*grid)[i][j + 1] = 1;
        }
        if(i > 0 && j < col - 1) {
            (*grid)[i - 1][j + 1] = 1;
        }
        if(j < col - 2){
            (*grid)[i][j + 2] = 1;
        }
        i += 2;
        //i++;
        j++;
    }
    i = row - 1;
    j = 1;
    while(!(*grid)[i][j]){              //create the base of the triangle
        (*grid)[i][j] = 1;
        j ++;
        count_base++;
    }
    count_base += 2;     // this will account for the two edges already occupied by a 1 on the corners of the equalateral triangle
}

void s_triangle(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_base, int count_diagonal){
    std::cout << count_base << " " << row_start << " " << col_start << std::endl;
    if(levels == 1){
        std::cout << "hello" << std::endl;
        return;
    }
    levels--;
    row_start += 2;             //increment to start at the first 0 point to be filled in
    col_start ++;
    int count = 1;
    int count_temp = count_diagonal;        //this will be used to drive the drawing of the recursive fractal base
    while(count_temp){                //create the diagonal downward branch of the triangle
        (*grid)[row_start][col_start] = 1;

        (*grid)[row_start - 1][col_start] = 1;  //fill out triangle more
        (*grid)[row_start][col_start + 1] = 1;
        (*grid)[row_start - 1][col_start + 1] = 1;
        (*grid)[row_start][col_start + 2] = 1;

        row_start += 2;
        col_start++;
        count++;
        count_temp--;
    }
    count++;
    /*for(int i = 0; i < (*grid).size(); i++){
        for(int j = 0; j < (*grid)[i].size(); j++){
            std::cout << (*grid)[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

    s_triangle(grid,row_start - (count_diagonal + 2), col_start - count_base + (count_base/4), levels, count_base/2, count_diagonal/2);  //start recursion on the lower left of the next level
    count = 1;
    row_start -= 2;
    col_start++;
    count_temp = count_diagonal;
    while(count_temp){                //create the diagonal upward branch of the triangle
        (*grid)[row_start][col_start] = 1;

        (*grid)[row_start - 1][col_start] = 1;  //fill out triangle more
        (*grid)[row_start][col_start - 1] = 1;
        (*grid)[row_start - 1][col_start - 1] = 1;
        (*grid)[row_start][col_start - 2] = 1;

        row_start -= 2;
        col_start++;
        count++;
        count_temp--;
    }
    count++;
    /*for(int i = 0; i < (*grid).size(); i++){
        for(int j = 0; j < (*grid)[i].size(); j++){
            std::cout << (*grid)[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

    s_triangle(grid,row_start + (count_diagonal) , col_start - ((count_base/4) + 2), levels, count_base/2, count_diagonal/2);  // start recursion on the lower right of the next level
    if((*grid)[row_start][col_start]){
        col_start--;
    }
    count = 1;
    count_temp = count_base;
    while(count_temp){                //create the branch across the triangle
        (*grid)[row_start][col_start] = 1;
        col_start--;
        count++;
        count_temp--;
    }
    count++;
    /*for(int i = 0; i < (*grid).size(); i++){
        for(int j = 0; j < (*grid)[i].size(); j++){
            std::cout << (*grid)[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

    s_triangle(grid,row_start - (count_diagonal) + 1, col_start + (count_base/4) , levels, count_base/2, count_diagonal/2);      //start recursion on the upper triangle of the next level
}
