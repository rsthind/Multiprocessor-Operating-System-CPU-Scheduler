# Multiprocessor-Operating-System-CPU-Scheduler
</br>

These are the sceduling algorithms that I implemented: </br>
</br>
1. First Come, First Serve (FCFS) - Runnable processes are kept in a ready queue. FCFS is non- preemptive; once a process begins running on a CPU, it will continue running until it either completes or blocks for I/O. </br>
2. Shortest Job First (SJF) - The SJF scheduler looks at the CPU burst times needed by the current set of processes that are ready to run and picks the one that needs the shortest CPU burst. SJF is also non-preemptive. </br>
3. Round-Robin - Similar to FCFS, except preemptive. Each process is assigned a timeslice when it is scheduled. At the end of the timeslice, if the process is still running, the process is preempted, and moved to the tail of the ready queue. </br>
4. Shortest Remaining Time First (SRTF) - The process with the shortest remaining time in its burst always gets the CPU. Longer processes must be pre-empted if a process that has a shorter burst becomes runnable. </br>
</br>

## Testing
</br>

./os-sim <# of CPUs>
