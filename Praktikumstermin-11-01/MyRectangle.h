#pragma once

class MyRectangle{
    int x1,y1,x2,y2;

public:
    int get_x1() const;
    int get_x2() const;
    int get_y1() const;
    int get_y2() const;
    void set_x1(int x1);
    void set_x2(int x2);
    void set_y1(int y1);
    void set_y2(int y2);
    void set(int x1, int y1, int x2, int y2);

    MyRectangle(int x1, int y1, int x2, int y2);
    MyRectangle();
    void draw();
    bool does_not_collide_with(const MyRectangle& other);

};