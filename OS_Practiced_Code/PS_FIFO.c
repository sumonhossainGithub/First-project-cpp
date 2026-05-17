#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], arrival[n], execution[n], completion[n];
    int i, j, pos, temp;

    // Input process details
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time of process %d: ", process[i]);
        scanf("%d", &arrival[i]);
        printf("Enter execution time of process %d: ", process[i]);
        scanf("%d", &execution[i]);
        completion[i] = -1;
    }

    // Sorting processes based on arrival time (FCFS scheduling)
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (arrival[pos] > arrival[j]) {
                pos = j;
            }
        }

        // Swap arrival time
        temp = arrival[i];
        arrival[i] = arrival[pos];
        arrival[pos] = temp;

        // Swap execution time
        temp = execution[i];
        execution[i] = execution[pos];
        execution[pos] = temp;

        // Swap process IDs
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    // Calculating Completion Time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            completion[i] = arrival[i] + execution[i];
        } else {
            if (completion[i - 1] > arrival[i]) {
                completion[i] = completion[i - 1] + execution[i];
            } else {
                completion[i] = arrival[i] + execution[i];
            }
        }
    }

    // Printing final table after calculating completion times
    printf("\nProcess\tArrival Time\tExecution Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", process[i], arrival[i], execution[i], completion[i]);
    }

    return 0;
}
