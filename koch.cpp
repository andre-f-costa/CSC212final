//This is my third (and last ditch) attempt to get the Koch Snowflake working. 
//My Second attempt, which is (in my opinion, more impressive despite not working) will be uploaded under the name, Koch_2.cpp
#include <iostream>
#include "CTurtle.hpp"
#include <string>
#include <vector>
//so I don't go insane
using namespace std; 
namespace ct = cturtle;

//This is the recursive loop, variables are as follows:
// * length is the current size of each edge
// * Level is the 'depth' we recurse to
// * turtle is the turtle object
// * color is the list of colors that will cycle through, one per depth
// * c_l saves the depth at which the recursion happened, this is used to index color and draw the output
void koch(double length, double level, ct::Turtle& turtle, vector<string>* color, int c_l) {  
    // basecase
    if (level == 0) {
        // if we reach a depth that is greater than the array of colors, loop back.
        // hooray for planning ahead!
        while (c_l > (*color).size() - 1) {
            c_l -= (*color).size();
        }
        // set the turtle color and move it fowards, rotation is handeled below. 
        turtle.pencolor({(*color)[c_l]});
        turtle.forward(length);
        return; 
    }
    
    // we divide each line into three more lines, the middle will form the base of an equilateral triangle later on. 
    length /= 3;
    // so we can actually get somewhere (oops)
    level = level - 1;

    // first line segment, they will form the following shape _/\_
    koch(length, level, turtle, &(*color), c_l);
    // rotate 60 degrees respective to prior orientation, very handy that our pet turtle can track this. 
    turtle.left(60);
    // second line segment
    koch(length, level, turtle, &(*color), c_l + 1);
    turtle.right(120);
    // third line segment
    koch(length, level, turtle, &(*color), c_l + 1);
    turtle.left(60);
    // fourth line segment
    koch(length, level, turtle, &(*color), c_l);
    
    // useless failsafe
    return;
}

// setting up the base equilateral triangle, recursive calls
int main(int argc, char *argv[]) { 
    // how deep we go in the recursion.
    double level = (int)atoi (argv[1]); 
    //size of koch triangle (pixels)
    double size = 500; 
    
    // here is the string we pass in, feel free to add colors!
    vector<string> color{"violet", "purple", "blue", "green", "yellow", "orange", "red"};

    // initializing the turtle
    ct::TurtleScreen scr; 
    ct::Turtle turtle(scr);
    turtle.speed(ct::TS_FASTEST);
    turtle.fillcolor({"black"});

    // get the turtle in position (mid of top) without messing up our canvas.
    turtle.penup(); 
    turtle.left(90);
    turtle.forward(300);
    turtle.right(150);
    turtle.pendown();
    turtle.begin_fill(); 
    
    // call the turtle three times to initialize each side. 
    koch(size, level, turtle, &color, 0);
    turtle.right(120);
    koch(size, level, turtle, &color, 0); 
    turtle.right(120);
    koch(size, level, turtle, &color, 0); 
    
    // keep the canvas open so we can admire our handiwork :)
    scr.exitonclick();

    return 0;
}
