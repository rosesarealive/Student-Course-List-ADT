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
#include <string>
#include <utility>

using namespace std;

//prints whether a test passed or failed
void printTest(const string& testName, bool passed)
{
    cout << testName << ": ";

    if (passed)
    {
        cout << "PASS";
    }
    else
    {
        cout << "FAIL";
    }

    cout << '\n';
}

int main()
{
 //sample courses used in tests
    Course cmpr120 = {"Introduction to Programming", "CMPR 120", 3,
                      "Professor Lopez", "A", "Fall 2025", "None"};

    Course cmpr121 = {"Programming Concepts", "CMPR 121", 3,
                      "Professor Chen", "B", "Spring 2026", "CMPR 120"};

    Course cmpr131 = {"Data Structures", "CMPR 131", 4,
                      "Professor Alweheiby", "A", "Fall 2026", "CMPR 121"};

    Course math180 = {"Calculus I", "MATH 180", 4,
                      "Professor Davis", "B", "Spring 2026", "MATH 170"};

    Course math185 = {"Calculus II", "MATH 185", 4,
                      "Professor Patel", "In Progress", "Fall 2026", "MATH 180"};

    cout << "=== BASIC LIST TESTS ===\n";

 //capacity of 2 forces the list to resize during insertion testing.
    StudentCourseList courseList(2);

    printTest("New list is empty", courseList.isEmpty());
    printTest("New list has size 0", courseList.size() == 0);

    courseList.append(cmpr120);
    courseList.append(cmpr121);

    printTest("append() adds courses", courseList.size() == 2);
    printTest("get() returns the expected course",
              courseList.get(1).courseID == "CMPR 121");

    cout << "\n=== INSERTION TESTS ===\n";

    courseList.insert(0, cmpr131);
    printTest("Insert at front",
              courseList.get(0).courseID == "CMPR 131");

    courseList.insert(2, math180);
    printTest("Insert in middle",
              courseList.get(2).courseID == "MATH 180");

    courseList.insert(courseList.size(), math185);
    printTest("Insert at end",
              courseList.get(courseList.size() - 1).courseID == "MATH 185");

    printTest("Resize preserves all courses",
          courseList.size() == 5 &&
          courseList.get(0).courseID == "CMPR 131" &&
          courseList.get(1).courseID == "CMPR 120" &&
          courseList.get(2).courseID == "MATH 180" &&
          courseList.get(3).courseID == "CMPR 121" &&
          courseList.get(4).courseID == "MATH 185");

    cout << "\n=== GET, SET, AND COURSE-SPECIFIC TESTS ===\n";

    Course updatedMath180 = math180;
    updatedMath180.grade = "A";
    courseList.set(2, updatedMath180);

    printTest("set() replaces a course",
              courseList.get(2).grade == "A");
    printTest("findCourse() finds an existing course",
              courseList.findCourse("MATH 180") == 2);
    printTest("findCourse() returns -1 when not found",
              courseList.findCourse("PHYS 227") == -1);
    printTest("calculateTotalCredits() totals the units",
              courseList.calculateTotalCredits() == 18);

    cout << "\ndisplayCourses() output:\n";
    courseList.displayCourses();

    cout << "\n=== REMOVAL TESTS ===\n";

//use a copy so the original list remains available for later tests
    StudentCourseList removalList(courseList);

    removalList.remove(0);
    printTest("Remove from front",
              removalList.size() == 4 &&
              removalList.get(0).courseID == "CMPR 120");

    removalList.remove(2);
    printTest("Remove from middle",
              removalList.size() == 3 &&
              removalList.findCourse("CMPR 121") == -1);

    removalList.remove(removalList.size() - 1);
    printTest("Remove from end",
              removalList.size() == 2 &&
              removalList.findCourse("MATH 185") == -1);

    removalList.clear();
    printTest("clear() sets size to 0", removalList.size() == 0);
    printTest("List is empty after clear()", removalList.isEmpty());

    cout << "\n=== COPY TESTS ===\n";

    StudentCourseList copiedList(courseList);

    Course changedCourse = courseList.get(0);
    changedCourse.grade = "F";
    courseList.set(0, changedCourse);

    printTest("Copy constructor copies ALL courses",
              copiedList.size() == 5);
    printTest("Copy constructor creates a deep copy",
              copiedList.get(0).grade == "A" &&
              courseList.get(0).grade == "F");

    StudentCourseList assignedList;
    assignedList = courseList;

    changedCourse = courseList.get(1);
    changedCourse.grade = "C";
    courseList.set(1, changedCourse);

    printTest("Copy assignment copies all courses",
              assignedList.size() == 5);
    printTest("Copy assignment creates a deep copy",
              assignedList.get(1).grade == "A" &&
              courseList.get(1).grade == "C");

    cout << "\n=== MOVE TESTS ===\n";

    StudentCourseList movedList(std::move(copiedList));

    printTest("Move constructor transfers the courses",
              movedList.size() == 5 &&
              movedList.get(0).courseID == "CMPR 131");
    printTest("Move constructor empties the source",
              copiedList.size() == 0 && copiedList.isEmpty());

    StudentCourseList moveAssignedList;
    moveAssignedList = std::move(assignedList);

    printTest("Move assignment transfers the courses",
              moveAssignedList.size() == 5 &&
              moveAssignedList.get(0).courseID == "CMPR 131");
    printTest("Move assignment empties the source",
              assignedList.size() == 0 && assignedList.isEmpty());

    cout << "\n=== TESTING COMPLETE ===\n";

    return 0;
}
