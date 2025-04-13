# Philosophers  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![42 logo little](https://github.com/user-attachments/assets/4cecf5b8-a28e-49c5-a4b1-2030e571a0b3)

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  

## Introduction  

`Philosophers` is a concurrency programming project simulating the famous **[Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)**.  
It introduces the basics of **threads**, **mutexes**, and **synchronization** in C.  

The program manages several philosophers sitting around a table, alternating between **thinking, eating, and sleeping**.  
To eat, a philosopher must pick up the fork to their left and the fork to their right.  
The challenge is to ensure that no philosopher **dies from starvation**, while avoiding **race conditions** and **deadlocks**.  

## Example Simulation  
```sh
timestamp_in_ms 1 X has taken a fork  
timestamp_in_ms 2 X has taken a fork  
timestamp_in_ms 3 X is eating  
timestamp_in_ms 10 X is sleeping  
timestamp_in_ms 15 X is thinking  
timestamp_in_ms 20 X died  
```

## Features  

- **Multi-threaded simulation**:  
  - Each philosopher is represented by a distinct **[thread](https://en.wikipedia.org/wiki/Thread_(computing))**.  
  - Forks are protected by **[mutexes](https://en.wikipedia.org/wiki/Mutex)** to prevent simultaneous access.  

- **Rules**:  
  - Each philosopher must **eat**, **think**, and **sleep**.  
  - A philosopher needs **two forks** to eat.  
  - If they don't eat within a **time limit**, they **die**.  
  - The simulation stops if **a philosopher dies** or if all philosophers have eaten a defined number of times.  

- **Synchronization & Timing**:  
  - State changes (taking a fork, eating, sleeping, thinking, dying) are displayed **without overlapping**.  
  - The **death message** of a philosopher must appear **within 10ms** of their actual death.  

## Usage  

### 1. Compile the project:  
```sh
make  
```

### 2. Run the simulation:  
```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]  
```

**Arguments**:  
- `number_of_philosophers`: The number of philosophers (and forks).  
- `time_to_die` (ms): The time before a philosopher dies if they haven’t eaten.  
- `time_to_eat` (ms): The time it takes to eat (while holding two forks).  
- `time_to_sleep` (ms): The sleep time before thinking again.  
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation ends once all philosophers have eaten this number of times.  

### 3. Example execution:  
```sh
./philo 4 410 200 200  
```

## Screenshot

<img width="218" alt="Capture d’écran 2024-08-02 à 02 34 22" src="https://github.com/user-attachments/assets/7c97f9e1-1a4b-4fd6-a9fb-2cffc1a78794">
