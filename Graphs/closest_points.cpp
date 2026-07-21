#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) +
                (a.y-b.y)*(a.y-b.y));
}

bool cmpX(Point a, Point b) {
    return a.x < b.x;
}

bool cmpY(Point a, Point b) {
    return a.y < b.y;
}

double bruteForce(vector<Point>& P, int l, int r) {
    double mn = DBL_MAX;

    for(int i=l;i<=r;i++)
        for(int j=i+1;j<=r;j++)
            mn = min(mn, dist(P[i], P[j]));

    return mn;
}

double stripClosest(vector<Point>& strip, double d) {

    sort(strip.begin(), strip.end(), cmpY);

    double mn = d;

    for(int i=0;i<strip.size();i++)
        for(int j=i+1;
            j<strip.size() &&
            (strip[j].y-strip[i].y)<mn;
            j++)
            mn = min(mn, dist(strip[i], strip[j]));

    return mn;
}

double closestUtil(vector<Point>& P, int l, int r) {

    if(r-l<=2)
        return bruteForce(P,l,r);

    int mid = (l+r)/2;

    Point midPoint = P[mid];

    double dl = closestUtil(P,l,mid);
    double dr = closestUtil(P,mid+1,r);

    double d = min(dl,dr);

    vector<Point> strip;

    for(int i=l;i<=r;i++)
        if(abs(P[i].x-midPoint.x)<d)
            strip.push_back(P[i]);

    return min(d, stripClosest(strip,d));
}

double closest(vector<Point>& P){

    sort(P.begin(), P.end(), cmpX);

    return closestUtil(P,0,P.size()-1);
}

int main(){

    vector<Point> P = {
        {2,3},
        {12,30},
        {40,50},
        {5,1},
        {12,10},
        {3,4}
    };

    cout << closest(P);

    return 0;
}