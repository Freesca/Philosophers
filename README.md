# 42 Philosopher

### Description

42 Philosopher is a project from the 42 School curriculum designed to simulate the famous Dining Philosophers Problem. This classic synchronization problem helps you understand how to handle concurrent processes, mutexes, and thread synchronization in a shared resource environment.

In this implementation, each philosopher alternates between eating, thinking, and waiting for forks (shared resources) to simulate real-life resource contention scenarios. The primary challenge is ensuring that deadlocks and race conditions are avoided while maintaining fairness between the philosophers.
Note on Data Structure:

In this project, linked lists were used instead of arrays to represent philosophers and forks. While lists provide flexibility in some cases, this choice is not optimal for performance, particularly in terms of memory usage and cache efficiency. Arrays would typically provide better optimization and faster access in scenarios like this.
Features

  Multithreading: Each philosopher runs in its own thread to simulate real concurrency.
  Mutexes for Forks: Mutexes are used to control access to forks and prevent race conditions.
  Avoiding Deadlocks: Implements strategies to prevent deadlocks, such as allowing philosophers to pick up forks only when both are available.
  Linked List Implementation: Philosophers and forks are stored in a circular linked list rather than arrays, which adds some flexibility but impacts performance and memory optimization.

### System Requirements

To run the 42 Philosopher project, you will need:

    GCC or any other C compiler that supports multithreading.
    POSIX Threads (pthreads): The project relies on the POSIX threads library for managing concurrent threads.

### Installation
##### Clone the Repository

First, clone the project repository:

    git clone https://github.com/your-username/philosopher.git
    cd philosopher

##### Compilation

To compile the project, simply run the make command in the project directory:

    make

This will generate the philosopher executable.
##### Running

Once compiled, you can run the philosopher simulation with:

    ./philosopher <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

  <number_of_philosophers>: Number of philosophers and forks.
  <time_to_die>: Time (in milliseconds) before a philosopher dies if they don't start eating.
  <time_to_eat>: Time (in milliseconds) a philosopher spends eating.
  <time_to_sleep>: Time (in milliseconds) a philosopher spends sleeping after eating.
  [number_of_times_each_philosopher_must_eat] (optional): If specified, the simulation ends once each philosopher has eaten this many times.

Example:

./philosopher 5 800 200 200

This command will simulate 5 philosophers, with each philosopher dying if they don't start eating within 800ms, eating for 200ms, and sleeping for 200ms.
### Project Structure

  src/: Contains the .c source files.
  include/: Contains the .h header files.
  Makefile: Build script for compiling the project.
  README.md: This file.

### Known Issues

  Performance Limitation Due to Linked Lists: The use of linked lists in this project may lead to slower performance and higher memory usage compared to using arrays. Linked lists add flexibility but are less efficient in terms of memory access and cache usage. Arrays would typically be more optimized for this kind of simulation.

  Thread Scheduling: Depending on the operating system's thread scheduler, there may be cases where philosophers don't act as "fairly" as expected. This could result in some philosophers getting more eating time than others, depending on system load and timing.
