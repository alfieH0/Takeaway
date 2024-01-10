#ifndef MAIN_COURSE_H
#define MAIN_COURSE_H

#include "Item.h"
#include <memory>

using namespace std;

class MainCourse : public Item 
{
public:
    MainCourse(const string& name, int calories, double price);    //Constructor
    string toString() const;
    ~MainCourse();
};

#endif
