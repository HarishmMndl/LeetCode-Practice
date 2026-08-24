class Solution {
public:
    char findTheDifference(string s, string t) {
     char ans;   
     sort(s.begin(),s.end());
     sort(t.begin(),t.end());
     int i = 0;
     int j = 0;
     while(i < s.length() && j < t.length()){
        if(s[i] == t[j]){
            i++;
            j++; 
        }else{
            ans = t[j];
            break;
        }
     } 
     if(!ans) ans = t[t.length()-1];

     return ans;  
    }
};