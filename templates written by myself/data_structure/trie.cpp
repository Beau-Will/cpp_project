struct trie{
  std::vector<std::vector<int>> next;
  std::vector<int> cnt;
  int siz;

  trie(){
    next.resize(100001,std::vector<int>(26));
    cnt.resize(100001);
    siz = 0;
  }

  void insert(std::string &s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
      int c = s[i]-'a';
      if(!next[p][c]){
        next[p][c] = ++siz;
      }
      p = next[p][c];
    }
    ++cnt[p];
  }

  int find(std::string &s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
      int c = s[i]-'a';
      if(!next[p][c]) return 0;
      p = next[p][c];
    }
    return cnt[p];
  }
};