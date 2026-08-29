class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // (value, original index)
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end()); // sort by value

        // Build connected components
        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i-1].first <= limit) {
                unite(v[i].second, v[i-1].second);
            }
        }

        // group[root] = all values belonging to that component
        map<int, vector<int>> group;

        for (auto [value, index] : v) {
            group[find(index)].push_back(value);
        }

        // Each group's values are already sorted because v is sorted.
        // Use the smallest remaining value for every index.
        vector<int> ptr(n, 0);
        /// isme pta krr rhe hai ki jo apne group me hai wo aaps me swapping krr skte hai 
        // isiliye particular index ke hum uske group me minimum waale ko rkhenge 

        for (int i = 0; i < n; i++) {
            int root = find(i);

            nums[i] = group[root][ptr[root]];
            ptr[root]++;
        }

        return nums;
    }
};