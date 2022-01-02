#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> graph[2505];
int node_value[505];

void relaxing(int u, int v, int w){
//	cout << "DEBUG " << u << " " << v << " " << w << "\n";
	if(node_value[u] > node_value[v] + w){	
		node_value[u] = node_value[v] + w;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;

	for(int i=0; i<tc; i++){
		bool cycle = true;
		int n, m, w;
		cin >> n >> m >> w;	// n = vertex, m = edge, w = worm
		for(int vv = 0; vv < n+2; vv++){
			node_value[vv] = 200000000;
		}

		for(int j=0; j<m; j++){
			int s, e, t;
			cin >> s >> e >> t;	// s = 1, e = 2, t = weight
			graph[s].push_back({t, e});
			graph[e].push_back({t, s});	// add road
		}
		for(int k=0; k<w; k++){
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({-t, e});	// add worm 
		}	
		
		node_value[1] = 0;
		
		
		for(int z=0; z<n-1; z++){
			for(int gg = 1; gg <= n; gg++){
				for(int gg2 = 0; gg2 < graph[gg].size(); gg2++){
//					cout << "DEUBG input: " << gg << " " << graph[gg][gg2].second << " " << graph[gg][gg2].first << "\n";
					relaxing(graph[gg][gg2].second, gg, graph[gg][gg2].first);
					for(int k=1; k<=n; k++){
//						cout << "DEBUG node: " << node_value[k] << " ";
					}
//					cout << "\n";	
				}
				for(int gg2 = 0; gg2 < graph[gg].size(); gg2++){
					relaxing(graph[gg][gg2].second, gg, graph[gg][gg2].first);
					if(node_value[graph[gg][gg2].second] > node_value[gg] + graph[gg][gg2].first){	
						cycle = false;
					}
				}

//				cout << "==== End of edges ===\n";
			}	
//			cout << "===== End of nodes====\n";
		}
		
		int flag = 0;

		for(int k=1; k<=n; k++){
//			cout << "DEBUG node: " << node_value[k] << " ";
			if(node_value[k] < 0){
				flag = 1;
			}
		}
//			cout << "\n";

		if(flag == 1 && cycle == true) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}

