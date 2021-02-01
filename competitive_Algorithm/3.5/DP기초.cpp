#include<iostream>
#include<cstring>
using namespace std;

// int M, C, price[25][25];
// int memo[210][25];
// int shop(int money, int g) {
//     if(money < 0) return -10000000;
//     if(g == C) return M - money;
//     // 아래줄을 주석 처리하고 나면, 탑다운  DP가 퇴각 검색으로 바귄다.!!!
//     if (memo[money][g] != -1 ) return memo[money][g];
//     int ans = -1;
//     for(int model = 1; model <= price[g][0]; ++model) {
//         ans = max(ans, shop(money - price[g][model], g+1));
//     }
//     return memo[money][g] = ans;
// }

// void topDown() {

//     int i, j, TC, score;

//     cin >> TC;
//     while(TC--) {
//         cin >> M >> C;
//         for(int i=0; i<C; ++i) {
//             cin >> price[i][0];
//             for(int j=1; j<=price[i][0]; ++j) cin >> price[i][j];
//         }

//         memset(memo, -1, sizeof memo);
//         score = shop(M, 0);
//         if (score < 0) cout << "NO SOLUTION" << endl;
//         else cout << score << endl; 
//     }

// }

void bottomUP() {
    
}
int main() {
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
                        }
                    }
                }
            }
        }
        for(money = 0; money <= M && !reachable[C - 1][money]; ++money);

        if(M+1 == money ) cout << "Np solution" << endl;
        else cout << M - money << endl;

    }


}
