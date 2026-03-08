# ARM-is-great
# Problem Statement : ARM is Great!

## Overview

As the Lead Architect at ARM, you are tasked with designing the scheduling logic for the forthcoming **“Core Conqueror 9000”** processor.

The silicon architecture consists of **M identical cores**. To maintain architectural simplicity and reduce clock skew, the processor uses a **Single Global Clock Tree**, meaning all cores must operate at the **same synchronized frequency at any given time**.

Your task is to schedule an incoming stream of **N tasks** while selecting an optimal operating frequency.

Since **power consumption increases exponentially with frequency**, even small performance improvements can significantly increase **heat generation and energy consumption**. Therefore, the goal is to design a **task scheduling and frequency scaling strategy** that balances performance and energy efficiency.

---

## Constraints

* At any given time **t**, all active cores must operate at the **same frequency `f`**, where:

```
L < f < H
```

* Power consumption depends on the number of active cores (`k`) and frequency (`f`):

```
Power Consumption = k * e^(alpha * f)
```

Where:

* `alpha` is a model-specific efficiency parameter
* `0.001 < alpha < 0.1`

---

* Each task requires a certain number of **Compute Units** to complete.

The processing rate of a core is proportional to the frequency:

```
Compute Rate = beta * f
```

Where:

* `beta` is a performance scaling constant
* `0.05 < beta < 0.5`

---

Additional conditions:

* A **single task cannot be divided across multiple cores**.
* Once assigned, a task must finish on the **same core**.
* The global frequency **can be adjusted at the beginning of any clock cycle**, but the change affects **all cores simultaneously**.

---

## Goal

Develop a **Scheduling and Frequency Scaling Algorithm** that:

1. Efficiently schedules all **N tasks**
2. Minimizes **Total Execution Time**
3. Minimizes **Total Energy Consumption**

---

## Input Specification

The algorithm receives the following inputs:

* **M** – Number of processor cores
* **L, H** – Minimum and maximum allowable frequency
* **alpha, beta** – Efficiency and performance constants
* **A list of N tasks**, each with a required **Compute Unit**

Example:

```
Task 1 : 150 Compute Units
Task 2 : 200 Compute Units
Task 3 : 90 Compute Units
Task 4 : 120 Compute Units
```

---

## Output Specification

The algorithm should produce a **schedule** that includes:

* The **selected frequency `f`** for each time interval
* The **task assigned to each core**
* The **execution order of tasks**

Example output format:

```
Time Interval 1
Frequency = 2.5 GHz
Core 1 → Task 1
Core 2 → Task 3
Core 3 → Task 4

Time Interval 2
Frequency = 3.0 GHz
Core 1 → Task 2
Core 2 → Task 5
Core 3 → Idle
```

---

## Objective

Design an algorithm that balances:

* **Performance (Execution Time)**
* **Energy Efficiency (Power Consumption)**

by intelligently selecting **core allocation** and **frequency scaling**.

The final solution should ensure that all tasks are completed while minimizing both **total execution time** and **overall energy consumption**.
