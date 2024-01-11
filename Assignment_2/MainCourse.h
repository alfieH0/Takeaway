#ifndef MAIN_COURSE_H
#define MAIN_COURSE_H

#include "Item.h"
#include <memory>

using namespace std;

class MainCourse : public Item
{
public:
    MainCourse(const string& name, int calories, double price);    //Constructor for the MainCourse class
    string toString() const;    //Convert MainCourse object to a string for display
    ~MainCourse();    //Destructor for the MainCourse class
};

#endif
