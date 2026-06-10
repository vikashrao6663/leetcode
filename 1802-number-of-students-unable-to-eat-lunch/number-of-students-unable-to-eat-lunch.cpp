class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n = students.size();
        int count =0;
        // push student in queue
        for(int i =0;i<n;i++){
            q.push(students[i]);
        }
        //if queue == sandwiches pop both
        int i =0;
        while(q.size()>0 && count!=q.size()){ // isme q ka size =0 ho gya to break ho jyga and count ka value kbhi size of kyu ho gya to break kr dege
            if(q.front()==sandwiches[i]){
               
                count=0;
                 q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return count;
    }
};