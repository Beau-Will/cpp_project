#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve(){
	double B,t1,a1,t2,a2;
	scanf("%lf%lf%lf%lf%lf",&B,&t1,&a1,&t2,&a2);
//	cin >> B >> t1 >> a1 >> t2 >> a2;
	double b2 = B/2.0;
	
	if(t1<=t2){
		double rest_a1 = a1-(t2-t1)*B;
		if(rest_a1<=0){
			double dt1 = a1/B;
			double dt2 = a2/B;
			printf("%.8lf %.8lf\n",dt1,dt2);
//			cout << fixed << setprecision(8) << dt1 << " " << dt2 << "\n";
		}else if(rest_a1<=a2){
			double dt1 = rest_a1/b2;
			double t3 = t2+dt1;
			double rest_a2 = a2-(t3-t2)*b2;
			double t4 = t3+rest_a2/B;
			printf("%.8lf %.8lf\n",t3-t1,t4-t2);
//			cout << fixed << setprecision(8) << t3-t1 << " " << t4-t2 << "\n";
		}else{
			double dt2 = a2/b2;
			double t4 = t2+dt2;
			rest_a1 = rest_a1-b2*dt2;
			double dt1 = rest_a1/B;
			double t3 = t4+dt1;
			printf("%.8lf %.8lf\n",t3-t1,t4-t2);
//			cout << fixed << setprecision(8) << t3-t1 << " " << t4-t2 << "\n";
		}
	}else{
		double rest_a2 = a2-(t1-t2)*B;
		if(rest_a2<=0){
			double dt2 = a2/B;
			double dt1 = a1/B;
			printf("%.8lf %.8lf\n",dt1,dt2);
//			cout << fixed << setprecision(8) << dt1 << " " << dt2 << "\n";
		}else if(rest_a2<=a1){
			double dt2 = rest_a2/b2;
			double t4 = t1+dt2;
			double dt1 = (a1-dt2*b2)/B;
			double t3 = t4+dt1;
			printf("%.8lf %.8lf\n",t3-t1,t4-t2);
//			cout << fixed << setprecision(8) << t3-t1 << " " << t4-t2 << "\n";
		}else{
			double dt1 = a1/b2;
			double t3 = t1+dt1;
			rest_a2 = rest_a2-dt1*b2;
			double dt2 = rest_a2/B;
			double t4 = t3+dt2;
			printf("%.8lf %.8lf\n",t3-t1,t4-t2);
//			cout << fixed << setprecision(8) << t3-t1 << " " << t4-t2 << "\n";
		}
	}
}

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
