# Operating Systems

Based on the book [Operating Systems](http://ostep.org).

## Virtualisation

### Processes

The **process** is the major OS abstraction of a running program. At any point in time, the process can be described by its state: the contents of memory in its address space, the contents of CPU registers (including the program counter and stack pointer, among others), and information about I/O (such as open files which can be read or written).

The **process API** consists of calls programs can make related to processes. Typically, this includes creation, destruction, and other useful calls.

Processes exist in one of many different **process states**, including running, ready to run, and blocked. Different events (e.g., getting scheduled or descheduled, or waiting for an I/O to complete) tran- sition a process from one of these states to the other.

A **process list** contains information about all processes in the sys- tem. Each entry is found in what is sometimes called a process control block (PCB), which is really just a structure that contains information about a specific process.

### Limited Direct Execution

The CPU should support at least two modes of execution: a restricted **user mode** and a privileged (non-restricted) **kernel mode**.

Typical user applications run in user mode, and use a **system call** to **trap** into the kernel to request operating system services.

The trap instruction saves register state carefully,changes the hardware status to kernel mode, and jumps into the OS to a pre-specified destination: the trap table.

When the OS finishes servicing a system call, it returns to the user program via another special **return-from-trap** instruction, which reduces privilege and returns control to the instruction after the trap that jumped into the OS.

The trap tables must be set up by the OS at boot time, and make sure that they cannot be readily modified by user programs. All of this is part of the **limited direct execution** protocol which runs programs efficiently but without loss of OS control.

Once a program is running,the OS must use hardware mechanisms to ensure the user program does not run forever, namely the **timer interrupt**. This approach is a **non-cooperative** approach to CPU scheduling.

Sometimes the OS, during a timer interrupt or system call, might wish to switch from running the current process to a different one, a low-level technique known as a **context switch**.

### Scheduling

#### Scheduling Metrics

The **turnaround time** of a job is defined as the time at which the job completes minus the time at which the job arrived in the system, i.e. $T_{turnaround} = T_{completions} - T_{arrival}$.

The **response time** metric is defined as the time from when the job arrives in a system to the first time it is scheduled, i.e. $T_{response} = T_{firstrun} - T_{arrival}$. (Some include the also the time until the job produces some kind of "response".)

#### Scheduling Policies

**First in, first out** (FIFO) policy has an issue if a number of relatively-short potential consumers of a resource get queued behind a heavyweight resource consumer. This problem is generally referred to as the **convoy effect**.

**Shortest job first** (SJF) runs the shortest job first, then the next shortest, and so on. It has an issue if the longest job arrives before all the short ones.

**Shortest time-to-completion first** (STCF) or **Preemptive shortest job first** (PSJF) runs the job that has the least time to completion, including the new jobs.

**Round Robin** (RR) runs a job for a **time slice** and then switches to the next job in the run queue.

SJF and STCF optimizes turnaround time, but is bad for response time, RR optimizes response time but is bad for turnaround.

**Multi-level feedback queue** (MLFQ) varies the priority of a job based on its observed behavior. (E.g. job repeatedly relinquishes the CPU while waiting for input from the keyboard will have a priority high - sign of an interactive process.)

The **job’s allotment** is the amount of time a job can spend at a given priority level before the scheduler reduces its priority.

The rules of MLFQ:

- Rule 1: If Priority(A) > Priority(B), A runs (B doesn’t).
- Rule 2: If Priority(A) = Priority(B), A & B run in round-robin fashion using the time slice (quantum length) of the given queue.
- Rule 3: When a job enters the system, it is placed at the highest priority (the topmost queue).
- Rule 4: Once a job uses up its time allotment at a given level (regardless of how many times it has given up the CPU), its priority is reduced (i.e., it moves down one queue).
- Rule 5: After some time period S, move all the jobs in the system to the topmost queue.

**Lottery scheduling** assigns number of tickets to each job that is proportional to it's 'priority'. Then generates a random number, the process that has ticket with that number is chosen to run. This scheduler is fair only in the long run.

**Stride scheduling** is a deterministic fair-share scheduler. Each job in the system has a stride and pass values. The stride is inversly proportional to the number of tickets. (E.g division of a large number by the number of tickets). The pass is a counter incremented by stride each time a job runs. The job with lowest pass value is scheduled.

**Completely fair scheduler** (CFS) gives each process a virtual runtime (vruntime) that accumulates the physical time the process run, i.e. $vruntime +\!\!= time\_slice$. The process with lowest vruntime is scheduled. The control parameters sched_latency and min_granularity are used to determine the process time slice. For $n$ processes running this gives
$$time\_slice = \max(min\_granularity, \frac{sched\_latency}{n}) \,.$$
To take into account the priority of processes, CFS uses the **nice** level of a process (Unix mechanism) and converts it to weight. Then the calculation changes to
$$time\_slice_k = \frac{weight_k}{\sum_{i=0}^{n-1} weight_i} sched\_latency \,.$$
The vruntime updates as follows
$$vruntime_i +\!\!= \frac{weight_0}{weight_i} runtime_i \,.$$

### Memory

**Address space** is the running program’s view of memory in the system and contains all of the memory state of the running program. It's usually organised with program code on top of the address space, then heap below it, and stack all the way at the bottom.

#### Address Translation

Assume that each program is written and compiled as if it is loaded at address zero. Then **base and bounds**, a.k.a. **dynamic relocation**, is a mechanism that loads a program into a specified address offset (e.g. 32kB) and then CPU automatically adds this offset to every memory operation. The offset and length are stored in designated registeres.

**Segmentation** is a modification of base and bounds mechanism that assigns for each segment (code, stack, and heap) a pair of base and bounds registers. This way, each segment can lie in a separate memory location. Additional HW bits for growth direction (e.g. stack) and protection bits (e.g. for read only data) that would allow to share code segment with multiple programs could be added to improve efficiency.

##### Paging

Another way to perform virtualisation of memory is by viewing the physical memeory as an array of fixed-sized slots called **page frames**. The mapping of virtual pages of the address space in the physical memory is called **page table** and it performs the **sddress translations** between the virtual pages and physical frames. It is a per-process data structure.
Virtual address is first split to the **virtual page number (VPN)** and the **offset**. For a 64 byte virtual address and 16 byte page it is 2-bit VPN and 4-bit offset. The 2 VPN bits are then translated to **physical frame number (PFN)**, a.k.a. **physical page number (PPN)**, by page table.
In order to speed up the sddress translations, **translation-lookaside buffer (TLB)** are used. It is a hardware per-process cash of virtual-to-physical address translations; and can be managed by either hardware or software.

To efficiently store the page table in memory one can organise the pages into (page size) groups. Each group is assigned to a **page directory entry (PDE)**. All page directory entreis reside in another table called **page directory**. This approach is called **multi-level page table**. If a PDE is composed completely of invalid pages, the whole directory is marked invalid and pages are not allocated.

##### Swapping pages to disc

**Swap space** is a space reserved on disk for moving pages back and forth between memory and disk.
**Present bit** is a bit indicating that the page is in the memory or swapped to disk.
**Page fault** is the act of accessing a page that does not resides in physical memory but was swapped to disk, this action usually invokes **page-fault handler**.
The process of picking a page to kick out of physical memory to disk, or replace is known as the **page-replacement policy**.

#### Page replacement policies

**Average memory access time (AMAT)** is calculated as follows $AMAT = T_{mem} + (P_{miss} T_{disk})$.
**The optimal policy** is a policy that evicts a page that is accessed firthest in the future. Other policies include first in first out(FIFO), Random, least frequently used (LFU), least recently used (LRU).

## Concurrency

A **lock (mutex)** is a variable that is either **available** or **acquired**.

The **test and set** instruction returns the old value and simultaneously updates the said value to the new passed value.

The **compare and swap** instruction performs an update to the new passed value if the original value is equal to a passed expected value, otherwise nothing is done.

The **load linked** and **store conditional** instructions works as follows, the load part loads a value from memory to a register; the store part only succeeds if no intervening store to the address has taken place.

The **fetch and add** instruction automatically increments a value while returning the old value.

A **condition variable** is an explicit queue that threads can put themselves on when some state of execution (i.e., some condition) is not as desired (by waiting on the condition); some other thread, when it changes the said state, can then wake one (or more) of those waiting threads and thus allow them to continue.

A **semaphore** is a structure that has two member functions, acquire and release. Acquire decrements a internal counter and release increments it. Thread is only allowed to proceed if the internal count is >= 0.

## Persistence

**Direct Memory Access (DMA)** is a very specific device within a system that can orchestrate transfers between devices and main memory without much CPU intervention.

**Interrupt** is another techinique to help with device efficiency.

The two approaches to access device registers are **I/O instructions** and **memory mapped I/O**.
