#include<bits/stdc++.h>
vector<int> collidingAsteroids(vector<int> &asteroids)
{
    vector<int> s;
    for(int i = 0 ; i < asteroids.size() ; i++){
        if(asteroids[i] > 0 || s.empty()){
            s.push_back(asteroids[i]);
        }
        else {
            bool destroyed = false;
            while(!s.empty() && s.back() > 0){
                if(s.back() < -asteroids[i]){
                    s.pop_back();
                } else if(s.back() == -asteroids[i]){
                    s.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                s.push_back(asteroids[i]);
            }
        }
    }
    return s;
}

// leetcode

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
             vector<int> s;
        for(int i = 0 ; i < asteroids.size() ; i++){
            if(asteroids[i] > 0) s.push_back(asteroids[i]);
            else{
                while(!s.empty() && s.back() > 0 && abs(asteroids[i]) > s.back()){
                    s.pop_back();
                }
                if(!s.empty() && s.back() == abs(asteroids[i])) s.pop_back();
                else if(s.empty() || s.back() < 0) s.push_back(asteroids[i]);
            }
        }
        return s;
        }
    };


    tc = o(2n)
    sc = o(n)