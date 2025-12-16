#include <bits/stdc++.h>
#include <sys/stat.h>
using namespace std;
namespace fs = filesystem;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)
#define rep3(i, s, e) for (auto i = s; i != e; s < e ? i++ : i--)
#define rep2(i, e) rep3(i, (e > 0 ? 0 : -(e)-1), (e > 0 ? e : -1))

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string path = "aoc2024";
    struct stat sb;
    string output = "";
    for (const auto& entry : fs::directory_iterator(path)) {
        fs::path outfilename = entry.path();
        string outfilename_str = outfilename.string();
        const char* path = outfilename_str.c_str();
        output = "";
        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
            output.append(path).append(" is a file\n");
            output = outfilename_str + " is a file\n";
            cout << output << "\n";
        }   else {
            output.append(path).append(" is a directory\n");
        }
    }
}