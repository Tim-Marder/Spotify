#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <string>

class Timestamp {
	public:
		Timestamp();
		unsigned int getSecs();
		unsigned int getMins();
		unsigned int getHours();
		unsigned int getDay();
		unsigned int getMonth();
		unsigned int getYear();
		Timestamp(const Timestamp& other);
		Timestamp& operator=(const Timestamp& other);
		void init(struct tm*);
		// print timestamp in yyyy/mm/dd hh:mm:ss format.
		std::string toString();
	private:
		void now();
		unsigned int secs;
		unsigned int mins;
		unsigned int hours;
		unsigned int day;
		unsigned int month;
		unsigned int year;
		// data members for secs, mins, hours, day, month and year.
};

#endif
