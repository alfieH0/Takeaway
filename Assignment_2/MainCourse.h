// MainCourse.h

#ifndef MAIN_COURSE_H
#define MAIN_COURSE_H

#include "Item.h"
#include <memory>

using namespace std;

class MainCourse : public Item 
{
public:
    // Constructor
    MainCourse(const string& name, int calories, double price);

    // toString method
    string toString() const;
    ~MainCourse();
};

#endif // MAIN_COURSE_H
