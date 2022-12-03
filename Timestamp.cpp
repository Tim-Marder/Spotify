#include "Timestamp.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void Timestamp::init(struct tm *tm_time) {

    secs = (unsigned int) tm_time->tm_sec;
    mins = (unsigned int) tm_time->tm_min;
    hours = (unsigned int) tm_time->tm_hour;
    day = (unsigned int) tm_time->tm_mday;
    month = (unsigned int) tm_time->tm_mon + 1;
    year = (unsigned int) tm_time->tm_year + 1900;

}

Timestamp::Timestamp() {
    now();
}

unsigned int Timestamp::getSecs() {
    return secs;
}

unsigned int Timestamp::getMins() {
    return mins;
}

unsigned int Timestamp::getHours() {
    return hours;
}

unsigned int Timestamp::getDay() {
    return day;
}

unsigned int Timestamp::getMonth() {
    return month;
}

unsigned int Timestamp::getYear() {
    return year;
}


Timestamp::Timestamp(const Timestamp& other) {
    secs = other.secs;
    mins = other.mins;
    hours = other.hours;
    day = other.day;
    month = other.month;
    year = other.year;
}

Timestamp& Timestamp::operator=(const Timestamp& other) {
    secs = other.secs;
    mins = other.mins;
    hours = other.hours;
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

void Timestamp::now() {
    time_t rightnow = time(0);
    struct tm *tm_time = localtime(&rightnow);
    init(tm_time);
}

std::string Timestamp::toString() {
    time_t rightnow = time(0);
    struct tm *tm_time = localtime(&rightnow);

    int year = 1900 + tm_time->tm_year;
    int mon = 1 + tm_time->tm_mon;
    int day = tm_time->tm_mday;
    int hour = tm_time->tm_hour;
    int min = tm_time->tm_min;
    int sec = tm_time->tm_sec;
    std::string output = to_string(year) + "/" + to_string(mon) + "/" + to_string(day) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
    return output;
}
