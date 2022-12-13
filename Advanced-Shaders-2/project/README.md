# Project 10: Advanced Shaders 2
Authors: Andrew Esch and Evan Lee

Date: 12-18-2022

## Software Requirements and Installation Guide
This program is designed to run in C on the Linux platform. To compile and run the program in Ubuntu 20.04, install the latest version of the g++ compiler, run the following command in an terminal window (with sudo permissions):
- sudo apt install g++

Also, please ensure that the g++ compiler is up-to-date by running the following command (for Ubuntu):
- g++ --version

The intended G++ version for Ubuntu 20.04 is 9.4.0. If your instance of Linux does not have this version, please update by using the following commands:
- sudo apt update
- sudo apt upgrade

### Linux Package Requirements
After installing and updating the G++ compiler to the latest version, please install the following libraries for Linux
- freeglut3-dev
- mesa-common-dev
- libglu1-mesa-dev
- libglew-dev
- libglfw3-dev
- libsoil-dev
- libglm-dev
- libassimp-dev

To install all of the package requirements for this program in one line, run the following command below:
- sudo apt-get install freeglut3-dev mesa-common-dev libglu1-mesa-dev libglew-dev libglfw3-dev libsoil-dev libglm-dev libassimp-dev

### Additional Installation Instructions for WSL2 on Windows 10
Linux environments on WSL2 have been tested and verified to run all project files. However, the setup process for running program files in this project is different between Windows 10 and Windows 11.

Windows 11 supports WSLg by default, which directly enables users to compile all program files in this project. However, Window 10 with WSL2 requires starting a remote desktop session with XRDP server on localhost.

To see more instructions on setting up the WSL2 environment for Windows 10, refer to the following links:
- https://harshityadav95.medium.com/install-gui-desktop-in-wsl2-ubuntu-20-04-lts-in-windows-10-ae0d8d9e4459
- https://www.briteccomputers.co.uk/posts/ubuntu-on-windows-10-with-wsl2-and-gui-setup-via-remote-desktop-2/

## Compiling and Running the Program
To compile the program properly, open a terminal window and use g++ to compile the program by using the following command:
- g++ {c-program-file-name.c} -o {insert-new-compiled-file-name-here} -lglfw -lGL -lGLEW -lSOIL -lassimp

A new compiled file will appear within the directory that the user is currently located in.

To run the program after compiling it, change the terminal directory to match the directory location of the compiled file and use the following to run it:
- ./{compiled-file-name}