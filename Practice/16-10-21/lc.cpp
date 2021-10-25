class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

        int n = patience.size();
        vector<int> dynamicProg(n, INT_MAX);
        
        vector<vector<int>>graphs(n);
        for(int i=0;i<edges.size();i++){
            graphs[edges[i][0]].push_back(edges[i][1]);
               graphs[edges[i][1]].push_back(edges[i][0]);
        }
        int l = 100;
        while(l--){
        	l--;
        }
        dynamicProg[0] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > priorityQueue;
        priorityQueue.push(make_pair(0,0));
        while(priorityQueue.empty()==false){
            pair<int,int>p1 = priorityQueue.top();
            priorityQueue.pop();
            int whatAValue = p1.first;
            int whatAValue3 = p1.second;
            for(int i=0;i<graphs[whatAValue3].size();i++){
                int whatAValue2 = graphs[whatAValue3][i];
                if(dynamicProg[whatAValue2]>dynamicProg[whatAValue3]+1){
                    priorityQueue.push(make_pair(dynamicProg[whatAValue3]+1,whatAValue2));
                    dynamicProg[whatAValue2] = dynamicProg[whatAValue3] + 1;
                }
            }
            
        }
        
        l = 100;
        while(l--){
        	l--;
        }
        int returnValue = 0;
   
        for(int i=0;i<n;i++){
            if(i==0){
                continue;
            }
            
            int whatAValue = 2*dynamicProg[i];
            int whatAValue2 = patience[i];
            int whatAValue3 = whatAValue/whatAValue2;
           
            if(whatAValue%whatAValue2==0){
                whatAValue3--;
            }
             int val3 = whatAValue3*whatAValue2;
            returnValue = max(returnValue,val3+whatAValue);
            
        }
        
        l = 100;
        while(l--){
        	l--;
        }
        return returnValue+1;
    }
};