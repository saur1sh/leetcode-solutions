struct CompareWords {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        // Compare by frequency (higher frequency should come first)
        if (a.second != b.second) {
            return a.second > b.second; // Use less than for max heap
        }
        // If frequencies are the same, compare lexicographically (lower string should come first)
        return a.first < b.first; // Use greater than for min heap
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        
        // Count the frequency of each word
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        // Create a min heap (priority queue) to store the words by their frequency
        priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> minHeap;
        
        // Iterate through the word count map and insert words into the min heap
        for (const auto& entry : wordCount) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Extract the k most frequent words from the min heap
        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            cout<<minHeap.top().first <<" "<<minHeap.top().second<<endl;
            result[i] = minHeap.top().first;
            minHeap.pop();
        }
        //sort(result.begin(), result.end());
        return result;
    }
};