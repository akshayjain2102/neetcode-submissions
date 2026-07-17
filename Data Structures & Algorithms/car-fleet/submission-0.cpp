class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
        vector<pair<int,double>> cars(n);
        for(int i=0;i<n;i++){
            cars[i] = make_pair(position[i], (double) (target-position[i])/speed[i]);
        }  
        sort(cars.begin(),cars.end());
        stack<double> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty() || st.top() < cars[i].second ){
                st.push(cars[i].second);
            }
        }
        return st.size(); 
    }
};
