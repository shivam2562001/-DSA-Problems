

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int P_B = 256;
    const int P_M = 1000005;
    int hash(const string& s) {
        int r = 0;
        for (int i = 0; i < s.size(); i++) {
            r = r * P_B + s[i];
            r %= P_M;
        }
        return r;
    }
    
    bool rabin_karp(const string& hstack,const string& n) {
        int h1 = hash(n);
        int h2 = 0;
        int power = 1;
        for (int i = 0; i < n.size(); i++)
            power = (power * P_B) % P_M;
        for (int i = 0; i < hstack.size(); i++) {
            h2 = h2 * P_B + hstack[i];
            h2 %= P_M;
            if (i >= n.size()) {
                h2 -= power * hstack[i - n.size()] % P_M;
                if (h2 < 0)
                    h2 += P_M;
            }
            if (i >= n.size() - 1 && h1 == h2){
                return true;}
        }
        return false;
    }

    bool rotateString(string s, string g) {

        if (s.length() != g.length())
            return false;
        string k = s + s;
        return rabin_karp(k, g);
    }
};