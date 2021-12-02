#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>

void s_triangle(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_base, int count_diagonal, int level_count, std::vector<std::vector<int>> * level, int base_row, int base_col);
void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col, int &count_base, int &count_diagonal, std::vector<std::vector<int>> * level);

int main(int argc, char** argv){
    int row = atoi(argv[1]); //square grid of odd value, has to be certain grid size in order for the triangle to be equalateral
    int col = atoi(argv[2]);    // some useable sizes are 949 x 949 , 2453 x 2453 , 5485 x 5485(takes a long time)
    int levels = atoi(argv[3]);
    std::string out_file = argv[4];

    std::vector<std::vector<int>> grid(row, std::vector<int> (col, 0)); // make and empty 2d array size x size of all zeros

    std::vector<std::vector<int>> level(row, std::vector<int> (col, 0));    //array to have a different color for each level

    int count_base = 0;      //this will hold the length of the base of the equalateral triangle
    int count_diagonal = 0; //this will hold the length of the diagonals of the equalateral triangle
    int base_row = 0;       //this will hold the base location row of the new triangle
    int base_col = 0;       //this will hold the base location col of the new triangle

    set_base_triangle(&grid, row, col, count_base,count_diagonal, &level); // fill in grid with the base level triangle

    //std::cout << count_base << " " << count_diagonal << std::endl;

    /*for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;*/

    int level_count = 1;
    base_row = row/2;
    base_col = row/4;
    //s_triangle divides count_base and count_diagonal to keep the length of the next recursive triangle which will be half the size of the previous one.
    //s_triangle(&grid, (row - (row/2)) - 1, (row/4) - 1, levels, (count_base/2), count_diagonal/2, level_count, &level);        //start recursion pass in the mid point of the left diagonal of the triangle
    s_triangle(&grid, row/2, row/4, levels, (count_base/2), count_diagonal/2, level_count, &level, base_row, base_col);        //start recursion pass in the mid point of the left diagonal of the triangle
    std::ofstream outfile (out_file);        //output the file to a .ppm file
    outfile << "P3" << std::endl;
    outfile << row << " " << col << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j]){
                if(level[i][j] < 3){
                   outfile << grid[i][j]*level[i][j]*100 << " " << 0 << " " << 0 << " ";
                }
                else if(level[i][j] < 6){
                    int level_num = level[i][j]/3;
                    outfile << 0 << " " << grid[i][j]*level_num*100 << " " << 0 << " ";
                }
                else if(level[i][j] < 9){
                    int level_num = level[i][j]/3;
                    outfile << 0 << " " << 0 << " " << grid[i][j]*level_num*100 << " ";
                }
                else{
                    outfile << 0 << " " << grid[i][j]*255 << " " << 0 << " ";
                }
            }
            else{
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
        }
        outfile << std::endl;
    }

    outfile.close();

}

void set_base_triangle(std::vector<std::vector<int>> * grid, int row, int col, int &count_base, int &count_diagonal, std::vector<std::vector<int>> * level){
    int i = row - 1;
    int j = 0;
    while(i >= 0 && j <= col/2){    //create the left diagonal upward branch of the triangle
        (*grid)[i][j] = 1;          //grid = 1 sets up triangle
        (*level)[i][j] = 1;         //level sets up what level of the triangle it is
        count_diagonal++;
        if(i > 0){
            (*grid)[i - 1][j] = 1;  //fill out triangle more
            (*level)[i - 1][j] = 1;
        }
        if(j > 0){
            (*grid)[i][j - 1] = 1;
            (*level)[i][j - 1] = 1;
        }
        if(i > 0 && j > 0) {
            (*grid)[i - 1][j - 1] = 1;
            (*level)[i - 1][j - 1] = 1;
        }
        if(j > 1){
            (*grid)[i][j - 2] = 1;
            (*level)[i][j - 2] = 1;
        }
        i -= 2;
        //i--;
        j++;
    }
    i += 4;
    //i += 2;
    while(i < row){                //create the right diagonal downward branch of the triangle
        (*grid)[i][j] = 1;
        (*level)[i][j] = 1;
         if(i > 0){
            (*grid)[i - 1][j] = 1;  //fill out triangle more
            (*level)[i - 1][j] = 1;
        }
        if(j < col - 1){
            (*grid)[i][j + 1] = 1;
            (*level)[i][j + 1] = 1;
        }
        if(i > 0 && j < col - 1) {
            (*grid)[i - 1][j + 1] = 1;
            (*level)[i - 1][j + 1] = 1;
        }
        if(j < col - 2){
            (*grid)[i][j + 2] = 1;
            (*level)[i][j + 2] = 1;
        }
        i += 2;
        //i++;
        j++;
    }
    i = row - 1;
    j = 1;
    while(!(*grid)[i][j]){              //create the base of the triangle
        (*grid)[i][j] = 1;
        (*level)[i][j] = 1;
        j ++;
        count_base++;
    }
    count_base += 2;     // this will account for the two edges already occupied by a 1 on the corners of the equalateral triangle
}

