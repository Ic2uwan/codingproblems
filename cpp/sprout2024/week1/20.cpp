#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        queue<int> vq[1001]; // index is group id
        vector<int> mp(1000001, 0);
        queue<int> idq; // store queue in groups
        int N;
        cin >> N;

        for(int i = 0, k; i < N; ++i){
            cin >> k;
            for(int j = 0, in; j < k; ++j){
                cin >> in;
                mp[in] = i+1;
            }
        }
        int M;
        cin >> M;
        cout << "Line #" << t << '\n';
        while(M--){
            string s;
            int opid;
            cin >> s;
            if(s=="ENQUEUE"){
                cin >> opid;
                int gid = mp[opid];
                if(gid == 0){
                    vq[gid].push(opid);
                    idq.push(gid);
                }
                else{
                    if(vq[gid].empty()){
                        idq.push(gid);
                    }
                    vq[gid].push(opid);
                }
            }
            else if(s=="DEQUEUE"){
                int frt = idq.front();
                cout << vq[frt].front() << '\n';
                if(frt == 0){
                    vq[frt].pop();
                    idq.pop();
                }
                else{
                    vq[frt].pop();
                    if(vq[frt].empty()){
                        idq.pop();
                    }
                }
            }
        }
    }
}
