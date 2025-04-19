std::vector<int> inv;

auto pre_procession = [&](int n){
	constexpr int P = 1e9+7;
	inv.resize(n+1);
	inv[0] = inv[1] = 1;
	for(int i = 2;i<=n;++i){
		inv[i] = i64(P-P/i)*inv[P%i]%P;
	}
};