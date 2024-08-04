class Solution{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({end[i],start[i]});
        }
        sort(temp.begin(),temp.end());
        int ans=1,last=temp[0].first;
        for(int i=1;i<n;i++){
            if(last<temp[i].second){
                ans++;
                last=temp[i].first;
            }
        }
        return ans;
        // Your code here
    }
};
