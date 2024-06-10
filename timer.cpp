//
// Created by timomt on 6/10/24.
//

#include "timer.h"

// timer -------------------------------------------

namespace timer
{
void launch_timer(std::size_t session_duration, std::size_t break_duration)
{
    std::string session_name = "Session";
    launch_timer_session(session_duration, session_name);
    session_name = "Break";
    launch_timer_session(break_duration, session_name);
}

void launch_timer_session(std::size_t session_duration, const std::string &session_name)
{
    std::size_t session_duration_seconds = session_duration * 60;
    for (std::size_t i = 0; i <= session_duration_seconds; ++i)
    {
        std::size_t remaining_seconds = session_duration_seconds - i;
        clear_screen();
        move_to(7, 5);
        std::cout << R"(
         ____                           _
        |  _ \ ___  _ __ ___   ___   __| | ___  _ __ ___
        | |_) / _ \| '_ ` _ \ / _ \ / _` |/ _ \| '__/ _ \
        |  __/ (_) | | | | | | (_) | (_| | (_) | | | (_) |
        |_|   \___/|_| |_| |_|\___/ \__,_|\___/|_|  \___/

        )";
        std::cout << session_name << ": [" << session_duration << ":00]" << "\t\t\tRemaining: [" <<
                  remaining_seconds / 60 << ":" << remaining_seconds % 60 << "]" << std::endl << std::endl;
        timer::show_progress_bar(
            static_cast<std::size_t>((static_cast<double>(i) / static_cast<double>(session_duration_seconds)) * 100));
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    timer::ansi_bell();
    timer::clear_screen();
}

void clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

void ansi_bell()
{
    std::cout << "\07";
}

void move_to(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H";
}

void show_progress_bar(std::size_t percentage)
{
    std::cout << "\033[1G\t[";
    std::size_t pos = percentage / 2;
    for (std::size_t i = 0; i < 50; ++i)
    {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << percentage << " %" << std::flush;
}
}