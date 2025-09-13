# Cache Replacement Policy Evaluation

A computer architecture project implementing and analyzing classical and novel cache replacement policies within the ChampSim simulator.

## Overview

This repository contains the source code and report for a university project focused on evaluating the performance of different cache replacement algorithms. The project extends the ChampSim simulator, a trace-based CPU cache hierarchy simulator, to include several policies. Their performance is measured and compared using standard metrics like Miss Rate, Hit Rate, and Cumulative IPC.

## Implemented Policies

The following cache replacement policies have been implemented and evaluated:

*   **LRU (Least Recently Used):** Evicts the block that has not been accessed for the longest time.
*   **LFU (Least Frequently Used):** Evicts the block that has been accessed the least number of times.
*   **MRU (Most Recently Used):** Evicts the block that was accessed most recently.
*   **FIFO (First-In, First-Out):** Evicts the block that has been in the cache the longest, regardless of access patterns.
*   **ETA (Estimated Time of Access) / Paper-Based Policy:** A novel policy based on the paper ["A Low-cost Predictor-based Cache Replacement Policy for Last-Level Caches"](https://doi.org/10.1145/3528414.3528433). It predicts the reuse distance of cache lines to make smarter eviction decisions.

## Project Structure
cache-replacement-policy-evaluation/
│
├── champ-sim/ # The modified ChampSim source code
│ ├── replacement/ # Directory containing the custom replacement policy implementations
│ └── ...
├── traces/ # Directory for memory access traces (not included in repo)
├── results/ # Output results from simulations (CSV, graphs, etc.)
├── report/ # Project report (analysis, conclusions, etc.)
└── README.md

## Results and Analysis
The project report (in Persian) provides a detailed analysis of the results, including:
- Comparison of Miss Rate and Hit Rate for each policy.
- Analysis of Cumulative IPC (Instructions Per Cycle).
- Discussion on the hardware complexity and cost of implementing the novel ETA policy.
- Conclusions on the effectiveness of each algorithm in different caching layers.
