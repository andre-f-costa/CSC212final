#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>

void orientation(std::vector<int> &ori, int start, int size){
    //std::cout << size << std::endl;
    int temp = size/4;
    if(size == 1){
        return;
    }
    else{
        for(int i = start; i < start+temp; i++){
            ori[i] = ori[i]+3;
        }
        for(int i = temp; i < start+2*temp; i++){
            ori[i] = ori[i]+1;
        }
        orientation(ori, 0, temp);
        orientation(ori, temp, temp);
        orientation(ori, 2*temp, temp);
        orientation(ori, 3*temp, temp);
        return;
    }
}

void orientat(std::vector<std::vector<int>> &array1, int size2, int rotation, int startX, int startY){
    int temp = size2/2;
    if(size2 == 1){
        return;
    }
    
    //Test to output
    /*
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            std::cout << array1[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "------------" << std::endl;
    */


    rotation = rotation%4;
    if(rotation == 0){
        for(int i = startY; i < temp+startY; i++){
            for(int j = startX; j < temp+startX; j++){
                array1[i][j] += 3;
            }
        }
        for(int i = startY; i < temp+startY; i++){
            for(int j = temp+startX; j < startX+temp*2; j++){
                array1[i][j] += 1;
            }
        }
        orientat(array1, temp, rotation+3, startX, startY);
        orientat(array1, temp, rotation+1, startX+temp, startY);
        orientat(array1, temp, rotation, startX, startY+temp);
        orientat(array1, temp, rotation, startX+temp, startY+temp);
    }
    if(rotation == 1){
        for(int i = startY; i < temp+startY; i++){
            for(int j = startX+temp; j < temp*2+startX; j++){//ERROR IN BOUNDING CAUSING CRASH
                array1[i][j] += 3;
            }
        }
        for(int i = startY+temp; i < temp*2+startY; i++){
            for(int j = temp+startX; j < startX+temp*2; j++){
                array1[i][j] += 1;
            }
        }
        orientat(array1, temp, rotation, startX, startY);
        orientat(array1, temp, rotation+3, startX+temp, startY);
        orientat(array1, temp, rotation, startX, startY+temp);
        orientat(array1, temp, rotation+1, startX+temp, startY+temp);
    }
    if(rotation == 2){
        for(int i = startY+temp; i < 2*temp+startY; i++){
            for(int j = temp+startX; j < 2*temp+startX; j++){
                array1[i][j] += 3;
            }
        }
        for(int i = startY+temp; i < temp*2+startY; i++){
            for(int j = startX; j < startX+temp; j++){
                array1[i][j] += 1;
            }
        }
        orientat(array1, temp, rotation, startX, startY);
        orientat(array1, temp, rotation, startX+temp, startY);
        orientat(array1, temp, rotation+1, startX, startY+temp);
        orientat(array1, temp, rotation+3, startX+temp, startY+temp);
    }
    if(rotation == 3){
        for(int i = startY+temp; i < temp*2+startY; i++){
            for(int j = startX; j < temp+startX; j++){
                array1[i][j] += 3;
            }
        }
        for(int i = startY; i < temp+startY; i++){
            for(int j = startX; j < startX+temp; j++){
                array1[i][j] += 1;
            }
        }
        orientat(array1, temp, rotation+1, startX, startY);
        orientat(array1, temp, rotation, startX+temp, startY);
        orientat(array1, temp, rotation+3, startX, startY+temp);
        orientat(array1, temp, rotation, startX+temp, startY+temp);
    }
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
    // Create the empty vector to track rotations
    std::vector<std::vector<int>> RotationMap (NumOfBoxes, (std::vector<int> (NumOfBoxes,0)));
    orientat(RotationMap, NumOfBoxes, 0, 0, 0);
    
    //std::vector<std::vector<int>> RotationMap (NumOfBoxes, (std::vector<int> (NumOfBoxes,0)));
    //std::vector<int> ori (NumOfBoxes*NumOfBoxes,0);
    //orientation(ori, 0, NumOfBoxes*NumOfBoxes, 1);
    //orientat(RotationMap, NumOfBoxes, 0, 0, 0);
    for(int i = 0; i < NumOfBoxes; i++){
        for(int j = 0; j < NumOfBoxes; j++){
            RotationMap[i][j] = RotationMap[i][j]%4;
            std::cout << RotationMap[i][j];
        }
        std::cout << std::endl;
    }
    //std::cout << NumOfBoxes << std::endl;
    int smallsize = size/NumOfBoxes;
    int distance = (smallsize-2)/4; // Distances into the box
    int leftin = distance+1; // Left start point
    int rightin = 3*distance+1; // Right start point
    int basein = 3*distance+1;
    int counter = 0;
    for(int a = 0; a < NumOfBoxes; a++){
        for(int b = 0; b < NumOfBoxes; b++){
            for(int i = distance; i <= basein; i++){
                //std::cout << RotationMap[a][b] << std::endl;
                if(RotationMap[a][b] != 1){
                    array[i+a*smallsize][rightin+b*smallsize] = 1; // Rigth line
                }
                if(RotationMap[a][b] != 3){
                    array[i+a*smallsize][leftin+b*smallsize] = 1;  // Left Line
                }
            }
            for(int j = leftin; j <= rightin; j++){
                if(RotationMap[a][b] != 2){
                    array[basein+a*smallsize][j+b*smallsize] = 1;     // Bottom Line
                }
                if(RotationMap[a][b] != 0){
                    array[(basein/3)+a*smallsize][j+b*smallsize] = 1; // Top Line
                }
            }
            counter++;
            if(counter == NumOfBoxes*NumOfBoxes){
                 std::cout << "test" << std::endl;
                    //RotationMap.clear();
            }
        }
    }

    return;
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
    
    //int NumOfBoxes = pow(2,(iterations-1));
    


    std::vector<std::vector<int>> map (size, (std::vector<int> (size,0))); // Create a square array filled with 0's
    hilbert(map, size, iterations);
    std::cout << "here" << std::endl;

    // File output generation
    std::ofstream outfile (out_fname);
    outfile << "P3" << std::endl;
    outfile << size << " " << size << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j] == 0){
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
            else{
                outfile << map[i][j]*100 << " " << 0 << " " << 0 << " ";
            } 
        }
        outfile << std::endl;
    }
    outfile.close();
    std::cout << "ran" << std::endl;
    
    //RotationMap.clear();
    
    //TEST TO OUTPUT 2D VECTOR
    /*for(double i=0; i < complete.size(); i++){
    for(double j = 0; j < complete[i].size(); j++){
        std::cout << complete[i][j] <<" ";
    }
        std::cout << std::endl;
    }*/
    
    return 0;
}