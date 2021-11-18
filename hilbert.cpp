#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>

void hilbert(std::vector<std::vector<int>> &array, int size, int iterations, int starthoriz, int startvert){
    if(iterations == 1){
        int distance = (size-2)/3; // Set the distances from the sides of the square
        int leftin = distance+1+starthoriz; // Left start point
        int rightin = size-distance-1+starthoriz; // Right start point
        // Vertical sides
        for(int i = distance+1; i <= size-distance-1; i++){
            array[i+startvert][rightin] = 1;
            array[i+startvert][leftin] = 1;
        }
        // Horizontal base
        for(int i = leftin; i <= rightin; i++){
            array[size-distance-1+startvert][i] = 1;
        }
    }
    else{
        hilbert(array, size/2, iterations-1, 0, 0);
        hilbert(array, size/2, iterations-1, size/2, 0);
        hilbert(array, size/2, iterations-1, 0, size/2);
        hilbert(array, size/2, iterations-1, size/2, size/2);
    }
}


int main(int argc, char** argv){
    // Input parameters
    // Input should be in format "filename.ppm size iteratons"
    std::string out_fname = argv[1]; // Get the output file name
    int size = atoi(argv[2]), iterations = atoi(argv[3]); // Set length and width of the output

    // Prevent size being too large
    if(size > 10000){
        std::cout << "Size is too large, try again with a value <= 10,000!" << std::endl;
        return 0;
    }
    
    std::vector<std::vector<int>> map (size, (std::vector<int> (size,0))); // Create a square array filled with 0's
    hilbert(map, size, iterations, 0, 0);

    // File output generation
    std::ofstream outfile (out_fname);
    outfile << "P3" << std::endl;
    outfile << size << " " << size << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < size; i++){
        for(int j = 0; j < size; j++){
            outfile << map[i][j]*100 << " " << 0 << " " << 0 << " "; 
        }
        outfile << std::endl;
    }

    outfile.close();
    
    //TEST TO OUTPUT 2D VECTOR
    /*for(double i=0; i < complete.size(); i++){
    for(double j = 0; j < complete[i].size(); j++){
        std::cout << complete[i][j] <<" ";
    }
        std::cout << std::endl;
    }*/
    
    return 0;
}