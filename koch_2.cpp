#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

void WriteFile(std::string file_name, std::vector<std::vector<int>> * const image_data){
    // Opens the outfile file, prepares it for writing
    std::ofstream output_file(file_name);

    // Loop rows
    for(unsigned int i = 0; i < image_data->size(); i++){
        // Loop columns
        for(unsigned int j = 0; j < image_data[0][0].size(); j++){
            // Output each value and a space
            output_file << (*image_data)[i][j] << " ";
        }
        // Output a newline character after every row
        output_file << "\n";
    }
}

void drawlow(vector<vector<int>>* img, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0; 
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        (*img)[y][x] = 1;
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        } 
        else {
            D = D + 2 * dy; 
        }
    }
    return;
}

void drawhigh(vector<vector<int>>* img, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0; 
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;
    for (int y = y0; y <= y1; y++) {
        (*img)[y][x] = 1; 
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } 
        else {
            D = D + 2 * dx; 
        }
    }
    return;
}

void draw(vector<vector<int>>* img, int x0, int y0, int x1, int y1) {
    if (abs(y1-y0) < abs(x1-x0)) {
        if (x0 > x1) {
            drawlow(&(*img), x1, y1, x0, y0);
        }
        else {
            drawlow(&(*img), x0, y0, x1, y1);
        }
    }
    else {
        if (y0 > y1) {
            drawhigh(&(*img), x1, y1, x0, y0);
        }
        else {
            drawhigh(&(*img), x0, y0, x1, y1);
        }
    }
    return;
}

void koch(int x0, int y0, int x1, int y1, double level, int size, vector<vector<int>>* img, double angle) {  
    if (level == 0) {
        cout << x0  << ", " << y0  << ", "  << x1  << ", "  << y1 << endl;
        draw(&(*img), x0, y0, x1, y1);
        return; 
    }

    int length = sqrt(pow((x0-x1), 2) + pow((y0-y1), 2))/3; 
    level -= 1;

    int dx = abs(x0 - x1);
    int dy = abs(y0 - y1); 

    //first segment
    koch(x0, y0, dx/3+x0, dy/3+y0, level, size, &(*img), angle);

    //second segment
    koch(dx/3+x0, dy/3+y0, dx/3+x0 + length * cos(angle), dy/3+y0 - length * sin(angle), level, size, &(*img), angle + M_PI/3);
    //third segment
    //koch((2 * dx)/3+x0, (2 * dy)/3+y0, (2 * dx)/3+x0 - length * cos(M_PI - angle), (2 * dy)/3+y0 - length * sin(M_PI - angle), level, size, &(*img), angle);

    //fourth segment
    koch((2 * dx)/3+x0, (2 * dy)/3+y0, x1, y1, level, size, &(*img), angle);

    return;
}

int main (int argc, char *argv[]){
    std::string fname = argv[1];
    int size = (int)atoi (argv[2]);
    int level = (int)atoi (argv[3]);

    vector<vector<int>> img(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            img[i][j] = 0;
        }
    }

    koch(0, 99, 99, 99, level, size, &img, (M_PI/3));

    WriteFile(fname, &img);
}
