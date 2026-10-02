/*
 Name: Conner Cunningham, Shahsar Shamim, Kimberly Guerrero
 Course: CMPR 131 - Fall 2026
 Date: September 28, 2026
 Assignment: Student Course List ADT Group Project

 Collaboration:
 Conner Cunningham - Core list implementation
 Shahsar Shamim - Big Five & Course Specific Methods
 Kimberly Guerrero - Header & main.cpp

 Resources/AI Tools Used: none
*/

#include "StudentCourseList.h"

#include <iostream>
#include <stdexcept>

//creates an empty course list
StudentCourseList::StudentCourseList(int initialCapacity)
    : courses(nullptr), listSize(0), capacity(initialCapacity)
{
    if (capacity <= 0)
    {
        capacity = 10;
    }

    courses = new Course[capacity];
}

//Shahsar - Big Five and course-specific methods

//releases the dynamically allocated array
StudentCourseList::~StudentCourseList()
{
    delete[] courses;
}

//creates a deep copy of another course list
StudentCourseList::StudentCourseList(const StudentCourseList& other)
    : courses(other.capacity > 0 ? new Course[other.capacity] : nullptr),
      listSize(other.listSize), capacity(other.capacity)
{
    for (int i = 0; i < listSize; ++i)
        courses[i] = other.courses[i];
}
// Replaces this list with a deep copy of another list.
StudentCourseList& StudentCourseList::operator=(const StudentCourseList& other)
{
    if (this != &other)
    {
        Course* newCourses =
            other.capacity > 0 ? new Course[other.capacity] : nullptr;

        for (int i = 0; i < other.listSize; i++)
        {
            newCourses[i] = other.courses[i];
        }

        delete[] courses;
        courses = newCourses;
        listSize = other.listSize;
        capacity = other.capacity;
    }

    return *this;
}
//transfers ownership of another list's array
StudentCourseList::StudentCourseList(StudentCourseList&& other)
    : courses(other.courses), listSize(other.listSize), capacity(other.capacity)
{
    other.courses = nullptr;
    other.listSize = 0;
    other.capacity = 0;
}

//replaces this list by taking ownership of another list's array
StudentCourseList& StudentCourseList::operator=(StudentCourseList&& other)
{
    if (this != &other) {
        delete[] courses;
        courses = other.courses;
        listSize = other.listSize;
        capacity = other.capacity;
        other.courses = nullptr;
        other.listSize = 0;
        other.capacity = 0;
    }
    return *this;
}

//searches for a course by its course ID
int StudentCourseList::findCourse(const std::string& courseID) const
{
    for (int i = 0; i < listSize; ++i)
        if (courses[i].courseID == courseID)
            return i;
    return -1;
}

//displays every course currently in the list
void StudentCourseList::displayCourses() const
{
    if (listSize == 0) {
        std::cout << "No courses in the list.\n";
        return;
    }
    for (int i = 0; i < listSize; ++i) {
        const Course& c = courses[i];
        std::cout << i << ". " << c.courseID << " - " << c.courseName
                  << " (" << c.units << " units)\n"
                  << "   Instructor: " << c.instructor << '\n'
                  << ", Grade: " << c.grade << '\n'
                  << ", Semester: " << c.semester << '\n'
                  << ", Prerequisite: " << c.prerequisite << "\n\n";
}

//calculates the total number of course units
int StudentCourseList::calculateTotalCredits() const
{
    int total = 0;
    for (int i = 0; i < listSize; ++i)
        total += courses[i].units;
    return total;
}


//Conner Cunningham - Core list implementation

// Doubles capacity and preserves the existing courses.
void StudentCourseList::resize()
{
   int newCapacity;

   if (capacity == 0)
   {
       newCapacity = 1;
   }
   else
   {
       newCapacity = capacity * 2;
   }
   Course* newCourses = new Course[newCapacity];

   for (int i = 0; i < listSize; i++)
   {
       newCourses[i] = courses[i];
   }

   delete[] courses;
   courses = newCourses;
   capacity = newCapacity;
}

// Checks indexes used by remove(), get(), and set().
void StudentCourseList::validateIndex(int index) const
{
    if (index < 0 || index >= listSize)
    {
        throw std::out_of_range("Course index is out of range.");
    }
}

// Adds a course to the end of the list.
void StudentCourseList::append(const Course& course)
{
    insert(listSize, course);
}

// Inserts a course at the specified index.
void StudentCourseList::insert(int index, const Course& course)
{
    // Unlike other operations, insertion allows index == listSize.
    if (index < 0 || index > listSize)
    {
        throw std::out_of_range("Insertion index is out of range.");
    }

    if (course.units <= 0)
    {
        throw std::invalid_argument("Course units must be greater than zero.");
    }

    for (int i = 0; i < listSize; i++)
    {
        if (courses[i].courseID == course.courseID)
        {
            throw std::invalid_argument("Course ID must be unique.");
        }
    }

    if (listSize == capacity)
    {
        resize();
    }

    // Shift courses right to make room.
    for (int i = listSize; i > index; i--)
    {
        courses[i] = courses[i - 1];
    }

    courses[index] = course;
    listSize++;
}

// Removes the course at the specified index.
void StudentCourseList::remove(int index)
{
    validateIndex(index);

    // Shift courses left to fill the gap.
    for (int i = index; i < listSize - 1; i++)
    {
        courses[i] = courses[i + 1];
    }

    courses[listSize - 1] = Course{};
    listSize--;
}

// Returns a copy of the course at the specified index.
Course StudentCourseList::get(int index) const
{
    validateIndex(index);
    return courses[index];
}

// Replaces the course at the specified index.
void StudentCourseList::set(int index, const Course& course)
{
    validateIndex(index);

    if (course.units <= 0)
    {
        throw std::invalid_argument("Course units must be greater than zero.");
    }

    for (int i = 0; i < listSize; i++)
    {
        // The course being replaced may keep its current ID.
        if (i != index && courses[i].courseID == course.courseID)
        {
            throw std::invalid_argument("Course ID must be unique.");
        }
    }

    courses[index] = course;
}

// Returns the number of courses currently stored.
int StudentCourseList::size() const
{
    return listSize;
}

// Returns true when the list contains no courses.
bool StudentCourseList::isEmpty() const
{
    return listSize == 0;
}

// Clears the courses while retaining capacity for reuse.
void StudentCourseList::clear()
{
    for (int i = 0; i < listSize; i++)
    {
        courses[i] = Course{};
    }

    listSize = 0;
}
