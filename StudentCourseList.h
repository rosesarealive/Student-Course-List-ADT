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

#ifndef STUDENT_COURSE_LIST_H
#define STUDENT_COURSE_LIST_H

#include <string>

//stores the information for one course
struct Course
{
    std::string courseName;
    std::string courseID;
    int units;
    std::string instructor;
    std::string grade;
    std::string semester;
    std::string prerequisite;
};

//an array-based list used to manage a student's courses
class StudentCourseList
{
private:
    Course* courses;
    int listSize;
    int capacity;

    //doubles the capacity while preserving the existing courses
    void resize();

    //throws an exception when an index is outside the valid range
    void validateIndex(int index) const;

public:
    //constructor
    StudentCourseList(int initialCapacity = 10);

    //big Five
    ~StudentCourseList();
    StudentCourseList(const StudentCourseList& other);
    StudentCourseList& operator=(const StudentCourseList& other);
    StudentCourseList(StudentCourseList&& other);
    StudentCourseList& operator=(StudentCourseList&& other);

    //required list operations
    void append(const Course& course);
    void insert(int index, const Course& course);
    void remove(int index);
    Course get(int index) const;
    void set(int index, const Course& course);
    int size() const;
    bool isEmpty() const;
    void clear();

    //course-specific operations
    int findCourse(const std::string& courseID) const;
    void displayCourses() const;
    int calculateTotalCredits() const;
};

#endif
