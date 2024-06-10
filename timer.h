//
// Created by timomt on 6/10/24.
//

#ifndef POMODORO_TIMER_H
#define POMODORO_TIMER_H

#include <cstddef>
#include <iostream>
#include <thread>
#include <fstream>
#include <streambuf>
#include <sstream>

namespace timer
{
/*
 * launch_timer
 * Used to invoke necessary functions
 * for the timer to begin properly
 * @param session_duration - duration for a learning session in minutes
 * @param break_duration - duration for a break in between learning sessions in minutes
 * */
void launch_timer(std::size_t session_duration, std::size_t break_duration);

/*
 * launch_timer_session
 * Launches the actual timer
 * @param session_duration - duration for a session in minutes
 * @param session_name - the name to be displayed
 * */
void launch_timer_session(std::size_t session_duration, const std::string &session_name);

/*
 * clear_screen
 * Used to clear the terminal emulator window
 * using ANSI escape codes
 * */
void clear_screen();

/*
 * ansi_bell
 * Makes an audible noise
 * using ANSI escape codes
 * */
void ansi_bell();

/*
 * move_to
 * Moves the cursor to the specified location
 * using ANSI escape codes
 * @param x - x-coordinate
 * @param y - y-coordinate
 * */
void move_to(int x, int y);

/*
 * show_progress_bar
 * Displays a progress bar
 * according to the percentage given
 * @param percentage - percentage of the progress bar
 * */
void show_progress_bar(std::size_t percentage);
}

#endif //POMODORO_TIMER_H