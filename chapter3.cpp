#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "please enter your name: "<< endl;
    string name;
    cin >> name;
    cout << "welcome " << name << endl;

    //ask to read midterm and final score
    cout << "pls enter you midterm and final scores: " << endl;
    double midterm, final;
    cin >> midterm >> final;
    cout << "midterm: " << midterm << endl << "final: " << final << endl;

    //ask and read the homework grades
    cout << "Enter all your homework grades,"
            "and followed by end of file: " << endl;
    vector<double> homework;
    double x;
    while(cin >> x) {
        homework.push_back(x);
    }

    //check that the student entered some grades
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << "you must enter your grades. "
                "pls try again. " << endl;
        return 1;
    }

    // cout the grades 
    cout << "the homework grades are: " << endl;
    for (vec_sz i=0; i< size; i++) {
        cout << homework[i] << endl;
    }
    cout << endl;

    //sort the grades
    sort(homework.begin(), homework.end());
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? median = (homework[mid] + homework[mid-1])/2 : homework[mid];

    // compute and write the final grade
    streamsize prec = cout.precision();
    cout << "Your final grades is: " << setprecision(5)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;
}