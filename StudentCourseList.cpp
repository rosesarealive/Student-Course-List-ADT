#include "StudentCourseList.h"

#include <iostream>
#include <utility>

StudentCourseList::StudentCourseList(int initialCapacity)
    : courses(nullptr), listSize(0), capacity(initialCapacity)
{
    if (capacity <= 0)
        capacity = 10;

    courses = new Course[capacity];
}

StudentCourseList::~StudentCourseList()
{
    delete[] courses;
}

StudentCourseList::StudentCourseList(const StudentCourseList& other)
    : courses(other.capacity > 0 ? new Course[other.capacity] : nullptr),
      listSize(other.listSize), capacity(other.capacity)
{
    for (int i = 0; i < listSize; ++i)
        courses[i] = other.courses[i];
}

StudentCourseList& StudentCourseList::operator=(const StudentCourseList& other)
{
    if (this != &other) {
        StudentCourseList copy(other);
        std::swap(courses, copy.courses);
        std::swap(listSize, copy.listSize);
        std::swap(capacity, copy.capacity);
    }
    return *this;
}

StudentCourseList::StudentCourseList(StudentCourseList&& other)
    : courses(other.courses), listSize(other.listSize), capacity(other.capacity)
{
    other.courses = nullptr;
    other.listSize = 0;
    other.capacity = 0;
}

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

int StudentCourseList::findCourse(const std::string& courseID) const
{
    for (int i = 0; i < listSize; ++i)
        if (courses[i].courseID == courseID)
            return i;
    return -1;
}

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
                  << "   Instructor: " << c.instructor
                  << ", Grade: " << c.grade
                  << ", Semester: " << c.semester
                  << ", Prerequisite: " << c.prerequisite << '\n';
    }
}

int StudentCourseList::calculateTotalCredits() const
{
    int total = 0;
    for (int i = 0; i < listSize; ++i)
        total += courses[i].units;
    return total;
}
