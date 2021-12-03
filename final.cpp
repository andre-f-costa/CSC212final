#include <iostream>
#include "CTurtle.hpp"
using namespace std;
namespace ct = cturtle;

void koch(double length, double level, ct::Turtle& turtle) {  
    if (level == 0) {
        turtle.forward(length);
        return; 
    }

    length /= 3;
    level = level - 1;

    koch(length, level, turtle);
    turtle.left(60);
    koch(length, level, turtle);
    turtle.right(120);
    koch(length, level, turtle);
    turtle.left(60);
    koch(length, level, turtle);

    return;
}

int main() { 
    double level = 0; //how deep we go in the recursion.
    double size = 200; //size of koch triangle

    ct::TurtleScreen scr; //initialize the turtle
    ct::Turtle turtle(scr);
    turtle.speed(ct::TS_SLOWEST);
    turtle.fillcolor({"black"});

    turtle.penup(); //get the turtle in position (mid of top)
    turtle.left(90);
    turtle.forward(300);
    turtle.right(150);
    turtle.pendown();
    turtle.begin_fill(); //call the turtle three times to initialize each side. 
    koch(size, level, turtle);
    turtle.right(120);
    koch(size, level, turtle); 
    turtle.right(120);
    koch(size, level, turtle); 
    scr.exitonclick();

    return 0;
}
