#include <bits/stdc++.h>

using namespace std; //lets go bad practice

//https://www.youtube.com/watch?v=sW9npZVpiMI

/*
generate a donut rotating about a an arbitrary, centered axis of rotation
this is just a matrix transform which should be fun



but then we have to figure out how to display to 2d
to do this, raycast from viewer (assume 30 units (inches) away from screen),
to each pixel of the screen, and project to the donut
*/

//this is really bad coding style...
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

//operations with small size array matrices are faster than vectors
template<class T, int z> using vec = array<T, z>;
template<class T, int z> using mat = vec<vec<T, z>, z>; //square matrix

template<class T, int z> vec<T, z> transform(const vec<T, z> &v, const mat<T, z> &m) {
    vec<T, z> res = {};
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z; j++) {
            res[i] += v[j] * m[i][j];
        }
    }
    return res;
}

//we only use it once, but I'd like to template it for other things
//(also why I'm not just using float and 3), and hand calculating stuff
template<class T, int z> mat<T, z> mult(const mat<T, z> &a, const mat<T, z> &b) {
    mat<T, z> res = {};
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z; j++) {
            for (int k = 0; k < z; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

//make transform matrices
mat<float, 3> make_trans_mat(float theta, float phi) { //wait what am i doing
    mat<float, 3> theta_trans = {{
        { cos(theta), -sin(theta), 0 },
        { sin(theta),  cos(theta), 0 },
        {          0,           0, 1 } //what the coding style
    }};

    mat<float, 3> phi_trans = {{
        { 1,        0,        0 },
        { 0, cos(phi), -sin(phi) },
        { 0, sin(phi),  cos(phi) }
    }};

    return mult<float, 3>(phi_trans, theta_trans);
}

int main() {
    const int HEIGHT = 20;
    const int WIDTH = 50;
    const int APPROX_FPS = 60;
    const int APPROX_MS_PER_FRAME = 1000 / APPROX_FPS;

    mt<char> framebuffer(HEIGHT, vt<char>(WIDTH, ' '));

    //yes i used chat to generate a framebuffer cry about it
    cout << "\033[?25l";

    auto rotations = make_trans_mat(1, 2);

    while (true) {
        for (auto &line : framebuffer) {
            for (auto &c : line) {
                c = ' ';
            }
        }

        cout << "\033[H";




        for (auto &line : framebuffer) {
            for (auto c : line) {
                cout << c;
            }
            cout << '\n';
        }
        for (int i = 0; i < WIDTH; i++) {
            cout << '.';
        }
        cout << "\n";
        

        this_thread::sleep_for(chrono::milliseconds(APPROX_MS_PER_FRAME));
        break;
    }
}
