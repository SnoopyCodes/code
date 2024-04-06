priority_queue<Cow> pq;  //hopefully sorts by seniority lol
    // int wait = 0;
    // int time = 0;
    // for (int i = 0; i <= N; i++) {
    //     //so, the time is whenever cow i arrives
    //     int arrival;
    //     if (i != N) { arrival = v[i].arrive; }
    //     else { arrival = INT_MAX; }
    //     while (!pq.empty() && time < arrival) {
    //         Cow c = pq.top();
    //         wait = max(wait, time - c.arrive);
    //         time += c.length;
    //     }
    //     pq.push(v[i]);
    // }
    // cout << wait;