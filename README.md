# keyboard-input
Live keyboard input display without 'Enter' key    

This program can be used to create own applications like notepad in C++. It reads live keypresses from the keyboard and display them on the screen.    

# Compile    
g++ keyStroke.cpp -o main -lpthread -std=c++11    

# Usage    
./main    

It should print live keypresses on terminal screen. Edit the `TOGGLE()` thread and/or `while(!TERMINATE)` to make it suitable for your use case.


