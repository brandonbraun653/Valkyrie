# Valkyrie Kernel
This directory forms the core of all Valkyrie functionality, effectively a "kernel" if you will.

## Data
Valkyrie houses a database of sorts to distribute system information across multiple threads in a safe way. For instance, multiple modules may
be interested in Gyro data, but for completely different purposes. The control system needs the information quickly and must ensure its validity
but the data logger or rotation event monitor also need the information and may happen to live in two different threads. This juncture of
multi-threaded access to the same data at different rates yields an interesting problem that can be solved by a MIMO database. This folder stores
all the configuration, registration, and some update methods for achieving this goal.


## Startup
As the name implies, this folder contains software that boots up the application and prepares the system for execution.