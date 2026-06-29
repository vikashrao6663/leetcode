class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int>ans;
        int sum =0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
     for(int i =0;i<students.size();i++){
        if(students[i]>seats[i])
        sum=sum+(students[i]-seats[i]);
        else
         sum += seats[i] - students[i];
     }
     return sum;
    }
};