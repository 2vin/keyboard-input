#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;

using namespace std;
bool SWITCH = false;
bool TERMINATE = false;
char c;

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
            perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
    return (buf);
}


void TOGGLE()
{
	system("clear");
	
	c = ' ';
	while(c!='x')
	{
		mtx.lock();
    
		c=getch();
		if(c=='x') // Press 'x' to terminate program
		{
			TERMINATE = true;
		}
		cout<<"You pressed : "<<c<<endl;
		
    mtx.unlock();
	}

}

int main ()
{
	thread toggle(TOGGLE);
	
	while(!TERMINATE) // Pressing 'x' will exit this loop
	{
		// Do Task
	}

	toggle.join();

	return 0;
}
