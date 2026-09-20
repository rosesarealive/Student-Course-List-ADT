# Student Course List ADT

## Project Overview

This project converts our previous `DArray` class into an array-based **Student Course List ADT**. The program stores and manages a student’s courses using a dynamically allocated array.

**Team Name:** Syntax Club
**Team Lead:** Conner Cunningham
**Due Date:** October 4, 2026 at 11:59 PM

## Course Information

Each course stores:

* Course name
* Course ID
* Number of units
* Instructor
* Grade
* Semester
* Prerequisite

## Required List Operations

* `append()`
* `insert()`
* `remove()`
* `get()`
* `set()`
* `size()`
* `isEmpty()`
* `clear()`

## Course-Specific Operations

* `findCourse()` — searches for a course
* `displayCourses()` — displays every course in the list
* `calculateTotalCredits()` — calculates the total number of units

## Additional Requirements

The class will include:

* Dynamic resizing when the array becomes full
* Index validation
* Private data members
* No direct pointer exposure
* Preservation of existing courses during resizing
* Destructor
* Copy constructor
* Copy assignment operator
* Move constructor
* Move assignment operator

## Work Division

### Person 1 — Kimberly: Header and Design

* [ ] Create the `Course` structure
* [ ] Create the `StudentCourseList` class declaration
* [ ] Declare private data members
* [ ] Declare the constructor and Big Five
* [ ] Declare all required list operations
* [ ] Declare the course-specific operations
* [ ] Write the ADT description, design decisions, and invariants

### Person 2 — Core Implementation

* [ ] Implement the required list operations
* [ ] Implement index validation
* [ ] Implement resizing and preserve existing courses
* [ ] Write the Big-O analysis for `append()`, `insert()`, `remove()`, and `get()`
* [ ] Write the reflection about shifting elements

### Person 3 — Memory and Course Features

* [ ] Implement the constructor
* [ ] Implement the Big Five
* [ ] Implement `findCourse()`
* [ ] Implement `displayCourses()`
* [ ] Implement `calculateTotalCredits()`
* [ ] Write about bugs, challenges, and memory management

### Person 4 — Conner: Driver, Testing, and Submission

* [ ] Create `main.cpp`
* [ ] Create sample courses
* [ ] Test all required list operations
* [ ] Test insertion at the front, middle, and end
* [ ] Test removal at the front, middle, and end
* [ ] Test the course-specific operations
* [ ] Test copy and move behavior
* [ ] Check for shallow-copy errors and memory leaks
* [ ] Compile and integrate all project files
* [ ] Take a screenshot of the program output
* [ ] Combine and proofread the written analysis
* [ ] Submit the final project

## Testing Checklist

The completed program must demonstrate:

* [ ] Insert at the front, middle, and end
* [ ] Remove from the front, middle, and end
* [ ] `get()` and `set()`
* [ ] Copy constructor
* [ ] Copy assignment operator
* [ ] Move constructor
* [ ] Dynamic resizing
* [ ] No shallow-copy errors
* [ ] No memory leaks

## Deliverables

* `StudentCourseList.h`
* `StudentCourseList.cpp`
* `main.cpp`
* Screenshot of the program output
* One-to-two-page written analysis
