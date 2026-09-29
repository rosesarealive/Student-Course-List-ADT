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
    cout << testName << ": "
         << (passed ? "PASS" : "FAIL") << '\n';
}

int main()
{
 //sample courses used in tests
    Course cmpr120 = {"Introduction to Programming", "CMPR 120", 3,
                      "Professor Lopez", "A", "Fall 2025", "None"};

    Course cmpr121 = {"Programming Concepts", "CMPR 121", 3,
                      "Professor Chen", "B", "Spring 2026", "CMPR 120"};

    Course cmpr131 = {"Data Structures", "CMPR 131", 4,
                      "Professor Smith", "A", "Fall 2026", "CMPR 121"};

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

    printTest("Resize preserves all courses", courseList.size() == 5);

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
}
