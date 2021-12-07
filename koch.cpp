#include <iostream>
#include "CTurtle.hpp"
#include <string>
#include <vector>
using namespace std;
namespace ct = cturtle;

void koch(double length, double level, ct::Turtle& turtle, vector<string>* color, int c_l) {  
    if (level == 0) {
        while (c_l > (*color).size() - 1) {
            c_l -= (*color).size();
        }
        turtle.pencolor({(*color)[c_l]});
        turtle.forward(length);
        return; 
    }

    length /= 3;
    level = level - 1;

    koch(length, level, turtle, &(*color), c_l);
    turtle.left(60);
    koch(length, level, turtle, &(*color), c_l + 1);
    turtle.right(120);
    koch(length, level, turtle, &(*color), c_l + 1);
    turtle.left(60);
    koch(length, level, turtle, &(*color), c_l);

    return;
}

int main() { 
    double level = 5; //how deep we go in the recursion.
    double size = 500; //size of koch triangle

    vector<string> color{"violet", "purple", "blue", "green", "yellow", "orange", "red"};

    ct::TurtleScreen scr; //initialize the turtle
    ct::Turtle turtle(scr);
    turtle.speed(ct::TS_FASTEST);

    turtle.fillcolor({"black"});

    turtle.penup(); //get the turtle in position (mid of top)
    turtle.left(90);
    turtle.forward(300);
    turtle.right(150);
    turtle.pendown();
    turtle.begin_fill(); //call the turtle three times to initialize each side. 
    koch(size, level, turtle, &color, 0);
    turtle.right(120);
    koch(size, level, turtle, &color, 0); 
    turtle.right(120);
    koch(size, level, turtle, &color, 0); 
    scr.exitonclick();

    return 0;
}
