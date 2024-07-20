// ChadaClock.h

#ifndef CHADA_CLOCK_H
#define CHADA_CLOCK_H

// Function prototypes
int getHour();
void setHour(int h);
int getMinute();
void setMinute(int m);
int getSecond();
void setSecond(int s);

void addOneHour();
void addOneMinute();
void addOneSecond();
void mainMenu();
void displayClocks(unsigned int h, unsigned int m, unsigned int s);

#endif // CHADA_CLOCK_H