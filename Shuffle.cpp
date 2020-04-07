#include <bits/stdc++.h>
using namespace std;


int main() {
	for(int n=3; n<=8; n++) {
	map<string,int, greater <int> >mp;
	mp.clear();

    mt19937 rng;
    rng.seed(std::random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(0,n-1);
	for(int k=1; k<1000000; k++) {
		int B[n+1];
		for(int r=0; r<n; r++)
			B[r] = r+1;
			
		for(int i=0;i<n;i++) {
			int j = rand()%n;
			swap(B[i],B[j]);
		}
		string str = "";
		for(int i=0;i<n;i++) {
			str+=to_string(B[i]);
		}
		mp[str]++;
	}
	string keymin, keymax;
	int max = INT_MIN, min = INT_MAX;
	  int cnt = 0; 
    for (auto it=mp.rbegin(); it!=mp.rend() ; it++) {
        if(cnt<=3) {
        	cout << "(" << (*it).first << ", "
             << (*it).second << ")" << endl; 
    
         } 
                  cnt++;
                  if (cnt>3) break;

      }
  
	// for(auto it : mp) {
	// 	if(it.second>max) {
	// 		max = it.second;
	// 		keymax = it.first;
	// 	}
	// 	if(it.second<min) {
	// 		min = it.second;
	// 		keymin = it.first;
	// 	}
	// 	//if(n==7)
	// 	//cout << it.first <<" " <<it.second << endl;
	// }
		//cout <<keymax<<" "<<max<<endl;
		//cout <<keymin<<" "<<min<<endl;	
	}
	return 0;
}