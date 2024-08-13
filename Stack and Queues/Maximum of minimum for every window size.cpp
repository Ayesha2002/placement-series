class Solution
{
    public:
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int>ans(n,0);
        stack<pair<int,int>>s;
        int res = 0;
        for(int i = 0; i<n; i++){
            if(s.empty()||s.top().first<=arr[i])s.push({arr[i],1});
            else{
                res = 0;
                while(!s.empty() && s.top().first>arr[i]){
                    ans[s.top().second+res-1] = max(ans[s.top().second+res-1],s.top().first);
                    res+=s.top().second;
                    s.pop();
                }
                s.push({arr[i],res+1});
            }
        }
        res = 0;
        while(!s.empty()){
            ans[s.top().second+res-1] = max(ans[s.top().second+res-1],s.top().first);
            res+=s.top().second;
            s.pop();
        }
        for(int i = n-2; i>=0; i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
    }
};
