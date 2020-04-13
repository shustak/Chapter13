#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
int main()
{
    try {
        using namespace Graph_lib;

        //Part 1 create window
        Point tl(150, 150);
        Simple_window win(tl, 1000, 800, "Chapter 13");
        win.wait_for_button();
       
        //Part 2 create grid
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        int x_grid = 100;
        int y_grid = 100;
        for (int x = x_grid; x < x_size; x += x_grid)
            grid.add(Point(x, 0), Point(x, y_size)); 
        for (int y = y_grid; y < y_size; y += y_grid)
            grid.add(Point(0, y), Point(x_size, y));
        win.attach(grid);
        win.wait_for_button();

        //Part 3 Draw diagonal rectagle in red
        Vector_ref<Graph_lib::Rectangle> vr;
        for (int i = 0; i < 8; ++i) 
        {
            vr.push_back(new Graph_lib::Rectangle(Point(i * 100, i * 100), 100, 100));
            vr[vr.size() - 1].set_fill_color(Color::red);
            win.attach(vr[vr.size() - 1]);
        }
        win.wait_for_button();

        //Part 4 Work with 200x200 pixel images
        Image im1(Point(200, 0), "162.jpg");
        win.attach(im1);
        Image im2(Point(500, 200), "162.jpg");
        win.attach(im2);
        Image im3(Point(100, 500), "171.gif");
        win.attach(im3);
        
        win.wait_for_button();

        //Part 5 Work with 100x100 pixel images
        Image im4(Point(0, 0), "171.gif");
        im4.set_mask(Point(100, 70), 100, 100);//cut 171.gif 
        win.attach(im4);
        win.wait_for_button();

        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 0;
        while (true) {
            x = std::rand()%8;
            y = std::rand() % 8;
            dx = 100 * x - im4.point(0).x;
            dy = 100 * y - im4.point(0).y;
            im4.move(dx, dy);
            win.wait_for_button();
        }
    }
    catch (exception& e) {
        return 1;
    }
    catch (...) {
        return 2;
    }
    return 0;
}


