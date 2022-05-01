//
// Created by bruce on 2/27/22.
//

#ifndef SORTING_BASIC_STUDENT_H
#define SORTING_BASIC_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? score > otherStudent.score : name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //SORTING_BASIC_STUDENT_H
