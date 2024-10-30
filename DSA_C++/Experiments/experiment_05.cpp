/*An election is contested by 5
candidates. The candidates are numbered 1to 5 and


the voting is done by marking the
candidate number on the ballot paper.


Write a C++ program to read the
ballots and count the votes cast for each candidate using an array.


In case, a number read is outside
the range 1 to 5, the ballot should be considered as a ‘spoilt ballot’ and the
program should also count the number of spoilt ballots.*/

#include <iostream>
#include <vector>
using namespace std;

class Election {
private:
    vector<int> votes;
    int spoiltVotes;

public:
    Election() : votes(5, 0), spoiltVotes(0) {}

    void readBallots() {
        int candidateNumber;
        cout << "Enter the candidate numbers (enter -1 to stop):" << endl;
        while (true) {
            cin >> candidateNumber;
            if (candidateNumber == -1) break;
            if (candidateNumber >= 1 && candidateNumber <= 5) {
                votes[candidateNumber - 1]++;
            } else {
                spoiltVotes++;
            }
        }
    }

    void displayResults() const {
        cout << "Results of the Election:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "Candidate " << i + 1 << ": " << votes[i] << " votes" << endl;
        }
        cout << "Spoilt Ballots: " << spoiltVotes << endl;
    }
};

int main() {
    Election election;
    election.readBallots();
    election.displayResults();
    return 0;
}