void s_triangle(std::vector<std::vector<int>> * grid, int row_start, int col_start , int levels, int count_base, int count_diagonal, int level_count, std::vector<std::vector<int>> * level, int base_row, int base_col){
    if(level_count == levels){
        return;
    }
    level_count ++;
    row_start += 2;             //increment to start at the first 0 point to be filled in
    col_start ++;
    int count = 1;
    int count_temp = count_diagonal;        //this will be used to drive the drawing of the recursive fractal base
    while(count_temp){                //create the diagonal downward branch of the triangle
        (*grid)[row_start][col_start] = 1;
        (*level)[row_start][col_start] = level_count;

        (*grid)[row_start - 1][col_start] = 1;  //fill out triangle more
        (*level)[row_start - 1][col_start] = level_count;
        (*grid)[row_start][col_start + 1] = 1;
        (*level)[row_start][col_start + 1] = level_count;
        (*grid)[row_start - 1][col_start + 1] = 1;
        (*level)[row_start - 1][col_start + 1] = level_count;
        (*grid)[row_start][col_start + 2] = 1;
        (*level)[row_start][col_start + 2] = level_count;

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

    //start recursion on the lower left of the next level
    s_triangle(grid, base_row + (count_base/2), base_col - (count_base/4), levels, count_base/2, count_diagonal/2, level_count, level, base_row + (count_base/2), base_col - (count_base/4));
    count = 1;
    row_start -= 2;
    col_start++;
    count_temp = count_diagonal;
    while(count_temp){                //create the diagonal upward branch of the triangle
        (*grid)[row_start][col_start] = 1;
        (*level)[row_start][col_start] = level_count;

        (*grid)[row_start - 1][col_start] = 1;  //fill out triangle more
        (*level)[row_start - 1][col_start] = level_count;
        (*grid)[row_start][col_start - 1] = 1;
        (*level)[row_start][col_start - 1] = level_count;
        (*grid)[row_start - 1][col_start - 1] = 1;
        (*level)[row_start - 1][col_start - 1] = level_count;
        (*grid)[row_start][col_start - 2] = 1;
        (*level)[row_start][col_start - 2] = level_count;

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

    // start recursion on the lower right of the next level
    s_triangle(grid, base_row + (count_base/2) , (base_col + (count_base/2) + (count_base/4)), levels, count_base/2, count_diagonal/2, level_count, level, base_row + (count_base/2) , (base_col + (count_base/2) + (count_base/4)));
    if((*grid)[row_start][col_start]){
        col_start--;
    }
    count = 1;
    count_temp = count_base;
    while(count_temp){                //create the branch across the triangle
        (*grid)[row_start][col_start] = 1;
        (*level)[row_start][col_start] = level_count;
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

    //start recursion on the upper triangle of the next level
    s_triangle(grid,base_row - (count_base/2), base_col + (count_base/4) , levels, count_base/2, count_diagonal/2, level_count, level, base_row - (count_base/2), base_col + (count_base/4));

}
