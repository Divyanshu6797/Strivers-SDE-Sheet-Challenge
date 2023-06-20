class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        int len=targetWord.size();
        queue<pair<string,int>> q;
        set<string> st(wordList.begin(),wordList.end());
        q.push({startWord,1});
        
        
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            
            if(word==targetWord)  return steps;
            
            for(int i=0;i<len;i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
            
            
        }
        return 0;
        
        
    }
};
