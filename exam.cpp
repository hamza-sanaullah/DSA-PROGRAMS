#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <chrono>

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void centerText(const string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    // Get the number of columns in the console
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calculate the number of spaces to insert before the text
    int spaces = (columns - text.length()) / 2;

    // Print the spaces and then the text
    for (int i = 0; i < spaces; ++i) {
        cout << " ";
    }
    cout << text << endl;
}

void loadingSpinner(int duration) {
    const char spinnerChars[] = {'|', '/', '-', '\\'};
    int spinnerIndex = 0;

    for (int i = 0; i < duration * 10; ++i) {
        cout << "\rProcessing " << spinnerChars[spinnerIndex] << flush;
        spinnerIndex = (spinnerIndex + 1) % 4;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\rProcessing complete!   " << std::endl;
}

void typingEffect(const string& text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cout << std::endl;
}

int main() {
    setConsoleColor(10); // Set text color to green

    std::string asciiArt[] = {
        "/   _____/_____   ____ |  | |  |     ____ |  |__   ____   ____ |  | __ ___________ ",
        "\\_____  \\\\____ \\_/ __ \\|  | |  |   _/ ___\\|  |  \\_/ __ \\_/ ___\\|  |/ // __ \\_  __ \\",
        "/        \\  |_> >  ___/|  |_|  |__ \\  \\___|   Y  \\  ___/\\  \\___|    <\\  ___/|  | \\/",
        "/_______  /   __/ \\___  >____/____/  \\___  >___|  /\\___  >\\___  >__|_ \\\\___  >__|   ",
        "        \\/|__|        \\/                 \\/     \\/     \\/     \\/     \\/    \\/    "
    };

    for (const std::string& line : asciiArt) {
        centerText(line);
    }

    setConsoleColor(7); // Reset to default color

    // Display a bordered welcome message
    setConsoleColor(11); // Set text color to cyan
    std::string welcomeMessage = "Welcome to the Spell Checker Program!";
    centerText(welcomeMessage);
    setConsoleColor(7); // Reset to default color

    // Simulate a loading spinner
    loadingSpinner(5); // Spinner for 5 seconds

    // Typing effect for output messages
    setConsoleColor(14); // Set text color to yellow
    typingEffect("Press 1 to Check a Word");
    typingEffect("Press 2 to Add a Word");
    typingEffect("Press 3 to Exit");
    setConsoleColor(7); // Reset to default color

    return 0;
}
