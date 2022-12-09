/*class Solution {
public:
bool able(string s,string t){
    if(s.length()!=t.length())
        return false;
    int c=0;
    for(int i=0;i<s.length();i++)
        c+=(s[i]!=t[i]);
    return c==1;
}
void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int sr,int ds){
    vector <int> dist(n,1005);
    queue <int> q;
    q.push(sr);
    parent[sr]={-1};
    dist[sr]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int u:g[x]){
            if(dist[u]>dist[x]+1){
                dist[u]=dist[x]+1;
                q.push(u);
                parent[u].clear();
                parent[u].push_back(x);
            }
            else if(dist[u]==dist[x]+1)
                parent[u].push_back(x);
        }
    }
}
void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[],int node){
    if(node==-1){
        Paths.push_back(path);
        return ;
    }
    for(auto u:parent[node]){
        path.push_back(u);
        shortestPaths(Paths,path,parent,u);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n=wordList.size(),sr=-1,ds=-1;
    vector<vector<string>> ANS;
    for(int i=0;i<n;i++){
        if(wordList[i]==beginWord)
            sr=i;
        if(wordList[i]==endWord)
            ds=i;
    }
    if(ds==-1)
        return ANS;
    if(sr==-1){
        wordList.emplace(wordList.begin(),beginWord);
        sr=0;
        ds++;
        n++;
    }
    vector <vector<int>> g(n,vector<int>()),Paths;
    vector <int> parent[n],path;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(able(wordList[i],wordList[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
    bfs(g,parent,n,sr,ds); 
    shortestPaths(Paths,path,parent,ds);
    for(auto u:Paths){
        vector <string> now;
        for(int i=0;i<u.size()-1;i++)
            now.push_back(wordList[u[i]]);
        reverse(now.begin(),now.end());
        now.push_back(wordList[ds]);
        ANS.push_back(now);
    }
    return ANS;
}
}; */
class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return vector<vector<string>>();
    unordered_map<string, vector<string>> similar_words;
    int word_len = beginWord.size();
    for (string &w : wordList)
      for (int i = 0; i < word_len; i++)
        similar_words[w.substr(0, i) + '*' + w.substr(i + 1, word_len)]
          .push_back(w);
    queue<string> q;
    unordered_map<string, int> min_distance;
    unordered_map<string, vector<string>> parent;

    q.push(beginWord);
    min_distance[beginWord] = 0;
    int distance = 1;
    bool found = false;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        string u = q.front();
        q.pop();
        if (u == endWord) {
          found = true;
          break;
        }
        for (int i = 0; i < word_len; i++) {
          string pattern = u.substr(0, i) + '*' + u.substr(i + 1, word_len);
          if (similar_words.find(pattern) == similar_words.end())
            continue;
          for (string &v : similar_words[pattern]) {
            if (!min_distance.count(v)) {
              min_distance[v] = distance;
              q.push(v);
            }
            if (min_distance[v] == distance)
              parent[v].push_back(u);
          }
        }
      }
      distance++;
    }

    vector<vector<string>> ans;
    function<void(string, vector<string>)> backtrack = [&](string cur,
                                                           vector<string> tmp) {
      tmp.push_back(cur);
      if (cur == beginWord)
        ans.push_back(vector<string>(tmp.rbegin(), tmp.rend()));
      for (string &w : parent[cur])
        backtrack(w, tmp);
      tmp.pop_back();
    };
    if (found)
      backtrack(endWord, vector<string>());
    return ans;
  }
};
