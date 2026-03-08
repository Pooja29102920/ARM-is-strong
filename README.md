# ARM-is-great
Problem Statement : ARM is great!
As the Lead Architect at ARM, you are tasked with designing the scheduling logic for the 
forthcoming “Core conqueror 9000” processor. The silicon architecture comprises M identical 
cores. To uphold architectural simplicity and mitigate clock skew, the processor employs a Single 
Global Clock Tree. This necessitates that each core operates at a precisely synchronized frequency 
at all times. Your objective is to schedule the incoming stream of N tasks. Given that power 
consumption exhibits exponential growth with frequency, a marginal enhancement in performance 
results in a substantial surge in heat generation and energy expenditure. Consequently, you must 
ascertain the optimal frequency and task allocation strategy.
Constraint:
• At any given time t, all active cores must operate at a same frequency f, where L < f < H.
• The power consumption P of the processor is determined by the number of active cores (k) 
and the frequency (f): Power Consumption = k * e^(alpha * f), where alpha is a model
specific efficiency parameter (0.001 < alpha < 0.1).
• Each task i requires a specific amount of “Compute Unit” to complete. The rate at which a 
core processes a task is directly proportional to the frequency: Compute Unit = beta * f, 
where beta is a model-specific performance scalar (0.05 < beta < 0.5).
• A single task cannot be divided across multiple cores; it must be completed on the core to 
which it was assigned.
• The global frequency f can be adjusted at the beginning of any clock cycle, but this 
adjustment will affect all tasks currently in execution.
Goal:
Develop a scheduling and frequency-scaling algorithm that efficiently manages all N tasks, 
optimizing the Total Execution Time while concurrently minimizing the Total Energy Consumption.
Input Specification:
• M: Number of cores.
• L, H: Minimum and Maximum allowable frequency.
• alpha, beta: Efficiency and Performance constants.
• A list of N tasks, each with a required Compute unit.
Output Specification:
• A schedule that displays the selected frequency f for each time interval and the task assigned 
to each core in the order of execution.
