int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int gas_sum = 0;
    int cost_sum = 0;

    for (int i = 0; i < gasSize; i++) {
        gas_sum += gas[i];
    }

    for (int j = 0; j < costSize; j++) {
        cost_sum += cost[j];
    }
    if (gas_sum < cost_sum) {
        return -1;
    }

    int total = 0;
    int start = 0;
    for (int i = 0; i < gasSize; i++) {
        total += (gas[i] - cost[i]);

        if (total < 0) {
            total = 0;
            start = i + 1;
        }
    }

    return start;
}