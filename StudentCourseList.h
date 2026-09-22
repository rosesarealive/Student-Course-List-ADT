#ifndef STUDENT_COURSE_LIST_H
#define STUDENT_COURSE_LIST_H

#include <string>

// Stores the information for one course.
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

// An array-based list used to manage a student's courses.
class StudentCourseList
{
private:
    Course* courses;
    int listSize;
    int capacity;

    // Doubles the capacity while preserving the existing courses.
    void resize();

    // Throws an exception when an index is outside the valid range.
    void validateIndex(int index) const;

public:
    // Constructor
    StudentCourseList(int initialCapacity = 10);

    // Big Five
    ~StudentCourseList();
    StudentCourseList(const StudentCourseList& other);
    StudentCourseList& operator=(const StudentCourseList& other);
    StudentCourseList(StudentCourseList&& other);
    StudentCourseList& operator=(StudentCourseList&& other);

    // Required list operations
    void append(const Course& course);
    void insert(int index, const Course& course);
    void remove(int index);
    Course get(int index) const;
    void set(int index, const Course& course);
    int size() const;
    bool isEmpty() const;
    void clear();

    // Course-specific operations
    int findCourse(const std::string& courseID) const;
    void displayCourses() const;
    int calculateTotalCredits() const;
};

#endif
