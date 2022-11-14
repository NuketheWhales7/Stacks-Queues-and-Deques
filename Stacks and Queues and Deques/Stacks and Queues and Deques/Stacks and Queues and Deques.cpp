// Stacks and Queues and Deques.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Christopher Miller
//CIS-2542 Net 01

// Include files
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

int main()
{
    // Your passcodes
    std::string stackString = "GI7DE1GINJTHGN";
    std::string queueString = "OANRBIONWDYG";
    std::string dequeString = "01IM45RWXH";

    // Create an empty stack
    std::stack<char> s;
    // Forward iterate through stackString and push each character onto your stack
    for (int i = 0; i < stackString.length(); i++) 
    {
        s.push(stackString[i]);
    }

    // Create an empty queue
    std::queue<char> q;
    // Forward iterate through queueString and push each character into your queue
    for (int i = 0; i < queueString.length(); i++) 
    {
        q.push(queueString[i]);
    }

    // Create an empty deque
    std::deque<char> d;
    // Forward iterate through dequeString and push each character into the front of your deque
    for (int i = 0; i < dequeString.length(); i++) {
        d.push_front(dequeString[i]);
    }
    // Your command list
    std::string commands = "2F145IF41268Q76963G5W651761W2W53G67JR1523F7W87897896769W85A4D2W85W7942357H87E8R77654";

    // Forward iterate through the commands string and do the following for each character you find:
    for (int i = 0; i < commands.length(); i++) 
    {
        // 1 = Pop the queue
        if (commands[i] == '1')
        {
            q.pop();
        }
        // 2 = Pop the front of the deque
        else if(commands[i]=='2')
        {
            d.pop_front();
        }
        // 3 = Pop the back of the deque
        else if (commands[i] == '3') 
        {
            d.pop_back();
        }
        // 4 = Pop the stack
        else if (commands[i] == '4') 
        {
            s.pop();
        }
        // 5 = COPY the top of the stack into the queue
        else if (commands[i] == '5') 
        {
            q.push(s.top());
        }
        // 6 = MOVE the front of the queue onto the stack
        else if (commands[i] == '6') 
        {
            int q_front = q.front();//grabs the front element of the queue
            q.pop(); //removes it from queue
            s.push(q_front);//puts the element of the queue into the stack
        }
        // 7 = COPY the front of the queue into the queue
        else if (commands[i] == '7') 
        {
            q.push(q.front());
        }
        // 8 = MOVE the top of the stack into the back of the deque
        else if (commands[i] == '8') 
        {
            int s_top = s.top(); //grabs the top of the stack
            s.pop(); //removes it from the stack
            d.push_back(s_top);//puts the element to the back of deque
        }
        // ANYTHING ELSE = Do nothing with all of the three data structures
        //  COPY means to get data from one data structure and copy it into another (maybe the same one)
        //  - One data structure will keep all its elements
        //  - The other data structure will gain an element
        //  MOVE means to remove data from one structure and place it into another (maybe the same one)
        //  - One data structure will lose an element
        //  - The other data structure will gain an element
    }
    // Keep this printout to the console
    std::cout << "Statistically speaking... What time might it be right now?" << std::endl;

    // The deque will now have the secret phrase, so forward iterate through it and print it out
    while (d.size() != 0) 
    {
        std::cout << d.front();
        d.pop_front();
    }
    //Prints "MIDNIGHT"
    return 0;
}

