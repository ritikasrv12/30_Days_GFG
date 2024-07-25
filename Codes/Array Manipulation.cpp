long arrayManipulation(int n, vector<vector<int>> queries) {
      vector<long> arr(n + 1, 0);

    // Perform all queries
    for (const auto& query : queries) {
        int a = query[0], b = query[1], k = query[2];
        arr[a - 1] += k;
        arr[b] -= k;
    }

    // Calculate prefix sums and find maximum
    long max_val = 0, prefix_sum = 0;
    for (const auto& val : arr) {
        prefix_sum += val;
        max_val = max(max_val, prefix_sum);
    }

    return max_val;
}
