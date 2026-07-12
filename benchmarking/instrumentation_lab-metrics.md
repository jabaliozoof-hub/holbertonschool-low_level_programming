## Benchmarking Results: Instrumentation Lab

### Raw Data
| Run | TOTAL (s) | BUILD_DATA (s) | PROCESS (s) | REDUCE (s) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 0.000800 | 0.000336 | 0.000315 | 0.000143 |
| 2 | 0.000771 | 0.000299 | 0.000311 | 0.000157 |
| 3 | 0.000809 | 0.000297 | 0.000352 | 0.000152 |
| **Avg** | **0.000793** | **0.000311** | **0.000326** | **0.000151** |

### Analysis
* **Observations:**
    * The **PROCESS** phase is the most time-consuming task, averaging 0.000326 seconds.
    * The **BUILD_DATA** phase follows closely, while the **REDUCE** phase is the fastest operation.
    * The sum of average sub-measurements (0.000788s) is remarkably close to the average TOTAL time (0.000793s), which confirms that the instrumentation boundaries are accurate and the overhead of the main function logic is minimal.
* **Reasoning:**
    * Profiling reveals that algorithmic complexity in data transformation (`process_dataset`) is the primary driver of execution time in this workload. This exercise demonstrates how critical it is to measure individual phases rather than the program as a whole to identify optimization targets effectively.
