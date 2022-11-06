/*
Leetcode weekly contest 318
(Priority_queue)

You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. 
Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because 
they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the 
smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.

TC: O(N*Log(N))  SC: O(N)

Approach is to store the candidates from front and back in two diff. priority queue.
Then remove the smallest cost candidate among both the queue and push a new candidate to the same
queue from where we removed last time.
*/
long long totalCost(vector<int>& costs, int k, int candidates){
    long long ans = 0;
    
    priority_queue<int, vector<int>, greater<int>> pqf, pqb;  // pqf - front pq,stores cost from front ; pqb -  back pq,stores cost from back
    int i = 0, j = costs.size() - 1;
    
    while( i < candidates && i <= j){  //push first and last candidate cost to both pq
        pqf.push(costs[i]);
        if(i != j) 
        	pqb.push(costs[j]);
        i++; j--;
    }
    
    int lastpop = 0; //keep track of which pq is used last, 0 - taken from front pq, 1 - taken from back pq
    
    //get smallest cost
    if(pqb.size() == 0 || (pqf.size() != 0 && pqf.top() <= pqb.top() ) ){
        ans += pqf.top(); 
        pqf.pop();
        lastpop = 0;
    }else{
        ans += pqb.top(); 
        pqb.pop();
        lastpop = 1;
    }
    
    while(--k){
        if(i <= j){   //push new cost to pq
            if(lastpop == 0 ) { 
            	pqf.push(costs[i]);  
            	++i;
            }
            else {
            	pqb.push(costs[j]); 
            	--j; 
            }
        }
        
        //get smallest cost
        if(pqb.size() == 0 || (pqf.size() != 0 && pqf.top() <= pqb.top() ) ){
            ans += pqf.top(); 
            pqf.pop();
            lastpop = 0;
        }else{
            ans += pqb.top(); 
            pqb.pop();
            lastpop = 1;
        }
    }
    
    return ans;

}
