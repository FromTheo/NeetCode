#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std; 

/* -------- Subject --------  
Implement a time-based key-value data structure that supports:
Storing multiple values for the same key at specified time stamps
Retrieving the key's value at a specified timestamp

Implement the TimeMap class:

- TimeMap() Initializes the object.
- void set(string key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
- string get(string key, int timestamp) Returns the most recent value of key if set was previously called on it and the most recent 
  timestamp for that key prev_timestamp is less than or equal to the given timestamp (prev_timestamp <= timestamp). 
  If there are no values, it returns "".

Note: For all calls to set, the timestamps are in strictly increasing order.*/

/* -------- Explanation --------
- The default constructor initializes keyStore using the default constructor of the std::map class.
- For the set method, we simply add the value using .push_back().
- For the get method, we search for result according to the previous criteria, using a search with two pointers. */

class TimeMap 
{
    private : 

    map<string, vector<pair<int,string>>> keyStore; 

    public:

    TimeMap() {}  
    
    void set(string key, string value, int timestamp) 
    {
        keyStore[key].push_back(std::make_pair(timestamp, value));  
    } 
    
    string get(string key, int timestamp) 
    {
        vector<pair<int,string>>& values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) 
            {
                result = values[mid].second;
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    TimeMap timeMap; 
    timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
    timeMap.get("alice", 1);           // return "happy"
    timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
    timeMap.get("alice", 3);           // return "sad"
    return 0; 
}