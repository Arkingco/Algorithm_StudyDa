#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int M, C, price[25][25];
int memo[210][25];
int count = 0;
int shop(int money, int g) {
    if(money < 0) return -10000000;
    if(g == C) return M - money;
    count++;
    // 아래줄을 주석 처리하고 나면, 탑다운  DP가 퇴각 검색으로 바귄다.!!!
    // if (memo[money][g] != -1 ) return memo[money][g];
    int ans = -1;
    for(int model = 1; model <= price[g][0]; ++model) {
        ans = max(ans, shop(money - price[g][model], g+1));
    }
    
    return memo[money][g] = ans;
}

void printf_shop(int money, int g) {
    if(money < 0 || g == C ) {
        return;
    }
    // 어느 품목이 최적인가?
    for(int model = 1; model <= price[g][0]; model++) { 
        cout << shop(money - price[g][model], g+1)<< " --- " << endl;
        if(shop(money - price[g][model], g+1) == memo[money][g]) {
            cout << price[g][model] << (g == C-1) ? '\n' : '-';
            printf_shop(money - price[g][model], g + 1);
        }
    }

}

void topDown() {

    int i, j, TC, score;

    cin >> TC;
    while(TC--) {
        cin >> M >> C;

        for(int i=0; i<C; ++i) {
            cin >> price[i][0];
            for(int j=1; j<=price[i][0]; ++j) cin >> price[i][j];
        }

        memset(memo, -1, sizeof memo);
        int score3 = shop3(0, 0);
        cout << count << " count " << endl;
        count =0;
        memset(memo, -1, sizeof memo);
        score = shop(M, 0);
        cout << count << " count2 " << endl;

         

        
        if (score < 0) cout << "NO SOLUTION" << endl;
        else {
            cout << score << endl;
            // for(int i=0; i<250; ++i) {
            //     for(int j=0; j<25; ++j) {
            //         cout << memo[i][j] << " "; 
            //     }
            //     cout << endl;
            // }
            // printf_shop(score, 0);
        }
    }

}

vector<pair<int, int> >anser;
vector<pair<int, int> > search[25][210];

void find(int g, int money) {

    // 기저사례
    if(g == 0) {
        anser.push_back({g, money});
        return;
    } 

    // 그래프 탐색처럼 정답 들을 역추적한다.
    for(int next=0; next<search[g][money].size(); ++next) {
        anser.push_back({g, money});
        int nextG = search[g][money][next].first;
        int nextMoney = search[g][money][next].second;

        find(nextG, nextMoney);
    }
}

void bottomUp() {
    int g, money, k, TC, M, C;
    int price[25][25];
    bool reachable[25][210];
   
    cin >> TC;
    while(TC--) {
        cin >> M >> C;
        for(g = 0; g < C; ++g) {
            cin >> price[g][0];
            for(money = 1; money<=price[g][0]; ++money) {
                cin >> price[g][money];
            }
        }
        memset(reachable, false, sizeof reachable);

        for(g = 1; g <= price[0][0]; ++g) {
            if(M-price[0][g] >= 0) {
                reachable[0][M-price[0][g]] = true;
            }
        }

        for(g = 1; g < C; ++g) {
            for(money = 0; money < M; ++money) {
                if(reachable[g-1][money]) {
                    for(k = 1; k <= price[g][0]; ++k) {
                        if(money - price[g][k] >= 0 ) {
                            reachable[g][money - price[g][k]] = true;
                            search[g][money-price[g][k]].push_back({g-1, money});
                        }
                    }
                }
            }
        }
        for(money = 0; money <= M && !reachable[C - 1][money]; ++money);

        if(M+1 == money ) cout << "No solution" << endl;
        else {
            find(C-1, money);
            cout << M - money << endl;
        } 

        for(money = 0; money <= M && !memo[C-1][money]; ++money);

        cout << endl;
        for(int i=0; i<anser.size(); ++i) {
            cout << anser[i].first << "," << anser[i].second << "   ";
            if( (i+1) % C == 0) cout << endl;
        }
        cout << endl;

        anser.clear();
    }
}

int main() {
   
    topDown();
    
}
