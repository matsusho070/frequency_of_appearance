#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  while(cin >> n, n != 0){
    int s[2][n];
    for(int i = 0; i < n ; i++)
    {
      cin >> s[0][i];
    }
    bool fixed = false;
    int src_index = 0;
    int operation_count = 0;
    while(!fixed)
    {
      map<int, int> appearance_map;
      for(int i = 0; i < n ; i ++)
      {
        ++appearance_map[s[src_index][i]];
      }
      fixed = true;
      for(int i = 0; i < n; i++) {
        s[1-src_index][i] = appearance_map[s[src_index][i]];
        if(s[0][i] != s[1][i]){
          fixed = false;
        }
      }
      if(fixed)break;
      src_index = 1 - src_index;
      ++operation_count;
    }
    cout << operation_count << endl;
    for(int i = 0; i < n; i++) {
      cout << s[0][i];
      if(i < n - 1) cout << " ";
    }
    cout << endl;
  }
}
