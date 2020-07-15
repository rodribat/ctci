
/*
    Angle Between Hands of a Clock
    Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/

    Time: O(1)
    Space: O(1)
*/

#include<iostream>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minutesAngle = minutes*6.0;
        double hoursAngle = hour*30.0 + minutes/60.0*30.0;
        
        /*
        cout << "minutesAngle: " << minutesAngle << endl;
        cout << "hoursAngle: " << hoursAngle << endl;
        */

        double dif = abs(hoursAngle - minutesAngle);
        if (dif > 180.0)
            dif = 360.0 - dif;
        
        return dif;
    }
};

int main()
{
    Solution s;
    cout << "12:30 -> " << s.angleClock(12,30) << endl;
    cout << "11:05 -> " << s.angleClock(11, 5) << endl;

    return 0;
}
