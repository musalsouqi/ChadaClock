//Mustafa Alsouqi
//Project 1 
//Cs-210-11405-M01
//Dr.Faisal Shakeel

#include "ChadaClock.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

static int currentHour = 0;
static int currentMinute = 0;
static int currentSecond = 0;

// Getter and Setters
int getHour() {
    return currentHour;
}

void setHour(int h) {
    if (h >= 0 && h < 24) {
        currentHour = h;
    }
}

int getMinute() {
    return currentMinute;
}

void setMinute(int m) {
    if (m >= 0 && m < 60) {
        currentMinute = m;
    }
}

int getSecond() {
    return currentSecond;
}

void setSecond(int s) {
    if (s >= 0 && s < 60) {
        currentSecond = s;
    }
}

int main() {
    //starts menu
    mainMenu();
    return 0;
}
std::string twoDigitString(unsigned int n) {
    std::ostringstream oss;
    // set the width to 2 and fill with 0
    oss << std::setw(2) << std::setfill('0') << n;
    // Convert the stream to a string and return
    return oss.str();
}
std::string nCharString(size_t n, char c) {
    // initialize the string
    std::string result(n, c);
    // Returns the string
    return result;
}
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // Formats hours minutes and seconds
    std::string hours = twoDigitString(h);
    std::string minutes = twoDigitString(m);
    std::string seconds = twoDigitString(s);

    // Combines the strings
    return hours + ":" + minutes + ":" + seconds;
}
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    std::string period = (h < 12) ? "A M" : "P M";
    unsigned int hour12 = h % 12;
    if (hour12 == 0) {
        hour12 = 12;
    }

    std::string hours = twoDigitString(hour12);
    std::string minutes = twoDigitString(m);
    std::string seconds = twoDigitString(s);

    return hours + ":" + minutes + ":" + seconds + " " + period;
}
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    // Prints the top border
    std::cout << nCharString(width, '*') << std::endl;

    // Loops through each item and prints it
    for (unsigned int i = 0; i < numStrings; ++i) {
        std::string item = strings[i];
        std::string itemNumber = std::to_string(i + 1);

        // Calculates spaces needed to align the right border
        size_t totalLength = 2 + itemNumber.length() + 3 + item.length();
        size_t spaces = width - totalLength - 1;

        // Print the item
        std::cout << "* " << itemNumber << " - " << item << nCharString(spaces, ' ') << "*" << std::endl;

        // Skip a line after each line except the last line
        if (i < numStrings - 1) {
            std::cout << std::endl;
        }
    }

    // Prints the bottom border of the menu
    std::cout << nCharString(width, '*') << std::endl;
}
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    // Loops until a valid choice is entered
    while (true) {
        // Reads the input
        std::cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break; 
        }
        // Clears the input stream if the input is invalid
        std::cin.clear(); //i dont think il need this
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores invalid input
    }
    // Returns the choice
    return choice;
}
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    std::string stars27 = nCharString(27, '*');
    std::string spaces3 = nCharString(3, ' ');

    std::string time12 = formatTime12(h, m, s);
    std::string time24 = formatTime24(h, m, s);

    // Print the top border
    std::cout << stars27 << spaces3 << stars27 << std::endl;

    // Print the titles
    std::cout << "*      12-HOUR CLOCK      *" << spaces3 << "*      24-HOUR CLOCK      *" << std::endl;

    std::cout << std::endl;

    // Print the times
    std::cout << "*      " << time12 << "       *" << spaces3 << "*        " << time24 << "         *" << std::endl;

    // Prints the bottom border
    std::cout << stars27 << spaces3 << stars27 << std::endl;
}
void addOneSecond() {
    int second = getSecond();

    if (second >= 0 && second < 59) {
        // If seconds are between 0 and 58 just add one second
        setSecond(second + 1);
    }
    else if (second == 59) {
        // If seconds are 59 wrap around to 0 and add one minute
        setSecond(0);
        addOneMinute();
    }
}
void addOneMinute() {
    int minute = getMinute();

    if (minute >= 0 && minute < 59) {
        // If minutes are between 0 and 58 just add one minute
        setMinute(minute + 1);
    }
    else if (minute == 59) {
        // If minutes are 59 wrap around to 0 and add one hour
        setMinute(0);
        addOneHour();
    }
}
void addOneHour() {
    int hour = getHour();

    if (hour >= 0 && hour < 23) {
        // If hours are between 0 and 22 just adds one hour
        setHour(hour + 1);
    }
    else if (hour == 23) {
        // If hours are 23, wrap around to 0
        setHour(0);
    }
}
void mainMenu() {
    unsigned int choice;

    do {
        // Get the user's choice from the menu
        choice = getMenuChoice(4);

        // Call the appropriate function based on the user's choice. 
        // FIX ME!!!!!!!!! i think this is still broken come back and fix.
        switch (choice) {
        case 1:
            addOneHour();
            break;
        case 2:
            addOneMinute();
            break;
        case 3:
            addOneSecond();
            break;
        case 4:
            // Exit choice does nothing
            break;
        default:
            std::cout << "Invalid choice. Please choose between 1 and 4." << std::endl;
            break;
        }
    } while (choice != 4);
}
