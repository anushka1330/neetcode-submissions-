class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while(l < r) {
            int mid = (l + r) / 2;
            long long hours = 0;
            
            for(int x : piles) {
                hours += (x + mid - 1) / mid; // ceil(x/mid)
            }
            
            if(hours <= h) r = mid;   // try smaller speed
            else l = mid + 1;         // need more speed
        }
        
        return l;
    }
};