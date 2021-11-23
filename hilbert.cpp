#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>

void orientation(std::vector<int> &ori, int start, int size){
    if(size == 1){
        return;
    }
    int temp = size/4;
    for(int i = start; i < temp; i++){
        ori[i] = ori[i]-1;
    }
    for(int i = temp; i < 2*temp; i++){
        ori[i] = ori[i]+1;
    }
    orientation(ori, 0, temp);
    orientation(ori, temp, temp);
    orientation(ori, 2*temp, temp);
    orientation(ori, 3*temp, temp);
}

void hilbert(std::vector<std::vector<int>> &array, int size, int iterations){
    int NumOfBoxes;
    if(iterations == 2){
        NumOfBoxes = 2;
    }
    else if(iterations > 2){
        NumOfBoxes = pow(2,(iterations-1));
    }
    else{
        NumOfBoxes = 1;
    }
    std::vector<int> ori (NumOfBoxes,0);
    orientation(ori, 0, NumOfBoxes);
    std::cout << NumOfBoxes << std::endl;
    int smallsize = size/NumOfBoxes;
    int distance = (smallsize-2)/4; // Distances into the box
    int leftin = distance+1; // Left start point
    int rightin = 3*distance+1; // Right start point
    int basein = 3*distance+1;
    int counter = 0;
    for(int a = 0; a < NumOfBoxes; a++){
        for(int b = 0; b < NumOfBoxes; b++){
            for(int i = distance; i <= basein; i++){
                array[i+b*smallsize][rightin+a*smallsize] = 1; // Rigth line
                array[i+b*smallsize][leftin+a*smallsize] = 1;  // Left Line
            }
            for(int j = leftin; j <= rightin; j++){
                array[basein+a*smallsize][j+b*smallsize] = 1;     // Bottom Line
                array[(basein/3)+a*smallsize][j+b*smallsize] = 1; // Top Line
            }
            counter++;
        }
    }
    
    
    
    /*if(iterations == 1){
        int distance = (size-2)/4; // Set the distances from the sides of the square
        int leftin = distance+1+starthoriz; // Left start point
        int rightin = 3*distance+1+starthoriz; // Right start point
        // Vertical sides
        for(int i = distance+1; i <= size-distance-1; i++){
            if(quad == 1){
                array[rightin][i+startvert] = 1;
                array[leftin][i+startvert] = 1;
            }
            else if(quad == 2){
                array[rightin-starthoriz][i+startvert+starthoriz] = 1;
                array[leftin-starthoriz][i+startvert+starthoriz] = 1;
            }
            else{
                array[i+startvert][rightin] = 1;
                array[i+startvert][leftin] = 1;
            }
        }
        // Horizontal base
        for(int i = leftin; i <= rightin; i++){
            if(quad == 1){
                array[i][size-distance-1+startvert] = 1;
            }
            else if(quad == 2){
                array[i-size][starthoriz+distance-1] = 1;
            }
            else{
                array[size-distance-1+startvert][i] = 1;
            }
        }
    }
    else{
        hilbert(array, size/2, iterations-1, 0, 0, 1);
        hilbert(array, size/2, iterations-1, size/2, 0, 2);
        hilbert(array, size/2, iterations-1, 0, size/2, 3);
        hilbert(array, size/2, iterations-1, size/2, size/2, 4);
    }*/
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
    hilbert(map, size, iterations);

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