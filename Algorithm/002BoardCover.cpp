///*
//testcase C (C<=30)
//H, W (1<= H, W<=20)
//Fill the board with 
//□
//□□ <<-- these
//
//output : print all Number of ways to cover them
//
//input
//3
//3 7
//#.....#
//#.....#
//##...##
//3 7
//#.....#
//#.....#
//##..###
//8 10
//##########
//#........#
//#........#
//#........#
//#........#
//#........#
//#........#
//##########
//
//output
//0
//2
//1514
//*/
//
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const vector<pair<int, int>> TYPES[4] = {
//    { make_pair(0, 0), make_pair(1, 0), make_pair(0, 1) },
//    { make_pair(0, 0), make_pair(1, 0), make_pair(1, 1) },
//    { make_pair(0, 0), make_pair(0, 1), make_pair(1, 1) },
//    { make_pair(0, 0), make_pair(0, 1), make_pair(-1, 1) }
//};
//
//bool isRange(int H, int W, int x, int y) {
//    return  (0 <= y && y < H) && (0 <= x && x < W);
//}
//
//pair<int, int> findCoordinate(int H, int W, vector< vector<char>> board) {
//    for (int y = 0; y < H; y++) {
//        for (int x = 0; x < W; x++) {
//            if (board[y][x] == '.') {
//                return make_pair(x, y);
//            }
//        }
//    }
//
//    return make_pair(-1, -1);
//}
//
//bool isAvailable(int H, int W, vector< vector<char>> board, int x, int y, int state) {
//    for (auto move : TYPES[state]) {
//        int nx = x + move.first;
//        int ny = y + move.second;
//
//        if (!isRange(H, W, nx, ny)) {
//            return false;
//        }
//
//        if (board[ny][nx] == '#') {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//void setBoard(vector< vector<char>>& board, int x, int y, int state, char c) {
//    for (auto move : TYPES[state]) {
//        int nx = x + move.first;
//        int ny = y + move.second;
//        board[ny][nx] = c;
//    }
//}
//
//int solution(int H, int W, vector< vector<char>> board) {
//    auto coordinate = findCoordinate(H, W, board);
//    int x = coordinate.first;
//    int y = coordinate.second;
//
//    if (y == -1) {
//        return 1;
//    }
//
//    int answer = 0;
//
//    for (int i = 0; i < 4; i++) {
//        if (isAvailable(H, W, board, x, y, i)) {
//            setBoard(board, x, y, i, '#');
//            answer += solution(H, W, board);
//            setBoard(board, x, y, i, '.');
//        }
//    }
//
//    return answer;
//}
//
//int main() {
//    int C;
//    cin >> C;
//
//    if (!(1 <= C && C <= 30)) {
//        cout << "fail" << endl;
//        return 0;
//    }
//
//    for (int i = 0; i < C; i++) {
//        int H, W;
//        cin >> H >> W;
//
//        if (!(1 <= H && H <= 20) || !(1 <= W && W <= 20)) {
//            cout << "fail" << endl;
//            return 0;
//        }
//
//        auto board = vector< vector<char>>(H, vector<char>(W, '.'));
//        int cnt = 0;
//
//        for (int y = 0; y < H; y++) {
//            for (int x = 0; x < W; x++) {
//                char c;
//                cin >> c;
//                board[y][x] = c;
//
//                if (!(c == '#' || c == '.')) {
//                    cout << "fail" << endl;
//                    return 0;
//                }
//
//                if (c == '.') {
//                    cnt += 1;
//                }
//            }
//        }
//
//        if (cnt > 50) {
//            cout << "fail" << endl;
//            return 0;
//        }
//
//        int result = solution(H, W, board);
//        cout << result << endl;
//    }
//
//    return 0;
//}