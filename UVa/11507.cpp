// https://onlinejudge.org/external/115/11507.pdf
#include <bits/stdc++.h>
using namespace std;

template<class T> struct Point3D {
  typedef Point3D P;
  typedef const P& R;
  T x, y, z;
  explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
  bool operator<(R p) const {
    return tie(x, y, z) < tie(p.x, p.y, p.z); }
  bool operator==(R p) const {
    return tie(x, y, z) == tie(p.x, p.y, p.z); }
  P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
  P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
  P operator*(T d) const { return P(x*d, y*d, z*d); }
  P operator/(T d) const { return P(x/d, y/d, z/d); }
  T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
  P cross(R p) const {
    return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
  }
  T dist2() const { return x*x + y*y + z*z; }
  double dist() const { return sqrt((double)dist2()); }
  //Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
  double phi() const { return atan2(y, x); } 
  //Zenith angle (latitude) to the z-axis in interval [0, pi]
  double theta() const { return atan2(sqrt(x*x+y*y),z); }
  P unit() const { return *this/(T)dist(); } //makes dist()=1
  //returns unit vector normal to *this and p
  P normal(P p) const { return cross(p).unit(); }
  //returns point rotated 'angle' radians ccw around axis
  P rotate(double angle, P axis) const {
    double s = sin(angle), c = cos(angle); P u = axis.unit();
    return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
  }
};

map<Point3D<int>, string> values;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  values[Point3D<int>(1, 0, 0)] = "+x";
  values[Point3D<int>(-1, 0, 0)] = "-x";
  values[Point3D<int>(0, 1, 0)] = "+y";
  values[Point3D<int>(0, -1, 0)] = "-y";
  values[Point3D<int>(0, 0, 1)] = "+z";
  values[Point3D<int>(0, 0, -1)] = "-z";

  int l;
  while (cin >> l) {
    if (!l) {
      break;
    }
    Point3D<int> initial(1, 0, 0), cur, rot, change;
    cur = initial;
    string s;
    for (int i = 0; i < l - 1; ++i) {
      cin >> s;
      if (s == "+y") {
        rot = Point3D<int>(0, 1, 0);
      } else if (s == "-y") {
        rot = Point3D<int>(0, -1, 0);
      } else if (s == "+z") {
        rot = Point3D<int>(0, 0, 1);
      } else if (s == "-z") {
        rot = Point3D<int>(0, 0, -1);
      } else {
        continue;
      }
      change = initial.cross(rot);
      if (!(change.cross(cur) == Point3D<int>(0, 0, 0))) {
        cur = change.cross(cur);
      }
    }
    cout << values[cur] << endl;
  }
  return 0;
}