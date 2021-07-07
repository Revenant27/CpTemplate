
using li = long long int;
using ld = long double;
using T = li;
const ld eps = 1e-9;

int ldcmp(ld a) {return abs(a) < eps? 0: (a>0?1:-1);}

struct pt{
    T x,y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T m) {return {x*m, y*m};}
    pt operator/(T m) {return {x/m, y/m};}
};

bool operator==(pt a, pt b) {return !ldcmp(a.x-b.x) && !ldcmp(a.y-b.y);}

T norm(pt p) {return p.x*p.x + p.y*p.y;}
ld abs(pt p) {return sqrt((ld)norm(p));}

ostream& operator<<(ostream& os, pt p){
    return os << "(" << p.x << "," << p.y << ")";
}
istream& operator>>(istream& os, pt &p){
    return os >> p.x >> p.y;
}

pt trans(pt p, pt v) {return p + v;}
pt scale(pt p, pt c, ld s) {return (p-c)*s + c;}
pt rot(pt p, pt c, ld ang) {
    return {(p.x-c.x)*cos(ang) - (p.y-c.y)*sin(ang) + c.x, (p.x-c.x)*sin(ang) + (p.y-c.y)*cos(ang) + c.y};
}

T dot(pt a, pt b) {return a.x*b.x + a.y*b.y;}
bool isPerp(pt a, pt b) {return !ldcmp(dot(a,b));}

ld angle(pt a, pt b){ //[0,PI]
    return acos(max((ld)-1.0,min((ld)1.0,(ld)dot(a,b) / abs(a) / abs(b))));
}

T cross(pt a, pt b) {return a.x*b.y - a.y*b.x;}

//orient>0 anti-clock, orient=0 colinear, orient>0 clock
T orient(pt a, pt b, pt c){ return cross(b-a,c-a);}

//is p inside BAC
bool insideAngle(pt a, pt b, pt c, pt p) {
    if(orient(a,b,c) < 0) swap(b,c);
    return orient(a,b,p) >= 0 && orient(a,c,p) <= 0;
}

//angle BAC [0,2PI]
ld orientedAngle(pt a, pt b, pt c){
    ld k = angle(b-a, c-a);
    if(orient(a, b, c) >= 0) return k;
    return 2*PI - k;
}

bool half(pt p) { return p.y > 0 || p.x < 0 && p.y == 0;}

bool polarCmp(pt a, pt b, pt o = {0,0}){
    return make_tuple(half(a-o), 0, norm(a-o)) < make_tuple(half(b-o), cross(a-o, b-o), norm(b-o));
}
