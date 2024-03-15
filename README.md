# Philosophers

The Philosophers project introduces learners to the concept of concurrency using threads and processes in the C programming language. It focuses on solving the famous Dining Philosophers problem, a classic computer science problem in concurrency.

## Overview

Concurrency is a crucial concept in modern computing, allowing programs to perform multiple tasks simultaneously and efficiently utilize system resources. The Philosophers project provides an opportunity to delve into concurrency in C, exploring both thread-based and process-based solutions to the Dining Philosophers problem.

## Key Concepts Covered

- Concurrency and Parallelism
- Thread Creation and Management
- Process Creation and Communication
- Synchronization and Mutual Exclusion
- Deadlock Prevention and Avoidance

## Solutions Implemented In This Project

- **Thread-Based Solution:** Implement a solution using POSIX threads (pthread library) to simulate philosophers dining and avoid deadlocks.
- **Process-Based Solution:** Explore a solution using processes (fork()) to model the dining philosophers problem with separate address spaces.
- **Resource Management:** Learn how to manage shared resources (such as forks) among multiple threads/processes to prevent conflicts.
- **Synchronization Techniques:** Apply synchronization techniques such as mutex locks, semaphores, and condition variables to coordinate access to shared resources.
- **Error Handling:** Handle errors and edge cases related to concurrency, including deadlock detection and resolution.

## Resources

- [POSIX Threads Programming](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
- [Concurrency in C Programming](https://www.geeksforgeeks.org/multithreading-in-c/)
- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
