class Solution {
public:
    bool isIsomorphic(string s, string t) {

        map<char, char> mp1;  // s -> t
        map<char, char> mp2;  // t -> s

        for(int i = 0; i < s.size(); i++) {

            // s[i] aur t[i] dono naye hain
            if(mp1.find(s[i]) == mp1.end() &&
               mp2.find(t[i]) == mp2.end()) {

                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }

            // s[i] pehle se mapped hai
            else {

                if(mp1[s[i]] != t[i])
                    return false;

                if(mp2[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};