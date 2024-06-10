#include <iostream>
#include <cstring>
#include "timer.h"

int main(int argc, char *argv[])
{
    std::size_t session_duration = 15;
    std::size_t break_duration = 5;

    for (int n = 1; n < argc; ++n)
    {
        if (std::strcmp(argv[n], "-h") == 0)
        {
            std::cout << "Help:" << std::endl;
            std::cout << "Syntax: pomodoro [-h (this Site)] [-s {Session duration in minutes}] [-b {Break duration in minutes}]" << std::endl;
        }
        else if (std::strcmp(argv[n], "-s") == 0)
        {
            try
            {
                session_duration = std::stoi(argv[++n]);
            }
            catch (std::invalid_argument const &ex)
            {
                std::cerr << "Invalid argument for flag \"-s\": " << argv[n] << std::endl;
                std::cout << "User flag \"-h\" for help" << std::endl;
                return 1;
            }
            catch (std::out_of_range const &ex)
            {
                std::cerr << "Argument out of range for flag \"-s\": " << argv[n] << std::endl;
                std::cout << "User flag \"-h\" for help" << std::endl;
                return 1;
            }
        }
        else if (std::strcmp(argv[n], "-b") == 0)
        {
            try
            {
                break_duration = std::stoi(argv[++n]);
            }
            catch (std::invalid_argument const &ex)
            {
                std::cerr << "Invalid argument for flag \"-s\": " << argv[n] << std::endl;
                std::cout << "User flag \"-h\" for help" << std::endl;
                return 1;
            }
            catch (std::out_of_range const &ex)
            {
                std::cerr << "Argument out of range for flag \"-s\": " << argv[n] << std::endl;
                std::cout << "User flag \"-h\" for help" << std::endl;
                return 1;
            }
        }
        else
        {
            std::cout << "Invalid flag: " << argv[n] << ", use -h for help" << std::endl;
        }
    }
    timer::launch_timer(session_duration, break_duration);
}