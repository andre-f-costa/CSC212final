#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>

void orientat(std::vector<std::vector<int>> &array1, int size2, int rotation, int startX, int startY,
                 std::vector<std::vector<int>> &output, int edgesize, int multiplier){
    int temp = size2/2;
    if(size2 == 1){
        return;
    }

    rotation = rotation%4; //Mod the rotation value so it is always between 0 and 3
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
        output[1][1] = 2;
        orientat(array1, temp, rotation+3, startX, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation+1, startX+temp, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX, startY+temp, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX+temp, startY+temp, output, edgesize, multiplier);
    }
    if(rotation == 1){
        for(int i = startY; i < temp+startY; i++){
            for(int j = startX+temp; j < temp*2+startX; j++){
                array1[i][j] += 3;
            }
        }
        for(int i = startY+temp; i < temp*2+startY; i++){
            for(int j = temp+startX; j < startX+temp*2; j++){
                array1[i][j] += 1;
            }
        }
        orientat(array1, temp, rotation, startX, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation+3, startX+temp, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX, startY+temp, output, edgesize, multiplier);
        orientat(array1, temp, rotation+1, startX+temp, startY+temp, output, edgesize, multiplier);
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
        orientat(array1, temp, rotation, startX, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX+temp, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation+1, startX, startY+temp, output, edgesize, multiplier);
        orientat(array1, temp, rotation+3, startX+temp, startY+temp, output, edgesize, multiplier);
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
        orientat(array1, temp, rotation+1, startX, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX+temp, startY, output, edgesize, multiplier);
        orientat(array1, temp, rotation+3, startX, startY+temp, output, edgesize, multiplier);
        orientat(array1, temp, rotation, startX+temp, startY+temp, output, edgesize, multiplier);
    }
}

void sidelines(std::vector<std::vector<int>> &output, int edgesize, std::vector<std::vector<int>> &direction, int totalwidth){
    int tempsize = direction[0].size();
    std::vector<std::vector<int>> temparray (tempsize/2, (std::vector<int> (tempsize/2,-1)));
    int movein = totalwidth/tempsize;
    for(int j = 1; j < tempsize; j += 2){
        for(int i = 1; i < tempsize; i += 2){
            int topleft = direction[i-1][j-1];
            int topright = direction[i-1][j];
            int botleft = direction[i][j-1];
            int botright = direction[i][j];
            
            if(botleft == botright){
                temparray[i/2][j/2] = 0;
                for(int k = i*movein-edgesize/2; k <= i*movein+edgesize/2; k++){
                    output[k][(j-1)*movein+(edgesize/2)] = 2;
                    output[k][(j+1)*movein-(edgesize/2+2)] = 2;
                    
                }
                for(int k = j*movein-edgesize/2; k <= j*movein+edgesize/2; k++){
                    output[i*movein+edgesize/2-1][k-1] = 2;
                }
            }
            else if(topleft == topright){
                temparray[i/2][j/2] = 2;
                for(int k = i*movein-edgesize/2; k <= i*movein+edgesize/2; k++){
                    output[k][(j-1)*movein+edgesize/2] = 3;
                    output[k][(j+1)*movein-edgesize/2] = 3;
                    
                }
                for(int k = j*movein-edgesize/2; k <= j*movein+edgesize/2; k++){
                    output[i*movein-edgesize/2][k] = 3;
                }
            }
            else if(topleft == botleft){
                temparray[i/2][j/2] = 1;
                for(int k = j*movein-edgesize/2; k <= j*movein+edgesize/2; k++){
                    output[(i-1)*movein+edgesize/2-1][k] = 2;
                    output[(i+1)*movein-edgesize/2][k] = 2;
                    
                }
                for(int k = i*movein-edgesize/2; k <= i*movein+edgesize/2; k++){
                    output[k][j*movein-edgesize/2] = 2;
                }
            }
            else if(topright == botright){
                temparray[i/2][j/2] = 1;
                for(int k = j*movein-edgesize/2; k <= j*movein+edgesize/2; k++){
                    output[(i-1)*movein+edgesize/2-1][k] = 2;
                    output[(i+1)*movein-edgesize/2][k] = 2;
                    
                }
                for(int k = i*movein-edgesize/2; k <= i*movein+edgesize/2; k++){
                    output[k-1][j*movein+edgesize/2] = 2;
                }
            }
        }
    }
    if(tempsize <= 2){
        return;
    }
    else{
        sidelines(output, edgesize, temparray, totalwidth);
    }
}

int hilbert(std::vector<std::vector<int>> &array, int size, int iterations){
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
    int smallsize = size/NumOfBoxes;
    size = NumOfBoxes*smallsize;

    // Create the empty vector to track rotations
    std::vector<std::vector<int>> RotationMap (NumOfBoxes, (std::vector<int> (NumOfBoxes,0)));
    orientat(RotationMap, NumOfBoxes, 0, 0, 0, array, smallsize/2, size/NumOfBoxes);
    
    for(int i = 0; i < NumOfBoxes; i++){
        for(int j = 0; j < NumOfBoxes; j++){
            RotationMap[i][j] = RotationMap[i][j]%4;
        }
    }
    
    int distance = (smallsize-2)/4; // Distances into the box
    int leftin = distance+1; // Left start point
    int rightin = 3*distance+1; // Right start point
    int basein = 3*distance+1;
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
        }
    }
    sidelines(array, smallsize/2, RotationMap, size);
    return size;
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
    int outsize = hilbert(map, size, iterations);

    // File output generation
    std::ofstream outfile (out_fname);
    outfile << "P3" << std::endl;
    outfile << outsize << " " << outsize << std::endl;
    outfile << "255" << std::endl;
    for(int i=0; i < outsize; i++){
        for(int j = 0; j < outsize; j++){
            if(map[i][j] == 0){
                outfile << 255 << " " << 255 << " " << 255 << " ";
            }
            else{
                outfile << 2*100 << " " << 0 << " " << 0 << " ";
            } 
        }
        outfile << std::endl;
    }
    outfile.close();
    
    return 0;
}