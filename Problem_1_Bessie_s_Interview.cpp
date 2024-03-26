#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

typedef long long LongLong;
typedef pair<LongLong, LongLong> PairLL;

int main() {
    LongLong num_jobs, num_sets;
    cin >> num_jobs >> num_sets;

    vector<set<LongLong>> job_sets;
    priority_queue<PairLL, vector<PairLL>, greater<PairLL>> priority_queue_jobs;

    for (int i = 0; i < num_sets; ++i) {
        set<LongLong> temp_set;
        temp_set.insert(i);
        job_sets.push_back(temp_set);

        LongLong duration;
        cin >> duration;
        priority_queue_jobs.push({duration, i});
    }

    int index = num_sets;
    while (index < num_jobs) {
        set<LongLong> combined_set;
        LongLong duration = priority_queue_jobs.top().first;
        int counter = 0;

        while (!priority_queue_jobs.empty() && duration == priority_queue_jobs.top().first) {
            combined_set.insert(job_sets[priority_queue_jobs.top().second].begin(), job_sets[priority_queue_jobs.top().second].end());
            priority_queue_jobs.pop();
            counter++;
        }

        int j = 0;
        while (j < counter) {
            LongLong time;
            cin >> time;
            job_sets.push_back(combined_set);
            priority_queue_jobs.push(make_pair(time + duration, index));
            index++;
            j++;
        }
    }
  
    set<LongLong> final_combined_set;
    LongLong final_duration = priority_queue_jobs.top().first;
    int final_counter = 0;

    while (!priority_queue_jobs.empty() && final_duration == priority_queue_jobs.top().first) {
        final_combined_set.insert(job_sets[priority_queue_jobs.top().second].begin(), job_sets[priority_queue_jobs.top().second].end());
        priority_queue_jobs.pop();
        final_counter++;
    }

    cout << final_duration << endl;

    const int k = num_sets;
    bool answer[k];
    for (int i = 0; i < k; ++i) {
        answer[i] = false;
    }

    for (int a: final_combined_set) {
        answer[a] = true;
    }

    for (int i = 0; i < k; ++i) {
        cout << answer[i];
    }

    return 0;
}
