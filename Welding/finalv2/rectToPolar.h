const double pi = 3.1415926;
const double toDegrees = 180/pi;
double angle(double x, double y)
{
	double ans;
    if (x>=0 && y>0){
        ans = (std::atan(y/x))*toDegrees;
    }
    if (x<0 && y>=0){
        ans = (pi + std::atan(y/x))*toDegrees;
    } 
    if (x<=0 && y<0){
        ans = (pi + std::atan(y/x))*toDegrees;
    } 
    if (x>0 && y<0){
        ans = (2*pi + std::atan(y/x))*toDegrees;
    }
    return ans; 
}
