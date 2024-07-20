# ChadaClock

A simple C++ clock application that allows you to manage and display time in both 12-hour and 24-hour formats. The application provides a text-based menu to interact with the clock, where you can increment hours, minutes, and seconds.

## Features

- **Time Management**: Increment hours, minutes, or seconds.
- **Time Display**: Show time in both 12-hour and 24-hour formats.
- **Menu Interface**: Simple text-based menu for interaction.

## Getting Started

### Prerequisites

Make sure you have a C++ compiler installed (e.g., g++, clang++). You can check for installation by running:

```bash
g++ --version
```

### Compilation

To compile the application, run the following command in your terminal:

```bash
g++ -o ChadaClock main.cpp
```

### Running the Application

After compiling, you can run the application with:

```bash
./ChadaClock
```

### Menu Options

Once the application starts, you will see a menu with the following options:

1. **Add One Hour**: Increment the hour by 1.
2. **Add One Minute**: Increment the minute by 1.
3. **Add One Second**: Increment the second by 1.
4. **Exit**: Exit the application.

Select an option by entering the corresponding number.

## Code Overview

### Key Functions

- `getHour()`, `setHour(int h)`: Get and set the current hour.
- `getMinute()`, `setMinute(int m)`: Get and set the current minute.
- `getSecond()`, `setSecond(int s)`: Get and set the current second.
- `twoDigitString(unsigned int n)`: Converts a number to a two-digit string.
- `formatTime24(unsigned int h, unsigned int m, unsigned int s)`: Formats time in 24-hour format.
- `formatTime12(unsigned int h, unsigned int m, unsigned int s)`: Formats time in 12-hour format.
- `printMenu(char* strings[], unsigned int numStrings, unsigned char width)`: Prints a formatted menu.
- `getMenuChoice(unsigned int maxChoice)`: Gets a valid menu choice from the user.
- `displayClocks(unsigned int h, unsigned int m, unsigned int s)`: Displays the current time in both formats.
- `addOneSecond()`, `addOneMinute()`, `addOneHour()`: Increment time components.
- `mainMenu()`: Displays the menu and handles user input.

## Contributing

Feel free to open issues or submit pull requests for improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

