class Solution {

public:

    string str;

    vector<string> allstr;

    vector<char> v{'a','b','c'};

    

    string getHappyString(int n, int k) {

        solve(n);

        return (allstr.size() >= k) ? allstr[k-1] : "";

    }

    

    void solve(int n) {

        if(str.size() == n) allstr.push_back(str);

        else{

            for(int i = 0; i < v.size(); i++){

                if(str.empty() || v[i] != str.back()){

                    str.push_back(v[i]);

                    solve(n);

                    str.pop_back();

                }

            }

        }

    }

};

