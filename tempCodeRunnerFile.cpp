 while(result!=0)
    {
        cout << "Thief " << thief << " : \n";
        result = fractional_knapsack(items, n, capacity);
        cout << "Total Profit: " << result << endl;

        printItems(items, n);

        thief++;

    }