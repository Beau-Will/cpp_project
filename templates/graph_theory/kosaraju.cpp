	int n,m;std::cin >> n >> m;
	
	std::vector<std::vector<int>> adj1(n),adj2(n),adj3(n);
	
	for(int i = 0;i<m;++i){
		int u,v;std::cin >> u >> v;
		--u,--v;
		adj1[u].emplace_back(v);
		adj2[v].emplace_back(u);
	}
	
	std::vector<bool> vis(n);
	std::vector<int> dfn;
	
	auto dfs1 = [&](auto &&self,int u)->void{
		vis[u] = true;
		for(const auto &v:adj1[u]){
			if(!vis[v]){
				self(self,v);
			}
		}
		dfn.emplace_back(u);
	};
	
	std::vector<int> _fa(n);
	std::iota(_fa.begin(),_fa.end(),0);
	std::vector<int> _siz(n);
	std::unordered_map<int,std::vector<int>> map;
	
	auto dfs2 = [&](auto &&self,int u,int fa)->void{
		vis[u] = false;
		_fa[u] = fa;
		++_siz[fa];
		map[fa].emplace_back(u);
		for(const auto &v:adj2[u]){
			if(vis[v]){
				self(self,v,fa);
			}
		}
	};
	
	auto kosaraju = [&](){
		for(int i = 0;i<n;++i){
			if(!vis[i]){
				dfs1(dfs1,i);
			}
		}
		for(int i = n-1;i>=0;--i){
			int &u = dfn[i];
			if(vis[u]){
				dfs2(dfs2,u,u);
			}
		}
	};
	
	auto shrinking_point = [&](){
		for(int u = 0;u<n;++u){
			for(const auto &v:adj1[u]){
				if(_fa[u]!=_fa[v]){
					adj3[_fa[u]].emplace_back(_fa[v]);
				}
			}
		}
	};