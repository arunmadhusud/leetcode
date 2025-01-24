class Disjointset {
public:
    vector<int> rank, parent;

    // Constructor to initialize the Disjoint Set
    Disjointset(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find the representative of the set containing u (with path compression)
    int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    // Union two sets by rank
    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;  // Already in the same set

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};




class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::map<string,int> accountIds;
        Disjointset ds(accounts.size());

        vector<vector<string>> result;

        map<int, vector<string>> mergedAccounts;
        for (int i = 0; i < accounts.size();i++){
            for (int j = 1; j < accounts[i].size();j++){
                string email_id = accounts[i][j];
                if(accountIds.find(email_id)!=accountIds.end()) ds.unionSet(accountIds[email_id],i);
                else accountIds[email_id]=i;
            }
        }

        for (auto& pair:accountIds){
            int p = pair.second;
            int pu = ds.findParent(p);
            mergedAccounts[pu].push_back(pair.first);
        }
        
        // Prepare result with account names and sorted emails
        for (auto& pair : mergedAccounts) {
            vector<string> account;
            int root = pair.first;  // root of the disjoint set
            string accountName = accounts[root][0];  // Account name
            vector<string> emails = pair.second;    // Emails for this account
            sort(emails.begin(), emails.end());     // Sort emails
            account.push_back(accountName);         // Add account name
            account.insert(account.end(), emails.begin(), emails.end()); // Add emails
            result.push_back(account);
        }

        return result;


        
    }
};