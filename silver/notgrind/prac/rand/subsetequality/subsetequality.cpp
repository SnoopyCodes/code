#include <bits/stdc++.h>

using namespace std;
int freqs[100001][18];
int freqt[100001][18];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s, t; cin >> s >> t;
    vector<vector<int>> sappear(18);  //which char, when it appears
    vector<vector<int>> tappear(18);
    for (int i = 0; i < s.size(); i++) {
        sappear[s[i] - 'a'].push_back(i);
        tappear[t[i] - 'a'].push_back(i);
        freqs[i][s[i] - 'a']++;
        freqt[i][t[i] - 'a']++;
    }
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 18; j++) {  //prefix sums
            //for this character, if any other characters don't appear the same amount of times,
            //we ban the other character.?
            //what if we store the indices of appearance, and then compare those?
            //the total should still be the same
            freqs[i][j] += freqs[i-1][j];
            freqt[i][j] += freqt[i-1][j];
        }
    }
    vector<unordered_set<int>> ban(18);  //which characters we will BAN for each character
    for (int i = 0; i < 18; i++) {
        if (sappear[i].size() != tappear[i].size()) { ban[i].insert(i); continue; }  //lol
        for (int occ = 0; occ < sappear[i].size(); occ++) {  //which occurrence of both we are on
            for (int c = 0; c < 18; c++) {  //which character we are comparing
                //if the #occurrences of char c before occurrence occ of char i in string s is not equal to the same in string t, banned!
                if (freqs[sappear[i][occ]][c] != freqt[tappear[i][occ]][c]) {  
                    ban[i].insert(c);
                }
            }
        }
    }
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        string query; cin >> query;
        //check for each one if the rest of the occurrences are banned
        bool valid = true;
        for (int i = 0; i < query.size(); i++) {
            int index = query[i] - 'a';
            for (int j = 0; j < query.size(); j++) {
                int jdex = query[j] - 'a';
                if (ban[index].find(jdex) != ban[index].end()) {
                    valid = false; break;
                }
            }
            if (!valid) { break; }
        }
        if (valid) { cout << "Y"; }
        else { cout << "N"; }
    }
    //oh the order matters
    //bruh
    //is this bitsets
    //so a naive solution is 
    //for each query
    //go through the strings and select the legal characters
    //this takes O(|s|Q) time
    //if we can actually do bitwise optimization
    //then this works
    //so one way we could do bitsets
    //is say for each letter
    //how many there are at this index
    //then we can find which letters
    //are valid for all indexes 0 to N - 1?
    //this really feels like we can use bitsets somehow
    //because we are "turning on" stuff
    //2^18 different subsets
    //what if we prefix sum it ok
    //and then for each letter
    //we check if {letters before} are equal for both
    //if they are not these are in different positions and we start crying
    //for different occurrences of the same letter
    //store the letters for which
    //they have the same # occurrences before?
    //wait actually i think so
    //then for each letter can we find a set of characters so that any subset of those are allowed?
}